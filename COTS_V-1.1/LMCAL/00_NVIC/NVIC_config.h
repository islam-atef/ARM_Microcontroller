#ifndef		NVIC_CONFIG_H
#define		NVIC_CONFIG_H

/**************************************************************************************/
/*             Groups and Subgroups Opitions  :                                       */
/*                                 Opition(1) : [16-0]  =  0b011                      */
/*                                 Opition(2) : [8-2]   =  0b100                      */
/*                                 Opition(3) : [4-4]   =  0b101                      */
/*                                 Opition(2) : [2-8]   =  0b110                      */
/*                                 Opition(4) : [0-16]  =  0b111    ( Defult Case )   */
/**************************************************************************************/
#define           Group_to_Subgroup_Ratio            (0b111)
/*   Then You Should Call The MSCB_VoidGroupRatio()  Function                          */
/**************************************************************************************/
			
#endif