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
#include <motor_control.h>

void initMotorContol()
{
    PWM_MOTOR_Start();
    PWM_MOTOR_WritePeriod(255);
}

void setMotor1(int direction, uint8 pwm)
{
    if(direction == -1)
    {
        MOTOR1_1_Write(1u);
        MOTOR1_2_Write(0u);
        PWM_MOTOR_WriteCompare1(pwm);
    }
    else if(direction == 1)
    {
        MOTOR1_1_Write(0u);
        MOTOR1_2_Write(1u);
        PWM_MOTOR_WriteCompare1(pwm);
    }
    else if(direction == 0)
    {
        MOTOR1_1_Write(0u);
        MOTOR1_2_Write(0u);
    } 
}

void setMotor2(int direction, uint8 pwm)
{
    if(direction == -1)
    {
        MOTOR2_1_Write(1u);
        MOTOR2_2_Write(0u);
        PWM_MOTOR_WriteCompare2(pwm);
    }
    else if(direction == 1)
    {
        MOTOR2_1_Write(0u);
        MOTOR2_2_Write(1u);
        PWM_MOTOR_WriteCompare2(pwm);
    }
    else if(direction == 0)
    {
        MOTOR2_1_Write(0u);
        MOTOR2_2_Write(0u);
    } 
}

/* [] END OF FILE */
