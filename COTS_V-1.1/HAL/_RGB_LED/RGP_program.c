#include	"Std_Types.h"
#include	"Bit_Math.h"

#include    "01 MCAL\01 GPIO\GPIO_interface.h"
#include    "01 MCAL\02 Delay\DELAY_ARM.h"
#include    "03 CONFIG\00 RGB_LED\RGB_config.h"

#include	"RGB_interface.h"

#define GPIOx_ODR     0x14


void RGB_Init(u8 TYPE)
{
	// OUTPUT INITIALIZATION
	
	             /* FIRST COLOR OUTPUT PIN */
	GPIO_MODE( port1_O , pin1_O , OUTPUT_TYPE );
	GPIO_OUTPUTSPEED( port1_O , pin1_O , VHS );
	             /* SECOND COLOR OUTPUT PIN */
	GPIO_MODE( port2_O , pin2_O , OUTPUT_TYPE );
	GPIO_OUTPUTSPEED( port2_O , pin2_O , VHS );
	             /* ThIRD COLOR OUTPUT PIN */
	GPIO_MODE( port3_O , pin3_O , OUTPUT_TYPE );
	GPIO_OUTPUTSPEED( port3_O , pin3_O , VHS );
	
	// INPUT INITIALIZATION
	if(TYPE == BUTTON)
	{
	    		     /* FIRST COLOR INPUT BIT */
	    GPIO_MODE( port1_I, bit1_I , INPUT_TYPE);
	    	         /* SECOND COLOR INPUT BIT */
	    GPIO_MODE( port2_I, bit2_I , INPUT_TYPE);
	    	         /* ThIRD COLOR INPUT BIT */
	    GPIO_MODE( port3_I, bit3_I , INPUT_TYPE);
	}

}


void  RGB_Triggers_BU(u8 MODE)
{
	switch(MODE)
	{
		case Blinking :
		{
			// First color
			if(GPIO_INPUTDATA( port1_I , bit1_I ) == LOW)
			{
				GPIO_OUTPUTTYPE( port1_O , pin1_O,1);
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			if(GPIO_INPUTDATA( port1_I , bit1_I ) == HIGH)
			{
				GPIO_OUTPUTTYPE( port1_O , pin1_O,0);
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			
			// Second color
			if(GPIO_INPUTDATA( port2_I , bit2_I ) == LOW)
			{
				GPIO_OUTPUTTYPE( port2_O , pin2_O,1);
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			if(GPIO_INPUTDATA( port2_I , bit2_I ) == HIGH)
			{
				GPIO_OUTPUTTYPE( port2_O , pin2_O,0);
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			
			// Third color
			if(GPIO_INPUTDATA( port3_I , bit3_I ) == LOW)
			{
				GPIO_OUTPUTTYPE( port3_O , pin3_O,1);
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			if(GPIO_INPUTDATA( port3_I , bit3_I ) == HIGH)
			{
				GPIO_OUTPUTTYPE( port3_O , pin3_O,0);
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			break;
		}
		case ON_OFF :
		{
			// First color
			if(GPIO_INPUTDATA( port1_I , bit1_I ) == LOW)
			{
				TOG_BIT(*((volatile u32 *)((port1_O) + GPIOx_ODR)),(pin1_O));
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			
			// Second color
			if(GPIO_INPUTDATA( port2_I , bit2_I ) == LOW)
			{
				TOG_BIT(*((volatile u32 *)((port2_O) + GPIOx_ODR)),(pin2_O));
				Delay_ms(20); /* it was Delay(); [5000000] */
			}
			
			// Third color
			if(GPIO_INPUTDATA( port3_I , bit3_I ) == LOW)
			{
				TOG_BIT(*((volatile u32 *)((port3_O) + GPIOx_ODR)),(pin3_O));
				Delay_ms(20); /* it was Delay(); [5000000] */
			}

			break;
		}
	}

}

void  RGB_Triggers_BI( u8 color_n )
{
	GPIO_OUTPUTTYPE( port1_O , pin1_O,0);
	GPIO_OUTPUTTYPE( port2_O , pin2_O,0);
	GPIO_OUTPUTTYPE( port3_O , pin3_O,0);
	
	/////////////////////////////////////////////////////////////
	
    // First color
	if( color_n == 1 )
	{
		GPIO_OUTPUTTYPE( port1_O , pin1_O,1);
		Delay_ms(20); /* it was Delay(); [5000000] */
	}
	// Second color
	else if(color_n == 2 )
	{
		GPIO_OUTPUTTYPE( port2_O , pin2_O,1);
		Delay_ms(20); /* it was Delay(); [5000000] */
	}
	// Third color
	else if(color_n == 3 )
	{
		GPIO_OUTPUTTYPE( port3_O , pin3_O,1);
		Delay_ms(20); /* it was Delay(); [5000000] */
	}
	
	/////////////////////////////////////////////////////////////
	
	// First color and Second color
	else if( (color_n == 12) || (color_n == 21) )
	{
		GPIO_OUTPUTTYPE( port1_O , pin1_O,1);
		GPIO_OUTPUTTYPE( port2_O , pin2_O,1);
		Delay_ms(20); /* it was Delay(); [5000000] */
	}
	// Second color and Third color
	else if( (color_n == 23) || (color_n == 32) )
	{
		GPIO_OUTPUTTYPE( port2_O , pin2_O,1);
		GPIO_OUTPUTTYPE( port3_O , pin3_O,1);
		Delay_ms(20); /* it was Delay(); [5000000] */
	}
	// Third color and First color
	else if( (color_n == 13) || (color_n == 31) )
	{
		GPIO_OUTPUTTYPE( port1_O , pin1_O,1);
		GPIO_OUTPUTTYPE( port3_O , pin3_O,1);
		Delay_ms(20); /* it was Delay(); [5000000] */
	}
	
	/////////////////////////////////////////////////////////////
	
	// First color , Second color and Third color 
	else if((color_n == 123) || (color_n == 132) || (color_n == 321) || (color_n == 312) || (color_n == 231 ) || (color_n == 213 ))
	{
		GPIO_OUTPUTTYPE( port1_O , pin1_O,1);
		GPIO_OUTPUTTYPE( port2_O , pin2_O,1);
		GPIO_OUTPUTTYPE( port3_O , pin3_O,1);
		Delay_ms(20); /* it was Delay(); [5000000] */
	}
	
	/////////////////////////////////////////////////////////////

}

