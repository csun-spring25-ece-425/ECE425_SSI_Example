/**
 * @file SysTick_Delay.h
 *
 * @brief Header file for the SysTick_Delay driver.
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
 
#include "TM4C123GH6PM.h"

/**
 * @brief The SysTick_Delay_Init function initializes the SysTick timer to be used for a blocking delay function.
 *
 * This function configures the SysTick timer and its interrupt with a specified reload value to 
 * generate interrupts every 1 us. It uses the Peripheral Internal Oscillator (PIOSC) as the clock source.
 * The PIOSC provides 16 MHz which is then divided by 4. The timer is used for creating delays in either 
 * microseconds or milliseconds.
 *
 * @param None
 *
 * @return None
 */
void SysTick_Delay_Init(void);

/**
 * @brief The SysTick_Delay1us function provides a blocking delay in microseconds using the SysTick timer.
 *
 * This function resets the global variable, us_elapsed, to zero and waits until us_elapsed reaches 
 * the specified delay_in_us.
 *
 * @param delay_in_us The delay time in microseconds.
 *
 * @return None
 */
void SysTick_Delay1us(uint32_t delay_in_us);

/**
 * @brief The SysTick_Delay1ms function provides a blocking delay in milliseconds using the SysTick timer.
 *
 * This function clears the global variables, us_elapsed and ms_elapsed, to zero and sets ms_active flag to 0x01 
 * indicating that milliseconds delay is active. It then waits until ms_elapsed reaches the specified delay_in_ms.
 * After the delay, it clears ms_active flag back to 0x00.
 *
 * @param delay_in_ms The delay time in milliseconds.
 *
 * @return None
 */
void SysTick_Delay1ms(uint32_t delay_in_ms);

/**
 * @brief The SysTick_Handler function is the interrupt service routine for the SysTick timer.
 *
 * This function is called whenever the SysTick timer generates an interrupt. It increments the global variable
 * us_elapsed by 1, indicating that 1 microsecond has passed. Additionally, if us_elapsed reaches 1000 and ms_active
 * flag is set to 0x01, it resets us_elapsed and increments ms_elapsed by 1, indicating that 1 millisecond has passed.
 *
 * @param None
 *
 * @return None
 */
void SysTick_Handler(void);
