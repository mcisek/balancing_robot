/*******************************************************************************
* File Name: ENK_MOTOR2B.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ENK_MOTOR2B_H) /* Pins ENK_MOTOR2B_H */
#define CY_PINS_ENK_MOTOR2B_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ENK_MOTOR2B_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ENK_MOTOR2B_Write(uint8 value) ;
void    ENK_MOTOR2B_SetDriveMode(uint8 mode) ;
uint8   ENK_MOTOR2B_ReadDataReg(void) ;
uint8   ENK_MOTOR2B_Read(void) ;
uint8   ENK_MOTOR2B_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ENK_MOTOR2B_DRIVE_MODE_BITS        (3)
#define ENK_MOTOR2B_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ENK_MOTOR2B_DRIVE_MODE_BITS))

#define ENK_MOTOR2B_DM_ALG_HIZ         (0x00u)
#define ENK_MOTOR2B_DM_DIG_HIZ         (0x01u)
#define ENK_MOTOR2B_DM_RES_UP          (0x02u)
#define ENK_MOTOR2B_DM_RES_DWN         (0x03u)
#define ENK_MOTOR2B_DM_OD_LO           (0x04u)
#define ENK_MOTOR2B_DM_OD_HI           (0x05u)
#define ENK_MOTOR2B_DM_STRONG          (0x06u)
#define ENK_MOTOR2B_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define ENK_MOTOR2B_MASK               ENK_MOTOR2B__MASK
#define ENK_MOTOR2B_SHIFT              ENK_MOTOR2B__SHIFT
#define ENK_MOTOR2B_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ENK_MOTOR2B_PS                     (* (reg32 *) ENK_MOTOR2B__PS)
/* Port Configuration */
#define ENK_MOTOR2B_PC                     (* (reg32 *) ENK_MOTOR2B__PC)
/* Data Register */
#define ENK_MOTOR2B_DR                     (* (reg32 *) ENK_MOTOR2B__DR)
/* Input Buffer Disable Override */
#define ENK_MOTOR2B_INP_DIS                (* (reg32 *) ENK_MOTOR2B__PC2)


#if defined(ENK_MOTOR2B__INTSTAT)  /* Interrupt Registers */

    #define ENK_MOTOR2B_INTSTAT                (* (reg32 *) ENK_MOTOR2B__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define ENK_MOTOR2B_DRIVE_MODE_SHIFT       (0x00u)
#define ENK_MOTOR2B_DRIVE_MODE_MASK        (0x07u << ENK_MOTOR2B_DRIVE_MODE_SHIFT)


#endif /* End Pins ENK_MOTOR2B_H */


/* [] END OF FILE */
