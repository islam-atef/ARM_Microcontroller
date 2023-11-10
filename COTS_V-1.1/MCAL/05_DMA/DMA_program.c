/********************************************************************************************/
/* 	AUTHOR  		: islam atef Mohamed 													*/
/* 	VERSION 		:	  V1 																*/
/* 	DATE    		:  9/2022 												    			*/
/*	Description  	:  This is the Program file Module For the EXTI Peripheral 				*/
/*											at ARM-CORTEX m4								*/
/********************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"


/******************************************************************************/
/// @brief Initialize the DMA according to the specified parameters in the DMA_InitTypeDef and create the associated handle.
/// @param DMA_Handler 
/// @return 
DMA_StateTypeDef HAL_DMA_Init (__DMA_HandleTypeDef *DMA_Handler)
{
    u32 Register_local_Buffer = 0U;

    // concatenate all configurations.
    // 1- Clear the CRx register.
    DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].CR = 0x00000000U;

    /* Check if the DMA Stream is effectively disabled */
    while(GET_BIT(DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].CR,0))
    {
    //   /* Check for the Timeout */
    //   if((HAL_GetTick() - tickstart ) > HAL_TIMEOUT_DMA_ABORT)
    //   {
    //     /* Update error code */
    //     hdma->ErrorCode = HAL_DMA_ERROR_TIMEOUT;
    //     /* Change the DMA state */
    //     hdma->State = HAL_DMA_STATE_TIMEOUT;
    //     return HAL_TIMEOUT;
    //   }
    }
    
    /* Get the CR register value */
    Register_local_Buffer = DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].CR;

    /* Clear CR Register  */
    Register_local_Buffer = 0x00000000UL;

    /* Prepare the DMA Stream configuration */
    Register_local_Buffer |=  DMA_Handler->DMA_Init->Channel             | DMA_Handler->DMA_Init->Direction        |
            DMA_Handler->DMA_Init->PeriphInc           | DMA_Handler->DMA_Init->MemInc           |
            DMA_Handler->DMA_Init->PeriphDataSize      | DMA_Handler->DMA_Init->MemDataSize      |
            DMA_Handler->DMA_Init->Mode                | DMA_Handler->DMA_Init->Priority;

    /* the Memory burst and peripheral burst are not used when the FIFO is disabled */
    if(DMA_Handler->DMA_Init->FIFOMode == DMA_FIFO_M_ENABLE)
    {
        /* Get memory burst and peripheral burst */
        Register_local_Buffer |=  DMA_Handler-> DMA_Init-> MemBurst | DMA_Handler-> DMA_Init-> PeriphBurs;
    }

    /* Write to DMA Stream CR register */
    DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].CR = Register_local_Buffer;  


    /* Get the FCR register value */
    Register_local_Buffer = DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].FCR;

    /* Reset FCR register */
    Register_local_Buffer = 0x00000021UL;

    /* Prepare the DMA Stream FIFO configuration */
    Register_local_Buffer |= DMA_Handler->DMA_Init->FIFOMode;

    /* The FIFO threshold is not used when the FIFO mode is disabled */
    if(DMA_Handler->DMA_Init->FIFOMode == DMA_FIFO_M_ENABLE)
    {
      /* Get the FIFO threshold */
      Register_local_Buffer |= DMA_Handler->DMA_Init->FIFOMode;
    
      /* Check compatibility between FIFO threshold level and size of the memory burst */
      /* for INCR4, INCR8, INCR16 bursts */
    //   if (DMA_Handler->Init.MemBurst != DMA_MBURST_SINGLE)
    //   {
    //     if (DMA_CheckFifoParam(DMA_Handler) != HAL_OK)
    //     {
    //       /* Update error code */
    //       DMA_Handler->ErrorCode = DMA_ERROR_PARAM;

    //       /* Change the DMA state */
    //       DMA_Handler->State = DMA_STATE_READY;

    //       return DMA_STATE_ERROR; 
    //     }
    //   }
    }

    /* Write to DMA Stream FCR */
    DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].FCR = Register_local_Buffer;

    /////////

    /* Initialize the error code */
    DMA_Handler ->ErrorCode = DMA_ERROR_NONE;
    // Set the State of the DMA.
    DMA_Handler ->State = DMA_STATE_READY;
    // return the state.
    return DMA_Handler->State;
}
/*----------------------------------------------------------------------------*/
/// @brief Initializes the DMA peripheral, by given the Peripheral name not the channel number.
/// @param DMA_Handler 
/// @return 
DMA_StateTypeDef HAL_DMA_Init_ByPeripheral (__DMA_HandleTypeDef *DMA_Handler , u32 peripheralID)
{

}
/*----------------------------------------------------------------------------*/
/// @brief Starts the DMA Transfer.
/// @param DMA_Handler 
/// @param SrcAddress  source address.
/// @param DstAddress  distention address.
/// @param DataLength  Size of the Block of data
/// @return 
DMA_StateTypeDef HAL_DMA_Start (__DMA_HandleTypeDef *DMA_Handler, u32 SrcAddress, u32 DstAddress, u32 DataLength)
{
    // Check the State.
    if (DMA_Handler->State == DMA_STATE_READY)
    {   
        // Change the State.
        DMA_Handler->State = DMA_STATE_BUSY;
        // Set the Error State. 
        DMA_Handler->ErrorCode = HAL_DMA_ERROR_NONE;

        /* Configure DMA Stream data length */
        DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].NDTR = DataLength;
        // Check the type of Direction.
        if(DMA_Handler->DMA_Init->Direction == DMA_MEMORY_TO_PERIPH)   /* Memory to Peripheral */
        {
            /* Configure DMA Stream destination address */
            DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].PAR = DstAddress;
            /* Configure DMA Stream source address */
            DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].M0AR = SrcAddress;
        }  
        else  /* Peripheral to Memory */
        {
            /* Configure DMA Stream source address */
            DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].PAR = SrcAddress;
            /* Configure DMA Stream destination address */
            DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].M0AR = DstAddress;
        }
        // Enable the DMA.
        SET_BIT(DMA_Handler->DMAx->S[DMA_Handler->StreamIndex].CR,0);
    }  
    return  DMA_Handler->State;
}
/*----------------------------------------------------------------------------*/
/// @brief Start the DMA Transfer with interrupt enabled.
/// @param DMA_Handler 
/// @param SrcAddress  source address.
/// @param DstAddress  distention address.
/// @param DataLength  Size of the Block of data
/// @return 
DMA_StateTypeDef HAL_DMA_Start_INT (__DMA_HandleTypeDef *DMA_Handler, u32 SrcAddress, u32 DstAddress, u32 DataLength)
{

}
/******************************************************************************/













 /* Initialize StreamBaseAddress and StreamIndex parameters to be used to calculate
    DMA steam Base Address needed by HAL_DMA_IRQHandler() and HAL_DMA_PollForTransfer() */
 regs = (DMA_Base_Registers *)DMA_CalcBaseAndBitshift(hdma);
 
 /* Clear all interrupt flags */
 regs->IFCR = 0x3FU << hdma->StreamIndex;

 /* Initialize the error code */
 hdma->ErrorCode = HAL_DMA_ERROR_NONE;
