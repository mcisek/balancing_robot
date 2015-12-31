/*******************************************************************************
* File Name: LED6.h  
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

#if !defined(CY_PINS_LED6_H) /* Pins LED6_H */
#define CY_PINS_LED6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED6_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED6_Write(uint8 value) ;
void    LED6_SetDriveMode(uint8 mode) ;
uint8   LED6_ReadDataReg(void) ;
uint8   LED6_Read(void) ;
uint8   LED6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED6_DRIVE_MODE_BITS        (3)
#define LED6_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED6_DRIVE_MODE_BITS))

#define LED6_DM_ALG_HIZ         (0x00u)
#define LED6_DM_DIG_HIZ         (0x01u)
#define LED6_DM_RES_UP          (0x02u)
#define LED6_DM_RES_DWN         (0x03u)
#define LED6_DM_OD_LO           (0x04u)
#define LED6_DM_OD_HI           (0x05u)
#define LED6_DM_STRONG          (0x06u)
#define LED6_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED6_MASK               LED6__MASK
#define LED6_SHIFT              LED6__SHIFT
#define LED6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED6_PS                     (* (reg32 *) LED6__PS)
/* Port Configuration */
#define LED6_PC                     (* (reg32 *) LED6__PC)
/* Data Register */
#define LED6_DR                     (* (reg32 *) LED6__DR)
/* Input Buffer Disable Override */
#define LED6_INP_DIS                (* (reg32 *) LED6__PC2)


#if defined(LED6__INTSTAT)  /* Interrupt Registers */

    #define LED6_INTSTAT                (* (reg32 *) LED6__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED6_DRIVE_MODE_SHIFT       (0x00u)
#define LED6_DRIVE_MODE_MASK        (0x07u << LED6_DRIVE_MODE_SHIFT)


#endif /* End Pins LED6_H */


/* [] END OF FILE */
