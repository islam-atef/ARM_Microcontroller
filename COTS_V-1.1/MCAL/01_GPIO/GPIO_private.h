#ifndef		GPIO_PRIVATE_H
#define		GPIO_PRIVATE_H

/* Register Addresses */

typedef struct
{
    volatile    u32     MODER   ;
    volatile    u32     OTYPER  ;
    volatile    u32     OSPEEDR ;
    volatile    u32     PUPDR   ;
    volatile    u32     IDR     ;
    volatile    u32     ODR     ;
    volatile    u16     BSRRL   ;
    volatile    u16     BSRRH   ;
    volatile    u32     LCKR    ;
    volatile    u32     AFRL    ;
    volatile    u32     AFRH    ;
}GPIO_TYPE;

#endif
