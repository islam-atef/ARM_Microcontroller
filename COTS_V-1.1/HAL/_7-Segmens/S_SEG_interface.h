/*         
              ----A----
	          -       -
	          -       -
	          -       -
	          -       -
	          F       B
	          -       -
	          -       -
	          -       -
	          -       -
	          ----G----
	          -       -
	          -       -
	          -       -
	          -       -
	          E       c
	          -       -
	          -       -
	          -       -
	          -       -
	          ----D----
*/
#ifndef		S_SEG_INTERFACE_H
#define		S_SEG_INTERFACE_H

////////////////////////////////////////////////

#define dot_C 10

///////////////////////////////////////////////

#define ON  0
#define OFF 1

///////////////////////////////////////////////

void  SSEG_Init();
			
void  SSEG_CONTROL( u8 state);
				
void  SSEG_SHOW(u8 SEVEN_SEGMENT_NUM );
					  


#endif
