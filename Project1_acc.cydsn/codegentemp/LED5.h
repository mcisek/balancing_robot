/*******************************************************************************
* File Name: LED5.h  
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

#if !defined(CY_PINS_LED5_H) /* Pins LED5_H */
#define CY_PINS_LED5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED5_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED5_Write(uint8 value) ;
void    LED5_SetDriveMode(uint8 mode) ;
uint8   LED5_ReadDataReg(void) ;
uint8   LED5_Read(void) ;
uint8   LED5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED5_DRIVE_MODE_BITS        (3)
#define LED5_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED5_DRIVE_MODE_BITS))

#define LED5_DM_ALG_HIZ         (0x00u)
#define LED5_DM_DIG_HIZ         (0x01u)
#define LED5_DM_RES_UP          (0x02u)
#define LED5_DM_RES_DWN         (0x03u)
#define LED5_DM_OD_LO           (0x04u)
#define LED5_DM_OD_HI           (0x05u)
#define LED5_DM_STRONG          (0x06u)
#define LED5_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED5_MASK               LED5__MASK
#define LED5_SHIFT              LED5__SHIFT
#define LED5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED5_PS                     (* (reg32 *) LED5__PS)
/* Port Configuration */
#define LED5_PC                     (* (reg32 *) LED5__PC)
/* Data Register */
#define LED5_DR                     (* (reg32 *) LED5__DR)
/* Input Buffer Disable Override */
#define LED5_INP_DIS                (* (reg32 *) LED5__PC2)


#if defined(LED5__INTSTAT)  /* Interrupt Registers */

    #define LED5_INTSTAT                (* (reg32 *) LED5__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED5_DRIVE_MODE_SHIFT       (0x00u)
#define LED5_DRIVE_MODE_MASK        (0x07u << LED5_DRIVE_MODE_SHIFT)


#endif /* End Pins LED5_H */


/* [] END OF FILE */
