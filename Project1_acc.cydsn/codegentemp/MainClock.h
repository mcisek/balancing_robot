/*******************************************************************************
* File Name: MainClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_MainClock_H)
#define CY_CLOCK_MainClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void MainClock_StartEx(uint32 alignClkDiv);
#define MainClock_Start() \
    MainClock_StartEx(MainClock__PA_DIV_ID)

#else

void MainClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void MainClock_Stop(void);

void MainClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 MainClock_GetDividerRegister(void);
uint8  MainClock_GetFractionalDividerRegister(void);

#define MainClock_Enable()                         MainClock_Start()
#define MainClock_Disable()                        MainClock_Stop()
#define MainClock_SetDividerRegister(clkDivider, reset)  \
    MainClock_SetFractionalDividerRegister((clkDivider), 0u)
#define MainClock_SetDivider(clkDivider)           MainClock_SetDividerRegister((clkDivider), 1u)
#define MainClock_SetDividerValue(clkDivider)      MainClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define MainClock_DIV_ID     MainClock__DIV_ID

#define MainClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define MainClock_CTRL_REG   (*(reg32 *)MainClock__CTRL_REGISTER)
#define MainClock_DIV_REG    (*(reg32 *)MainClock__DIV_REGISTER)

#define MainClock_CMD_DIV_SHIFT          (0u)
#define MainClock_CMD_PA_DIV_SHIFT       (8u)
#define MainClock_CMD_DISABLE_SHIFT      (30u)
#define MainClock_CMD_ENABLE_SHIFT       (31u)

#define MainClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << MainClock_CMD_DISABLE_SHIFT))
#define MainClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << MainClock_CMD_ENABLE_SHIFT))

#define MainClock_DIV_FRAC_MASK  (0x000000F8u)
#define MainClock_DIV_FRAC_SHIFT (3u)
#define MainClock_DIV_INT_MASK   (0xFFFFFF00u)
#define MainClock_DIV_INT_SHIFT  (8u)

#else 

#define MainClock_DIV_REG        (*(reg32 *)MainClock__REGISTER)
#define MainClock_ENABLE_REG     MainClock_DIV_REG
#define MainClock_DIV_FRAC_MASK  MainClock__FRAC_MASK
#define MainClock_DIV_FRAC_SHIFT (16u)
#define MainClock_DIV_INT_MASK   MainClock__DIVIDER_MASK
#define MainClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_MainClock_H) */

/* [] END OF FILE */
