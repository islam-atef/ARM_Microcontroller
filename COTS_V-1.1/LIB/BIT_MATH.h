/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define 	SET_BIT(VAR,BITNO) 		(VAR) |=  (1 << (BITNO))
#define 	CLR_BIT(VAR,BITNO)		(VAR) &= ~(1 << (BITNO))
#define 	TOG_BIT(VAR,BITNO) 		(VAR) ^=  (1 << (BITNO))
#define 	GET_BIT(VAR,BITNO) 		(((VAR) >> (BITNO)) & 0x01)

#define CONCATE(b7, b6, b5, b4, b3, b2, b1, b0)   (0b##b7##b6##b5##b4##b3##b2##b1##b0)

#define HELPER(b7, b6, b5, b4, b3, b2, b1, b0)    CONCATE(b7, b6, b5, b4, b3, b2, b1, b0)

#endif
