/************************************************************************************************/
/*                                 IRRECEIVER_config.h                                          */
/*      Created on     : Sep 6, 2022                                                            */
/*      Author         : Islam Atef                                                             */
/************************************************************************************************/
#ifndef IRRECEIVER_CONFIG_H_
#define IRRECEIVER_CONFIG_H_
/************************************************************************************************/
/*                   The Total Numeber OF bits In The Frame = 33                                */
/*............................. == .............................................................*/
/*                    The Numeber OF The Start bits In The Frame                                */
#define     StartBIT_Size               1     
/*                   The Numeber OF The Radings bits In The Frame                               */
#define     Readings_Size               32    
/*              The Total Numeber OF AddressBITS_Size bits In The Frame                         */
#define     AddressBITS_Size            8 
/*             The Total Numeber OF InAddressBITS_Size bits In The Frame                        */
#define     InAddressBITS_Size          8     
/*               The Total Numeber OF DataBITS_Size bits In The Frame                           */
#define     DataBITS_Size               8   
/*              The Total Numeber OF InDataBITS_Size bits In The Frame                          */
#define     InDataBITS_Size             8           
/*                            The Numeber OF TiCks In (1500 MS)                                 */
#define     Wait_Time                   1500
/************************************************************************************************/
/*                 IR Receiver Module Output Pin Connected with EXTI_LINEx  =                   */
/*        {EXTI_LINE0 } , {EXTI_LINE0 } , {EXTI_LINE0 } , {EXTI_LINE0 } , {EXTI_LINE0 }         */
/*...............................  == ..........................................................*/
#define     IR_R_OUTPUT_EXTI_LINE       EXTI_LINE0 
/*                                     Choose The Port and Pin                                  */
/*............................. == .............................................................*/
#define     IR_R_OUTPUT_PORT            PA
#define     IR_R_OUTPUT_PIN             0
/************************************************************************************************/
/*          Here We Choose The MODE of The System Either {Normal} Or {RTOS}                     */
#define     Normal_MODE                 0
#define     RTOS_MODE                   1
/*........................  == .................................................................*/
#define     Operating_MODE      Normal_MODE
/************************************************************************************************/
/*          Here We Choose The MODE of The System Either {Normal} Or {RTOS}                     */
#define     ON                          0
#define     OFF                         1
/*........................  == .................................................................*/
#define     ADRESS_CHECKING             ON
#define     MODULE_ADRESS               (0b00000000)
/************************************************************************************************/

#endif