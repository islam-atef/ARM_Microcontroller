#include "LIB/BIT_MATH.h"
#include "LIB/STD_Types.h"

#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

/************************************************************************************************************/
/*  Function : MNVICL_voidEnablePeripheral
 */
/*  I/P parameters : interrupt ID
 */
/*  Returning : Returns Nothing
 */
/*  Description : This Function Enable the INT of the Peripheral on NVIC
 */
/************************************************************************************************************/
void MNVIC_voidEnablePeripheral(u8 copy_U8INTID) {
  LMNVIC->ISER[copy_U8INTID / 32] = 1 << (copy_U8INTID % 32);
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MNVICL_voidDisablePeripheral
 */
/*  I/P parameters : interrupt ID
 */
/*  Returning : Returns Nothing
 */
/*  Description : This Function Disable the INT of the Peripheral on NVIC
 */
/************************************************************************************************************/
void MNVIC_voidDisablePeripheral(u8 copy_U8INTID) {
  LMNVIC->ICER[copy_U8INTID / 32] = 1 << (copy_U8INTID % 32);
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MNVIC_voidSetPending
 */
/*  I/P parameters : interrupt ID
 */
/*  Returning : Returns Nothing
 */
/*  Description : This Function Set the Pending Flag of the INT on NVIC
 */
/************************************************************************************************************/
void MNVIC_voidSetPending(u8 copy_U8INTID) {
  LMNVIC->ISPR[copy_U8INTID / 32] = 1 << (copy_U8INTID % 32);
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MNVIC_voidClearPending
 */
/*  I/P parameters : interrupt ID
 */
/*  Returning : Returns Nothing
 */
/*  Description : This Function Clear the Pending Flag of the INT on NVIC
 */
/************************************************************************************************************/
void MNVIC_voidClearPending(u8 copy_U8INTID) {
  LMNVIC->ICPR[copy_U8INTID / 32] = 1 << (copy_U8INTID % 32);
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MNVIC_u8GetActive
 */
/*  I/P parameters : interrupt ID
 */
/*  Returning : Returns the Value of The Active Flag of The INT
 */
/*  Description : This Function Read the Vale Of Active Flag Of the INT
 */
/************************************************************************************************************/
u8 MNVIC_u8GetActive(u8 copy_U8INTID) {
  if (LMNVIC->IABR[copy_U8INTID / 32] & (1 << (copy_U8INTID % 32)))
    return 1;
  else
    return 0;
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MNVIC_voidGroupConfig
 */
/*  I/P parameters : Takes No Parameters
 */
/*  Returning : Returns Nothing
 */
/*  Description : This Function Set the Ratio Between Groups and Subgroups in
 * AIRCR Register an SCB Peri    */
/************************************************************************************************************/
void MNVIC_voidGroupConfig(void) {
  MSCB->AIRCR = VECTKEY | (Group_to_Subgroup_Ratio << 8);
}
/************************************************************************************************************/

/************************************************************************************************************/
/*  Function : MNVIC_voidSetINTPriority
 */
/*  I/P parameters : interrupt ID
 */
/*  Returning : Returns Nothing
 */
/*  Description : This Function Set the Priority of the INT
 */
/************************************************************************************************************/
void MNVIC_voidSetINTPriority(s8 copy_S8INTID, u8 copy_U8GroupNUM,
                              u8 copy_U8SubgroupNUM) {
  u8 Group_Subgroup_Vale =
      (((copy_U8GroupNUM << (Group_to_Subgroup_Ratio - 3)) |
        (copy_U8SubgroupNUM))
       << (4));
  if (copy_S8INTID < 0) {
    switch (copy_S8INTID) {
    case NVIC_MemManage:
      /* Clear The Four Bits The Write On Them */
      MSCB->SHPR1 &= ~(0b11 << ((copy_S8INTID + 6) * 8));
      MSCB->SHPR1 |= (Group_Subgroup_Vale << ((copy_S8INTID + 6) * 8));
      break;
    case NVIC_BusFault:
      /* Clear The Four Bits The Write On Them */
      MSCB->SHPR1 &= ~(0b11 << ((copy_S8INTID + 6) * 8));
      MSCB->SHPR1 |= (Group_Subgroup_Vale << ((copy_S8INTID + 6) * 8));
      break;
    case NVIC_UsageFault:
      /* Clear The Four Bits The Write On Them */
      MSCB->SHPR1 &= ~(0b11 << ((copy_S8INTID + 6) * 8));
      MSCB->SHPR1 |= (Group_Subgroup_Vale << ((copy_S8INTID + 6) * 8));
      break;
    case NVIC_SVCall:
      /* Clear The Four Bits The Write On Them */
      MSCB->SHPR2 &= ~(0b11 << ((copy_S8INTID + 6) * 8));
      MSCB->SHPR2 |= (Group_Subgroup_Vale << ((copy_S8INTID + 6) * 8));
      break;
    case NVIC_PendSV:
      /* Clear The Four Bits The Write On Them */
      MSCB->SHPR3 &= ~(0b11 << ((copy_S8INTID + 4) * 8));
      MSCB->SHPR3 |= (Group_Subgroup_Vale << ((copy_S8INTID + 4) * 8));
      break;
    case NVIC_Systick:
      /* Clear The Four Bits The Write On Them */
      MSCB->SHPR3 &= ~(0b11 << ((copy_S8INTID + 4) * 8));
      MSCB->SHPR3 |= (Group_Subgroup_Vale << ((copy_S8INTID + 4) * 8));
      break;
    }
  } else {
    /* Write Directly on the Four Bits */
    LMNVIC->IPR[copy_S8INTID] = Group_Subgroup_Vale;
  }
}
/************************************************************************************************************/