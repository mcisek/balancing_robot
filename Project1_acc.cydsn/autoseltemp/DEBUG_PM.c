/*******************************************************************************
* File Name: DEBUG_PM.c
* Version 3.0
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DEBUG.h"
#include "DEBUG_PVT.h"

#if(DEBUG_SCB_MODE_I2C_INC)
    #include "DEBUG_I2C_PVT.h"
#endif /* (DEBUG_SCB_MODE_I2C_INC) */

#if(DEBUG_SCB_MODE_EZI2C_INC)
    #include "DEBUG_EZI2C_PVT.h"
#endif /* (DEBUG_SCB_MODE_EZI2C_INC) */

#if(DEBUG_SCB_MODE_SPI_INC || DEBUG_SCB_MODE_UART_INC)
    #include "DEBUG_SPI_UART_PVT.h"
#endif /* (DEBUG_SCB_MODE_SPI_INC || DEBUG_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(DEBUG_SCB_MODE_UNCONFIG_CONST_CFG || \
   (DEBUG_SCB_MODE_I2C_CONST_CFG   && (!DEBUG_I2C_WAKE_ENABLE_CONST))   || \
   (DEBUG_SCB_MODE_EZI2C_CONST_CFG && (!DEBUG_EZI2C_WAKE_ENABLE_CONST)) || \
   (DEBUG_SCB_MODE_SPI_CONST_CFG   && (!DEBUG_SPI_WAKE_ENABLE_CONST))   || \
   (DEBUG_SCB_MODE_UART_CONST_CFG  && (!DEBUG_UART_WAKE_ENABLE_CONST)))

    DEBUG_BACKUP_STRUCT DEBUG_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: DEBUG_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The "Enable wakeup from Sleep Mode" selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DEBUG_Sleep(void)
{
#if(DEBUG_SCB_MODE_UNCONFIG_CONST_CFG)

    if(DEBUG_SCB_WAKE_ENABLE_CHECK)
    {
        if(DEBUG_SCB_MODE_I2C_RUNTM_CFG)
        {
            DEBUG_I2CSaveConfig();
        }
        else if(DEBUG_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            DEBUG_EzI2CSaveConfig();
        }
    #if(!DEBUG_CY_SCBIP_V1)
        else if(DEBUG_SCB_MODE_SPI_RUNTM_CFG)
        {
            DEBUG_SpiSaveConfig();
        }
        else if(DEBUG_SCB_MODE_UART_RUNTM_CFG)
        {
            DEBUG_UartSaveConfig();
        }
    #endif /* (!DEBUG_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        DEBUG_backup.enableState = (uint8) DEBUG_GET_CTRL_ENABLED;

        if(0u != DEBUG_backup.enableState)
        {
            DEBUG_Stop();
        }
    }

#else

    #if (DEBUG_SCB_MODE_I2C_CONST_CFG && DEBUG_I2C_WAKE_ENABLE_CONST)
        DEBUG_I2CSaveConfig();

    #elif (DEBUG_SCB_MODE_EZI2C_CONST_CFG && DEBUG_EZI2C_WAKE_ENABLE_CONST)
        DEBUG_EzI2CSaveConfig();

    #elif (DEBUG_SCB_MODE_SPI_CONST_CFG && DEBUG_SPI_WAKE_ENABLE_CONST)
        DEBUG_SpiSaveConfig();

    #elif (DEBUG_SCB_MODE_UART_CONST_CFG && DEBUG_UART_WAKE_ENABLE_CONST)
        DEBUG_UartSaveConfig();

    #else

        DEBUG_backup.enableState = (uint8) DEBUG_GET_CTRL_ENABLED;

        if(0u != DEBUG_backup.enableState)
        {
            DEBUG_Stop();
        }

    #endif /* defined (DEBUG_SCB_MODE_I2C_CONST_CFG) && (DEBUG_I2C_WAKE_ENABLE_CONST) */

#endif /* (DEBUG_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: DEBUG_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting
*  Deep Sleep. The "Enable wakeup from Sleep Mode" option has an influence
*  on this function implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DEBUG_Wakeup(void)
{
#if(DEBUG_SCB_MODE_UNCONFIG_CONST_CFG)

    if(DEBUG_SCB_WAKE_ENABLE_CHECK)
    {
        if(DEBUG_SCB_MODE_I2C_RUNTM_CFG)
        {
            DEBUG_I2CRestoreConfig();
        }
        else if(DEBUG_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            DEBUG_EzI2CRestoreConfig();
        }
    #if(!DEBUG_CY_SCBIP_V1)
        else if(DEBUG_SCB_MODE_SPI_RUNTM_CFG)
        {
            DEBUG_SpiRestoreConfig();
        }
        else if(DEBUG_SCB_MODE_UART_RUNTM_CFG)
        {
            DEBUG_UartRestoreConfig();
        }
    #endif /* (!DEBUG_CY_SCBIP_V1) */
        else
        {
            /* Unknown mode */
        }
    }
    else
    {
        if(0u != DEBUG_backup.enableState)
        {
            DEBUG_Enable();
        }
    }

#else

    #if (DEBUG_SCB_MODE_I2C_CONST_CFG  && DEBUG_I2C_WAKE_ENABLE_CONST)
        DEBUG_I2CRestoreConfig();

    #elif (DEBUG_SCB_MODE_EZI2C_CONST_CFG && DEBUG_EZI2C_WAKE_ENABLE_CONST)
        DEBUG_EzI2CRestoreConfig();

    #elif (DEBUG_SCB_MODE_SPI_CONST_CFG && DEBUG_SPI_WAKE_ENABLE_CONST)
        DEBUG_SpiRestoreConfig();

    #elif (DEBUG_SCB_MODE_UART_CONST_CFG && DEBUG_UART_WAKE_ENABLE_CONST)
        DEBUG_UartRestoreConfig();

    #else

        if(0u != DEBUG_backup.enableState)
        {
            DEBUG_Enable();
        }

    #endif /* (DEBUG_I2C_WAKE_ENABLE_CONST) */

#endif /* (DEBUG_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
