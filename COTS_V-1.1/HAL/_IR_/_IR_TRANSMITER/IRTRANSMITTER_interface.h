/************************************************************************************************/
/*                                 LEDMATERIX_interface.h                                       */
/*      Created on     : Sep 6, 2022                                                            */
/*      Author         : Islam Atef                                                             */
/************************************************************************************************/
#ifndef LEDMATRIX_INTERFACE_H_
#define LEDMATRIX_INTERFACE_H_


/********************************************************************************************************************/
extern   u8 HLEDMATRIX_Global_FrameArray[COLUMNS_NUM] ; 
extern   u8 HLEDMATRIX_Global_PinONtime[ROWS_NUM][COLUMNS_NUM] ;
/********************************************************************************************************************/
/*  Function        : HLEDMATRIX_voidInit	                       	    						                    */
/*  I/P parameters  : takes Nothing                                                                                 */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Initialize The GPIO-PINs of The Module                                          */   
/********************************************************************************************************************/ 
void    HLEDMATRIX_voidInit(void) ;
/********************************************************************************************************************/
/********************************************************************************************************************/
/*  Function        : HLEDMATRIX_voidDispaly	                       	    					                    */
/*  I/P parameters  : takes An Array Of The Rows' Values and The Number of Repeating The Frame                      */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Dispaly The Frame on The Module                                                 */
/********************************************************************************************************************/ 
void    HLEDMATRIX_voidDispaly( u8 copy_ImageSpeed ) ;
/********************************************************************************************************************/
/********************************************************************************************************************/
/*  Function        : HLEDMATRIX_voidFrameMaker	                       	    					                    */
/*  I/P parameters  : takes An Array Of Tree Dimantions That Represents The Frame                                   */
/*  Returnning      : Returns The Frame By writing The Valuse on Global Variables             	                    */
/*  Discribtion     : This Function Create The Frame Of The Given Image                                             */
/********************************************************************************************************************/ 
void    HLEDMATRIX_voidFrameMaker( u8 copy_ImageArray[ROWS_NUM][COLUMNS_NUM][2] ); 
/********************************************************************************************************************/

#endif