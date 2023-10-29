#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "RCC_config.h"
#include "RCC_private.h"
#include "RCC_interface.h"


/********************************************************************************************/
/*  Function : MRCC_VoidSysClkInit		                                					*/
/*  I/P parameters : Takes Nothing                                         					*/
/*  Returnning : Returns Nothing                                           					*/
/*  Discribtion : This Function Initializes the System Clock 			   					*/
/********************************************************************************************/
void	MRCC_VoidSysClkInit(void)
{
/********************************************************************************************/
/* 									External Clock HSE Bypass 								*/

	#if    Bypass_Condition == Bypass_OFF
			CLR_BIT( (RCC->CR) , 18 );   // Disable Bypass Oscillator

	#elif  Bypass_Condition == Bypass_ON		
			SET_BIT(RCC->CR,18);		 // Enable Bypass Oscillator
	#endif
/*********************************************************************************************/

/********************************************************************************************/
/* 											CSS Mode  										*/
	#if    CSS_Condition == CSS_OFF
			CLR_BIT((RCC -> CR),19);    // Disable CSS MODE

	#elif  CSS_Condition == CSS_ON			
			SET_BIT((RCC -> CR),19);	// Enable CSS MODE
	#endif
/*********************************************************************************************/

/*********************************************************************************************/
/*                           RCC PLL configuration register (RCC_PLLCFGR)      			     */
	
	// Set the (M) parameter into the (PLLCFGR) register  */
	RCC -> PLLCFGR |= PLL_M ;   

	// Set the (N) parameter into the (PLLCFGR) register  */        
	RCC -> PLLCFGR |= ( PLL_N << 6  ) ;

	// Set the (P) parameter into the (PLLCFGR) register  */
	RCC -> PLLCFGR |= ( PLL_P << 16 ) ;

	// Set the (Q) parameter into the (PLLCFGR) register  */
	RCC -> PLLCFGR |= ( PLL_Q << 24 ) ;

	#if    PLL_SOURCE 		== 		HSI
			/* Enable HSI */
			SET_BIT( RCC -> CR , 0 );    
			/* HSI is the input of the PLL */ 
			CLR_BIT(RCC->PLLCFGR,22);  	  

	#elif  PLL_SOURCE 		== 		HSE	
			/* Enable HSE */
			SET_BIT( RCC -> CR , 16 );     
			/* HSE is the input of the PLL */
			SET_BIT(RCC->PLLCFGR,22);  	   

	#endif
/*********************************************************************************************/

/*********************************************************************************************/
/*                                    System Clock Sorce                               	     */
	#if    System_Clock_Sorce 		== 		HSI
			/* Enable HSI */
			SET_BIT( RCC -> CR , 0 );     
			/* configure the (SW-bits) at (CFGR) to Choose the HSI as The Syslem Clock Source */
			RCC -> CFGR |=  (0b00);		  

	#elif  System_Clock_Sorce 		== 		HSE	
			/* Enable HSE */
			SET_BIT( RCC -> CR , 16 );     
			/* configure the (SW-bits) at (CFGR) to Choose the HSE as The Syslem Clock Source */
			RCC -> CFGR |=  (0b01);		   

	#elif  System_Clock_Sorce 		== 		PLL		
			/* Enable PLL */
			SET_BIT( RCC -> CR , 24 );
			/* configure the (SW-bits) at (CFGR) to Choose the PLL as The Syslem Clock Source */
			RCC -> CFGR |=  (0b10);        

	#endif
/*********************************************************************************************/
}
/********************************************************************************************/



/********************************************************************************************/
/*  Function : MRCC_VoidEnablePerClk		                                				*/
/*  I/P parameters : Takes The Bus and the Peripheral IDs                                   */
/*  Returning : Returns Nothing                                           					*/
/*  Discribtion : This Function Enable The Peripheral clock 			   					*/
/********************************************************************************************/
void	MRCC_VoidEnablePerClk( volatile u8 copy_u8PeripheralID )
{
	/*		Range Check			*/
	if( copy_u8PeripheralID < 32								  )
	 {SET_BIT(RCC -> AHB1ENR , ( copy_u8PeripheralID      ) );    }
	else if( 32 <= copy_u8PeripheralID && copy_u8PeripheralID < 62 )
	 {SET_BIT(RCC -> AHB2ENR , ( copy_u8PeripheralID - 32 ) );    }
	else if( 64 <= copy_u8PeripheralID && copy_u8PeripheralID < 96 )
	 {SET_BIT(RCC -> APB1ENR , ( copy_u8PeripheralID - 64 ) );    }
	else if( 96 <= copy_u8PeripheralID     						  ) 
	 {SET_BIT(RCC -> APB2ENR , ( copy_u8PeripheralID - 96 ) );    }
	
}
/********************************************************************************************/


/********************************************************************************************/
/*  Function : MRCC_VoidDisablePerClk	                                					*/
/*  I/P parameters : Takes The Bus and the Peripheral IDs                					*/
/*  Returning : Returns Nothing                                           					*/
/*  Discribtion : This Function Disable The Peripheral clock 		   						*/
/********************************************************************************************/
void	MRCC_VoidDisablePerClk( volatile u8 copy_u8PeripheralID )
{
	/*		Range Check			*/
	if( copy_u8PeripheralID < 32 								  )
	 {CLR_BIT( RCC -> AHB1ENR , ( copy_u8PeripheralID      ) ) ;  }
	else if( 32 <= copy_u8PeripheralID && copy_u8PeripheralID < 62 )
	 {CLR_BIT( RCC -> AHB2ENR , ( copy_u8PeripheralID - 32 ) ) ;  }
	else if( 64 <= copy_u8PeripheralID && copy_u8PeripheralID < 96 )
	 {CLR_BIT( RCC -> APB1ENR , ( copy_u8PeripheralID - 64 ) ) ;  }
	else if( 96 <= copy_u8PeripheralID      						  ) 
	 {CLR_BIT( RCC -> APB2ENR , ( copy_u8PeripheralID - 96 ) ) ;  }
	
}
/********************************************************************************************/


/********************************************************************************************/
/*  Function : MRCC_VoidLPEnablePerClk		                                				*/
/*  I/P parameters : Takes The Bus and the Peripheral IDs                                   */
/*  Returning : Returns Nothing                                           					*/
/*  Discribtion : This Function Enable The Peripheral clock in low power mode				*/
/********************************************************************************************/
void	MRCC_VoidLPEnablePerClk( volatile u8 copy_u8PeripheralID )
{
	/*		Range Check			*/
	if( copy_u8PeripheralID < 32 							      )
	 {SET_BIT(RCC -> AHB1LPENR , ( copy_u8PeripheralID      ) );  }
	else if( 32 <= copy_u8PeripheralID && copy_u8PeripheralID < 62 )
	 {SET_BIT(RCC -> AHB2LPENR , ( copy_u8PeripheralID - 32 ) );  }
	else if( 64 <= copy_u8PeripheralID && copy_u8PeripheralID < 96 )
	 {SET_BIT(RCC -> APB1LPENR , ( copy_u8PeripheralID - 64 ) );  }
	else if( 96 <= copy_u8PeripheralID                             ) 
	 {SET_BIT(RCC -> APB2LPENR , ( copy_u8PeripheralID - 96 ) );  }
}
/********************************************************************************************/


/********************************************************************************************/
/*  Function : MRCC_VoidLPDisablePerClk	                                					*/
/*  I/P parameters : Takes The Bus and the Peripheral IDs                					*/
/*  Returning : Returns Nothing                                           					*/
/*  Discribtion : This Function Disable The Peripheral clock in low power mode				*/
/********************************************************************************************/
void	MRCC_VoidLPDisablePerClk( volatile u8 copy_u8PeripheralID )
{
	/*		Range Check			*/
	if( copy_u8PeripheralID < 32								  )
	 {CLR_BIT( RCC -> AHB1LPENR , ( copy_u8PeripheralID      ) ); }
	else if( 32 <= copy_u8PeripheralID && copy_u8PeripheralID < 62 )
	 {CLR_BIT( RCC -> AHB2LPENR , ( copy_u8PeripheralID - 32 ) ); }
	else if( 64 <= copy_u8PeripheralID && copy_u8PeripheralID < 96 )
	 {CLR_BIT( RCC -> APB1LPENR , ( copy_u8PeripheralID - 64 ) ); }
	else if( 96 <= copy_u8PeripheralID      						  ) 
	 {CLR_BIT( RCC -> APB2LPENR , ( copy_u8PeripheralID - 96 ) ); }
}
/********************************************************************************************/


/********************************************************************************************/
/*  Function : MRCC_VoidPerReset  	        	                        					*/
/*  I/P parameters : Takes The Bus and the Peripheral IDs                					*/
/*  Returning : Returns Nothing                                           					*/
/*  Discribtion : This Function Reset The Peripheral 				   						*/
/********************************************************************************************/
void	MRCC_VoidPerReset( volatile u8 copy_u8PeripheralID )
{
	/*		Range Check			*/ 
	if(  copy_u8PeripheralID < 32 									)
		{SET_BIT( RCC -> AHB1RSTR , ( copy_u8PeripheralID      ) ); }
	else if( 32 <= copy_u8PeripheralID && copy_u8PeripheralID < 62   )
		{SET_BIT( RCC -> AHB2RSTR , ( copy_u8PeripheralID - 32 ) ); }
	else if( 64 <= copy_u8PeripheralID && copy_u8PeripheralID < 96   )
		{SET_BIT( RCC -> APB1RSTR , ( copy_u8PeripheralID - 64 ) ); }
	else if( 96 <= copy_u8PeripheralID     						    )
		{SET_BIT( RCC -> APB2RSTR , ( copy_u8PeripheralID - 96 ) ); }
}
/********************************************************************************************/



void	MRCC_VoidMCO1sorce(u8 copy_u8AMCO1sorce);  // not yet 
void	MRCC_VoidMCO1prescaler(u8 copy_u8MCO1prescaler);  // not yet 

void	MRCC_VoidMCO2sorce(u8 copy_u8AMCO2sorce);  // not yet 
void	MRCC_VoidMCO2prescaler(u8 copy_u8MCO2prescaler);  // not yet 


/********************************************************************************************/
/*  Function : MRCC_VoidAHBprescaler		                                				*/
/*  I/P parameters : Takes the Prescaler value                             					*/
/*  Returnning : Returns Nothing                                           					*/
/*  Discribtion : This Function Changes the prescaler of the System Clock (AHB)		   		*/
/********************************************************************************************/
void	MRCC_VoidAHBprescaler(u32 copy_u8AHBprescaler)
{
	switch(copy_u8AHBprescaler)
	{
		case 2   	: 		{ RCC -> CFGR |= 0x00000080 ; break; }
		case 4   	: 		{ RCC -> CFGR |= 0x00000090 ; break; }
		case 8   	: 		{ RCC -> CFGR |= 0x000000A0 ; break; }
		case 16  	:	  	{ RCC -> CFGR |= 0x000000B0 ; break; }
		case 64  	:		{ RCC -> CFGR |= 0x000000C0 ; break; }
		case 128 	: 		{ RCC -> CFGR |= 0x000000D0 ; break; }
		case 256 	: 		{ RCC -> CFGR |= 0x000000E0 ; break; }
		case 512 	: 		{ RCC -> CFGR |= 0x000000F0 ; break; }

	};
}
/********************************************************************************************/


/********************************************************************************************/
/*  Function : MRCC_VoidAPB2prescaler		                                				*/
/*  I/P parameters : Takes the Prescaler value                             					*/
/*  Returnning : Returns Nothing                                           					*/
/*  Discribtion : This Function Changes the prescaler of the (APB1)	High speed		   		*/
/********************************************************************************************/
void	MRCC_VoidAPB2prescaler(u8 copy_u8APB2prescaler)
{
	switch(copy_u8APB2prescaler)
	{
		case Not_Divided   	: 		{ RCC -> CFGR |= (0b011 << 13 ) ; break; }
		case 2   			: 		{ RCC -> CFGR |= (0b100 << 13 ) ; break; }
		case 4   			: 		{ RCC -> CFGR |= (0b101 << 13 ) ; break; }
		case 8   			: 		{ RCC -> CFGR |= (0b110 << 13 ) ; break; }
		case 16  			:	  	{ RCC -> CFGR |= (0b111 << 13 ) ; break; }
	};
}
/********************************************************************************************/


/********************************************************************************************/
/*  Function : MRCC_VoidAPB1prescaler		                                				*/
/*  I/P parameters : Takes the Prescaler value                             					*/
/*  Returnning : Returns Nothing                                           					*/
/*  Discribtion : This Function Changes the prescaler of the (APB1)	Low speed		   		*/
/********************************************************************************************/
void	MRCC_VoidAPB1prescaler(u8 copy_u8APB1prescaler)
{
	switch(copy_u8APB1prescaler)
	{
		case Not_Divided   	: 		{ RCC -> CFGR |= (0b011 << 10 ) ; break; }
		case 2   			: 		{ RCC -> CFGR |= (0b100 << 10 ) ; break; }
		case 4   			: 		{ RCC -> CFGR |= (0b101 << 10 ) ; break; }
		case 8   			: 		{ RCC -> CFGR |= (0b110 << 10 ) ; break; }
		case 16  			:	  	{ RCC -> CFGR |= (0b111 << 10 ) ; break; }
	};
}
/********************************************************************************************/

void	MRCC_VoidRTCprescaler(u8 copy_u8ARTCprescaler);  // not yet 