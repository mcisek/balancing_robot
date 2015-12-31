/*******************************************************************************
* File Name: i2c_isr.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_i2c_isr_H)
#define CY_ISR_i2c_isr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void i2c_isr_Start(void);
void i2c_isr_StartEx(cyisraddress address);
void i2c_isr_Stop(void);

CY_ISR_PROTO(i2c_isr_Interrupt);

void i2c_isr_SetVector(cyisraddress address);
cyisraddress i2c_isr_GetVector(void);

void i2c_isr_SetPriority(uint8 priority);
uint8 i2c_isr_GetPriority(void);

void i2c_isr_Enable(void);
uint8 i2c_isr_GetState(void);
void i2c_isr_Disable(void);

void i2c_isr_SetPending(void);
void i2c_isr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the i2c_isr ISR. */
#define i2c_isr_INTC_VECTOR            ((reg32 *) i2c_isr__INTC_VECT)

/* Address of the i2c_isr ISR priority. */
#define i2c_isr_INTC_PRIOR             ((reg32 *) i2c_isr__INTC_PRIOR_REG)

/* Priority of the i2c_isr interrupt. */
#define i2c_isr_INTC_PRIOR_NUMBER      i2c_isr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable i2c_isr interrupt. */
#define i2c_isr_INTC_SET_EN            ((reg32 *) i2c_isr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the i2c_isr interrupt. */
#define i2c_isr_INTC_CLR_EN            ((reg32 *) i2c_isr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the i2c_isr interrupt state to pending. */
#define i2c_isr_INTC_SET_PD            ((reg32 *) i2c_isr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the i2c_isr interrupt. */
#define i2c_isr_INTC_CLR_PD            ((reg32 *) i2c_isr__INTC_CLR_PD_REG)



#endif /* CY_ISR_i2c_isr_H */


/* [] END OF FILE */
