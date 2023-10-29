#ifndef		STK_PRIVATE_H
#define		STK_PRIVATE_H
/**************************************************************************************/
#define		MSTK_SINGLE_INTERVAL		0
#define		MSTK_PERIOD_INTERVAL		1
/**************************************************************************************/

#define     Systick_BASE_ADDRESS		(u32)0xE000E010

typedef struct
{
	volatile	u32	CTRL	;
	volatile	u32	LOAD	;
	volatile	u32	VAL		;
	volatile	u32	CALIB	;

}MSTK_Type;

#define		MSTK		((MSTK_Type *)Systick_BASE_ADDRESS)

#endif
