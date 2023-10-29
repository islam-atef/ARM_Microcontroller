/********************************************************************************************/
/* 	AUTHOR  		: islam atef Mohamed 													*/
/* 	VERSION 		:	  V2.0 																*/
/* 	DATE    		:  1/2023 																*/
/*	 Discribtion  	:  This is the Interface file For the Embedded Flash Memory				*/
/* 								interface Peripheral at ARM-CORTEX m4						*/
/********************************************************************************************/
#ifndef		EFMI_INTERFACE_H
#define		EFMI_INTERFACE_H



/********************************************************************************************/
/*           	The Flash Memory Interface Peripheral Functions' status type.               */
/********************************************************************************************/
typedef enum
{	
 	FMI_OK        		= 0x00U,
 	FMI_ERROR     		= 0x01U,
	FMI_ADDRESS_ERROR  	= 0x03U
}FMI_Fun_Status;
/********************************************************************************************/

typedef enum{
	SECTOR_0	=	0b000U,	
	SECTOR_1	=	0b001U,
	SECTOR_2	=	0b010U,
	SECTOR_3	=	0b011U,
	SECTOR_4	=	0b100U,
	SECTOR_5	=	0b101U
}SECTOR_NUM;

/********************************************************************************************/
/*-----------  Function Prototypes	:-------------------------------------------------------*/

/// @brief MCAL_FMI_MassErase : this function Erase "Delete" the Application Data From the Flash Memory.
/// @param   Takes Nothing.
FMI_Fun_Status	MCAL_FMI_MassErase( void );
/*------------------------------------------------------------------------------------------*/
/// @brief MCAL_FMI_SectorErase : This function Erase "Delete" a Spacific sector From the Flash Memory.
/// @param A_u8SectorNUM 		 : Takes the Number Of the Sector In the Flash Memory.
FMI_Fun_Status	MCAL_FMI_SectorErase( SECTOR_NUM SectorNUM );
/*------------------------------------------------------------------------------------------*/
/// @brief MCAL_FMI_Prog_B  : this function Write a Byte of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_B( u32  Address , u8 * ptData , u16   DataLength );
/*------------------------------------------------------------------------------------------*/
/// @brief MCAL_FMI_Prog_HW  : this function Write a Half word of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_HW( u32  Address , u8 * ptData , u16   DataLength );
/*------------------------------------------------------------------------------------------*/
/// @brief MCAL_FMI_Prog_W  : this function Write a Word of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_W( u32  Address , u8 * ptData , u16   DataLength );
/*------------------------------------------------------------------------------------------*/
/// @brief MCAL_FMI_Prog_WD  : this function Write a Double Word of data in a spacific Location in the Flash Memory.
/// @param Address 			: Takes the Address of The Location that we need to Write in.
/// @param ptData 			: Takes the address of the data that we need to Write.
/// @param DataLength 		: Takes the length of the data that will be written .
/// @retval		the Function State.
FMI_Fun_Status	MCAL_FMI_Prog_DW( u32  Address , u8 * ptData , u16   DataLength );
/*------------------------------------------------------------------------------------------*/

/********************************************************************************************/
#endif
