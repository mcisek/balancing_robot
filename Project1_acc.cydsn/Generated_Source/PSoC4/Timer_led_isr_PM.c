/*******************************************************************************
* File Name: Timer_led_isr_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Timer_led_isr.h"

static Timer_led_isr_BACKUP_STRUCT Timer_led_isr_backup;


/*******************************************************************************
* Function Name: Timer_led_isr_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_led_isr_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_led_isr_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_led_isr_Sleep(void)
{
    if(0u != (Timer_led_isr_BLOCK_CONTROL_REG & Timer_led_isr_MASK))
    {
        Timer_led_isr_backup.enableState = 1u;
    }
    else
    {
        Timer_led_isr_backup.enableState = 0u;
    }

    Timer_led_isr_Stop();
    Timer_led_isr_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_led_isr_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_led_isr_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: Timer_led_isr_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Timer_led_isr_Wakeup(void)
{
    Timer_led_isr_RestoreConfig();

    if(0u != Timer_led_isr_backup.enableState)
    {
        Timer_led_isr_Enable();
    }
}


/* [] END OF FILE */
