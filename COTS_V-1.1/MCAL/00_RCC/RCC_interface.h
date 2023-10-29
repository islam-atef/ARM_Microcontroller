#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H

/********************************************************************************************/
        /* Peripherals BIT Numbers */

#define		RCC_PORTA		    (   0   )
#define		RCC_PORTB		    (   1   )
#define		RCC_PORTC		    (   2   )
#define		RCC_PORTD		    (   3   )
#define		RCC_GPIOE		    (   4   )
#define		RCC_GPIOH		    (   7   )
#define		RCC_CRC 		    (   12  )
#define		RCC_DMA1		    (   21  )
#define		RCC_DMA2		    (   22  )

#define		RCC_OTGFS		    ((7 )+32)

#define		RCC_TIM2		    ((0 )+64)
#define		RCC_TIM3		    ((1 )+64)
#define		RCC_TIM4		    ((2 )+64)
#define		RCC_TIM5		    ((3 )+64)
#define		RCC_WWDG		    ((11)+64)
#define		RCC_SPI2		    ((14)+64)
#define		RCC_SPI3		    ((15)+64)
#define		RCC_USART2		    ((17)+64)
#define		RCC_I2C1		    ((21)+64)
#define		RCC_I2C2		    ((22)+64)
#define		RCC_I2C3		    ((23)+64)
#define		RCC_PWR 		    ((28)+64)

#define		RCC_TIM1		    ((0 )+96)
#define		RCC_USART1		    ((4 )+96)
#define		RCC_USART6		    ((5 )+96)
#define		RCC_ADC1		    ((8 )+96)
#define		RCC_SDIO		    ((11)+96)
#define		RCC_SPI1		    ((12)+96)
#define		RCC_SPI4		    ((13)+96)
#define		RCC_SYSCFG		    ((14)+96)   /* Shouid Be Enabled For External-Interrupts */
#define		RCC_TIM9		    ((16)+96)
#define		RCC_TIM10		    ((17)+96)
#define		RCC_TIM11		    ((18)+96)
/********************************************************************************************/
#define     Not_Divided          (0)
/********************************************************************************************/

void	MRCC_VoidSysClkInit(void);

void	MRCC_VoidEnablePerClk( u8 copy_u8PeripheralID );
void	MRCC_VoidDisablePerClk( u8 copy_u8PeripheralID );

void	MRCC_VoidLPEnablePerClk( u8 copy_u8PeripheralID );
void	MRCC_VoidLPDisablePerClk( u8 copy_u8PeripheralID );

void	MRCC_VoidPerReset( u8 copy_u8PeripheralID );

void	MRCC_VoidAHBprescaler(u32 copy_u8AHBprescaler);

void	MRCC_VoidAPB1prescaler(u8 copy_u8APB1prescaler);
void	MRCC_VoidAPB2prescaler(u8 copy_u8APB2prescaler);

void	MRCC_VoidRTCprescaler(u8 copy_u8ARTCprescaler);  // not yet 

void	MRCC_VoidMCO1sorce(u8 copy_u8AMCO1sorce);  // not yet 
void	MRCC_VoidMCO1prescaler(u8 copy_u8MCO1prescaler);  // not yet 

void	MRCC_VoidMCO2sorce(u8 copy_u8AMCO2sorce);  // not yet 
void	MRCC_VoidMCO2prescaler(u8 copy_u8MCO2prescaler);  // not yet 


#endif
