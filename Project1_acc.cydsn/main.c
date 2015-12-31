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
#include <mpu_i2c.h>
#include <leds_disp.h>

void Initialize_System()
{
    GPIO_0_Write(1);
    CyDelay(1000u);
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    #ifdef DEBUG
        DEBUG_Start();
		DEBUG_UartInit();
    #endif
	
    //initMotorContol();
    //initLeds();
	Init_MPU();
    
	//DEBUG_UartPutString("START");
}

int main()
{    
    Initialize_System();
    
    for(;;)
    {
        if(get_i2c_flag() == 1)
        {
            set_i2c_flag(0u);
            Read_accelerometer_values();
            
        }
    }
}

