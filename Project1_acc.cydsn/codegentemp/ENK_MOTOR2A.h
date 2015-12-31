/*******************************************************************************
* File Name: ENK_MOTOR2A.h  
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

#if !defined(CY_PINS_ENK_MOTOR2A_H) /* Pins ENK_MOTOR2A_H */
#define CY_PINS_ENK_MOTOR2A_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ENK_MOTOR2A_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ENK_MOTOR2A_Write(uint8 value) ;
void    ENK_MOTOR2A_SetDriveMode(uint8 mode) ;
uint8   ENK_MOTOR2A_ReadDataReg(void) ;
uint8   ENK_MOTOR2A_Read(void) ;
uint8   ENK_MOTOR2A_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ENK_MOTOR2A_DRIVE_MODE_BITS        (3)
#define ENK_MOTOR2A_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ENK_MOTOR2A_DRIVE_MODE_BITS))

#define ENK_MOTOR2A_DM_ALG_HIZ         (0x00u)
#define ENK_MOTOR2A_DM_DIG_HIZ         (0x01u)
#define ENK_MOTOR2A_DM_RES_UP          (0x02u)
#define ENK_MOTOR2A_DM_RES_DWN         (0x03u)
#define ENK_MOTOR2A_DM_OD_LO           (0x04u)
#define ENK_MOTOR2A_DM_OD_HI           (0x05u)
#define ENK_MOTOR2A_DM_STRONG          (0x06u)
#define ENK_MOTOR2A_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define ENK_MOTOR2A_MASK               ENK_MOTOR2A__MASK
#define ENK_MOTOR2A_SHIFT              ENK_MOTOR2A__SHIFT
#define ENK_MOTOR2A_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ENK_MOTOR2A_PS                     (* (reg32 *) ENK_MOTOR2A__PS)
/* Port Configuration */
#define ENK_MOTOR2A_PC                     (* (reg32 *) ENK_MOTOR2A__PC)
/* Data Register */
#define ENK_MOTOR2A_DR                     (* (reg32 *) ENK_MOTOR2A__DR)
/* Input Buffer Disable Override */
#define ENK_MOTOR2A_INP_DIS                (* (reg32 *) ENK_MOTOR2A__PC2)


#if defined(ENK_MOTOR2A__INTSTAT)  /* Interrupt Registers */

    #define ENK_MOTOR2A_INTSTAT                (* (reg32 *) ENK_MOTOR2A__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define ENK_MOTOR2A_DRIVE_MODE_SHIFT       (0x00u)
#define ENK_MOTOR2A_DRIVE_MODE_MASK        (0x07u << ENK_MOTOR2A_DRIVE_MODE_SHIFT)


#endif /* End Pins ENK_MOTOR2A_H */


/* [] END OF FILE */
