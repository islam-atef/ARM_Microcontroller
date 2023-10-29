#ifndef		LCD_INTERFACE_H
#define		LCD_INTERFACE_H

////////////////////////////////////////////////////////////////////////////////////////
                                   /* COMMAND CODE */

#define CLEAR_DISPALY      			0x01
#define RETURN_HOME        			0x02
#define DECREMENT_CURSOR  			0x04
#define INCREMENT_CURSOR 		 	0x05
#define SHIFT_DISPLAY_LEFT 			0x05
#define SHIFT_DISPLAY_RIGHT 		0x07
#define DISPAY_OFF_CURSOR_OFF 		0x08 /* clearing Display without clearing DDRAM content */
#define DISPAY_OFF_CURSOR_ON 		0x0A
#define DISPAY_ON_CURSOR_OFF 		0x0C
#define DISPAY_ON_CURSOR_ON 		0x0E
#define DISPAY_ON_CURSOR_BLINK      0x0F
#define SHIFT_CURSOR_POSITION_LEFT  0x10
#define SHIFT_CURSOR_POSITION_RIGHT 0x14
#define SHIFT_ENTIRE_DISPLAY_LEFT   0x18
#define SHIFT_ENTIRE_DISPLAY_RIGHT  0x1C
#define FORCE_CURSOR_1_LINE 		0x80
#define FORCE_CURSOR_2_LINE 		0xC0

                                   /* MODE COMMAND CODE */

#define _8_BIT 						0x38
#define _4_BIT 						0x28

////////////////////////////////////////////////////////////////////////////////////////

void LCD_init(u8 mode);
void LCD_COMMAND(u8 command);
void LCD_WRITE(u8 Data);
void LCD_WRITE_STRING(u8 *Data);

#endif