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
#include <mpu_i2c.h>

const uint8 acc_adr = 0x68;

volatile uint16 acX = 0;
volatile uint16 acY = 0;
volatile uint16 acZ = 0;

volatile uint8 gyX [2];
volatile uint8 gyY [2];
volatile uint8 gyZ [2];

volatile uint8 i2c_flag = 0; 

void Read_accelerometer_values()
{
	I2C_I2CMasterSendStart(acc_adr, I2C_I2C_WRITE_XFER_MODE);
	I2C_I2CMasterWriteByte(0x3B);
	I2C_I2CMasterSendStop();
	
	//I2C_I2CMasterSendStart(acc_adr, I2C_I2C_MODE_NO_STOP);
	uint8 buf[6];
	I2C_I2CMasterReadBuf(acc_adr, buf, 6, I2C_I2C_WRITE_XFER_MODE);
	I2C_I2CMasterSendStop();
	
	acX = buf[0]<<8 | buf[1];
	acY = buf[2]<<8 | buf[3];
	acZ = buf[4]<<8 | buf[5];
}

void Read_gyroscope_values()
{
	I2C_I2CMasterSendStart(acc_adr, I2C_I2C_WRITE_XFER_MODE);
	I2C_I2CMasterWriteByte(0x43);
	I2C_I2CMasterSendStop();
	
	//I2C_I2CMasterSendStart(acc_adr, I2C_I2C_MODE_NO_STOP);
	uint8 buf[6];
	I2C_I2CMasterReadBuf(acc_adr, buf, 6, I2C_I2C_WRITE_XFER_MODE);
	I2C_I2CMasterSendStop();
	
	gyX[0] = buf[0]; gyX[1] = buf[1];
	gyY[0] = buf[2]; gyY[1] = buf[3];
	gyZ[0] = buf[4]; gyZ[1] = buf[5];
}

CY_ISR(I2cInterruptHandler)
{
    //i2c_isr_ClearPending();
    //Read_accelerometer_values();
    //Read_gyroscope_values();
    i2c_flag = 1;
    
    GPIO_0_Write(~GPIO_0_Read());
    
    i2c_isr_ClearPending();
    Timer_i2c_isr_ClearInterrupt(Timer_i2c_isr_INTR_MASK_TC);
}

uint8 get_i2c_flag()
{
    return i2c_flag;
}

void set_i2c_flag(uint8 flag)
{
    i2c_flag = flag;
}

void Init_MPU()
{   
    I2C_Start();
	I2C_I2CMasterSendStart(acc_adr, I2C_I2C_WRITE_XFER_MODE);
	I2C_I2CMasterWriteByte(0x6B);
	I2C_I2CMasterWriteByte(0x00);
	I2C_I2CMasterSendStop();	
    
    i2c_isr_StartEx(I2cInterruptHandler);
    Timer_i2c_isr_Start();
}

void Debug_send_accelerometer_values()
{
	
}

void Debug_send_gyroscope_values()
{
	DEBUG_tx_Write(gyX[0]);
	DEBUG_tx_Write(gyX[1]);
	DEBUG_tx_Write(gyY[0]);
	DEBUG_tx_Write(gyY[1]);
	DEBUG_tx_Write(gyZ[0]);
	DEBUG_tx_Write(gyZ[1]);
}

/* [] END OF FILE */
