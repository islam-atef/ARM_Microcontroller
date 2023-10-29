/********************************************************************************************/
/* 	AUTHOR  		: islam atef Mohamed 													                              */
/* 	VERSION 		:	  V2.0 																                                    */
/* 	DATE    		:  1/2023 																                                  */
/*	Discribtion  	:  This is the Program file For the Embedded Flash Memory				          */
/* 								interface Peripheral at ARM-CORTEX m4						                          */
/********************************************************************************************/

#include 	"LIB/BIT_MATH.h"
#include 	"LIB/STD_Types.h"

#include 	"FMI_interface.h"
#include 	"FMI_private.h"
#include 	"FMI_config.h"

/********************************************************************************************/


/********************************************************************************************/

/// @brief MCAL_FMI_MassErase : this function Erase "Delete" the Application Data From the Flash Memory.
/// @param   Takes Nothing.
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_MassErase( void )
{
  // 1- Wait if the Flash is Busy By Checking the (BSY) flag .
	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}

	// 2- Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	} 

  // Select Erase Operation .
	SET_BIT(FLASH -> CR , CR_MER );

	// Start Erase Operation .
	SET_BIT(FLASH -> CR , CR_STRT );

  // Wait For Busy Flag (BSY).
	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}

	// Deselect Erase Operation .
	CLR_BIT(FLASH -> CR , CR_MER );

  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK); 
  
  return FMI_OK;
}


/// @brief MCAL_FMI_SectorErase : This function Erase "Delete" a Spacific sector From the Flash Memory.
/// @param SectorNUM 		 	: Takes the Number Of the Sector In the Flash Memory.
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_SectorErase( SECTOR_NUM SectorNUM )
{
	// Wait if the Flash is Busy By Checking the (BSY) flag .
	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}

	//- Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}

	// Clear the Sector Number Bits.
	__CLEAR_SNB__();	
  // Select The Sector Which we want to Erase .
	__SET_SNB__(SectorNUM);

	// Select Erase Operation .
	SET_BIT(FLASH -> CR , CR_SER );

	// Start Erase Operation .
	SET_BIT(FLASH -> CR , CR_STRT );

	// Wait For Busy Flag (BSY).
	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}

	// Deselect Erase Operation .
	CLR_BIT(FLASH -> CR , CR_SER );

  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  return FMI_OK;
}


/// @brief MCAL_FMI_Prog_B  : this function Write a Byte of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_B( u32  Address , u8 * ptData , u16   DataLength )
{
  // Check the parameters 
  // address Checking.
  if (!(__CHECK_ADDRESS__(Address,DataLength)))
  {
    return FMI_ADDRESS_ERROR;
  }

  u16 local_counter = 0U;

  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}

  // clear the parallelism bits.
  __CLEAR_PSIZE__();
  // Set the parallelism bits to BYTE option.
  __SET_PSIZE__(_BYTE_);

  // Activate the Programming Mode (PG) Bit .
  SET_BIT(FLASH -> CR , CR_PG );

  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  while (local_counter < DataLength)
  {
    // Wait if the Flash is Busy By Checking the (BSY) flag .
  	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}
    // Write the data into the specific location.
    *(volatile u8*)Address = *ptData;
    // Go to the next element in the data, and the next location.
    ptData  += 0x1U ;
    Address += 0x1U;

    local_counter ++;
  }

  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}
  // Deselect Programming Operation .
  CLR_BIT(FLASH -> CR , CR_PG );
  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  return FMI_OK;
}


/// @brief MCAL_FMI_Prog_HW  : this function Write a Half word of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_HW( u32  Address , u8 * ptData , u16   DataLength )
{
  // Check the parameters 
  // address Checking.
  if (!(__CHECK_ADDRESS__(Address,DataLength)))
  {
    return FMI_ADDRESS_ERROR;
  }

  u16 local_counter = 0U;
  u16 data_Buffer;
  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}

  // clear the parallelism bits.
  __CLEAR_PSIZE__();
  // Set the parallelism bits to BYTE option.
  __SET_PSIZE__(_HALF_WORD_);

  // Activate the Programming Mode (PG) Bit .
  SET_BIT(FLASH -> CR , CR_PG );

  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  while (local_counter < DataLength)
  {
    // Wait if the Flash is Busy By Checking the (BSY) flag .
  	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}

    // Store the two elements of data into the data_Buffer. 
    data_Buffer =  (u16)( ( (*ptData +1) << 8) | (*ptData) );

    // Write the data into the specific location.
    *(volatile u16*)Address = data_Buffer;

    // Go to the next element in the data, and the next location.
    ptData  += 0x2U ;
    Address += 0x2U;

    local_counter += 2U;
  }

  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}
  // Deselect Programming Operation .
  CLR_BIT(FLASH -> CR , CR_PG );
  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  return FMI_OK;
}


/// @brief MCAL_FMI_Prog_W  : this function Write a Word of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_W( u32  Address , u8 * ptData , u16   DataLength )
{
  // Check the parameters 
  // address Checking.
  if (!(__CHECK_ADDRESS__(Address,DataLength)))
  {
    return FMI_ADDRESS_ERROR;
  }

  u16 local_counter = 0U;
  u32 data_Buffer;
  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}

  // clear the parallelism bits.
  __CLEAR_PSIZE__();
  // Set the parallelism bits to BYTE option.
  __SET_PSIZE__(_WORD_);

  // Activate the Programming Mode (PG) Bit .
  SET_BIT(FLASH -> CR , CR_PG );

  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  while (local_counter < DataLength)
  {
    // Wait if the Flash is Busy By Checking the (BSY) flag .
  	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}

    // Store the two elements of data into the data_Buffer. 
    data_Buffer =  (u32)( ( (*ptData +3) << 24) |( (*ptData +2) << 16) |( (*ptData +1) << 8) | (*ptData) );

    // Write the data into the specific location.
    *(volatile u32*)Address = data_Buffer;

    // Go to the next element in the data, and the next location.
    ptData  += 0x4U ;
    Address += 0x4U;

    local_counter += 4U;
  }

  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}
  // Deselect Programming Operation .
  CLR_BIT(FLASH -> CR , CR_PG );
  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  return FMI_OK;
}


/// @brief MCAL_FMI_Prog_WD  : this function Write a Double Word of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_DW( u32  Address , u8 * ptData , u16   DataLength )
{
  // Check the parameters 

  // address Checking.
  if (!(__CHECK_ADDRESS__(Address,DataLength)))
  {
    return FMI_ADDRESS_ERROR;
  }

  u16 local_counter = 0U;
  u32 data_Buffer;
  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}

  // clear the parallelism bits.
  __CLEAR_PSIZE__();
  // Set the parallelism bits to BYTE option.
  __SET_PSIZE__(_DOUBLE_WORD_);

  // Activate the Programming Mode (PG) Bit .
  SET_BIT(FLASH -> CR , CR_PG );

  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  while (local_counter < DataLength)
  {
    // Wait if the Flash is Busy By Checking the (BSY) flag .
  	while(GET_BIT(FLASH -> SR , SR_BSY ) == 1){}

    for (u8 i = 0; i < 2; i++)
    {
      // Store the two elements of data into the data_Buffer. 
      data_Buffer =  (u32)( ( (*ptData +3) << 24) |( (*ptData +2) << 16) |( (*ptData +1) << 8) | (*ptData) );

      // Write the data into the specific location.
      *(volatile u32*)Address = data_Buffer;

      // Go to the next element in the data, and the next location.
      ptData  += 0x4U ;
      Address += 0x4U;
    }
    local_counter += 8U;
  }
  // Unlock The Flash Registers By Using the KEYS .
	if(GET_BIT(FLASH -> CR , CR_LOCK) == 1)
	{
		FLASH -> KEYR = EFMI_KEY_1 ;
		FLASH -> KEYR = EFMI_KEY_2 ;
	}
  // Deselect Programming Operation .
  CLR_BIT(FLASH -> CR , CR_PG );
  // lock the {CR} register.
  SET_BIT(FLASH -> CR , CR_LOCK);

  return FMI_OK;
}


/// @brief MCAL_FMI_Read_W  : this function is used to read date from the Flash.
/// @param First_Address    : the first address we start reading from.
/// @param ptData_Buffer    : pointer to the location where the reading data will be stored in.
/// @param Buffer_Size      : the size of the Data Buffer.
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Read_W( u32 Address , u32 *ptData_Buffer , u16 Buffer_Size)
{
  // address Checking.
  if (!(__CHECK_ADDRESS__(Address,Buffer_Size)))
  {
    return FMI_ADDRESS_ERROR;
  }

  // Reading process.
  u16 local_counter = 0;
  while (local_counter < Buffer_Size)
  {
    *ptData_Buffer = *(u32*)Address ;

    ptData_Buffer++;
    Address++;
    local_counter++;
  }
  
  return FMI_OK;
}