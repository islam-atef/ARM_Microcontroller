#include	"00 LIB/Std_Types.h"
#include	"00 LIB/Bit_Math.h"


#include	"03 CONFIG\03 keypad\KEYPAD_config.h"
#include	"01 MCAL\01 GPIO\GPIO_interface.h"

#include	"KEYPAD_interface.h"

#define GPIOx_IDR     0x10

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


void KEYPAD_init()
{
	
/* FIRST FOUR PINS ARE INPUT_PULL_UP PINS */
	GPIO_MODE(PORT1, PIN1 , INPUT_PU );
	GPIO_MODE(PORT2, PIN2 , INPUT_PU );
	GPIO_MODE(PORT3, PIN3 , INPUT_PU );
	GPIO_MODE(PORT4, PIN4 , INPUT_PU );
	
/* LAST FOUR PINS ARE OUTPUT_PUSH_PULL_PULL_UP PINS , THE OUTPUT SIGNAL IS LOW */
	GPIO_MODE( PORT5,PIN5,OUTPUT_PP_PU );
	GPIO_OUTPUTSPEED( PORT5,PIN5,VHS );
	GPIO_OUTPUTTYPE( PORT5,PIN5,LOW );
	
	GPIO_MODE( PORT6,PIN6,OUTPUT_PP_PU );
	GPIO_OUTPUTSPEED( PORT6,PIN6,VHS );
	GPIO_OUTPUTTYPE( PORT6,PIN6,LOW );
	
	GPIO_MODE( PORT7,PIN7,OUTPUT_PP_PU );
	GPIO_OUTPUTSPEED( PORT7,PIN7,VHS );
	GPIO_OUTPUTTYPE( PORT7,PIN7,LOW );
	
	GPIO_MODE( PORT8,PIN8,OUTPUT_PP_PU );
	GPIO_OUTPUTSPEED( PORT8,PIN8,VHS );
	GPIO_OUTPUTTYPE( PORT8,PIN8,LOW );
						
}

//////////////////////////////////////////////////////////////////////////////////

u8 keypad()
{
	GPIO_OUTPUTTYPE( PORT5,PIN5,LOW );
	GPIO_OUTPUTTYPE( PORT6,PIN6,HIGH );
	GPIO_OUTPUTTYPE( PORT7,PIN7,HIGH );
	GPIO_OUTPUTTYPE( PORT8,PIN8,HIGH );
	if(GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1));
		return 'D';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2));
		return '#';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3));
		return '0';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4));
		return '*';
	}

    GPIO_OUTPUTTYPE( PORT5,PIN5,HIGH );
	GPIO_OUTPUTTYPE( PORT6,PIN6,LOW );
	GPIO_OUTPUTTYPE( PORT7,PIN7,HIGH );
	GPIO_OUTPUTTYPE( PORT8,PIN8,HIGH );
	if(GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1));
		return 'C';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2));
		return '0';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3));
		return '8';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4));
		return '7';
	}

    GPIO_OUTPUTTYPE( PORT5,PIN5,HIGH );
	GPIO_OUTPUTTYPE( PORT6,PIN6,HIGH );
	GPIO_OUTPUTTYPE( PORT7,PIN7,LOW );
	GPIO_OUTPUTTYPE( PORT8,PIN8,HIGH );
	if(GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1));
		return 'B';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2));
		return '6';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3));
		return '5';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4));
		return '4';
	}
	
	GPIO_OUTPUTTYPE( PORT5,PIN5,HIGH );
	GPIO_OUTPUTTYPE( PORT6,PIN6,HIGH );
	GPIO_OUTPUTTYPE( PORT7,PIN7,HIGH );
	GPIO_OUTPUTTYPE( PORT8,PIN8,LOW );
	if(GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1));
		return 'A';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2));
		return '3';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3));
		return '2';
	}
	else if(GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4) == 0)
	{
		while(!GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4));
		return '1';
	}
 
}

//////////////////////////////////////////////////////////////////////////////////

u8 Keypad_Listen()
{
	if((GET_BIT(*(volatile u32 *)(PORT1+GPIOx_IDR), PIN1) != 0) ||
	   (GET_BIT(*(volatile u32 *)(PORT2+GPIOx_IDR), PIN2) != 0) ||
	   (GET_BIT(*(volatile u32 *)(PORT3+GPIOx_IDR), PIN3) != 0) ||                                            
       (GET_BIT(*(volatile u32 *)(PORT4+GPIOx_IDR), PIN4) != 0)   )
	{                                                    
		return 1;
	}
	else
	{
		return 0;
	}
}
