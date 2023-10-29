/********************************************************************************************/
/* 	AUTHOR  		: islam atef Mohamed 													*/
/* 	VERSION 		:	  V1.0 																*/
/* 	DATE    		:  1/2023 																*/
/*	Distribution  	:  This is the Interface file For the (ESP8266_module)   				*/
/*											at ARM-CORTEX m4								*/
/********************************************************************************************/
#ifndef		ESP_INTERFACE_H
#define		ESP_INTERFACE_H

/********************************************************************************************/
/*          	       	The ESP module Functions' status type.            		            */
/********************************************************************************************/
typedef enum
{	
 	ESP_OK              = 0x00U,
 	ESP_UART_ERROR      = 0x01U,
 	ESP_GPIO_ERROR      = 0x02U,
	ESP_ERROR           = 0x03U,
	ESP_UNDERSIZE       = 0x04U,
	ESP_BUSY            = 0x05U
}ESP_Fun_Status;
/********************************************************************************************/
/*                                 controlling  Commands                                     */

#define      Test_AT_startup                        "AT\r\n" 
#define      Restart_module                         "AT+RST\r\n"
#define      echo_on                                "ATE1\r\n"
#define      echo_off                               "ATE0\r\n"
#define      Factory_reset                          "AT+RESTORE\r\n"
/*--------------------------the other controlling commands have parameters------------------*/

/********************************************************************************************/
/*                                      prototypes                                          */
/********************************************************************************************/
/// @brief  HAL_ESP_Init  : this function is used for Initialization of the WIFI module.
/// @param  USARTX        : the USART Struct that the module will use.
/// @param  USARTX        : the USART Struct that the Terminal which will show the response and other data use.
/// @param  ch_en         : the Enabling Pin that the module will use.
/// @param  ch_res        : the Resetting Pin that the module will use.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Init(USART_Struct *USARTX , USART_Struct *USARTY , PIN_CONFIG *ch_en, PIN_CONFIG *ch_res);
/*------------------------------------------------------------------------------------------*/
/// @brief  HAL_ESP_Enable : this function is used for Initialization of the WIFI module.
/// @param          Takes No parameters.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Enable(void);
/*------------------------------------------------------------------------------------------*/
/// @brief  HAL_ESP_Disable : this function is used for Initialization of the WIFI module.
/// @param          Takes No parameters.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Disable();
/*------------------------------------------------------------------------------------------*/
/// @brief  HAL_ESP_Reset : this function is used for Initialization of the WIFI module.
/// @param          Takes No parameters.
/// @retval         the Function Status.
ESP_Fun_Status  HAL_ESP_Reset();
/*------------------------------------------------------------------------------------------*/
/// @brief HAL_ESP_Command  : this function is Used to send a general command to the ESP8266_module. 
/// @param ptCommand        : the command that will be sent.
/// @return     the Function Status.
ESP_Fun_Status  HAL_ESP_Command(u8 *ptCommand);
/*------------------------------------------------------------------------------------------*/
/// @brief HAL_ESP_ConnectionInit  : this function is responsible of initialization of the connection of the WIFI Network.
/// @param PWD      Takes No parameters.
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_ConnectionInit(void);
/*------------------------------------------------------------------------------------------*/
/// @brief HAL_ESP_WIFIConnect  : this function is responsible of connecting to the WIFI Network.
/// @param SSID                 : the AP’s SSID (Network SSID).
/// @param PWD                  : the AP's password (Network PWD).
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_WIFIConnect(u8 *SSID, u8 *PWD);
/*------------------------------------------------------------------------------------------*/
/// @brief HAL_ESP_TCPserver_connect : this function is responsible of connecting to a Server Using TCP.
/// @param ServerIp                  : the Server IP address.
/// @param PortNo                    : the Server Port number that we will use.
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_TCPserver_connect(u8 *ServerIp, u8 *PortNUM);
/*------------------------------------------------------------------------------------------*/
/// @brief HAL_ESP_HTTPRequest : this function is responsible of Sending HTTPRequest.
/// @param HTTPRequest         : the HTTPRequest that will be Sent.
/// @param resp_Buffer         : the buffer where the server answer will be stored in.
/// @param resp_LEN            : the length of the buffer that we need to use.
/// @return         the Function Status.
ESP_Fun_Status  HAL_ESP_HTTPRequest(u8 *HTTPRequest, u8 *resp_Buffer,u32 resp_LEN);
/*------------------------------------------------------------------------------------------*/
/********************************************************************************************/


					  


#endif
