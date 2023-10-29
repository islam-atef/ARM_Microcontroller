#ifndef		RCC_PRIVATE_H
#define		RCC_PRIVATE_H

#define		RCC_BASE_ADD			(u32)(0x40023800)

typedef struct
{
    volatile      u32   	CR			    ;
    volatile      u32   	PLLCFGR		    ;
    volatile      u32   	CFGR		    ;
    volatile      u32   	CIR			    ;
    volatile      u32   	AHB1RSTR	    ;
    volatile      u32   	AHB2RSTR	    ;
    volatile      u32   	RESERVED_1[2]	;
    volatile      u32   	APB1RSTR	    ;
    volatile      u32   	APB2RSTR	    ;
    volatile      u32   	RESERVED_2[2]	;
    volatile      u32   	AHB1ENR		    ;
    volatile      u32   	AHB2ENR		    ;
    volatile      u32   	RESERVED_3[2]	;
    volatile      u32   	APB1ENR		    ;
    volatile      u32   	APB2ENR		    ;
    volatile      u32   	RESERVED_4[2]	;
    volatile      u32   	AHB1LPENR	    ;
    volatile      u32   	AHB2LPENR	    ;
    volatile      u32   	RESERVED_5[2]	;
    volatile      u32   	APB1LPENR	    ;
    volatile      u32   	APB2LPENR	    ;
    volatile      u32   	RESERVED_6[2]	;
    volatile      u32   	BDCR		    ;
    volatile      u32   	CSR			    ;
    volatile      u32   	RESERVED_7[2]	;
    volatile      u32   	SSCGR		    ;
    volatile      u32   	PLLI2SCFGR	    ;
    volatile      u32   	RESERVED	    ;
    volatile      u32   	DCKCFGR		    ;
}RCC_TYPE ;

#define RCC  ((RCC_TYPE * )RCC_BASE_ADD)

#endif
