#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"

#include    "MCAL\01_GPIO\GPIO_interface.h"


#include	"S_SEG_interface.h"

volatile u8 sw = 0 ;

void  SSEG_MInit();
//{
//	// OUTPUT INITIALIZATION
//	
//	             /* 1 A OUTPUT PIN */
//	GPIO_MODE( porta , pina , OUT_TYPE );
//	GPIO_OUTPUTSPEED( porta , pina, VHS );
//	             /* 2 B OUTPUT PIN */
//	GPIO_MODE( portb , pinb , OUT_TYPE );
//	GPIO_OUTPUTSPEED( portb , pinb , VHS );
//	             /* 3 C OUTPUT PIN */
//	GPIO_MODE( portc , pinc , OUT_TYPE );
//	GPIO_OUTPUTSPEED( portc , pinc , VHS );
//	             /* 4 D OUTPUT PIN */
//	GPIO_MODE( portd , pind , OUT_TYPE );
//	GPIO_OUTPUTSPEED( portd , pind , VHS );
//	             /* 5 E OUTPUT PIN */
//	GPIO_MODE( porte , pine , OUT_TYPE );
//	GPIO_OUTPUTSPEED( porte , pine , VHS );
//	             /* 6 F OUTPUT PIN */
//	GPIO_MODE( portf , pinf , OUT_TYPE );
//	GPIO_OUTPUTSPEED( portf , pinf , VHS );
//	             /* 7 G OUTPUT PIN */
//	GPIO_MODE( portg , ping , OUT_TYPE );
//	GPIO_OUTPUTSPEED( portg , ping , VHS );
//	             /* 8 DOT OUTPUT PIN */
//	GPIO_MODE( portD , DOT , OUT_TYPE );
//	GPIO_OUTPUTSPEED( portD , DOT , VHS );
//	          
//}
//
//volatile u8 NUM_1 = 0 ;
//volatile u8 NUM_2 = 0 ;
//
//void  SSEG_MSHOW(u8 SEVEN_SEGMENT_NUM )
//{
//	if(SEVEN_SEGMENT_NUM < 10 || SEVEN_SEGMENT_NUM == DOT )
//	{
//		NUM_1 = SEVEN_SEGMENT_NUM ;
//		NUM_2 = 0 ;
//	}
//	else
//	{
//	NUM_1 = SEVEN_SEGMENT_NUM % 10 ;
//	NUM_2 = SEVEN_SEGMENT_NUM / 10 ;
//	}
//	for(u8 count = 0 ; count < 200 ; count++ )
//	{
//	SSEG_SHOW(porta,pina ,portb,pinb ,portc,pinc,portd,pind ,porte,pine ,portf,pinf ,portg,ping ,portD,DOT  ,NUM_1 );
//	SSEG_CONTROL(portC_1,pinC_1,OUT_TYPE,ON);
//	Delay_MICRO_s(500);
//	SSEG_CONTROL(portC_1,pinC_1,OUT_TYPE,OFF);
//	SSEG_SHOW(porta,pina ,portb,pinb ,portc,pinc,portd,pind ,porte,pine ,portf,pinf ,portg,ping ,portD,DOT  ,NUM_2 );
//	SSEG_CONTROL(portC_2,pinC_2,OUT_TYPE,ON);
//	Delay_MICRO_s(500);
//	SSEG_CONTROL(portC_2,pinC_2,OUT_TYPE,OFF);
//	}
//}
//