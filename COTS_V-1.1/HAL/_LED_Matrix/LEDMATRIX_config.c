/************************************************************************************************/
/*                                 LEDMATERIX_config.c                                          */
/*      Created on     : Sep 6, 2022                                                            */
/*      Author         : Islam Atef                                                             */
/************************************************************************************************/
#include "../../MCAL/01_GPIO/GPIO_interface.h"

#include "LEDMATRIX_config.h"
/************************************************************************************************/
/*                   PORTS and Pins Configuration For The LEDMATRIX Module                      */
/*                                                                                              */
/*  The Rows Configuration  :                                                                   */

PIN_CONFIG ROW_ARRAY[ROWS_NUM] = 
{
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 0},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 1},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 2},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 3},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 4},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 5},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 6},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PA , .pin = 7}
};

/*  The COLUMNS Configuration  :                                                               */

PIN_CONFIG COLUMN_ARRAY[COLUMNS_NUM] = 
{
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 5 },
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 6 },
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 7 },
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 8 },
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 9 },
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 10},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 11},
    {.MODEV = OUTPUT , .OSPEEDV = MS , .OTYPEV = OD , .PUPDV = PD , .port = PB , .pin = 12}
};
/************************************************************************************************/