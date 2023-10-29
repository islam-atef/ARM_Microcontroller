#ifndef		RGB_CONFIG_H
#define		RGB_CONFIG_H

/////////////////////////////////////////////////////////////////////////////////////

/*   COLOR_NUMBER , You Should Connect Each Color With its Defined Port and Pin   */

#define  RED    1  // Port1_0 and Pin1_o
#define  GREEN  2  // Port2_0 and Pin2_o
#define  BLUE   3  // Port3_0 and Pin3_o

/////////////////////////////////////////////////////////////////////////////////////

                /* This Part Is Constant */

#define  OUTPUT_TYPE   OUTPUT_PP_PU
#define  INPUT_TYPE    INPUT_PU

/////////////////////////////////////////////////////////////////////////////////////
                /* This Part Is Configurable */ 
				
            	      /* Output Part */
				
#define  port1_O   B
#define  pin1_O    1

#define  port2_O   B
#define  pin2_O    1

#define  port3_O   B
#define  pin3_O    1
				   
	/* Use The Input  Part Just With BUTTON Type */

            	/* Input Part */	
/*                 

#define  port1_I   0
#define  bit1_I    0

#define  port2_I   0
#define  bit2_I    0

#define  port3_I   0
#define  bit3_I    0

*/

/////////////////////////////////////////////////////////////////////////////////////

#endif
