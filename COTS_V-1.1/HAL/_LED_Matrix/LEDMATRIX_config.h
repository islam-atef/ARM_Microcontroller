/************************************************************************************************/
/*                                 LEDMATERIX_config.h                                          */
/*      Created on     : Sep 6, 2022                                                            */
/*      Author         : Islam Atef                                                             */
/************************************************************************************************/
#ifndef LEDMATRIX_CONFIG_H_
#define LEDMATRIX_CONFIG_H_

/************************************************************************************************/
/*                      The Numeber OF ROWS In The LEDMATRIX Module                             */
#define     COLUMNS_NUM     8
/*                     The Numeber OF COLUMNSIn The LEDMATRIX Module                            */
#define     ROWS_NUM        8
/*                            The Numeber OF TiCks In (2.5 mS)                                  */
#define     D_TickNUM       25000
/************************************************************************************************/
/*          Here We Choose The MODE of The System Either {Normal} Or {RTOS}                     */
#define     Normal_MODE         0
#define     RTOS_MODE           1
/*........................  == .................................................................*/
#define     Operating_MODE      Normal_MODE
/************************************************************************************************/
/*  Rows' Configuration   :                                                                     */
extern  PIN_CONFIG    ROW_ARRAY[ ROWS_NUM ];
/*  Columns' Configuration   :                                                                  */
extern  PIN_CONFIG    COLUMN_ARRAY[ COLUMNS_NUM ];
/************************************************************************************************/

#endif