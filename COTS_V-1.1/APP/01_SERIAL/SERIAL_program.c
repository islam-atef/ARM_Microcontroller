////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                     Author : islam atef mohamed                                            */
/*                                  File name :   SERIAL_program.c   (TTL_module)                             */
/*                                      Date  :   1/22                                                        */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include    <stdio.h>

#include	"LIB/BIT_MATH.h"
#include	"LIB/STD_Types.h"

#include    "MCAL/04_USART/USART_interface.h"

#include    "SERIAL_config.h"
#include    "SERIAL_interface.h"



void      Serial_INIT(void)
{
    MUSART_voidPeriph_Init(huart , &Serial_Frame , &Serial_Receiving , Half_Duplex , BAUDRATE);
    MUSART_voidEnablePeri(huart , TX_RX );
}

void    Serial_Close(void)
{
    MUSART_voidDisablePeri( huart   ,   TX_RX);
}


int 	__io_putchar(u8 *ch)
{
	MUSART_voidTXstring_Asynch( huart , ch );
	return *ch;
}


int     __io_getchar(void)
{
    u8 Data[15];
    MUSART_ptrRXString_Asynch( huart , Data , 20);
    return *Data;
}
