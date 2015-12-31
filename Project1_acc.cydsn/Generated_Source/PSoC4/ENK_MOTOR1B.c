/*******************************************************************************
* File Name: ENK_MOTOR1B.c  
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
#include "ENK_MOTOR1B.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        ENK_MOTOR1B_PC =   (ENK_MOTOR1B_PC & \
                                (uint32)(~(uint32)(ENK_MOTOR1B_DRIVE_MODE_IND_MASK << (ENK_MOTOR1B_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (ENK_MOTOR1B_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: ENK_MOTOR1B_Write
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
void ENK_MOTOR1B_Write(uint8 value) 
{
    uint8 drVal = (uint8)(ENK_MOTOR1B_DR & (uint8)(~ENK_MOTOR1B_MASK));
    drVal = (drVal | ((uint8)(value << ENK_MOTOR1B_SHIFT) & ENK_MOTOR1B_MASK));
    ENK_MOTOR1B_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: ENK_MOTOR1B_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ENK_MOTOR1B_DM_STRONG     Strong Drive 
*  ENK_MOTOR1B_DM_OD_HI      Open Drain, Drives High 
*  ENK_MOTOR1B_DM_OD_LO      Open Drain, Drives Low 
*  ENK_MOTOR1B_DM_RES_UP     Resistive Pull Up 
*  ENK_MOTOR1B_DM_RES_DWN    Resistive Pull Down 
*  ENK_MOTOR1B_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ENK_MOTOR1B_DM_DIG_HIZ    High Impedance Digital 
*  ENK_MOTOR1B_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ENK_MOTOR1B_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(ENK_MOTOR1B__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: ENK_MOTOR1B_Read
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
*  Macro ENK_MOTOR1B_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ENK_MOTOR1B_Read(void) 
{
    return (uint8)((ENK_MOTOR1B_PS & ENK_MOTOR1B_MASK) >> ENK_MOTOR1B_SHIFT);
}


/*******************************************************************************
* Function Name: ENK_MOTOR1B_ReadDataReg
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
uint8 ENK_MOTOR1B_ReadDataReg(void) 
{
    return (uint8)((ENK_MOTOR1B_DR & ENK_MOTOR1B_MASK) >> ENK_MOTOR1B_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ENK_MOTOR1B_INTSTAT) 

    /*******************************************************************************
    * Function Name: ENK_MOTOR1B_ClearInterrupt
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
    uint8 ENK_MOTOR1B_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(ENK_MOTOR1B_INTSTAT & ENK_MOTOR1B_MASK);
		ENK_MOTOR1B_INTSTAT = maskedStatus;
        return maskedStatus >> ENK_MOTOR1B_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
