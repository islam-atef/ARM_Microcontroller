/********************************************************************************************************************/
/*                                 LEDMATERIX_program.c                                                             */
/*      Created on     : Sep 6, 2022                                                                                */
/*      Author         : Islam Atef                                                                                 */
/********************************************************************************************************************/ 
#include "../../../LIB/BIT_MATH.h"
#include "../../../LIB/STD_Types.h"

#include "../../../LMCAL/01_STK/STK_interface.h"
#include "../../../MCAL/01_GPIO/GPIO_interface.h"
#include "../../../MCAL/03_EXTI/EXTI_interface.h"

#include "IRRECEIVER_config.h"
#include "IRRECEIVER_interface.h"


/********************************************************************************************************************/
u8 HIRRECEIVER_GReadings_Array[Readings_Size + StartBIT_Size] ;
u8 Start_Flag = 0 ;
u8 Readings_Counter = 0 ;
u8 OUTPUT_DATA = 0 ;
/********************************************************************************************************************/
PIN_CONFIG IR_R_OUTPUT_CONFIG = 
{ .MODEV = INPUT , .OSPEEDV = MS , .OTYPEV = PP , .PUPDV = PD , .port = IR_R_OUTPUT_PORT , .pin = IR_R_OUTPUT_PIN  };
/********************************************************************************************************************/
/*  Function        : HIRRECEIVER_voidInit	                       	    						                    */
/*  I/P parameters  : takes Nothing                                                                                 */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Initialize The GPIO-PINs of The Module                                          */   
/********************************************************************************************************************/ 
void    HIRRECEIVER_voidInit(void)
{   
    MEXTI_voidEnableInterruptLine(IR_R_OUTPUT_EXTI_LINE);
    MEXTI_voidTriggerConfig(IR_R_OUTPUT_EXTI_LINE,Falling_trigger);
    MGPIO_voidMODEInit(&IR_R_OUTPUT_CONFIG);
}
/********************************************************************************************************************/


/********************************************************************************************************************/
/*  Function        : HIRRECEIVER_void	                       	    					                */
/*  I/P parameters  : takes An Array Of Tree Dimantions That Represents The Frame                                   */
/*  Returnning      : Returns The Frame By writing The Valuse on Global Variables             	                    */
/*  Discribtion     : This Function Create The Frame Of The Given Image                                             */
/********************************************************************************************************************/ 
void    HIRRECEIVER_voidSystick_Handler( void )
{
#if ADDRESS_CHECKING == ON
    u8 Local_Address_v = 0;
    u8 Local_Data_v = 0;
    for (u8 i = 1; i < 9; i++)
    {
        Local_Address_v |= (HIRRECEIVER_GReadings_Array[i] << (i-1) );
    }
    if (Local_Address_v == MODULE_ADRESS)
    {
        for (u8 i = 17; i < 25; i++)
        {
            Local_Data_v |= (HIRRECEIVER_GReadings_Array[i] << (i-1) );
        }
        OUTPUT_DATA = Local_Data_v ;
    }
#endif

} 
/********************************************************************************************************************/


/********************************************************************************************************************/
/*  Function        : HIRRECEIVER_void	                       	    					                    */
/*  I/P parameters  : takes An Array Of The Rows' Values and The Number of Repeating The Frame                      */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Dispaly The Frame on The Module                                                 */
/********************************************************************************************************************/ 
void    HIRRECEIVER_voidEXTI_Handler( void )
{
    if (Start_Flag == 0)
    {
        Start_Flag = 1 ;
        MSTK_voidSetIntervalSingle( Wait_Time , HIRRECEIVER_voidSystick_Handler );
    }
    else
    {
        HIRRECEIVER_GReadings_Array[Readings_Counter] = MSTK_u32GetElapsedTime();
        MSTK_voidSetIntervalSingle( Wait_Time , HIRRECEIVER_voidSystick_Handler );
        Readings_Counter++;
    }
    if (sizeof(HIRRECEIVER_GReadings_Array) > 33)
    {
        Start_Flag = 0 ;
        MSTK_voidStopTimer() ;
        Readings_Counter = 0 ;
    }
}
/********************************************************************************************************************/

