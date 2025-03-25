/*
 * @file main.c
 *
 * @brief Main source code for the SSI0 program.
 *
 * This file contains the main entry point and function definitions for the SSI0 program.
 *
 * @note For more information regarding the SSI module, refer to the
 * Synchronous Serial Interface (SSI) section of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @author
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "UART0.h"
#include "SSI0.h"

#define SPI_MOSI_TEST 1
//#define SPI_EXT_LOOPBACK_TEST 1

int main(void)
{
	SysTick_Delay_Init();
	
	UART0_Init();
	
	SSI0_Init();
	
	uint8_t spi_tx_data = 0xAA;
	
	while(1)
	{
#ifdef SPI_MOSI_TEST
		SSI0_Output_Data(spi_tx_data);
		//SSI0_Output_Data(spi_tx_data + 1);
		//SSI0_Output_Data(spi_tx_data + 2);
		SysTick_Delay1ms(100);
#endif
		
#ifdef SPI_EXT_LOOPBACK_TEST
		// SPI External Loopback Test
		// Connect the following pins together: PA5 (MOSI) <---> PA4 (MISO)
		SSI0_Output_Data(spi_tx_data);
		uint8_t spi_rx_data = SSI0_Input_Data();
		UART0_Output_String("(SPI) TX DATA: ");
		UART0_Output_Unsigned_Hexadecimal(spi_tx_data);
		UART0_Output_String(" RX DATA: ");
		UART0_Output_Unsigned_Hexadecimal(spi_rx_data);
		UART0_Output_Newline();
		SysTick_Delay1ms(100);
#endif	
	}
}
