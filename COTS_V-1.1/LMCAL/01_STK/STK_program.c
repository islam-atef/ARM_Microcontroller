#include	"LIB/STD_Types.h"
#include	"LIB/BIT_MATH.h"

#include	"STK_interface.h"
#include	"STK_private.h"
#include	"STK_config.h"


/********************************************************************************************/
#ifndef		NULL
#define		NULL		(void *)0
#endif
/********************************************************************************************/

static	void	(* MSTK_CAllBack) (void);

static u8	MSTK_u8ModeOfInterval ;

/************************************************************************************************************/
/*  Function : MSTK_voidSystickPrescaler	 		                                   						*/
/*  I/P parameters : Takes Nothings                                          								*/
/*  Returning : Returns Nothings								           									*/
/*  Description : This Function Define The Prescaler Of the Systick Peripheral				 				*/
/************************************************************************************************************/
void	MSTK_voidSystickPrescaler(void)
{
	#if	MSTK_CLK_SRC	==	MSTK_SRC_AHB1 
		MSTK ->	CTRL = 0x00000004;
	#elif	MSTK_CLK_SRC	==	MSTK_SRC_AHB1_8
		MSTK -> CTRL = 0x00000000;
	#else
		#error("Wrong Systick Clock Source Selection")
	#endif
}
/************************************************************************************************************/


/************************************************************************************************************/
/*  Function : MSTK_voidSetBusyWait 		                                   								*/
/*  I/P parameters : Takes The Ticks Number                                          						*/
/*  Returning : Returns Nothing								           									*/
/*  Description : This Function Performs a Delay 						  									*/
/************************************************************************************************************/
void	MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/*	Load Ticks to Load Register		*/
	MSTK -> LOAD	=	(Copy_u32Ticks-1);
	/*	Start Timer				*/
	SET_BIT(MSTK -> CTRL,0);
	/*	Wait till the flag is raised		*/
	while((GET_BIT(MSTK -> CTRL , 16 )) == 0)
	{
		asm("NOP");
	}	
	/*	Stop Timer				*/
	CLR_BIT(MSTK -> CTRL, 0 );
	MSTK -> LOAD = 0;
	MSTK -> VAL = 0;
}
/************************************************************************************************************/


/************************************************************************************************************/
/*  Function : MSTK_voidSetWhileLoop 		                                   								*/
/*  I/P parameters : Takes The Ticks Number and The Performed Function                             			*/
/*  Returning : Returns Nothing								           									*/
/*  Description : This Function Performs a Specific Function 						  						*/
/************************************************************************************************************/
void	MSTK_voidSetWhileLoop(u32 Copy_u32Ticks , void (*copy_prt)(void))
{
	/*	Load Ticks to Load Register		*/
	MSTK -> LOAD	=	(Copy_u32Ticks-1);
	/*	Start Timer				*/
	SET_BIT(MSTK -> CTRL,0);
	/*	Wait till the flag is raised		*/
	while((GET_BIT(MSTK -> CTRL , 16 )) == 0)
	{
		copy_prt();
	}	
	/*	Stop Timer				*/
	CLR_BIT(MSTK -> CTRL, 0 );
	MSTK -> LOAD = 0;
	MSTK -> VAL = 0;
}
/************************************************************************************************************/



/************************************************************************************************************/
/*  Function : MSTK_voidSetIntervalSingle 		                                   							*/
/*  I/P parameters : It Takes The Number Of Ticks and The Wanted Interrupt Handler                          */
/*  Returning : Returns Nothing								         									*/
/*  Description : This Function takes a Specific time and Executes a Specific Function after This time for   */
/*										Just One Time				    									*/
/************************************************************************************************************/
void	MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_ptr)(void))
{	
	/*	Load Ticks to Load Register		*/
	MSTK -> LOAD	=	(Copy_u32Ticks-1);

	/*	Start Timer				*/
	SET_BIT(MSTK -> CTRL,0);
	
	/*	Save CallBack				*/
	MSTK_CAllBack = *Copy_ptr;

	/*	Set Interval Mode to Single		*/
	MSTK_u8ModeOfInterval =	MSTK_SINGLE_INTERVAL ;
	
	/*	Enable STK Interrupt			*/
	SET_BIT(MSTK -> CTRL,1);
}
/************************************************************************************************************/


/************************************************************************************************************/
/*  Function : MSTK_voidSetIntervalPeriodic 		                                   						*/
/*  I/P parameters : It Takes The Number Of Ticks and The Wanted Interrupt Handler                          */
/*  Returning : Returns Nothing								         									*/
/*  Description : This Function takes a Specific time and Executes a Specific Function after This time in a  */
/*										Periodic Way				    									*/
/************************************************************************************************************/
void	MSTK_voidSetIntervalPeriodic(u32 Copy_u32TicksNum , void (*Copy_ptr)(void))
{
	/*	Load Ticks to Load Register		*/
	MSTK -> LOAD	=	(Copy_u32TicksNum-1);

	/*	Start Timer				*/
	SET_BIT(MSTK -> CTRL,0);
	
	/*	Save CallBack				*/
	MSTK_CAllBack = *Copy_ptr;

	/*	Set Interval Mode to Periodic		*/
	MSTK_u8ModeOfInterval =	MSTK_PERIOD_INTERVAL ;
	
	/*	Enable STK Interrupt			*/
	SET_BIT(MSTK -> CTRL,1);
}
/************************************************************************************************************/



/************************************************************************************************************/
/*  Function : MSTK_voidStartTimer		 		                                   							*/
/*  I/P parameters : It Takes Nothing											                            */
/*  Returning : Returns Nothing								         									*/
/*  Description : This Function Runs as A Timer 															*/
/************************************************************************************************************/
void	MSTK_voidStartTimer(void)
{	
	/*	Load Ticks to Load Register																			*/
	MSTK -> LOAD	= 16777215	;
	/*	Start Timer																							*/
	SET_BIT(MSTK -> CTRL,0);
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MSTK_voidPauseTimer 		                                   									*/
/*  I/P parameters : Takes Nothings                                          								*/
/*  Returning : Returns Nothings								           									*/
/*  Description : This Function Stops the Timer at The Current Point without Clearing anything 				*/
/************************************************************************************************************/
void	MSTK_voidPauseTimer(void)
{	
	/*	Disable	STK Interrupt																				*/
	CLR_BIT(MSTK -> CTRL,1);	
	/*	Stop Timer																							*/
	CLR_BIT(MSTK -> CTRL, 0 );
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MSTK_voidStopTimer	 		                                   								*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returning : Returns Nothings								          									*/
/*  Description : This Function Stops the Timer and Clear all Values In (LOAD)  and (VAL) Registers    		*/
/************************************************************************************************************/
void	MSTK_voidStopTimer(void)
{
	/*	Disable	STK Interrupt																				*/
	CLR_BIT(MSTK -> CTRL,1);	
	/*	Stop Timer																							*/
	CLR_BIT(MSTK -> CTRL, 0 );
	MSTK -> LOAD = 0;
	MSTK -> VAL = 0;
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MSTK_voidPlayTimer 		                                   									*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returning : Returns Nothings									     									*/
/*  Description : This Function Restart The Timer From The Point It has Stopped in    						*/
/************************************************************************************************************/
void	MSTK_voidPlayTimer(void)
{
	/*	Open	STK Interrupt																				*/
	SET_BIT(MSTK -> CTRL,1);	
	/*	Open Timer																							*/
	SET_BIT(MSTK -> CTRL, 0 );
}
/************************************************************************************************************/



/************************************************************************************************************/
/*  Function : MSTK_u32GetElapsedTime                                   									*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returning : Returns the Value of The Elapsed Time 				       									*/
/*  Description :  This Function Read the (VAL) Register and the (LOAD) Register Then subtract These 		*/
/*								two values to Return the as The Elapsed time    							*/
/************************************************************************************************************/
u32	MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime = 0;
	
	Local_u32ElapsedTime = ((MSTK -> LOAD) - (MSTK -> VAL));

	return Local_u32ElapsedTime ;
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MSTK_u32GetRemainingTime 		                                   							*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returning : Returns the Value of The Remaining Time		           									*/
/*  Description : This Function Read the (VAL) Register and Return It as The Remaining time 				*/
/************************************************************************************************************/
u32	MSTK_u32GetRemainingTime(void)
{
	/* Variable That Will Store the VAL value 																*/
	u32 Local_u32RemainingTime = 0;
	/* Read the VAL value 																					*/
	Local_u32RemainingTime = (MSTK -> VAL);

	return Local_u32RemainingTime ;
}
/************************************************************************************************************/


/************************************************************************************************************/
/*  Function : SysTick_Handler 		                                   										*/
/*  I/P parameters : Takes Nothing                                          								*/
/*  Returning : Returns Nothing          																	*/
/*  Description : This is The Handler Function Of the Systick Peripheral    								*/
/************************************************************************************************************/
void	SysTick_Handler(void)
{
	if( MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL )
	{	
		/*	Disable	STK Interrupt																			*/
		CLR_BIT(MSTK -> CTRL,1);	
		/*	Stop Timer																						*/
		CLR_BIT(MSTK -> CTRL, 0 );
		MSTK -> LOAD = 0;
		MSTK -> VAL = 0;
	}
	/*	CallBack Notification																				*/
	MSTK_CAllBack();
	/*	Clear interrupt Flag																				*/
	MSTK -> CTRL |= (1 << 16) ;	
}
/************************************************************************************************************/












