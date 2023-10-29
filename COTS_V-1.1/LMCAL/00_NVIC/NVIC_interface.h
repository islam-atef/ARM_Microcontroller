#ifndef		NVIC_INTERFACE_H
#define		NVIC_INTERFACE_H

/************************************************************************************/
/*                    The Internal Interrupt Position Table                         */

#define                 NVIC_MemManage                   -6
#define                 NVIC_BusFault                    -5
#define                 NVIC_UsageFault                  -4
#define                 NVIC_SVCall                      -3
#define                 NVIC_PendSV                      -2
#define                 NVIC_Systick                     -1

/*                    The External Interrupt Position Table                         */

/* WWDG Interrupt                                                                   */
#define                 NVIC_WWDG                        0
/* PVD Interrupt                                                                    */
#define                 NVIC_PVD                         1
/* TAMP_STAMP Interrupt                                                             */
#define                 NVIC_TAMP_STAMP                  2
/* SDIO Interrupt                                                                   */
#define                 NVIC_SDIO                        49
/* FPU Interrupt                                                                    */
#define                 NVIC_FPU                         81
/* ff Interrupts                                                                    */
#define                 NVIC_ff                          84
/* FLASH Interrupts                                                                 */
#define                 NVIC_FLASH                       4
/* RCC Interrupts                                                                   */
#define                 NVIC_RCC                         5
/* ADC Interrupts                                                                   */
#define                 NVIC_ADC                         18
/* OTG Interrupts                                                                   */
#define                 NVIC_OTG_FS                      67
#define                 NVIC_OTG_FS_WKUP                 42
/* External Enterrupt Lines                                                         */
#define                 NVIC_EXTI0                       6
#define                 NVIC_EXTI1                       7
#define                 NVIC_EXTI2                       8
#define                 NVIC_EXTI3                       9
#define                 NVIC_EXTI4                       10
#define                 NVIC_EXTI9_5                     23
#define                 NVIC_EXTI15_10                   40
#define                 NVIC_EXTI16                      1
#define                 NVIC_EXTI17                      41
#define                 NVIC_EXTI18                      42
#define                 NVIC_EXTI21                      2
#define                 NVIC_EXTI22                      3
/* DWA1 Interrupts                                                                  */
#define                 NVIC_DMA1_Stream0                11
#define                 NVIC_DMA1_Stream1                12
#define                 NVIC_DMA1_Stream2                13
#define                 NVIC_DMA1_Stream3                14
#define                 NVIC_DMA1_Stream4                15
#define                 NVIC_DMA1_Stream5                16
#define                 NVIC_DMA1_Stream6                17
#define                 NVIC_DMA1_Stream7                47
/* DWA2 Interrupts                                                                  */
#define                 NVIC_DMA2_Stream0                56
#define                 NVIC_DMA2_Stream1                57
#define                 NVIC_DMA2_Stream2                58
#define                 NVIC_DMA2_Stream3                59
#define                 NVIC_DMA2_Stream4                60
#define                 NVIC_DMA2_Stream5                68
#define                 NVIC_DMA2_Stream6                69
#define                 NVIC_DMA2_Stream7                70
/* Timers' Interrupts                                                               */
#define                 NVIC_TIM1_BRK_TIM9               24
#define                 NVIC_TIM1_UP_TIM10               25
#define                 NVIC_TIM1_TRG_COM_TIM11          26
#define                 NVIC_TIM1_CC                     27
#define                 NVIC_TIM2                        28
#define                 NVIC_TIM3                        29
#define                 NVIC_TIM4                        30
#define                 NVIC_TIM5                        50
/* I2C Interrupts                                                                   */
#define                 NVIC_I2C1_EV                     31
#define                 NVIC_I2C1_ER                     32
#define                 NVIC_I2C2_EV                     33
#define                 NVIC_I2C2_ER                     34
#define                 NVIC_I2C3_EV                     72
#define                 NVIC_I2C3_ER                     73
/* ISP Interrupts                                                                   */
#define                 NVIC_SPI1                        35
#define                 NVIC_SPI2                        36
#define                 NVIC_SPI3                        51
/* USART Interrupts                                                                 */
#define                 NVIC_USART1                      37
#define                 NVIC_USART2                      38
#define                 NVIC_USART6                      71
/* RTC Interrupts                                                                   */
#define                 NVIC_RTC_WKUP                    3
#define                 NVIC_RTC_Alarm                   41
/************************************************************************************/
void    MNVIC_voidEnablePeripheral( u8 copy_U8INTID ); // copy_U8INTID = Just +INTID
void    MNVIC_voidDisablePeripheral( u8 copy_U8INTID ); // copy_U8INTID = Just +INTID
/************************************************************************************/
void    MNVIC_voidSetPending( u8 copy_U8INTID ); // copy_U8INTID = Just +INTID
void    MNVIC_voidClearPending( u8 copy_U8INTID ); // copy_U8INTID = Just +INTID
/************************************************************************************/
u8      MNVIC_u8GetActive( u8 copy_U8INTID ); // copy_U8INTID = Just +INTID
/************************************************************************************/
void    MNVIC_voidGroupConfig(void);
/************************************************************************************/
/* for Opition(1) [16-0] : copy_U8GroupNUM = [15:0] and copy_U8SubgroupNUM = [0:0]  */
/* for Opition(2) [8-2]  : copy_U8GroupNUM = [7:0]  and copy_U8SubgroupNUM = [1:0]  */
/* for Opition(3) [4-4]  : copy_U8GroupNUM = [3:0]  and copy_U8SubgroupNUM = [3:0]  */
/* for Opition(4) [2-8]  : copy_U8GroupNUM = [1:0]  and copy_U8SubgroupNUM = [7:0]  */
/* for Opition(1) [0-16] : copy_U8GroupNUM = [0:0]  and copy_U8SubgroupNUM = [15:0] */
/************************************************************************************/
void    MNVIC_voidSetINTPriority( s8 copy_S8INTID , u8 copy_U8GroupNUM , u8 copy_U8SubgroupNUM );
/************************************************************************************/
#endif
