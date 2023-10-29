#ifndef		NVIC_PRIVATE_H
#define		NVIC_PRIVATE_H


/*********************************************************************************************************************************/
												/* THE NVIC PERIPHERAL */
/*********************************************************************************************************************************/

#define 	NVIC_BASED_ADDRESS   	(u32)0xE000E100

typedef struct
{
	volatile		u32	     	ISER[32]			;
	volatile		u32	     	ICER[32]			;
	volatile		u32	     	ISPR[32]			;
	volatile		u32	     	ICPR[32]			;
	volatile		u32	     	IABR[32]			;
	volatile		u8 	     	IPR[128]			;
	//volatile		u32	     	STIR				;
	
}LM_NVIC_Type;

#define		 LMNVIC  		((LM_NVIC_Type *)NVIC_BASED_ADDRESS)

/*********************************************************************************************************************************/
												/* THE SCB PERIPHERAL */
/*********************************************************************************************************************************/
#define  	      VECTKEY 			(u32)0x05FA0000 


#define 	SCB_BASED_ADDRESS   	(u32)0xE000ED00

typedef struct
{
	volatile		u32	     	ACTLR			;
	volatile		u32	     	CPUID			;
	volatile		u32	     	ICSR			;
	volatile		u32	     	VTOR			;
	volatile		u32	     	AIRCR			;   /* The Register That Responsable for the Ratio Between The Groups and Subgroups */
	volatile		u32	     	SCR				;
	volatile		u32	     	CCR				;
	volatile		u32	     	SHPR1			;
	volatile		u32	     	SHPR2			;
	volatile		u32	     	SHPR3			;
	volatile		u32	     	SHCSR			;
	volatile		u32	     	CFSR			;
	volatile		u32	     	HFSR			;
	volatile		u32	     	LOST			;
	volatile		u32	     	MMAR			;
	volatile		u32	     	BFAR			;
	volatile		u32	     	AFSR			;
}LM_SCB_Type;

#define		 MSCB  		((LM_SCB_Type *)SCB_BASED_ADDRESS)

#endif
