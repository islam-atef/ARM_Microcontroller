/********************************************************************************************/
/* 	AUTHOR  		: islam atef Mohamed 													*/
/* 	VERSION 		:	  V2.0 																*/
/* 	DATE    		:  1/2023 																*/
/*	 Discribtion  	:  This is the Private file For the Embedded Flash Memory				*/
/* 								interface Peripheral at ARM-CORTEX m4						*/
/********************************************************************************************/
#ifndef		FMI_PRIVATE_H
#define		FMI_PRIVATE_H

/********************************************************************************************/
/*					Flash Memory Interface Peripheral Registers								*/
/********************************************************************************************/
#define 	EFMI_BASE_ADDRESS	0x40023c00

typedef 	struct
{
	volatile	u32 	ACR 	;
	volatile	u32		KEYR	;
	volatile	u32		OPTKEYR	;
	volatile	u32		SR		;
	volatile	u32		CR		;
	volatile	u32		OPTCR	;
}
EFMI_TYPE;

#define 	FLASH		((EFMI_TYPE *)EFMI_BASE_ADDRESS)
/********************************************************************************************/



/********************************************************************************************/
/*									FMI Keys Values											*/
/********************************************************************************************/
#define 	EFMI_KEY_1 	0x45670123
#define 	EFMI_KEY_2 	0xCDEF89AB
/********************************************************************************************/

/********************************************************************************************/
/*							     parallelism Bits Values					 				*/
/********************************************************************************************/
#define		_BYTE_ 	 		00U
#define		_HALF_WORD_ 	01U
#define		_WORD_ 		 	10U
#define		_DOUBLE_WORD_  	11U
/********************************************************************************************/

/********************************************************************************************/
/*									Registers' Bits											*/
/********************************************************************************************/
// Flash access control register (FLASH_ACR)-----------------------------------------------------------------------------------------------------/

//Latency Bits.
#define		ACR_LATENCY_0	0
#define		ACR_LATENCY_1	1
#define		ACR_LATENCY_2	2
#define		ACR_LATENCY_3	3

#define		ACR_PRFTEN		8		//Prefetch enable.
#define		ACR_ICEN		9		//Instruction cache enable.
#define		ACR_DCEN		10		//Data cache enable.
#define		ACR_ICRST		11		//Instruction cache reset.
#define		ACR_DCRST		12		//Data cache reset.




// Flash status register (FLASH_SR) -------------------------------------------------------------------------------------------------------------/

#define		SR_EOP			0		//End of operation.
#define		SR_OPERR		1		//Operation error.
#define		SR_WRPERR		4		// Write protection error.
#define		SR_PGAERR		5		//Programming alignment error.
#define		SR_PGPERR		6		// Programming parallelism error.
#define		SR_PGSERR		7		//Programming sequence error.
#define		SR_RDERR		8		//Read Protection Error (pcrop).
#define		SR_BSY			16		// Busy bit.




// Flash control register (FLASH_CR) ------------------------------------------------------------------------------------------------------------/

#define		CR_PG			0		//Programming Operation Bit.
#define		CR_SER			1		//Sector Erase Operation Bit.
#define		CR_MER			2		//Mass Erase Bit.

//Sector number Bits : (0b0000) sector 0, (0b0001) sector 1, (0b0010) sector 2, (0b0011) sector 3, (0b0100) sector 4, (0b0101) sector 5.
#define		CR_SNB_0		3		
#define		CR_SNB_1		4
#define		CR_SNB_2		5
#define		CR_SNB_3		6

//Program size Bits : (0b00) program x8, (0b01) program x16, (0b10) program x32, (0b11) program x64.
#define		CR_PSIZE_0		8		
#define		CR_PSIZE_1		9

#define		CR_STRT			16		//Start Erase Operation Bit.
#define		CR_EOPIE		24		//End of operation interrupt enable.
#define		CR_ERRIE		25		//Error interrupt enable.	
#define		CR_LOCK			31		//Lock Bit.



//Flash option control register (FLASH_OPTCR) ------------------------------------------------------------------------------------------------/

#define		OPTCR_OPTLOCK	0		//Option lock.
#define		OPTCR_OPTSTRT	1		//Option start.

/*BOR reset Level Bits : (0b00): BOR Level 3 (VBOR3) brownout threshold level 3, 
*						 (0b01): BOR Level 2 (VBOR2) brownout threshold level 2,
*				 	     (0b10): BOR Level 1 (VBOR1) brownout threshold level 1,
*						 (0b11): BOR off (POR/PDR) reset threshold level is applied 
*/
#define		OPTCR_BOR_LEV_0	2
#define		OPTCR_BOR_LEV_1	3

/*User option bytes : Bit 7: nRST_STDBY
*					  Bit 6: nRST_STOP
*					  Bit 5: WDG_SW 
*/
#define		OPTCR_USER_0	5
#define		OPTCR_USER_1	6
#define		OPTCR_USER_2	7


/*Read protect Bits :	0xAA: Level 0, read protection not active
*						0xCC: Level 2, chip read protection active
*						Others: Level 1, read protection of memories active
*/
#define		OPTCR_RDP_0		8
#define		OPTCR_RDP_1		9
#define		OPTCR_RDP_2		10
#define		OPTCR_RDP_3		11
#define		OPTCR_RDP_4		12
#define		OPTCR_RDP_5		13
#define		OPTCR_RDP_6		14
#define		OPTCR_RDP_7		15

// Not write protect Bits.
#define		OPTCR_nWRP_0	16
#define		OPTCR_nWRP_1	17
#define		OPTCR_nWRP_2	18
#define		OPTCR_nWRP_3	19
#define		OPTCR_nWRP_4	20
#define		OPTCR_nWRP_5	21

#define		OPTCR_nWRP_6	22
#define		OPTCR_nWRP_7	23

#define		OPTCR_SPRMOD	31	/*Selection of Protection Mode of nWPRi bits : (0b0): PCROP disabled, nWPRi bits used for Write Protection on sector i
**																			   (0b1): PCROP enabled, nWPRi bits used for PCROP Protection on sector i  */

/********************************************************************************************/

/********************************************************************************************/
/*									Flash Sectors											*/
/********************************************************************************************/

//----------------------------------------------- Main Memory Sector Addresses :-------------/
// Sector 0 : 0x0800 0000 ----> 0x0800 3FFF (16 Kbytes).
#define		SECTOR0_BASE	(u32)0x08000000	
#define		SECTOR0_END		(u32)0x08003FFF

// Sector 1 : 0x0800 4000 ----> 0x0800 7FFF	(16 Kbytes).
#define		SECTOR1_BASE	(u32)0x08004000	
#define		SECTOR1_END		(u32)0x08007FFF

// Sector 2 : 0x0800 8000 ----> 0x0800 BFFF	(16 Kbytes).
#define		SECTOR2_BASE	(u32)0x08008000
#define		SECTOR2_END		(u32)0x0800BFFF

// Sector 3 : 0x0800 C000 ----> 0x0800 FFFF	(16 Kbytes).
#define		SECTOR3_BASE	(u32)0x0800C000	
#define		SECTOR3_END		(u32)0x0800FFFF

// Sector 4 : 0x0801 0000 ----> 0x0801 FFFF	(64 Kbytes).
#define		SECTOR4_BASE	(u32)0x08010000
#define		SECTOR4_END		(u32)0x0801FFFF

// Sector 5 : 0x0802 0000 ----> 0x0803 FFFF	(128 Kbytes).
#define		SECTOR5_BASE	(u32)0x08020000
#define		SECTOR5_END		(u32)0x0803FFFF

/********************************************************************************************/

/********************************************************************************************/
/*										FMI MACROS											*/
/********************************************************************************************/
/// @brief __CLEAR_PSIZE__ : this MACRO is used to clear the parallelism Bits in the {CR} register.
/// @param      takes no parameters.
/// @retval     return Nothing.  	
#define		__CLEAR_PSIZE__()			(FLASH -> CR) &= ~(11 << (CR_PSIZE_0))
/*----------------------------------------------------------------------------------------------------------------------------*/
/// @brief __SET_PSIZE__ : this MACRO is used to Set the parallelism Bits in the {CR} register with the needed value.
/// @param _SIZE_        : the size of the program parallelism,
///				@arg _BYTE_ 	 	: set the parallelism bits with (00).	
///				@arg _HALF_WORD_ 	: set the parallelism bits with (01).
///				@arg _WORD_ 		: set the parallelism bits with (10).
///				@arg _DOUBLE_WORD_  : set the parallelism bits with (11).
/// @retval     return Nothing.  	
#define		__SET_PSIZE__(_SIZE_)			(FLASH -> CR) |=  ((_SIZE_) << (CR_PSIZE_0))
/*----------------------------------------------------------------------------------------------------------------------------*/
/// @brief __CLEAR_SNB__ : this MACRO is used to clear the Sector Number Bits in the {CR} register.
/// @param      takes no parameters.
/// @retval     return Nothing.  	
#define		__CLEAR_SNB__()					(FLASH -> CR) &= ~( (u32)0b1111 << CR_SNB_0)
/*----------------------------------------------------------------------------------------------------------------------------*/
/// @brief __SET_SNB__	 : this MACRO is used to Set the Sector Number Bits in the {CR} register with the needed value.
/// @param _SECTOE_      : the sector number,
///				@arg SECTOR_0	: set the parallelism bits with (000).	
///				@arg SECTOR_1	: set the parallelism bits with (001).
///				@arg SECTOR_2	: set the parallelism bits with (010).
///				@arg SECTOR_3  	: set the parallelism bits with (011).
///				@arg SECTOR_4  	: set the parallelism bits with (100).
///				@arg SECTOR_5  	: set the parallelism bits with (101).
/// @retval     return Nothing.  	
#define		__SET_SNB__(_SECTOE_)			(FLASH -> CR) |=  ((_SECTOE_) << ( CR_SNB_0))
/*----------------------------------------------------------------------------------------------------------------------------*/
/// @brief __CHECK_ADDRESS__ : this MACRO is used to check if the used address is between the Main Memory limits.
/// @param  _ADDRESS_		 : the Starting address.
/// @param  _DATA_LENGTH_	 : the length of the data to get the last address.
/// @retval     return Nothing.  
#define		__CHECK_ADDRESS__(_ADDRESS_,_DATA_LENGTH_)	((((_ADDRESS_)>=(SECTOR0_BASE))&&((_ADDRESS_ + _DATA_LENGTH_)<=(SECTOR5_END)))?(1):(0))
/********************************************************************************************/
#endif

