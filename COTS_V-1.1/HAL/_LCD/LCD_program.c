#include	"Std_Types.h"
#include	"Bit_Math.h"


#include	"03 CONFG\04 LCD\LCD_config.h"
#include	"01 MCAL\01 GPIO\GPIO_interface.h"
#include    "01 MCAL\02 Delay\DELAY_ARM.h"

#include	"LCD_interface.h"

#define GPIOx_BSRRL   0x18
#define GPIOx_BSRRH   0x1A


volatile u8 WRITE_C  = 7  ;
volatile u8 ARRAY_C ;
volatile u8 MODE ;
volatile u8 PIN_ARRAY[8] ;

void pin_clear(void);

void LCD_init(u8 mode)
{
	Delay_ms(15);
	/* DATA_BUS INITIALIZATION */
	switch(mode)
	{
		case _4_BIT :
		{
			GPIO_MODE( DATA_PORT,PIN0,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN1,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN1,LOW );
			PIN_ARRAY[0]=PIN0;
			GPIO_MODE( DATA_PORT,PIN1,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN1,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN1,LOW );
			PIN_ARRAY[1]=PIN1;
			GPIO_MODE( DATA_PORT,PIN2,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN2,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN2,LOW );
			PIN_ARRAY[2]=PIN2;
			GPIO_MODE( DATA_PORT,PIN3,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN3,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN3,LOW );
			PIN_ARRAY[3]=PIN3;
			
			MODE = 3 ;
			break;
		}
		case _8_BIT :
		{
			GPIO_MODE( DATA_PORT,PIN0,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN1,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN1,LOW );
			PIN_ARRAY[0]=PIN0;
			GPIO_MODE( DATA_PORT,PIN1,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN1,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN1,LOW );
			PIN_ARRAY[1]=PIN1;
			GPIO_MODE( DATA_PORT,PIN2,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN2,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN2,LOW );
			PIN_ARRAY[2]=PIN2;
			GPIO_MODE( DATA_PORT,PIN3,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN3,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN3,LOW );
			PIN_ARRAY[3]=PIN3;
			GPIO_MODE( DATA_PORT,PIN4,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN4,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN4,LOW );
			PIN_ARRAY[4]=PIN4;
			GPIO_MODE( DATA_PORT,PIN5,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN5,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN5,LOW );
			PIN_ARRAY[5]=PIN5;
			GPIO_MODE( DATA_PORT,PIN6,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN6,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN6,LOW );
			PIN_ARRAY[6]=PIN6;
			GPIO_MODE( DATA_PORT,PIN7,OUTPUT_PP_PU );
	        GPIO_OUTPUTSPEED( DATA_PORT,PIN7,VHS );
			GPIO_OUTPUTTYPE( DATA_PORT,PIN7,LOW );
			PIN_ARRAY[7]=PIN7;
			
			MODE = 7 ;

			break;
		}
	}
	
	/* CONTROL INITIALIZATION */
	GPIO_MODE( RS_PORT , RS_PIN,OUTPUT_PP_PU );
	GPIO_OUTPUTSPEED( RS_PORT , RS_PIN ,VHS );
	GPIO_OUTPUTTYPE( RS_PORT , RS_PIN ,LOW );
	
	GPIO_MODE( E_PORT , E_PIN ,OUTPUT_PP_PU );
	GPIO_OUTPUTSPEED( E_PORT , E_PIN ,VHS );
	GPIO_OUTPUTTYPE( E_PORT , E_PIN ,LOW );
	
	/* COMMAND INITIALIZATION */
	
	LCD_COMMAND(mode);
	LCD_COMMAND(DISPAY_ON_CURSOR_ON);
	LCD_COMMAND(CLEAR_DISPALY);
} 

void LCD_COMMAND(u8 command)
{
	*(volatile u16 *)(RS_PORT + GPIOx_BSRRH) = (1<<RS_PIN); // reset RS
	WRITE_C = 7;
	while(DATA_C>=0)
	{
		for(ARRAY_C = MODE ; ARRAY_C >= 0 ; ARRAY_C --)
		{
			*(volatile u16 *)(DATA_PORT + GPIOx_BSRRL) = (GET_BIT(command,WRITE_C)<<PIN_ARRAY[ARRAY_C]);
			DATA_C --;
		}	
		*(volatile u16 *)(E_PORT + GPIOx_BSRRL) = (1<<E_PIN); // set E
		Delay_ms(1);
		*(volatile u16 *)(E_PORT + GPIOx_BSRRH) = (1<<E_PIN); // reset E
		pin_clear();
	}
	Delay_ms(2);	
}

void LCD_WRITE(u8 Data)
{
	*(volatile u16 *)(RS_PORT + GPIOx_BSRRL) = (1<<RS_PIN); // set RS
	WRITE_C = 7;
	while(DATA_C>=0)
	{
		for(ARRAY_C = MODE ; ARRAY_C >= 0 ; ARRAY_C --)
		{
			*(volatile u16 *)(DATA_PORT + GPIOx_BSRRL) = (GET_BIT(Data,WRITE_C)<<PIN_ARRAY[ARRAY_C]);
			DATA_C --;
		}	
		*(volatile u16 *)(E_PORT + GPIOx_BSRRL) = (1<<E_PIN); // set E
		Delay_ms(1);
		*(volatile u16 *)(E_PORT + GPIOx_BSRRH) = (1<<E_PIN); // reset E
		pin_clear();
	}
	Delay_ms(2);	
}


void LCD_WRITE_STRING(u8 *Data)
{
	u8 i=0;
	while(Data[i] != 0)
	{
		LCD_WRITE(Data[i]);
		i++;
	}
}

void pin_clear()
{
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN0); // reset RS
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN1); // reset RS
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN2); // reset RS
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN3); // reset RS
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN4); // reset RS
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN5); // reset RS
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN6); // reset RS
	*(volatile u16 *)(DATA_PORT + GPIOx_BSRRH) = (1<<PIN7); // reset RS
}