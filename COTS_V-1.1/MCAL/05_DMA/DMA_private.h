#ifndef		DMA_PRIVATE_H
#define		DMA_PRIVATE_H

/***********************************************************************/

#define		DMA1_BASE_ADD			(u32)(0x40026000)
#define		DMA2_BASE_ADD			(u32)(0x40026400)

/*                      The Register For Each Stream                   */
typedef struct
{
    volatile      u32           CR          ;
    volatile      u32           NDTR        ;
    volatile      u32           PAR         ;
    volatile      u32           M0AR        ;
    volatile      u32           M1AR        ;	
    volatile      u32           FCR         ;
}MDMA_STREAM_TYPE ;

/*                       The DMA Registers                             */
typedef struct
{
    volatile      u32               LISR        ;
    volatile      u32               HISR        ;
    volatile      u32               LIFCR       ;
    volatile      u32               HIFCR       ;
    volatile      MDMA_STREAM_TYPE  S[8]        ;
}MDMA_TYPE ;

#define DMA1  (MDMA_TYPE * )DMA1_BASE_ADD
#define DMA2  (MDMA_TYPE * )DMA2_BASE_ADD

/***********************************************************************/
#endif
