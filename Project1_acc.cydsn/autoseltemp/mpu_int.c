/*******************************************************************************
* File Name: mpu_int.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "mpu_int.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        mpu_int_PC =   (mpu_int_PC & \
                                (uint32)(~(uint32)(mpu_int_DRIVE_MODE_IND_MASK << (mpu_int_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (mpu_int_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: mpu_int_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void mpu_int_Write(uint8 value) 
{
    uint8 drVal = (uint8)(mpu_int_DR & (uint8)(~mpu_int_MASK));
    drVal = (drVal | ((uint8)(value << mpu_int_SHIFT) & mpu_int_MASK));
    mpu_int_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: mpu_int_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  mpu_int_DM_STRONG     Strong Drive 
*  mpu_int_DM_OD_HI      Open Drain, Drives High 
*  mpu_int_DM_OD_LO      Open Drain, Drives Low 
*  mpu_int_DM_RES_UP     Resistive Pull Up 
*  mpu_int_DM_RES_DWN    Resistive Pull Down 
*  mpu_int_DM_RES_UPDWN  Resistive Pull Up/Down 
*  mpu_int_DM_DIG_HIZ    High Impedance Digital 
*  mpu_int_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void mpu_int_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(mpu_int__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: mpu_int_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro mpu_int_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 mpu_int_Read(void) 
{
    return (uint8)((mpu_int_PS & mpu_int_MASK) >> mpu_int_SHIFT);
}


/*******************************************************************************
* Function Name: mpu_int_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 mpu_int_ReadDataReg(void) 
{
    return (uint8)((mpu_int_DR & mpu_int_MASK) >> mpu_int_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(mpu_int_INTSTAT) 

    /*******************************************************************************
    * Function Name: mpu_int_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 mpu_int_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(mpu_int_INTSTAT & mpu_int_MASK);
		mpu_int_INTSTAT = maskedStatus;
        return maskedStatus >> mpu_int_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
