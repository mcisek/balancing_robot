/*******************************************************************************
* File Name: MOTOR1_PWM.c  
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
#include "MOTOR1_PWM.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        MOTOR1_PWM_PC =   (MOTOR1_PWM_PC & \
                                (uint32)(~(uint32)(MOTOR1_PWM_DRIVE_MODE_IND_MASK << (MOTOR1_PWM_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (MOTOR1_PWM_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: MOTOR1_PWM_Write
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
void MOTOR1_PWM_Write(uint8 value) 
{
    uint8 drVal = (uint8)(MOTOR1_PWM_DR & (uint8)(~MOTOR1_PWM_MASK));
    drVal = (drVal | ((uint8)(value << MOTOR1_PWM_SHIFT) & MOTOR1_PWM_MASK));
    MOTOR1_PWM_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: MOTOR1_PWM_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  MOTOR1_PWM_DM_STRONG     Strong Drive 
*  MOTOR1_PWM_DM_OD_HI      Open Drain, Drives High 
*  MOTOR1_PWM_DM_OD_LO      Open Drain, Drives Low 
*  MOTOR1_PWM_DM_RES_UP     Resistive Pull Up 
*  MOTOR1_PWM_DM_RES_DWN    Resistive Pull Down 
*  MOTOR1_PWM_DM_RES_UPDWN  Resistive Pull Up/Down 
*  MOTOR1_PWM_DM_DIG_HIZ    High Impedance Digital 
*  MOTOR1_PWM_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void MOTOR1_PWM_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(MOTOR1_PWM__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: MOTOR1_PWM_Read
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
*  Macro MOTOR1_PWM_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 MOTOR1_PWM_Read(void) 
{
    return (uint8)((MOTOR1_PWM_PS & MOTOR1_PWM_MASK) >> MOTOR1_PWM_SHIFT);
}


/*******************************************************************************
* Function Name: MOTOR1_PWM_ReadDataReg
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
uint8 MOTOR1_PWM_ReadDataReg(void) 
{
    return (uint8)((MOTOR1_PWM_DR & MOTOR1_PWM_MASK) >> MOTOR1_PWM_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(MOTOR1_PWM_INTSTAT) 

    /*******************************************************************************
    * Function Name: MOTOR1_PWM_ClearInterrupt
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
    uint8 MOTOR1_PWM_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(MOTOR1_PWM_INTSTAT & MOTOR1_PWM_MASK);
		MOTOR1_PWM_INTSTAT = maskedStatus;
        return maskedStatus >> MOTOR1_PWM_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
