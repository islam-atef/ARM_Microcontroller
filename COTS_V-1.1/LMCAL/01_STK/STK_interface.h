#ifndef		STK_INTERFACE_H
#define		STK_INTERFACE_H

/************************************************************************************************************/
/*  Function : MSTK_voidSystickPrescaler	 		                                   						*/
/*  I/P parameters : Takes Nothings                                          								*/
/*  Returnning : Returns Nothings								           									*/
/*  Discribtion : This Function Define The Prescaler Of the Systick Peripheral				 				*/
/************************************************************************************************************/
void	MSTK_voidSystickPrescaler(void);
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidSetBusyWait 		                                   								*/
/*  I/P parameters : Takes The Ticks Number                                          						*/
/*  Returnning : Returns Nothing								           									*/
/*  Discribtion : This Function Performs a Delay 						  									*/
/************************************************************************************************************/
void	MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidSetWhileLoop 		                                   								*/
/*  I/P parameters : Takes The Ticks Number and The Performed Function                             			*/
/*  Returnning : Returns Nothing								           									*/
/*  Discribtion : This Function Performs a Specific Function 						  						*/
/************************************************************************************************************/
void	MSTK_voidSetWhileLoop(u32 Copy_u32Ticks , void (*copy_prt)(void));
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidSetIntervalSingle 		                                   						    */
/*  I/P parameters : It Takes The Number Of Ticks and The Wanted Interrupt Handler                          */
/*  Returnning : Returns Nothing								         									*/
/*  Discribtion : This Function takes a Specific time and Excutes a Specific Function after This time for   */
/*										Just One Time				    									*/
/************************************************************************************************************/
void	MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_ptr)(void));
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidSetIntervalPeriodic 		                                   						*/
/*  I/P parameters : It Takes The Number Of Ticks and The Wanted Interrupt Handler                          */
/*  Returnning : Returns Nothing								         									*/
/*  Discribtion : This Function takes a Specific time and Excutes a Specific Function after This time in a  */
/*										Periodic Way				    									*/
/************************************************************************************************************/
void	MSTK_voidSetIntervalPeriodic(u32 Copy_u32TicksNum , void (*Copy_ptr)(void));
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidPauseTimer 		                                   									*/
/*  I/P parameters : Takes Nothings                                          								*/
/*  Returnning : Returns Nothings								           									*/
/*  Discribtion : This Function Stops the Timer at The Current Point without Clearing anything 				*/
/************************************************************************************************************/
void	MSTK_voidPauseTimer(void);
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidStopTimer    		                                   								*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returnning : Returns Nothings								          									*/
/*  Discribtion : This Function Stops the Timer and Clear all Values In (LOAD)  and (VAL) Registers    		*/
/************************************************************************************************************/
void	MSTK_voidStopTimer(void);
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidStartTimer		 		                                   							*/
/*  I/P parameters : It Takes Nothing											                            */
/*  Returnning : Returns Nothing								         									*/
/*  Discribtion : This Function Runs as A Timer 															*/
/************************************************************************************************************/
void	MSTK_voidStartTimer(void);
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_voidPlayTimer 		                                   									*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returnning : Returns Nothings									     									*/
/*  Discribtion : This Function Restart The Timer From The Point It has Stopped in    						*/
/************************************************************************************************************/
void	MSTK_voidPlayTimer(void);
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_u32GetElapsedTime                                   									*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returnning : Returns the Value of The Elapsed Time 				       									*/
/*  Discribtion :  This Function Read the (VAL) Register and the (LOAD) Register Then subtract These 		*/
/*								two values to Return the as The Elapsed time    							*/
/************************************************************************************************************/
u32	MSTK_u32GetElapsedTime(void);
/************************************************************************************************************/
/************************************************************************************************************/
/*  Function : MSTK_u32GetRemainingTime 		                                   							*/
/*  I/P parameters : Takes Nothings                                        									*/
/*  Returnning : Returns the Value of The Remaining Time		           									*/
/*  Discribtion : This Function Read the (VAL) Register and Return It as The Remaining time 				*/
/************************************************************************************************************/
u32	MSTK_u32GetRemainingTime(void);
/************************************************************************************************************/




#endif
