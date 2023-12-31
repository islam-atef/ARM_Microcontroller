////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*                                     Author : islam atef mohamed                                            */
/*                                  File name : SERIAL_config.h   (TTL_module)                                */
/*                                      Date  :   1/22                                                        */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef		SERIAL_CONFIG_H
#define		SERIAL_CONFIG_H


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define     huart       USART2
#define     BAUDRATE    115200
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MUSART_Frame_Config         Serial_Frame        = 
{  
    .M_VALUE        =            _8_Bit              ,
    .parity_op      =           Parity_Disable       ,
    .Stop_Bit_NUM   =           _1_0_Bit   
};

MUSART_Receiving_Config     Serial_Receiving    =
{
    .OneBit_Sampling_method =     	One_Sample  , 
    .Oversampling_type      =       Sampling_By_8
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif