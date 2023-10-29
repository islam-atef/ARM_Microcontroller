/*******************************************************************************************************************/
/*                                 IRRECEIVER_interface.h                                                          */
/*      Created on     : Sep 6, 2022                                                                               */
/*      Author         : Islam Atef                                                                                */
/*******************************************************************************************************************/
#ifndef IRRECEIVER_INTERFACE_H_
#define IRRECEIVER_INTERFACE_H_
/********************************************************************************************************************/
/*  Function        : HIRRECEIVER_voidInit	                       	    						                    */
/*  I/P parameters  : takes Nothing                                                                                 */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Initialize The GPIO-PINs of The Module                                          */   
/********************************************************************************************************************/ 
void    HIRRECEIVER_voidInit(void) ;
/********************************************************************************************************************/
/********************************************************************************************************************/
/*  Function        : HIRRECEIVER_void	                       	    					                    */
/*  I/P parameters  : takes An Array Of The Rows' Values and The Number of Repeating The Frame                      */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Dispaly The Frame on The Module                                                 */
/********************************************************************************************************************/ 
void    HIRRECEIVER_void( u8 copy_ImageSpeed ) ;
/********************************************************************************************************************/
/********************************************************************************************************************/
/*  Function        : HIRRECEIVER_void	                       	    					                */
/*  I/P parameters  : takes An Array Of Tree Dimantions That Represents The Frame                                   */
/*  Returnning      : Returns The Frame By writing The Valuse on Global Variables             	                    */
/*  Discribtion     : This Function Create The Frame Of The Given Image                                             */
/********************************************************************************************************************/ 
void    HIRRECEIVER_void( u8 copy_ImageArray[ROWS_NUM][COLUMNS_NUM][2] ); 
/********************************************************************************************************************/

#endif