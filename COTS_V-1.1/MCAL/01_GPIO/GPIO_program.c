#include	"../../LIB/STD_Types.h"
#include	"../../LIB/BIT_MATH.h"

#include	"GPIO_interface.h"
#include	"GPIO_private.h"


/******************************************************************************************************************/
/*  Function : MGPIO_voidMODEInit			                                									  */
/*  I/P parameters : a pointer To ( PIN_CONFIG ) struct                                      					  */
/*  Returning	   : Returns Nothing                                           									  */
/*  Description    :       This Function Initializes the Pin and Define The {Mode Type} , {Output Type} ,	   	  */
/*								{Output Speed} and {PULL_UP PULL_DOWN state}		   							  */
/******************************************************************************************************************/
void 	MGPIO_voidMODEInit( PIN_CONFIG* copy_PinConfiguration   )
{
	/* Define a Struct Point To The GPIO-Peripheral's Registers                                                   */
	GPIO_TYPE *PORT   =  (GPIO_TYPE *)(copy_PinConfiguration->port) ;
	if(copy_PinConfiguration->pin < 16 )
	{
	    if(    (copy_PinConfiguration->port == PA && copy_PinConfiguration->pin ==13) \
			|| (copy_PinConfiguration->port == PA && copy_PinConfiguration->pin ==14) \
			|| (copy_PinConfiguration->port == PB && copy_PinConfiguration->pin ==3)  \
			|| (copy_PinConfiguration->port == PB && copy_PinConfiguration->pin ==4) )
        {	/* Error */ 	}
        else
        {		/* 			Configure The (MODER) register to the Needed Mode 									 */
        	(PORT) -> MODER &= ~( 0b11 << (copy_PinConfiguration->pin*2) );
        	(PORT) -> MODER |=  ( copy_PinConfiguration->MODEV << (copy_PinConfiguration->pin*2) );

			if(copy_PinConfiguration->MODEV == (OUTPUT || ALTERNATE))
			{
				/* 				Configure The (OTYPER) register to the Needed output Type 						  */
        		(PORT) -> OTYPER &= ~( 0b1 << (copy_PinConfiguration->pin) );
				(PORT) -> OTYPER |=  ( copy_PinConfiguration->OTYPEV << (copy_PinConfiguration->pin) );
	   				/* 				Configure The (OSPEEDR) register to the Needed output speed					  */
				(PORT) -> OSPEEDR &= ~( 0b11 << (copy_PinConfiguration->pin*2) );
        		(PORT) -> OSPEEDR |=  ( copy_PinConfiguration->OSPEEDV << (copy_PinConfiguration->pin*2) );
			}
					/* 			Configure The (PUPDR) register to the Needed Type 								  */
        	(PORT) -> PUPDR &= ~( 0b11 << (copy_PinConfiguration->pin*2) );
        	(PORT) -> PUPDR |=  ( copy_PinConfiguration->PUPDV << (copy_PinConfiguration->pin*2) );
        }
	}
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/*  Function : MGPIO_voidPortWRITE			                                									  */
/*  I/P parameters : a pointer To ( PIN_CONFIG ) struct and The Whole PORT Output Pins Value                      */
/*  Returning	   : Returns Nothing                                           								      */
/*  Description	   :       This Function Write The Output Signal Type If The Whole POrt Is used as OUTPUT         */
/******************************************************************************************************************/
void 	MGPIO_voidPortWRITE( PIN_CONFIG* copy_PinConfiguration  , u16 VAL )
{
	/* Define a Struct Point To The GPIO-Peripheral's Registers                                                   */
	GPIO_TYPE *PORT   =  (GPIO_TYPE *)(copy_PinConfiguration->port) ;
	/* 			Configure The Whole (ODR) Register of The Port	 										 		  */
    (PORT) -> ODR =  VAL ;
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/*  Function : MGPIO_voidPinWRITE			                                									  */
/*  I/P parameters : a pointer To ( PIN_CONFIG ) struct and The Pin Output Signal Type		                      */
/*  Returning	: Returns Nothing                                           									  */
/*  Description :       This Function Write The Output Signal Type For a spacific Pin				              */
/******************************************************************************************************************/
void 	MGPIO_voidPinWRITE(  PIN_CONFIG* copy_PinConfiguration , OUTPUT_SIGNAL_TYPE copy_PinType )
{
	/* Define a Struct Point To The GPIO-Peripheral's Registers                                                   */
	GPIO_TYPE *PORT   =  (GPIO_TYPE *)(copy_PinConfiguration->port) ;
	/* Define The Type Of The Output Signal From The Pin                                                          */
	switch(copy_PinType)
	{
		case HIGH : 
			(PORT) -> BSRRL = ( 1 << copy_PinConfiguration->pin );
			//SET_BIT((PORT) -> ODR , (copy_PinConfiguration->pin));
			break;               		
		
		case LOW : 
			(PORT) -> BSRRH = ( 1 << copy_PinConfiguration->pin );
			//CLR_BIT((PORT) -> ODR , (copy_PinConfiguration->pin));
			break;               		

		case TOGG :
			(PORT) -> ODR ^=  (1 << (copy_PinConfiguration->pin));
			break;
		
	}
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/*  Function : MGPIO_voidALTFuncTYPE			                                								  */
/*  I/P parameters : 1- a pointer To ( PIN_CONFIG ) struct and The Pin Alternate Function Type.		              */
/*					 2- the type of the Alternate Function that will be operated.							      */
/*  Returning	   : Returns Nothing.                                           					 			  */
/*  Description    :       This Function Define The Alternate Function Type For The Pin 						  */
/******************************************************************************************************************/
void     MGPIO_voidALTFuncTYPE( PIN_CONFIG* copy_PinConfiguration , AFR_TYPE copy_AlternateFunction )
{
	/* Define a Struct Point To The GPIO-Peripheral's Registers                                                   */
	GPIO_TYPE *PORT   =  (GPIO_TYPE *)(copy_PinConfiguration->port) ;
	/* Define The Type Of The Alternate Function of The Pin                                                       */
	if(copy_PinConfiguration->pin < 8) 
	{
		(PORT) -> AFRL &= ~( 0b1111 << (copy_PinConfiguration->pin*4) );
		(PORT) -> AFRL |=  ( copy_AlternateFunction << (copy_PinConfiguration->pin*4) );            		
	}
	else
	{
		(PORT) -> AFRH &= ~( 0b1111 << (((copy_PinConfiguration->pin) -8 ) *4));
		(PORT) -> AFRH |=  ( copy_AlternateFunction << (((copy_PinConfiguration->pin) -8 ) *4));
	}             		  
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/*  Function : MGPIO_u8INPUTREAD			                                									  */
/*  I/P parameters : a pointer To ( PIN_CONFIG ) struct 									                      */
/* 	Returning	: Returns The Signal On The Pin                                          						  */
/* 	Description :       This Function Read the Signal On The Input Pin   									 	  */
/******************************************************************************************************************/
u8        MGPIO_u8INPUTREAD( PIN_CONFIG* copy_PinConfiguration  )
{
	/* Define a Struct Point To The GPIO-Peripheral's Registers                                                   */
	GPIO_TYPE *PORT   =  (GPIO_TYPE *)(copy_PinConfiguration->port) ;
	if(!GET_BIT( (PORT) -> IDR ,copy_PinConfiguration->pin ))
	{
		return LOW ;
	}
	else
	{
		return HIGH ;
	}
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/*  Function : MGPIO_voidLOCKPORT			                                									  */
/*  I/P parameters : Takes Nothing                                         										  */
/*  Returning	: Returns Nothing                                           									  */
/*  Description :       This Function Initializes the EXTI Peripheral 											  */
/******************************************************************************************************************/
void      MGPIO_voidLOCKPORT()
{}