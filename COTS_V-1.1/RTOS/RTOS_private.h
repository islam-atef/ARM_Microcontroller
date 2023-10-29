#ifndef		RTOS_PRIVATE_H
#define		RTOS_PRIVATE_H


/**************************************************************************************/

typedef enum 
{
	Suspend,
	Running,
	Sleep
}Task_State_OP ;

/**************************************************************************************/

typedef struct
{
	void	(*Copy_ptr)(void)	;
	u8		Periodicity			;
	u8		First_Delay			;
	u8		Task_State 			;
}TASK;

/**************************************************************************************/

#endif
