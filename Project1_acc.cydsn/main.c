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
#define DEBUG

const uint8 acc_adr = 0x68;

volatile uint16 acX = 0;
volatile uint16 acY = 0;
volatile uint16 acZ = 0;

volatile uint8 gyX [2];
volatile uint8 gyY [2];
volatile uint8 gyZ [2];

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

void Init_MPU()
{
	I2C_I2CMasterSendStart(acc_adr, I2C_I2C_WRITE_XFER_MODE);
	I2C_I2CMasterWriteByte(0x6B);
	I2C_I2CMasterWriteByte(0x00);
	I2C_I2CMasterSendStop();	
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

void Initialize_System()
{
    #ifdef DEBUG
        DEBUG_Start();
		DEBUG_UartInit();
    #endif
	
	I2C_Start();
	Init_MPU();
}

int main()
{
    CyGlobalIntEnable;      /* Enable global interrupts */
    
    Initialize_System();
	
	DEBUG_UartPutString("START");
    
    for(;;)
    {
         Read_accelerometer_values();
		CyDelay(100);
		#ifdef DEBUG
			Debug_send_gyroscope_values();
		#endif
		
    }
}

