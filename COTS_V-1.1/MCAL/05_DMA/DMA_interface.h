#ifndef		DMA_INTERFACE_H
#define		DMA_INTERFACE_H

/******************************************************************************/
#define		DMA1_BASE_ADD			(u32)(0x40026000)
#define		DMA2_BASE_ADD			(u32)(0x40026400)
/*----------------------------------------------------------------------------*/
#define DMA1  (MDMA_TYPE * )DMA1_BASE_ADD
#define DMA2  (MDMA_TYPE * )DMA2_BASE_ADD

/******************************************************************************/

/******************************************************************************/
/*                              DMA_State                                     */
typedef enum
{
  DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled */
  DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use   */
  DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing              */
  DMA_STATE_TIMEOUT           = 0x03U,  /*!< DMA timeout state                   */
  DMA_STATE_ERROR             = 0x04U,  /*!< DMA error state                     */
  DMA_STATE_ABORT             = 0x05U,  /*!< DMA Abort state                     */
}DMA_StateTypeDef;
/*----------------------------------------------------------------------------*/
/*                              DMA_Error_Code                                */
typedef enum{
DMA_ERROR_NONE          ,    /*!< No error                               */
DMA_ERROR_TE            ,    /*!< Transfer error                         */
DMA_ERROR_FE            ,    /*!< FIFO error                             */
DMA_ERROR_DME           ,    /*!< Direct Mode error                      */
DMA_ERROR_TIMEOUT       ,    /*!< Timeout error                          */
DMA_ERROR_PARAM         ,    /*!< Parameter error                        */
DMA_ERROR_NO_XFER       ,    /*!< Abort requested with no Xfer ongoing   */
DMA_ERROR_NOT_SUPPORTED      /*!< Not supported mode                     */
}DMA_ERROR;
/*----------------------------------------------------------------------------*/
/*           Specifies the channel used for the specified stream.             */
typedef enum
{
    DMA_CHANNEL_0  = 0x00000000U ,   /*!< DMA Channel 0 */
    DMA_CHANNEL_1  = 0x02000000U ,   /*!< DMA Channel 1 */
    DMA_CHANNEL_2  = 0x04000000U ,   /*!< DMA Channel 2 */
    DMA_CHANNEL_3  = 0x06000000U ,   /*!< DMA Channel 3 */
    DMA_CHANNEL_4  = 0x08000000U ,   /*!< DMA Channel 4 */
    DMA_CHANNEL_5  = 0x0A000000U ,   /*!< DMA Channel 5 */
    DMA_CHANNEL_6  = 0x0C000000U ,   /*!< DMA Channel 6 */
    DMA_CHANNEL_7  = 0x0E000000U     /*!< DMA Channel 7 */
}DMA_Channel;
/*----------------------------------------------------------------------------*/
/* Specifies if the data will be transferred from memory to peripheral, 
 *          from memory to memory or from peripheral to memory               
 */
typedef enum
{
DMA_PERIPH_TO_MEMORY = 0x00000000U  ,  /* Peripheral to memory direction     */
DMA_PERIPH_TO_PERIPH = 0x00000000U  ,  /* Peripheral to Peripheral direction */
DMA_MEMORY_TO_PERIPH = 0x00000040U  ,  /* Memory to peripheral direction     */
DMA_MEMORY_TO_MEMORY = 0x00000080U     /* Memory to memory direction         */
}DMA_DIRECTION;
/*----------------------------------------------------------------------------*/
/* Specifies whether the Peripheral address register should be incremented or not. */
typedef enum
{
    DMA_PERIPH_INC_ENABLE  = 0x00000000U ,    /*!< Peripheral increment mode enable  */
    DMA_PERIPH_INC_DISABLE = 0x00000200U    /*!< Peripheral increment mode disable */
}DMA_PERIPH_INC;
/*----------------------------------------------------------------------------*/
/* Specifies whether the memory address register should be incremented or not. */
typedef enum
{
    DMA_MEMORY_INC_ENABLE  = 0x00000000U,    /*!< Peripheral increment mode enable  */
    DMA_MEMORY_INC_DISABLE = 0x00000400U     /*!< Peripheral increment mode disable */
}DMA_MEMORY_INC;
/*----------------------------------------------------------------------------*/
/*                  Specifies the Peripheral data width.                      */
typedef enum
{
    DMA_PDATA_BYTE      = 0x00000000U, /*!< Peripheral data alignment: Byte     */
    DMA_PDATA_HALFWORD  = 0x00000800U, /*!< Peripheral data alignment: HalfWord */
    DMA_PDATA_WORD      = 0x00001000U  /*!< Peripheral data alignment: Word     */
}DMA_PERIPH_DATA_SIZE;
/*----------------------------------------------------------------------------*/
/*                     Specifies the Memory data width.                       */
typedef enum
{
    DMA_MDATA_BYTE      = 0x00000000U, /*!< Memory data alignment: Byte     */
    DMA_MDATA_HALFWORD  = 0x00002000U, /*!< Memory data alignment: HalfWord */
    DMA_MDATA_WORD      = 0x00004000U /*!< Memory data alignment: Word     */
}DMA_MEMO_DATA_SIZE;
/*----------------------------------------------------------------------------*/
/*             Specifies the operation mode of the DMAx Streamx.              */
typedef enum
{
    DMA_NORMAL       = 0x00000000U,          /* Normal mode                  */
    DMA_CIRCULAR     = 0x00000100U,          /* Circular mode                */
    DMA_PERI_FL_CONT = 0x00000020U           /* Peripheral flow control mode */
}DMA_MODE;
/*----------------------------------------------------------------------------*/
/*         Specifies the software priority for the DMAy Streamx.              */
typedef enum
{
    DMA_PRIORITY_LOW        = 0x00000000U,       /* Priority level: Low       */     
    DMA_PRIORITY_MEDIUM     = 0x00010000U,       /* Priority level: Medium    */
    DMA_PRIORITY_HIGH       = 0x00020000U,       /* Priority level: High      */
    DMA_PRIORITY_VERY_HIGH  = 0x00030000U        /* Priority level: Very High */
}DMA_PRIORITY;
/*----------------------------------------------------------------------------*/
/*          Specifies if the FIFO mode or Direct mode will be used
*                        for the specified stream.
*/
typedef enum
{
    DMA_FIFO_M_DISABLE,         /* FIFO mode disable */
    DMA_FIFO_M_ENABLE           /* FIFO mode enable  */
}DMA_FIFO_MODE;
/*----------------------------------------------------------------------------*/
/*                   Specifies the FIFO threshold level.                      */
typedef enum
{
    DMA_FIFO_THRESHOLD_1_QUARTERFULL    = 0u,  /* FIFO threshold 1 quart full configuration  */
    DMA_FIFO_THRESHOLD_HALFFULL         = 1u,  /* FIFO threshold half full configuration     */
    DMA_FIFO_THRESHOLD_3_QUARTERSFULL   = 2u,  /* FIFO threshold 3 quarts full configuration */
    DMA_FIFO_THRESHOLD_FULL             = 3u   /* FIFO threshold full configuration          */
}DMA_FIFO_THRESH_LEVEL;
/*----------------------------------------------------------------------------*/
/*   Specifies the Burst transfer configuration for the memory transfers.     */
typedef enum
{
    DMA_M_BURST_SINGLE = 0x00000000U,
    DMA_M_BURST_INC4   = 0x00800000U,
    DMA_M_BURST_INC8   = 0x01000000U,
    DMA_M_BURST_INC16  = 0x01800000U
}DMA_MEMO_BURST;
/*----------------------------------------------------------------------------*/
/*   Specifies the Burst transfer configuration for the Peripheral transfers. */
typedef enum
{
    DMA_P_BURST_SINGLE = 0x00000000U,
    DMA_P_BURST_INC4   = 0x00200000U,
    DMA_P_BURST_INC8   = 0x00400000U,
    DMA_P_BURST_INC16  = 0x00600000U
}DMA_PERI_BURST;
/******************************************************************************/



/******************************************************************************/
/*                      stream configuration Struct                           */
typedef struct 
{
  DMA_Channel               Channel;          // DMA Used Channel, Does not necessary in the MEMORY_TO_MEMORY mode.
  DMA_MEMO_BURST            MemBurst;         // Memory Burst.
  DMA_PERI_BURST            PeriphBurs;       // Peripheral Burst. 
  DMA_PRIORITY              Priority;         // DMA Priority.
  DMA_MEMO_DATA_SIZE        MemDataSize;      // DMA Memory Data Size 
  DMA_PERIPH_DATA_SIZE      PeriphDataSize;   // DMA Peripheral Data Size
  DMA_MEMORY_INC            MemInc;           // DMA Memory Increment Enable Option.
  DMA_PERIPH_INC            PeriphInc;        // DMA Peripheral Increment Enable Option.
  DMA_MODE                  Mode;             // DMA Mode.
  DMA_DIRECTION             Direction;        // DMA Direction.
  DMA_FIFO_THRESH_LEVEL     FIFOThresh;       // FIFO Threshold Level.
  DMA_FIFO_MODE             FIFOMode;         // FIFO mode Enable Option.
}DMA_InitTypeDef;
/*----------------------------------------------------------------------------*/
/*                    DMA Peripheral Handler Struct                           */
typedef struct DMA_HandleTypeDef
{
  MDMA_TYPE                 *DMAx;                                        /* Register base s                                   */
  u32                       StreamBaseAddress;                            /* DMA Stream Base s                                 */
  u32                       StreamIndex;                                  /* DMA Stream                                        */
  DMA_InitTypeDef           *DMA_Init;                                    /* DMA Steam initialization                          */ 
  DMA_ERROR                 ErrorCode;                                    /* DMA Error                                         */
  DMA_StateTypeDef          State;                                        /* DMA transfer                                      */
  void                      (*prt)( struct DMA_HandleTypeDef *dmaH);      /* DMA transfer complete callback                    */
  void                      (*prt)( struct DMA_HandleTypeDef *dmaH);      /* DMA Half transfer complete callback               */
  void                      (*prt)( struct DMA_HandleTypeDef *dmaH);      /* DMA transfer error callback                       */
  void                      (*prt)( struct DMA_HandleTypeDef *dmaH);      /* Stream direct mode error interrupt flag callback  */
  void                      (*prt)( struct DMA_HandleTypeDef *dmaH);      /* Stream FIFO error interrupt flag callback         */
}__DMA_HandleTypeDef;
/******************************************************************************/




/******************************************************************************/
/*                           Functions Prototypes                             */
/******************************************************************************/
/// @brief Initialize the DMA according to the specified parameters in the DMA_InitTypeDef and create the associated handle.
/// @param DMA_Handler 
/// @return 
DMA_StateTypeDef HAL_DMA_Init (__DMA_HandleTypeDef *DMA_Handler);
/*----------------------------------------------------------------------------*/
/// @brief Initializes the DMA peripheral, by given the Peripheral name not the channel number.
/// @param DMA_Handler 
/// @return 
DMA_StateTypeDef HAL_DMA_Init_ByPeripheral (__DMA_HandleTypeDef *DMA_Handler , u32 peripheralID);
/*----------------------------------------------------------------------------*/
/// @brief Starts the DMA Transfer.
/// @param DMA_Handler 
/// @param SrcAddress  source address.
/// @param DstAddress  distention address.
/// @param DataLength  Size of the Block of data
/// @return 
DMA_StateTypeDef HAL_DMA_Start (__DMA_HandleTypeDef *DMA_Handler, u32 SrcAddress, u32 DstAddress, u32 DataLength);
/*----------------------------------------------------------------------------*/
/// @brief Start the DMA Transfer with interrupt enabled.
/// @param DMA_Handler 
/// @param SrcAddress  source address.
/// @param DstAddress  distention address.
/// @param DataLength  Size of the Block of data
/// @return 
DMA_StateTypeDef HAL_DMA_Start_INT (__DMA_HandleTypeDef *DMA_Handler, u32 SrcAddress, u32 DstAddress, u32 DataLength);
/******************************************************************************/
#endif
