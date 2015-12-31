/*******************************************************************************
* File Name: MainClock.c
* Version 2.20
*
*  Description:
*   Provides system API for the clocking, interrupts and watchdog timer.
*
*  Note:
*   Documentation of the API's in this file is located in the
*   System Reference Guide provided with PSoC Creator.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <cydevice_trm.h>
#include "MainClock.h"

#if defined CYREG_PERI_DIV_CMD

/*******************************************************************************
* Function Name: MainClock_StartEx
********************************************************************************
*
* Summary:
*  Starts the clock, aligned to the specified running clock.
*
* Parameters:
*  alignClkDiv:  The divider to which phase alignment is performed when the
*    clock is started.
*
* Returns:
*  None
*
*******************************************************************************/
void MainClock_StartEx(uint32 alignClkDiv)
{
    /* Make sure any previous start command has finished. */
    while((MainClock_CMD_REG & MainClock_CMD_ENABLE_MASK) != 0u)
    {
    }
    
    /* Specify the target divider and it's alignment divider, and enable. */
    MainClock_CMD_REG =
        ((uint32)MainClock__DIV_ID << MainClock_CMD_DIV_SHIFT)|
        (alignClkDiv << MainClock_CMD_PA_DIV_SHIFT) |
        (uint32)MainClock_CMD_ENABLE_MASK;
}

#else

/*******************************************************************************
* Function Name: MainClock_Start
********************************************************************************
*
* Summary:
*  Starts the clock.
*
* Parameters:
*  None
*
* Returns:
*  None
*
*******************************************************************************/

void MainClock_Start(void)
{
    /* Set the bit to enable the clock. */
    MainClock_ENABLE_REG |= MainClock__ENABLE_MASK;
}

#endif /* CYREG_PERI_DIV_CMD */


/*******************************************************************************
* Function Name: MainClock_Stop
********************************************************************************
*
* Summary:
*  Stops the clock and returns immediately. This API does not require the
*  source clock to be running but may return before the hardware is actually
*  disabled.
*
* Parameters:
*  None
*
* Returns:
*  None
*
*******************************************************************************/
void MainClock_Stop(void)
{
#if defined CYREG_PERI_DIV_CMD

    /* Make sure any previous start command has finished. */
    while((MainClock_CMD_REG & MainClock_CMD_ENABLE_MASK) != 0u)
    {
    }
    
    /* Specify the target divider and it's alignment divider, and disable. */
    MainClock_CMD_REG =
        ((uint32)MainClock__DIV_ID << MainClock_CMD_DIV_SHIFT)|
        ((uint32)MainClock_CMD_DISABLE_MASK);

#else

    /* Clear the bit to disable the clock. */
    MainClock_ENABLE_REG &= (uint32)(~MainClock__ENABLE_MASK);
    
#endif /* CYREG_PERI_DIV_CMD */
}


/*******************************************************************************
* Function Name: MainClock_SetFractionalDividerRegister
********************************************************************************
*
* Summary:
*  Modifies the clock divider and the fractional divider.
*
* Parameters:
*  clkDivider:  Divider register value (0-65535). This value is NOT the
*    divider; the clock hardware divides by clkDivider plus one. For example,
*    to divide the clock by 2, this parameter should be set to 1.
*  fracDivider:  Fractional Divider register value (0-31).
* Returns:
*  None
*
*******************************************************************************/
void MainClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional)
{
    uint32 maskVal;
    uint32 regVal;
    
#if defined (MainClock__FRAC_MASK) || defined (CYREG_PERI_DIV_CMD)
    
	/* get all but divider bits */
    maskVal = MainClock_DIV_REG & 
                    (uint32)(~(uint32)(MainClock_DIV_INT_MASK | MainClock_DIV_FRAC_MASK)); 
	/* combine mask and new divider vals into 32-bit value */
    regVal = maskVal |
        ((uint32)((uint32)clkDivider <<  MainClock_DIV_INT_SHIFT) & MainClock_DIV_INT_MASK) |
        ((uint32)((uint32)clkFractional << MainClock_DIV_FRAC_SHIFT) & MainClock_DIV_FRAC_MASK);
    
#else
    /* get all but integer divider bits */
    maskVal = MainClock_DIV_REG & (uint32)(~(uint32)MainClock__DIVIDER_MASK);
    /* combine mask and new divider val into 32-bit value */
    regVal = clkDivider | maskVal;
    
#endif /* MainClock__FRAC_MASK || CYREG_PERI_DIV_CMD */

    MainClock_DIV_REG = regVal;
}


/*******************************************************************************
* Function Name: MainClock_GetDividerRegister
********************************************************************************
*
* Summary:
*  Gets the clock divider register value.
*
* Parameters:
*  None
*
* Returns:
*  Divide value of the clock minus 1. For example, if the clock is set to
*  divide by 2, the return value will be 1.
*
*******************************************************************************/
uint16 MainClock_GetDividerRegister(void)
{
    return (uint16)((MainClock_DIV_REG & MainClock_DIV_INT_MASK)
        >> MainClock_DIV_INT_SHIFT);
}


/*******************************************************************************
* Function Name: MainClock_GetFractionalDividerRegister
********************************************************************************
*
* Summary:
*  Gets the clock fractional divider register value.
*
* Parameters:
*  None
*
* Returns:
*  Fractional Divide value of the clock
*  0 if the fractional divider is not in use.
*
*******************************************************************************/
uint8 MainClock_GetFractionalDividerRegister(void)
{
#if defined (MainClock__FRAC_MASK)
    /* return fractional divider bits */
    return (uint8)((MainClock_DIV_REG & MainClock_DIV_FRAC_MASK)
        >> MainClock_DIV_FRAC_SHIFT);
#else
    return 0u;
#endif /* MainClock__FRAC_MASK */
}


/* [] END OF FILE */
