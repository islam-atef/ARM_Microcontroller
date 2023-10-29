#include    "../LIB/STD_Types.h"
#include    "../LIB/BIT_MATH.h"

#include    "../LMCAL/01_STK/STK_interface.h"

#include	"RTOS_interface.h"
#include	"RTOS_private.h"
#include	"RTOS_config.h"
/************************************************************************************************************************/
void	RTOS_Schduler(void);
/************************************************************************************************************************/
/*              The Tasks Array That Includes The Task's Handler , The First_Delay and The Task's Periodicity   		*/
TASK Task_Array[TaskNum]                ;
/*                                      The Tasks Array That Acts as The Timer For each Task   	                    	*/
u8   Task_Timer_Array[TaskNum]          ;
/*                        The Tasks Array That Acts as The Timer at Sleep Mode For each Task   	                    	*/
u8   Task_Sleep_Timer_Array[TaskNum]    ;
/*                                                          Null Struct  	                                        	*/
TASK   Null_Task                        = {0} ;
/************************************************************************************************************************/


/************************************************************************************************************************/
/*  Function        : RTOS_StartOS	 		                                   						                    */
/*  I/P parameters  : Takes Nothings                                          								            */
/*  Returnning      : Returns Nothings								           									        */
/*  Discribtion     : 			 				*/
/************************************************************************************************************************/
void	RTOS_StartOS(void)
{
    MSTK_voidSetIntervalPeriodic( TICK_TIME , RTOS_Schduler );
}
/************************************************************************************************************************/
/************************************************************************************************************************/
/*  Function        : RTOS_CreateTask                                         								            */
/*  I/P parameters  : Takes Task Priority , First_Delay , Task_Function , and Task Periodicity    			            */
/*  Returnning      : Returns Error State						           									            */
/*  Discribtion     : This Function Enters a new Task in the Task_Array and Define all Its Parameters                   */
/*                                            according To The Priority Of the Task                                     */
/************************************************************************************************************************/
u8	    RTOS_CreateTask( void (*Copy_ptr)(void) , u8 copy_TaskPriority , u8 copy_TaskPeriodicity , u8 copy_FirstDelay )
{
    u8 Local_Error_state = 0 ;
    if (copy_TaskPriority < TaskNum)
    {
        if (Task_Array[copy_TaskPriority].Copy_ptr == 0)
        {
/*                 There is No Error Exixting                                                                           */
            Local_Error_state = 0 ;

            Task_Array[copy_TaskPriority].Copy_ptr      = Copy_ptr               ;
            Task_Array[copy_TaskPriority].First_Delay   = copy_FirstDelay        ;
            Task_Array[copy_TaskPriority].Periodicity   = copy_TaskPeriodicity   ;
/*                  We initialize the Task_timer For the First Time to Equal The First_Delay                            */
            Task_Timer_Array[copy_TaskPriority]         = copy_FirstDelay        ;
/*                  We initialize the Task_State For the First Time to be Running                                       */
            Task_Array[copy_TaskPriority].Task_State    = Running                ;
        }
        else
        {
/*                 the Error Code For The Existing index                                                                */
            Local_Error_state = 1 ;
        }
    }
    else
    {
/*                 the Error Code For The Out Range index                                                               */
            Local_Error_state = 2 ;
    }
    return Local_Error_state;
}
/************************************************************************************************************************/


/************************************************************************************************************************/
/*  Function        : RTOS_DeleteTask       	                                   						                */
/*  I/P parameters  : Takes Task Index                                                                                  */
/*  Returnning      : Returns Error State       								         					            */
/*  Discribtion     : This Function Takes The Task Index and Remove It From the Task_Array and Clear Its Timer          */
/************************************************************************************************************************/
u8	    RTOS_DeleteTask( u8 copy_TaskIndex )
{
    u8 Local_Error_state = 0 ;
    if (copy_TaskIndex < TaskNum)
    {
        if (Task_Array[copy_TaskIndex].Copy_ptr != 0)
        {
/*                 There is No Error Exixting                                                                           */
            Local_Error_state = 0 ;
/*                  We initialize the Task_timer For the First Time to Equal The First_Delay                            */
            Task_Timer_Array[copy_TaskIndex]  = 0           ;
/*                  We initialize the Task_State For the First Time to be Running                                       */
            Task_Array[copy_TaskIndex]        = Null_Task   ;
        }
        else
        {
/*                 the Error Code For The Non Existing index                                                            */
            Local_Error_state = 1 ;
        }
    }
    else
    {
/*                 the Error Code For The Out Range index                                                               */
            Local_Error_state = 2 ;
    }
    return Local_Error_state;
}
/************************************************************************************************************************/


/************************************************************************************************************************/
/*  Function        : RTOS_SuspendTask		                                   				        		            */
/*  I/P parameters  : Takes Task Index                                                                                  */
/*  Returnning      : Returns Error State								         							            */
/*  Discribtion     :           		*/
/************************************************************************************************************************/
u8	    RTOS_SuspendTask( u8 copy_TaskIndex )
{
     u8 Local_Error_state = 0 ;
    if (copy_TaskIndex < TaskNum)
    {
        if (Task_Array[copy_TaskIndex].Copy_ptr != 0)
        {
/*                 There is No Error Exixting                                                                           */
            Local_Error_state = 0 ;
/*                  We initialize the Task_timer For the First Time to Equal The Periodicity                            */
            Task_Timer_Array[copy_TaskIndex]       = Task_Array[copy_TaskIndex].Periodicity     ;
/*                  We initialize the Task_State For the First Time to be Running                                       */
            Task_Array[copy_TaskIndex].Task_State  = Suspend   ;
        }
        else
        {
/*                 the Error Code For The Non Existing index                                                            */
            Local_Error_state = 1 ;
        }
    }
    else
    {
/*                 the Error Code For The Out Range index                                                               */
            Local_Error_state = 2 ;
    }
    return Local_Error_state;
}
/************************************************************************************************************************/


/************************************************************************************************************************/
/*  Function        : RTOS_ResumeTask                                   									            */
/*  I/P parameters  : Takes Task Index                                         								            */
/*  Returnning      : Returns Error State							           								            */
/*  Discribtion     :				*/
/************************************************************************************************************************/
u8	    RTOS_ResumeTask( u8 copy_TaskIndex )
{
     u8 Local_Error_state = 0 ;
   if (copy_TaskIndex < TaskNum)
    {
        if (Task_Array[copy_TaskIndex].Copy_ptr != 0)
        {
/*                 There is No Error Exixting                                                                           */
            Local_Error_state = 0 ;
/*                  We initialize the Task_State For the First Time to be Running                                       */
            Task_Array[copy_TaskIndex].Task_State  = Running                                    ;
        }
        else
        {
/*                 the Error Code For The Non Existing index                                                            */
            Local_Error_state = 1 ;
        }
    }
    else
    {
/*                 the Error Code For The Out Range index                                                               */
            Local_Error_state = 2 ;
    }
    return Local_Error_state;
}
/************************************************************************************************************************/


/************************************************************************************************************************/
/*  Function        : RTOS_FreezeTask                                   									            */
/*  I/P parameters  : Takes Task Index                                         								            */
/*  Returnning      : Returns Error State							           								            */
/*  Discribtion     :				*/
/************************************************************************************************************************/
u8	    RTOS_FreezeTask( u8 copy_TaskIndex )
{
     u8 Local_Error_state = 0 ;
   if (copy_TaskIndex < TaskNum)
    {
        if (Task_Array[copy_TaskIndex].Copy_ptr != 0)
        {
/*                 There is No Error Exixting                                                                           */
            Local_Error_state = 0 ;
/*                  We initialize the Task_State For the First Time to be Running                                       */
            Task_Array[copy_TaskIndex].Task_State  = Suspend                                    ;
        }
        else
        {
/*                 the Error Code For The Non Existing index                                                            */
            Local_Error_state = 1 ;
        }
    }
    else
    {
/*                 the Error Code For The Out Range index                                                               */
            Local_Error_state = 2 ;
    }
    return Local_Error_state;
}
/************************************************************************************************************************/


/************************************************************************************************************************/
/*  Function        : RTOS_SleepTask                                   									                */
/*  I/P parameters  : Takes Task Index and The number of Ticks that Shoud pass During Sleeping  					    */
/*  Returnning      : Returns Error State							           								            */
/*  Discribtion     :				*/
/************************************************************************************************************************/
u8	    RTOS_SleepTask( u8 copy_TaskIndex , u8 copy_TickNum )
{
     u8 Local_Error_state = 0 ;
   if (copy_TaskIndex < TaskNum)
    {
        if (Task_Array[copy_TaskIndex].Copy_ptr != 0)
        {
/*                 There is No Error Exixting                                                                           */
            Local_Error_state = 0 ;
/*                  We initialize the Task_State For the First Time to be Sleep                                         */
            Task_Array[copy_TaskIndex].Task_State   = Sleep                                    ;
            Task_Sleep_Timer_Array[copy_TaskIndex]  = copy_TickNum                             ;
        }
        else
        {
/*                 the Error Code For The Non Existing index                                                            */
            Local_Error_state = 1                                                              ;
        }
    }
    else
    {
/*                 the Error Code For The Out Range index                                                               */
            Local_Error_state = 2 ;
    }
    return Local_Error_state;
}
/************************************************************************************************************************/

/************************************************************************************************************************/
/*  Function        : RTOS_ResumeTask                                   									            */
/*  I/P parameters  : Takes Task Index                                         								            */
/*  Returnning      : Returns Error State							           								            */
/*  Discribtion     :				*/
/************************************************************************************************************************/
void	RTOS_Schduler(void)
{	u8 LOCAL_COUNTER          ;
 
    for (LOCAL_COUNTER = 0; LOCAL_COUNTER < TaskNum ; LOCAL_COUNTER++)
    {
        if (Task_Array[LOCAL_COUNTER].Copy_ptr != 0)
        {
           switch (Task_Array[LOCAL_COUNTER].Task_State)
           {
            case Running:

                if (Task_Timer_Array[LOCAL_COUNTER] == 0)
                {
/*                                  Run The Task Function                                                               */
                    Task_Array[LOCAL_COUNTER].Copy_ptr()                                    ;
/*                                  Run The Task Function                                                               */
                    Task_Timer_Array[LOCAL_COUNTER] = Task_Array[LOCAL_COUNTER].Periodicity ;
                }
                else
                {
                    Task_Timer_Array[LOCAL_COUNTER]--                                       ;
                }
                break;

            case Sleep:
        
                if (Task_Sleep_Timer_Array[LOCAL_COUNTER] == 0)
                {
/*                                  Run The Task Function                                                               */
                    Task_Array[LOCAL_COUNTER].Copy_ptr()                                    ;
/*                                  Run The Task Function                                                               */
                    Task_Timer_Array[LOCAL_COUNTER] = Task_Array[LOCAL_COUNTER].Periodicity ;
                }
                else
                {
                    Task_Sleep_Timer_Array[LOCAL_COUNTER]--                                 ;
                }
                break;

            case Suspend:

                break;   
           }
        }
    }
}
/************************************************************************************************************************/


