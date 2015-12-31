/*******************************************************************************
* File Name: GPIO_0.h  
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

#if !defined(CY_PINS_GPIO_0_H) /* Pins GPIO_0_H */
#define CY_PINS_GPIO_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "GPIO_0_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    GPIO_0_Write(uint8 value) ;
void    GPIO_0_SetDriveMode(uint8 mode) ;
uint8   GPIO_0_ReadDataReg(void) ;
uint8   GPIO_0_Read(void) ;
uint8   GPIO_0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define GPIO_0_DRIVE_MODE_BITS        (3)
#define GPIO_0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - GPIO_0_DRIVE_MODE_BITS))

#define GPIO_0_DM_ALG_HIZ         (0x00u)
#define GPIO_0_DM_DIG_HIZ         (0x01u)
#define GPIO_0_DM_RES_UP          (0x02u)
#define GPIO_0_DM_RES_DWN         (0x03u)
#define GPIO_0_DM_OD_LO           (0x04u)
#define GPIO_0_DM_OD_HI           (0x05u)
#define GPIO_0_DM_STRONG          (0x06u)
#define GPIO_0_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define GPIO_0_MASK               GPIO_0__MASK
#define GPIO_0_SHIFT              GPIO_0__SHIFT
#define GPIO_0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GPIO_0_PS                     (* (reg32 *) GPIO_0__PS)
/* Port Configuration */
#define GPIO_0_PC                     (* (reg32 *) GPIO_0__PC)
/* Data Register */
#define GPIO_0_DR                     (* (reg32 *) GPIO_0__DR)
/* Input Buffer Disable Override */
#define GPIO_0_INP_DIS                (* (reg32 *) GPIO_0__PC2)


#if defined(GPIO_0__INTSTAT)  /* Interrupt Registers */

    #define GPIO_0_INTSTAT                (* (reg32 *) GPIO_0__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define GPIO_0_DRIVE_MODE_SHIFT       (0x00u)
#define GPIO_0_DRIVE_MODE_MASK        (0x07u << GPIO_0_DRIVE_MODE_SHIFT)


#endif /* End Pins GPIO_0_H */


/* [] END OF FILE */
