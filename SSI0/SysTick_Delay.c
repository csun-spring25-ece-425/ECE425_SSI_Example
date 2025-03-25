/**
 * @file SysTick_Delay.c
 *
 * @brief Source code for the SysTick_Delay driver.
 *
 * It provides two blocking functions, SysTick_Delay1ms and SysTick_Delay1us,
 * to create a delay with a busy-wait loop. It uses the SysTick timer with 
 * a specified reload value to generate interrupts every 1 us.
 * 
 * In addition, it uses the Peripheral Internal Oscillator (PIOSC) 
 * as the clock source. The PIOSC provides 16 MHz which is then divided by 4. 
 * The timer is used for creating delays in either microseconds or milliseconds.
 *
 * @author Aaron Nanas
 */

#include "SysTick_Delay.h"

// Global variable used to keep track of elapsed time in microseconds
static uint32_t us_elapsed = 0;

// Global variable used to keep track of elapsed time in milliseconds
static uint32_t ms_elapsed = 0;

// Global flag used to indicate if milliseconds delay is active
static uint8_t ms_active = 0;

void SysTick_Delay_Init(void)
{	
	// Set the SysTick timer reload value for 1 us intervals
	// Each clock cycle is (1 / 4 MHz) = 0.25 us
	SysTick->LOAD = (4 - 1);
	
	// Clear the VAL register by writing any value to it
	SysTick->VAL = 0;
	
	// Enable the SysTick timer and its interrupt
	// with the Peripheral Internal Oscillator (PIOSC) as the clock source
	SysTick->CTRL |= 0x03;
}

void SysTick_Delay1us(uint32_t delay_in_us)
{
	// Reset the global variable, us_elapsed
	us_elapsed = 0;
	
	// Wait until ms_value reaches the specified delay_in_ms
	while (delay_in_us > us_elapsed);
}

void SysTick_Delay1ms(uint32_t delay_in_ms)
{
	// Reset the global variables, us_elapsed and ms_elapsed
	us_elapsed = 0;
	ms_elapsed = 0;
	
	// Set the ms_active global flag
	ms_active = 0x01;
	
	// Wait until ms_elapsed reaches the specified delay_in_ms
	while (delay_in_ms > ms_elapsed);
	
	// Reset the ms_active global flag
	ms_active = 0x00;
}

void SysTick_Handler(void)
{
	// Increment the global variable, us_elapsed
	us_elapsed = us_elapsed + 1;
	
	// Check if us_elapsed has reached 1000 (1 millisecond) and if milliseconds delay is active
	if (us_elapsed == 1000 && (ms_active == 0x01))
	{
		// Reset us_elapsed
		us_elapsed = 0;
		
		// Increment ms_elapsed to indicate that 1 millisecond has passed
		ms_elapsed = ms_elapsed + 1;
	}
}
