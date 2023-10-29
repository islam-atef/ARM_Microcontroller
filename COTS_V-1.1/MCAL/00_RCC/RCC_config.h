#ifndef		RCC_CONFIG_H
#define		RCC_CONFIG_H
/*****************************************************************************************************************************************/
/*             -------------------->     External Clock HSE Bypass Condition : { Bypass_ON } or { Bypass_OFF }                           */
/*             --------------------> Option (1) : 																					     */
#define 	Bypass_ON			0
/*             --------------------> Option (2) : 																						 */
#define 	Bypass_OFF			1
/*             --------------------> Answer :																						     */
#define     Bypass_Condition      Bypass_ON

/*****************************************************************************************************************************************/
/*             -------------------->            CSS Mode Condition : { CSS_ON or CSS_OFF }                                            	 */
/*             --------------------> Option (1) : 																						 */
#define 	CSS_ON			0
/*             --------------------> Option (2) : 																						 */
#define 	CSS_OFF			1
/*             --------------------> Answer : 																							 */
#define     CSS_Condition         CSS_ON

/*****************************************************************************************************************************************/
/*                                       RCC PLL configuration register (RCC_PLLCFGR)                                                    */
/**/
#define		PLL_M		         2      /*  ---->  PLL_M Value could : be between [ 2 : 63 ]                                     		 */
#define		PLL_N		         192    /*  ---->  PLL_N Value could : be between [ 192 : 432 ]                                  		 */
#define		PLL_P		         0b00   /*  ---->  PLL_O Value Could : be {2 = 0b00} or {4 = 0b01} or {6 = 0b10} or {8 = 0b11}   		 */
#define		PLL_Q		         2      /*  ---->  PLL_Q Value Could : be {2} or {3} or {4}                                      		 */
/*             --------------------> Option (1) : 																						 */
#define 	HSI			hsi
/*             --------------------> Option (2) : 																						 */
#define 	HSE			hse
/*             --------------------> Answer Could be  : { HSE } or { HSI }                                           		             */																					
#define		PLL_SOURCE           HSE    

/*****************************************************************************************************************************************/
/*                                                   System Clock Source                                                                 */
/*           -------------------->       there ate Three Options : {HSI} or {HSE} or {PLL}                                               */
/*                              We should Configure The PLL-Parameters If we will Choose One of the (Pll) sources                        */
/*             --------------------> Option (1) : 																						 */
#define 	HSI			hsi
/*             --------------------> Option (2) : 																						 */
#define 	HSE			hse
/*             --------------------> Option (3) :																						 */
#define 	PLL			pll
/*             --------------------> Answer :																							 */
#define		System_Clock_Sorce		    HSE

/*****************************************************************************************************************************************/
#endif
