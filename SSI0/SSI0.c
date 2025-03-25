/**
 * @file SSI0.c
 *
 * @brief Source code for the SSI0 driver.
 *
 * This file contains the function definitions for the SSI0 driver.
 *
 * @note For more information regarding the SSI module, refer to the
 * Synchronous Serial Interface (SSI) section of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @note Assumes that the system clock (50 MHz) is used.
 *
 * @author Aaron Nanas
 */

#include "SSI0.h"

void SSI0_Init(void)
{
	// Enable the clock to the SSI0 module by setting the 
	// R0 bit (Bit 0) in the RCGCSSI register
	SYSCTL->RCGCSSI |= 0x01;
	
	// Enable the clock to Port A by setting the
	// R0 bit (Bit 0) in the RCGCGPIO register
	SYSCTL->RCGCGPIO |= 0x01;
	
	// Configure the PA2 (SCLK), PA3 (CS), PA4 (MISO) and PA5 (MOSI) pins to use the alternate function
	// by setting Bits 5 to 3 in the AFSEL register
	GPIOA->AFSEL |= 0x3C;
	
	// Clear the PMC2, PMC3, PMC4 and PMC5 fields in the PCTL register before configuration
	GPIOA->PCTL &= ~0x00FFFF00;
	
	// Configure the PA5 to PA2 pins to operate as SSI pins by writing 0x2 to the
	// corresponding PMCn fields in the PCTL register.
	// The 0x2 value is derived from Table 15-1 in the TM4C123G Microcontroller Datasheet
	GPIOA->PCTL |= 0x00222200;
	
	// Enable the digital functionality for the PA5 to PA2 pins
	// by setting Bits 5 to 2 in the DEN register
	GPIOA->DEN |= 0x3C;
	
	// Disable the SSI0 module before configuration by clearing
	// the SSE bit (Bit 1) in the CR1 register
	SSI0->CR1 &= ~0x02;
	
	// Disable SSI loopback mode by clearing the LBM bit (Bit 0) in the CR1 register
	SSI0->CR1 &= ~0x01;
	
	// Configure the SSI0 module as a master device by clearing
	// the MS bit (Bit 2) in the CR1 register
	SSI0->CR1 &= ~0x04;
	
	// Specify the SSI0 clock source to use the system clock by
	// writing a value of 0x0 to the CS field (Bits 3 to 0) in the CC register
	SSI0->CC &= ~0xF;
	
	// Set the clock frequency of SCLK by writing the prescale divisor value
	// to the CPSDVSR field (Bits 7 to 0) in the CPSR register.
	// For example, a value of 50 can be written to CPSR and the SCR field (Bits 15 to 8)
	// in the CR0 register can be cleared to 0 to configure the SCLK frequency to 1 MHz
	// SSInClk = SysClk / (CPSDVSR * (1 + SCR))
	// SSInClk = 50 MHz / (50 * (1 + 0))
	// SSInClk = 1 MHz
	SSI0->CPSR = 50;
	SSI0->CR0 &= ~0xFF00;
	
	// Configure the SSI0 module to capture data on the first clock edge transition
	// by clearing the SPH bit (Bit 7) in the CR0 register
	SSI0->CR0 &= ~0x0080;
	
	// Configure the SCLK of the SSI0 module to be idle low when inactive
	// by clearing the SPO bit (Bit 6) in the CR0 register
	SSI0->CR0 &= ~0x0040;
	
	// Configure the SSI0 module to use the Freescale SPI Frame Format
	// by clearing the FRF field (Bits 5 to 4) in the CR0 register
	SSI0->CR0 &= ~0x0030;
	
	// Configure the SSI0 module to have a data length of 8 bits
	// by writing a value of 0x7 to the DSS field (Bits 3 to 0) in the CR0 register
	SSI0->CR0 |= 0x0007;
	
	// Enable the SSI0 module after configuration by setting
	// the SSE bit (Bit 1) in the CR1 register
	SSI0->CR1 |= 0x02;
}

uint8_t SSI0_Input_Data(void)
{
	// Wait until the RX FIFO is not empty and then read the data
	while((SSI0->SR & SSI0_RX_FIFO_NOT_EMPTY_BIT_MASK) == 0);
	
	return (uint8_t)(SSI0->DR & 0xFF);
}

void SSI0_Output_Data(uint8_t data)
{
	// Wait until the TX FIFO is empty and then transmit the data
	while((SSI0->SR & SSI0_TX_FIFO_EMPTY_BIT_MASK) == 0);
	
	SSI0->DR = data;
}
