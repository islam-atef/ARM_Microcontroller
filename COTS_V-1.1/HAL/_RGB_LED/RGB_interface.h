#ifndef		RGB_INTERFACE_H
#define		RGB_INTERFACE_H

/*   TYPE OF OPERATION */

#define BUTTON 0


/*   MODES OF OPERATION */

#define Blinking 0
#define ON_OFF 1




void  RGB_Init(u8 TYPE);
					  
void  RGB_Triggers_BU(u8 MODE);

void  RGB_Triggers_BI( u8 color_n );


					  


#endif
