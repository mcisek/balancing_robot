/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <leds_disp.h>

uint8 i = 0;

void turnLedsOff()
{
    LED0_Write(1u);
    LED1_Write(1u);
    LED2_Write(1u);
    LED3_Write(1u);
    LED4_Write(1u);
    LED5_Write(1u);
    LED6_Write(1u);
    GPIO_0_Write(1u);
    GPIO_1_Write(1u);
}

void turnLedsOn()
{
    LED0_Write(0u);
    LED1_Write(0u);
    LED2_Write(0u);
    LED3_Write(0u);
    LED4_Write(0u);
    LED5_Write(0u);
    LED6_Write(0u);
    GPIO_0_Write(0u);
    GPIO_1_Write(0u);
}

void nightRider(uint8 i)
{
    turnLedsOff();
    switch(i){
        case 0:
            LED4_Write(0u);
            break;
        case 1: case 13:
            LED4_Write(0u);
            LED2_Write(0u);
            break;
        case 2: case 12:
            LED2_Write(0u);
            LED0_Write(0u);
            break;
        case 3: case 11:
            LED0_Write(0u);
            LED1_Write(0u);
            break;
        case 4: case 10:
            LED1_Write(0u);
            LED3_Write(0u);
            break;
        case 5: case 9:
            LED3_Write(0u);
            LED5_Write(0u);
            break;
        case 6: case 8:
            LED5_Write(0u);
            LED6_Write(0u);
            break;
        case 7:
            LED6_Write(0u);
            break;
        default:
            break;
    }
}

int j=0;
CY_ISR(LedInterruptHandler)
{
    nightRider(i);
    i++;
    if(i==14)
        i=0;
   
    led_isr_ClearPending();
    Timer_led_isr_ClearInterrupt(Timer_led_isr_INTR_MASK_TC);
}

void initLeds()
{
    led_isr_StartEx(LedInterruptHandler);
    Timer_led_isr_Start();
}
/* [] END OF FILE */
