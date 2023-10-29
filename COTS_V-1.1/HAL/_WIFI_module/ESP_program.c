/********************************************************************************************/
/* 	AUTHOR  		: islam atef Mohamed 													*/
/* 	VERSION 		:	  V1.0 																*/
/* 	DATE    		:  1/2023 																*/
/*	Distribution  	:  This is the Program file For the (ESP8266_module)   					*/
/*											at ARM-CORTEX m4								*/
/********************************************************************************************/
#include	"LIB/BIT_MATH.h"
#include	"LIB/STD_Types.h"

#include    "MCAL/01_GPIO/GPIO_interface.h"
#include    "MCAL/USART/USART_interface.h"
#include    "LMCAL/01_STK/STK_interface.h"

#include    "ESP_interface.h"
#include    "ESP_private.h"
/********************************************************************************************/
USART_Struct    *ESP_USART;
USART_Struct    *Terminal_USART;
PIN_CONFIG      *CH_EN;
PIN_CONFIG      *CH_RES;
/*------------------------------------------------------------------------------------------*/
u8              *ESP_Response;
u8              Local_TERFLAG;
/*------------------------------------------------------------------------------------------*/
static u8* ITOS(u16 num, u8 *str, u8 base);
/*-----------------------------Initialization function--------------------------------------*/
/// @brief  HAL_ESP_Init  : this function is used for Initialization of the WIFI module.
/// @param  USARTX        : the USART Struct that the module will use.
/// @param  USARTX        : the USART Struct that the Terminal which will show the response and other data use.
/// @param  ch_en         : the Enabling Pin that the module will use.
/// @param  ch_res        : the Resetting Pin that the module will use.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Init(USART_Struct *USARTX , USART_Struct *USARTY , PIN_CONFIG *ch_en, PIN_CONFIG *ch_res)
{
    // Check parameters
    if (USARTX -> USART_x == NULL)
    {
        return ESP_UART_ERROR;
    }   
    // Initialize the ESP_USART struct.
    ESP_USART = USARTX;

    if (USARTY -> USART_x != NULL)
    {
        // Initialize the Terminal_USART struct.
        Terminal_USART = USARTY;
        Local_TERFLAG = 1;
    }   
    else{ Local_TERFLAG=0; }

    if ((ch_en == NULL) || (ch_res == NULL))
    {
        return ESP_GPIO_ERROR;
    }
    // Initialize the CH_EN, and CH_RES Structs.
    CH_EN  = ch_en;
    CH_RES = ch_res;
    // Pull Up (HIGH) the Reset pin to avoid the Module Reset.
    MGPIO_voidPinWRITE( CH_EN , HIGH );
    
    return ESP_OK;
}
/*-----------------------------------------------------------------------------------------*/



/*----------------------------------Options function---------------------------------------*/
/// @brief  HAL_ESP_Enable : this function is used for Initialization of the WIFI module.
/// @param          Takes No parameters.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Enable()
{   
    if ( CH_EN == NULL )
    {
        return ESP_ERROR;
    }
    MGPIO_voidPinWRITE( CH_EN , HIGH );

    return ESP_OK;
}

/// @brief  HAL_ESP_Disable : this function is used for Initialization of the WIFI module.
/// @param          Takes No parameters.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Disable()
{
    if ( CH_EN == NULL )
    {
        return ESP_ERROR;
    }
    MGPIO_voidPinWRITE( CH_EN , LOW );

    return ESP_OK;
}

/// @brief  HAL_ESP_Reset : this function is used for Initialization of the WIFI module.
/// @param          Takes No parameters.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Reset()
{
    if ( CH_EN == NULL )
    {
        return ESP_ERROR;
    }
    MGPIO_voidPinWRITE( CH_EN , LOW );
    MSTK_voidSetBusyWait(10);
    MGPIO_voidPinWRITE( CH_EN , HIGH );

    return ESP_OK;
}
/*-----------------------------------------------------------------------------------------*/


/*-------------------------------Transaction function--------------------------------------*/
/// @brief HAL_ESP_Command  : this function is Used to send a general command to the ESP8266_module. 
/// @param ptCommand        : the command that will be sent.
/// @return     the Function Status.
ESP_Fun_Status  HAL_ESP_Command(u8 *ptCommand)
{
    // send command
    MCAL_UART_Transmit( ESP_USART , ptCommand , 20 , 10000 , '\n');
    // receive the response.
    MCAL_UART_Receive(ESP_USART,ESP_Response,20,100000,'\n');
    // check if the Terminal is used.
    if (Local_TERFLAG == 1)
    {
        MCAL_UART_Transmit(Terminal_USART,(u8 *)"ESP Command response >", 100 , 10000 ,'>');
        MCAL_UART_Transmit(Terminal_USART,ESP_Response,30,10000,'\n');
    }
    return ESP_OK;
}
/*-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------*/
/// @brief HAL_ESP_ConnectionInit  : this function is responsible of initialization of the connection of the WIFI Network.
/// @param PWD      Takes No parameters.
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_ConnectionInit(void)
{

	// disable the Echo
	MCAL_UART_Transmit( ESP_USART , (u8 *)echo_off , 20 , 10000 , '\n');

	// set Mode: station+AccessPoint
	MCAL_UART_Transmit(ESP_USART , (u8 *)"AT+CWMODE=3\r\n" , 20 , 10000 , '\n');

    // receive the response.
    MCAL_UART_Receive(ESP_USART,ESP_Response,30,100000,'\n');
    // check if the Terminal is used.
    if (Local_TERFLAG == 1)
    {
        MCAL_UART_Transmit(Terminal_USART,(u8 *)"ESP Initializing the connection >" , 100 , 10000 ,'>');
        MCAL_UART_Transmit(Terminal_USART,ESP_Response,30,10000,'\n');
    }
    return ESP_OK;
}

/// @brief HAL_ESP_WIFIConnect  : this function is responsible of connecting to the WIFI Network.
/// @param SSID                 : the AP’s SSID (Network SSID).
/// @param PWD                  : the AP's password (Network PWD).
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_WIFIConnect(u8 *SSID, u8 *PWD)
{
    // Sending the SSID and PWD to connect to the WIFI
    MCAL_UART_Transmit(ESP_USART , (u8 *)"AT+CWJAP_CUR=\"" , 20 , 10000 , '"' );
	MCAL_UART_Transmit(ESP_USART , SSID , 100 , 10000 , '\0' );
	MCAL_UART_Transmit(ESP_USART , (u8 *)"\",\"" , 3 , 10000 , '"');
	MCAL_UART_Transmit(ESP_USART , PWD , 100 , 10000 , '\0');
	MCAL_UART_Transmit(ESP_USART , (u8 *)"\"\r\n" , 3 , 10000 , '\n');

    // receive the response.
    MCAL_UART_Receive(ESP_USART,ESP_Response,30,100000,'\n');
    // check if the Terminal is used.
    if (Local_TERFLAG == 1)
    {
        MCAL_UART_Transmit(Terminal_USART,(u8 *)"ESP Connecting to the Network >" , 100 , 10000 ,'>');
        MCAL_UART_Transmit(Terminal_USART,ESP_Response,30,10000,'\n');
    }
    return ESP_OK;
}

/// @brief HAL_ESP_TCPserver_connect : this function is responsible of connecting to a Server Using TCP.
/// @param ServerIp                  : the Server IP address.
/// @param PortNo                    : the Server Port number that we will use.
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_TCPserver_connect(u8 *ServerIp, u8 *PortNUM)
{
    MCAL_UART_Transmit(ESP_USART , (u8 *)"AT+CIPSTART=\"TCP\",\"" , 50 , 10000 , '"' );
    MCAL_UART_Transmit(ESP_USART , ServerIp , 20 , 10000 , '\0' );
    MCAL_UART_Transmit(ESP_USART , (u8 *)"\"," , 2 , 10000 , ',' );
    MCAL_UART_Transmit(ESP_USART , PortNUM , 10 , 10000 , '\0' );
    MCAL_UART_Transmit(ESP_USART , (u8 *)"\r\n" , 2 , 10000 , '\n' );

    // receive the response.
    MCAL_UART_Receive(ESP_USART,ESP_Response,30,100000,'\n');
    // check if the Terminal is used.
    if (Local_TERFLAG == 1)
    {
        MCAL_UART_Transmit(Terminal_USART,(u8 *)"ESP Connecting to the Server >" , 100 , 10000 ,'>');
        MCAL_UART_Transmit(Terminal_USART,ESP_Response,30,10000,'\n');
    }

    return ESP_OK;

}

/// @brief HAL_ESP_HTTPRequest : this function is responsible of Sending HTTPRequest.
/// @param HTTPRequest         : the HTTPRequest that will be Sent.
/// @param resp_Buffer         : the buffer where the server answer will be stored in.
/// @param resp_LEN            : the length of the buffer that we need to use.
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_HTTPRequest(u8 *HTTPRequest, u8 *resp_Buffer,u32 resp_LEN)
{   
    u8 local_requestLEN = 0;
    u8 local_Data = *HTTPRequest;;
    u8 *len ;
    // get the length of the HTTP request.
    while (local_Data != '\n')
    {
        local_requestLEN ++;
        local_Data = (*HTTPRequest +1);
    }
    ITOS( local_requestLEN , len , 10 );
    // Sending the HTTP_request command to the module.
    MCAL_UART_Transmit(ESP_USART , (u8 *)"AT+CIPSEND=" , 20 , 10000 , '=' );
	MCAL_UART_Transmit(ESP_USART , len , 100 , 10000 , '\0' );
	MCAL_UART_Transmit(ESP_USART , (u8 *)"\r\n", 3 , 10000 , '\n');

    // send the request.
    MCAL_UART_Transmit(ESP_USART , HTTPRequest , 1000 , 10000 , '\n' );
	
    // receive the Server Message.

    MCAL_UART_Receive(ESP_USART , resp_Buffer , resp_LEN , 10000000,0);


    // check if the Terminal is used.
    if (Local_TERFLAG == 1)
    {
        MCAL_UART_Transmit(Terminal_USART,(u8 *)"Server Answer >" , 100 , 10000 ,'>');
        MCAL_UART_Transmit(Terminal_USART,resp_Buffer,resp_LEN,100000,0);
    }

    return ESP_OK;
}
/*-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------*/
static u8* ITOS(u16 num, u8 *str, u8 base)
{
    // declare variable  
    u8 a , temp;
    u8 i=0;
   // Process individual digits
    while (num != 0)
    {
        u32 rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    // use for loop to iterate the string   
    for (a = 0; a < i/2; a++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str[a];  
        str[a] = str[i - a - 1];  
        str[i - a - 1] = temp;  
    }  
    return str;
}
/*-----------------------------------------------------------------------------------------*/