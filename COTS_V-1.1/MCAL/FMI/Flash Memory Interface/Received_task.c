/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "main.h"
#include "cmsis_os.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */




/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */




/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define  	_10S_				pdMS_TO_TICKS(100000)
#define		_THE_STOP_CHAR_		'0'
/* USER CODE END PD */




/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */




/*---------------------------Private variables -------------------------------*/
/* Private Uart Handle -------------------------------------------------------*/
UART_HandleTypeDef huart2;	/*USART_HANDLE UART_2 ={ .USART_x = USART2_R};*/
/* Private UART Configuration structs ----------------------------------------*/
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
/* Private Pin Configuration structs -----------------------------------------*/
PIN_CONFIG USART2_TX =
	{
			.port 	= PA ,
			.pin  	= 2 ,
			.MODEV	= ALTERNATE ,
			.OSPEEDV= MS ,
			.OTYPEV = PP
	};
PIN_CONFIG USART2_RX =
	{
			.port 	= PA ,
			.pin  	= 3 ,
			.MODEV	= ALTERNATE ,
			.OSPEEDV= MS ,
			.OTYPEV = PP
	};


/* Private Queue Handles -----------------------------------------------------*/
QueueHandle_t Uart_Message_Queue = NULL;
/* Private Task Handles ------------------------------------------------------*/
TaskHandle_t Receive_Uart_H ;
/* Private Semaphore Handles -------------------------------------------------*/
SemaphoreHandle_t Receive_Mutex;









/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
void StartDefaultTask(void *argument);
/* Private Task prototypes ---------------------------------------------------*/
void Receive_Uart_F(void * pvParameters);




/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void Uart_ReceiveISR_Int(void)
{
	MRCC_VoidEnablePerClk(RCC_USART2);
	MCAL_UART_Init_( &UART_2 , &Serial_Frame , &Serial_Receiving , 115200);
	MCAL_UART_Enable(&UART_2);
	MNVIC_voidEnablePeripheral(USART2);
}
/* USER CODE END 0 */




/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  Receive_Mutex = xSemaphoreCreateMutex();
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_QUEUES */
  Uart_Message_Queue 	= xQueueCreate(8,sizeof(char));
  /* USER CODE END RTOS_QUEUES */



  /* Create the thread(s) */
  /* USER CODE BEGIN RTOS_THREADS */
  xTaskCreate( Receive_Uart_F , "Receive_Uart"  , 100 , NULL , 10U , &Receive_Uart_H );
  /* USER CODE END RTOS_THREADS */


  /* Start scheduler */
  vTaskStartScheduler();


  while (1)
  {}
}



void add_callbackRX(USART_HANDLE *USARTx)
{
	if(USARTx -> RX_Buffer_Size == USARTx -> RX_Process_Count)
	{
		// start from the Highest priority task or not.
		portBASE_TYPE xHigherPriorityTaskWoken = pdFALSE;

		// Give the Semaphore.
		xSemaphoreGiveFromISR( Received_Mutex , &HigherPriorityTaskWoken );

		// Return to the RTOS.
		portYIELD_FROM_ISR(HigherPriorityTaskWoken);
	}
}


// the Task that Receive From Uart :
void Receive_Uart_F(void * pvParameters)
{
	char 		*Received_Data_Pointer;
	char		 error_counter = 0;
	int			 local_waitTime	= pdMS_TO_TICKS(0);

	void Uart_ReceiveISR_Int(void);
	MCAL_UART_INTT_CALLBACK(&UART_2, RXNE_INT, add_callbackRX);

	while(1)
		{
			// 1- Take the Mutex to Start the task.
			xSemaphoreTake( Receive_Mutex , portMAX_DELAY );

			// 2- Put the Received message into a Filter Queue.
			if( sizeof(Received_Data_Pointer) == 10 )
			{
				xQueueSend( Uart_Message_Queue , Received_Data_Pointer , local_waitTime );
				error_counter =0;
			}
			else
			{
				error_counter++;
			}

			// 3- Restart the receive function.
			MCAL_UART_Receive_INT( &UART_2 , Received_Data_Pointer, _BUFFER_SIZE_ , _THE_STOP_CHAR_ );

			// 4- Small delay for stability.
			vTaskDelay(10);

			// 5- Give the Semaphore to stop the task.
			xSemaphoreGive( Receive_Mutex );
		};
}







/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
