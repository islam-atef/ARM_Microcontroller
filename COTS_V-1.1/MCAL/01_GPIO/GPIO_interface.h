#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/* Pin signal MODES {MODER} */
typedef enum {

  INPUT,
  OUTPUT,
  ALTERNATE,
  ANALOG

} MODE_TYPE;

/* Output Signal Speed {OSPEEDR} */

typedef enum {

  LS, // 8   MHz = 125  nS
  MS, // 50  MHz = 20   nS
  HS, // 80  MHz = 12.5 nS
  VHS // 180 MHz = 5.6  nS

} OUTPUT_SPEED_TYPE;

/* INPUT Signal Type {PUPDR} */
typedef enum {

  FLOAT,
  PU,
  PD

} INPUT_SIGNAL_TYPE;

/* OUTPUT Signal Type {OTYPEV} */
typedef enum {

  PP, // Reset State
  OD

} OUTPUT_OPERATION_TYPE;

/* Alternate Function Type {AFR} */

typedef enum {

  System,
  TIM1_TIM2,
  TIM_3__5,
  TIM_9__11,
  I2C_1__3,
  SPI_1__4,
  SPI3,
  USART1_USART2,
  USART6,
  I2C_2__3,
  OTG_FS,
  AF11,
  SDIO,
  AF13,
  AF14,
  EVENTOUT

} AFR_TYPE;

/* Output Signal Types */
typedef enum {

  LOW,
  HIGH,
  TOGG

} OUTPUT_SIGNAL_TYPE;

/* Port Addresses */

#define GPIO_A (volatile u32)(0x40020000)
#define GPIO_B (volatile u32)(0x40020400)
#define GPIO_C (volatile u32)(0x40020800)

/* PIN CONFIG STRUCT */

typedef struct {

  volatile u32 port;
  volatile u8 pin;
  volatile MODE_TYPE MODEV;
  volatile INPUT_SIGNAL_TYPE PUPDV;
  volatile OUTPUT_OPERATION_TYPE OTYPEV;
  volatile OUTPUT_SPEED_TYPE OSPEEDV;

} PIN_CONFIG;

/******************************************************************************************************************
 *  Function : MCAL_GPIO_vMODE
 *
 *  IP parameters : a pointer To ( PIN_CONFIG ) struct
 *
 *  Returning : Returns Nothing
 *
 *  Description :       This Function Initializes the Pin and Define The {Mode
 * Type} , {OutputType} ,{Output Speed} and {PULL_UP PULL_DOWN state}
 ******************************************************************************************************************/
void MGPIO_voidMODEInit(PIN_CONFIG *copy_PinConfiguration);
/******************************************************************************************************************
 *  Function : MGPIO_voidPortWRITE
 *  I/P parameters : a pointer To ( PIN_CONFIG ) struct and The Whole PORT
 * Output Pins Value
 *  Returning : Returns Nothing
 *  Description :       This Function Write The Output Signal Type If The Whole
 * POrt Is used as OUTPUT
 ******************************************************************************************************************/
void MGPIO_voidPortWRITE(PIN_CONFIG *copy_PinConfiguration, u16 VAL);
/******************************************************************************************************************
 *  Function : MGPIO_voidPinWRITE
 *  IP parameters : a pointer To ( PIN_CONFIG ) struct and The Pin Output
 * Signal Type
 *  Returning : Returns Nothing
 *  Description :       This Function Write The Output Signal Type For a
 * specific Pin
 ******************************************************************************************************************/
void MGPIO_voidPinWRITE(PIN_CONFIG *copy_PinConfiguration,
                        OUTPUT_SIGNAL_TYPE copy_PinType);
/******************************************************************************************************************
 *  Function : MGPIO_voidALTFuncTYPE
 *
 *  I/P parameters : a pointer To ( PIN_CONFIG ) struct and The Pin Alternate
 * Function Type
 *  Returning : Returns Nothing
 *
 *  Description :       This Function Define The Alternate Function Type For The
 * Pin
 ******************************************************************************************************************/
void MGPIO_voidALTFuncTYPE(PIN_CONFIG *copy_PinConfiguration,
                           AFR_TYPE copy_AlternateFunction);
/******************************************************************************************************************
 *  Function : MGPIO_u8INPUTREAD
 *
 *  IP parameters : a pointer To ( PIN_CONFIG ) struct
 *
 *  Returning : Returns The Signal On The Pin
 *  Description :       This Function Read the Signal On The Input Pin
 *
 ******************************************************************************************************************/
u8 MGPIO_u8INPUTREAD(PIN_CONFIG *copy_PinConfiguration);
/******************************************************************************************************************
 *  Function : MGPIO_voidLOCKPORT
 *
 *  I/P parameters : Takes Nothing
 *
 *  Returning : Returns Nothing
 *
 *  Description :       This Function Initializes the EXTI Peripheral
 *
 ******************************************************************************************************************/
void MGPIO_voidLOCKPORT();

#endif
