#include	"Std_Types.h"
#include	"Bit_Math.h"

#include    "01 MCAL\01 GPIO\GPIO_interface.h"
#include    "03 CONFIG\01 7-Segmens\S_SEG_config.h"

#include	"S_SEG_interface.h"

//#define GPIOx_ODR     0x14



void  SSEG_Init()
{
	// OUTPUT INITIALIZATION
	
	             /* 1 A OUTPUT PIN */
	GPIO_MODE( porta , pina , OUT_TYPE );
	GPIO_OUTPUTSPEED( porta , pina, VHS );
	             /* 2 B OUTPUT PIN */
	GPIO_MODE( portb , pinb , OUT_TYPE );
	GPIO_OUTPUTSPEED( portb , pinb , VHS );
	             /* 3 C OUTPUT PIN */
	GPIO_MODE( portc , pinc , OUT_TYPE );
	GPIO_OUTPUTSPEED( portc , pinc , VHS );
	             /* 4 D OUTPUT PIN */
	GPIO_MODE( portd , pind , OUT_TYPE );
	GPIO_OUTPUTSPEED( portd , pind , VHS );
	             /* 5 E OUTPUT PIN */
	GPIO_MODE( porte , pine , OUT_TYPE );
	GPIO_OUTPUTSPEED( porte , pine , VHS );
	             /* 6 F OUTPUT PIN */
	GPIO_MODE( portf , pinf , OUT_TYPE );
	GPIO_OUTPUTSPEED( portf , pinf , VHS );
	             /* 7 G OUTPUT PIN */
	GPIO_MODE( portg , ping , OUT_TYPE );
	GPIO_OUTPUTSPEED( portg , ping , VHS );
	             /* 8 DOT OUTPUT PIN */
	GPIO_MODE( portD , DOT , OUT_TYPE );
	GPIO_OUTPUTSPEED( portD , DOT , VHS );
	             /* 9 CONTROL PIN */
	GPIO_MODE( port_C , pin_C , OUT_TYPE );
	GPIO_OUTPUTSPEED( port_C ,pin_C, VHS );
	          
}

void  SSEG_CONTROL(u8 state)
{
	switch(state)
	{
		case ON :
		{
		GPIO_OUTPUTTYPE( port_C , pin_C ,0);
	    break;
		}
		case OFF :
		{
		GPIO_OUTPUTTYPE( port_C , pin_C ,1);
	    break;
		}
	}
}

void  SSEG_SHOW(u8 SEVEN_SEGMENT_NUM )
{
	switch(SEVEN_SEGMENT_NUM)
	{
		case 0:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,1);
			GPIO_OUTPUTTYPE( porte , pine,1);
			GPIO_OUTPUTTYPE( portf , pinf,1);
			GPIO_OUTPUTTYPE( portg , ping,0);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}
		case 1:
		{
			GPIO_OUTPUTTYPE( porta , pina,0);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,0);
			GPIO_OUTPUTTYPE( porte , pine,0);
			GPIO_OUTPUTTYPE( portf , pinf,0);
			GPIO_OUTPUTTYPE( portg , ping,0);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}
		case 2:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,0);
			GPIO_OUTPUTTYPE( portd , pind,1);
			GPIO_OUTPUTTYPE( porte , pine,1);
			GPIO_OUTPUTTYPE( portf , pinf,0);
			GPIO_OUTPUTTYPE( portg , ping,1);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}
		case 3:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,1);
			GPIO_OUTPUTTYPE( porte , pine,0);
			GPIO_OUTPUTTYPE( portf , pinf,0);
			GPIO_OUTPUTTYPE( portg , ping,1);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}case 4:
		{
			GPIO_OUTPUTTYPE( porta , pina,0);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,0);
			GPIO_OUTPUTTYPE( porte , pine,0);
			GPIO_OUTPUTTYPE( portf , pinf,1);
			GPIO_OUTPUTTYPE( portg , ping,1);
			GPIO_OUTPUTTYPE( portD , DOT ,0);
			

			break;
		}
		case 5:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,0);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,1);
			GPIO_OUTPUTTYPE( porte , pine,0);
			GPIO_OUTPUTTYPE( portf , pinf,1);
			GPIO_OUTPUTTYPE( portg , ping,1);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}
		case 6:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,0);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,1);
			GPIO_OUTPUTTYPE( porte , pine,1);
			GPIO_OUTPUTTYPE( portf , pinf,1);
			GPIO_OUTPUTTYPE( portg , ping,1);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}
		case 7:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,0);
			GPIO_OUTPUTTYPE( porte , pine,0);
			GPIO_OUTPUTTYPE( portf , pinf,0);
			GPIO_OUTPUTTYPE( portg , ping,0);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}
		case 8:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,1);
			GPIO_OUTPUTTYPE( porte , pine,1);
			GPIO_OUTPUTTYPE( portf , pinf,1);
			GPIO_OUTPUTTYPE( portg , ping,1);
			GPIO_OUTPUTTYPE( portD , DOT ,0);

			break;
		}
		case 9:
		{
			GPIO_OUTPUTTYPE( porta , pina,1);
			GPIO_OUTPUTTYPE( portb , pinb,1);
			GPIO_OUTPUTTYPE( portc , pinc,1);
			GPIO_OUTPUTTYPE( portd , pind,1);
			GPIO_OUTPUTTYPE( porte , pine,0);
			GPIO_OUTPUTTYPE( portf , pinf,1);
			GPIO_OUTPUTTYPE( portg , ping,1);
			GPIO_OUTPUTTYPE( portD , DOT ,0);
			break;
		}
		case dot_C:
		{
			GPIO_OUTPUTTYPE( porta , pina,0);
            GPIO_OUTPUTTYPE( portb , pinb,0);
	        GPIO_OUTPUTTYPE( portc , pinc,0);
	        GPIO_OUTPUTTYPE( portd , pind,0);
	        GPIO_OUTPUTTYPE( porte , pine,0);
	        GPIO_OUTPUTTYPE( portf , pinf,0);
	        GPIO_OUTPUTTYPE( portg , ping,0);
	        GPIO_OUTPUTTYPE( portD , DOT ,1);

			break;
		}
	}
}
