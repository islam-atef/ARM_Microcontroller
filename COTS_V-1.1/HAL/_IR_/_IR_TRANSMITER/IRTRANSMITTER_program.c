/********************************************************************************************************************/
/*                                 LEDMATERIX_program.c                                                             */
/*      Created on     : Sep 6, 2022                                                                                */
/*      Author         : Islam Atef                                                                                 */
/********************************************************************************************************************/ 
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "../../MCAL/01_GPIO/GPIO_interface.h"
#include "../../LMCAL/01_STK/STK_interface.h"

#include "LEDMATRIX_config.h"
#include "LEDMATRIX_interface.h"


/********************************************************************************************************************/
u8 HLEDMX_Global_FrameArray[COLUMNS_NUM] ;
u8 HLEDMX_Global_PinONtime[ROWS_NUM][COLUMNS_NUM] ;
/********************************************************************************************************************/
/*  Function        : HLEDMATRIX_voidInit	                       	    						                    */
/*  I/P parameters  : takes Nothing                                                                                 */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Initialize The GPIO-PINs of The Module                                          */   
/********************************************************************************************************************/ 
void    HLEDMATRIX_voidInit(void)   
{
    /*  ROWS Initialization :                                                                                       */
    for (u8 i = 0; i < ROWS_NUM ; i++)                      
    {                       
        MGPIO_voidMODEInit(&ROW_ARRAY[i]);
    }                       
    /*  COLUMNS Initialization :                                                                                     */
    for (u8 i = 0; i < ROWS_NUM ; i++)
    {
        MGPIO_voidMODEInit(&COLUMN_ARRAY[i]);
    }
}
/********************************************************************************************************************/

/********************************************************************************************************************/
/*  Function        : HLEDMATRIX_voidDispaly	                       	    					                    */
/*  I/P parameters  : takes An Array Of The Rows' Values and The Number of Repeating The Frame                      */
/*  Returnning      : Returns Nothing                                           				                    */
/*  Discribtion     : This Function Dispaly The Frame on The Module                                                 */
/********************************************************************************************************************/ 
void    HLEDMATRIX_voidDispaly( u8 copy_ImageSpeed ) 
{   u32 Local_SpeedCounter  = 0 ;
    do
    {
        /*  Switch Off All The Columns                                                                              */
        for (u8 i = 0; i < COLUMNS_NUM; i++)                
        {               
            MGPIO_voidPinWRITE( &COLUMN_ARRAY[i] , LOW );
        }               
        u8 Local_Columncounter = 0 ;              
        do              
        {   /*  Switch On The Needed Column                                                                         */
            MGPIO_voidPinWRITE( &COLUMN_ARRAY[Local_Columncounter] , HIGH );
            /*  Write The Rows' Values On The Rows' Pins                                                            */
            for ( u8 j = 0 ; j < ROWS_NUM ; j++ )               
            {               
                MGPIO_voidPinWRITE( &ROW_ARRAY[j] , GET_BIT( HLEDMX_Global_FrameArray[j] , Local_Columncounter ) );
            }               
            /*  The On State For The ROWS and COLUMNS Should last For (2.5 mS) ,                                    *
             *  but if we want to control The brightness of the LED we can Do That by controlling                   *
             *  The On-State Duration for Each Row Seperatelly                                                      */
            #if     Operating_MODE == Normal_MODE
            MSTK_voidStartTimer();
            while (MSTK_u32GetElapsedTime() < D_TickNUM )
            {
                for (u8 x = 0; x < ROWS_NUM; x++)
                {
                    if (((HLEDMX_Global_PinONtime[x][Local_Columncounter]*D_TickNUM)/(10))>=MSTK_u32GetElapsedTime())
                    {
                        MGPIO_voidPinWRITE( &ROW_ARRAY[x] , LOW );
                    }
                }
            }
            MSTK_voidStopTimer();
            #endif
            Local_Columncounter++ ;
        }
        while (Local_Columncounter < COLUMNS_NUM);
    } 
    while (Local_SpeedCounter <= copy_ImageSpeed);
    
}
/********************************************************************************************************************/


/********************************************************************************************************************/
/*  Function        : HLEDMATRIX_voidFrameMaker	                       	    					                    */
/*  I/P parameters  : takes An Array Of Tree Dimantions That Represents The Frame                                   */
/*  Returnning      : Returns The Frame By writing The Valuse on Global Variables             	                    */
/*  Discribtion     : This Function Create The Frame Of The Given Image                                             */
/********************************************************************************************************************/ 
void    HLEDMATRIX_voidFrameMaker( u8 copy_ImageArray[ROWS_NUM][COLUMNS_NUM][2] ) 
{
    /*  First : Clear All Values Inside The Frame Array                                                             */
    for (u8 i = 0; i < COLUMNS_NUM; i++)
    {
    	HLEDMX_Global_FrameArray[i] = 0 ;
    }
    /*  Second : Write The Value of the Frame Array                                                                 */
    for (u8 i = 0; i < COLUMNS_NUM; i++)
    {
        for (u8 j = 0; j < ROWS_NUM; j++)
        {
        	HLEDMX_Global_FrameArray[i] |= ( copy_ImageArray[j][i][0] << j );
        }
    }
    /*  Third : Write The Value of the PinONTime Array                                                              */
    for (u8 i = 0; i < COLUMNS_NUM; i++)
    {
        for (u8 j = 0; j < ROWS_NUM; j++)
        {
        	HLEDMX_Global_PinONtime[j][i] = copy_ImageArray[j][i][1] ;
        }
    }
}
/********************************************************************************************************************/
