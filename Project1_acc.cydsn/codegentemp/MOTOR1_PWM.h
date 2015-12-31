/*******************************************************************************
* File Name: MOTOR1_PWM.h  
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

#if !defined(CY_PINS_MOTOR1_PWM_H) /* Pins MOTOR1_PWM_H */
#define CY_PINS_MOTOR1_PWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "MOTOR1_PWM_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    MOTOR1_PWM_Write(uint8 value) ;
void    MOTOR1_PWM_SetDriveMode(uint8 mode) ;
uint8   MOTOR1_PWM_ReadDataReg(void) ;
uint8   MOTOR1_PWM_Read(void) ;
uint8   MOTOR1_PWM_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MOTOR1_PWM_DRIVE_MODE_BITS        (3)
#define MOTOR1_PWM_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - MOTOR1_PWM_DRIVE_MODE_BITS))

#define MOTOR1_PWM_DM_ALG_HIZ         (0x00u)
#define MOTOR1_PWM_DM_DIG_HIZ         (0x01u)
#define MOTOR1_PWM_DM_RES_UP          (0x02u)
#define MOTOR1_PWM_DM_RES_DWN         (0x03u)
#define MOTOR1_PWM_DM_OD_LO           (0x04u)
#define MOTOR1_PWM_DM_OD_HI           (0x05u)
#define MOTOR1_PWM_DM_STRONG          (0x06u)
#define MOTOR1_PWM_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define MOTOR1_PWM_MASK               MOTOR1_PWM__MASK
#define MOTOR1_PWM_SHIFT              MOTOR1_PWM__SHIFT
#define MOTOR1_PWM_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOTOR1_PWM_PS                     (* (reg32 *) MOTOR1_PWM__PS)
/* Port Configuration */
#define MOTOR1_PWM_PC                     (* (reg32 *) MOTOR1_PWM__PC)
/* Data Register */
#define MOTOR1_PWM_DR                     (* (reg32 *) MOTOR1_PWM__DR)
/* Input Buffer Disable Override */
#define MOTOR1_PWM_INP_DIS                (* (reg32 *) MOTOR1_PWM__PC2)


#if defined(MOTOR1_PWM__INTSTAT)  /* Interrupt Registers */

    #define MOTOR1_PWM_INTSTAT                (* (reg32 *) MOTOR1_PWM__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define MOTOR1_PWM_DRIVE_MODE_SHIFT       (0x00u)
#define MOTOR1_PWM_DRIVE_MODE_MASK        (0x07u << MOTOR1_PWM_DRIVE_MODE_SHIFT)


#endif /* End Pins MOTOR1_PWM_H */


/* [] END OF FILE */
