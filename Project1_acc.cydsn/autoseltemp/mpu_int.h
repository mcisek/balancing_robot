/*******************************************************************************
* File Name: mpu_int.h  
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

#if !defined(CY_PINS_mpu_int_H) /* Pins mpu_int_H */
#define CY_PINS_mpu_int_H

#include "cytypes.h"
#include "cyfitter.h"
#include "mpu_int_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    mpu_int_Write(uint8 value) ;
void    mpu_int_SetDriveMode(uint8 mode) ;
uint8   mpu_int_ReadDataReg(void) ;
uint8   mpu_int_Read(void) ;
uint8   mpu_int_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define mpu_int_DRIVE_MODE_BITS        (3)
#define mpu_int_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - mpu_int_DRIVE_MODE_BITS))

#define mpu_int_DM_ALG_HIZ         (0x00u)
#define mpu_int_DM_DIG_HIZ         (0x01u)
#define mpu_int_DM_RES_UP          (0x02u)
#define mpu_int_DM_RES_DWN         (0x03u)
#define mpu_int_DM_OD_LO           (0x04u)
#define mpu_int_DM_OD_HI           (0x05u)
#define mpu_int_DM_STRONG          (0x06u)
#define mpu_int_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define mpu_int_MASK               mpu_int__MASK
#define mpu_int_SHIFT              mpu_int__SHIFT
#define mpu_int_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define mpu_int_PS                     (* (reg32 *) mpu_int__PS)
/* Port Configuration */
#define mpu_int_PC                     (* (reg32 *) mpu_int__PC)
/* Data Register */
#define mpu_int_DR                     (* (reg32 *) mpu_int__DR)
/* Input Buffer Disable Override */
#define mpu_int_INP_DIS                (* (reg32 *) mpu_int__PC2)


#if defined(mpu_int__INTSTAT)  /* Interrupt Registers */

    #define mpu_int_INTSTAT                (* (reg32 *) mpu_int__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define mpu_int_DRIVE_MODE_SHIFT       (0x00u)
#define mpu_int_DRIVE_MODE_MASK        (0x07u << mpu_int_DRIVE_MODE_SHIFT)


#endif /* End Pins mpu_int_H */


/* [] END OF FILE */
