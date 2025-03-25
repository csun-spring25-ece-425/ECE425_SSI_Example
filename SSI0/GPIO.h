/**
 * @file GPIO.h
 *
 * @brief Header file for the GPIO driver.
 *
 * This file contains the function definitions for the GPIO driver.
 * It interfaces with the following:
 *  - User LED (RGB) Tiva C Series TM4C123G LaunchPad
 *	- EduBase Board LEDs (LED0 - LED3)
 *	- EduBase Board Push Buttons (SW2 - SW5)
 *
 * To verify the pinout of the user LED, refer to the Tiva C Series TM4C123G LaunchPad User's Guide
 * Link: https://www.ti.com/lit/pdf/spmu296
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"

// Constant definitions for the user LED (RGB) colors
extern const uint8_t RGB_LED_OFF;
extern const uint8_t RGB_LED_RED;
extern const uint8_t RGB_LED_BLUE;
extern const uint8_t RGB_LED_GREEN;

// Constant definitions for the EduBase board LEDs
extern const uint8_t EDUBASE_LED_ALL_OFF;
extern const uint8_t EDUBASE_LED_ALL_ON;

/**
 * @brief The RGB_LED_Init function initializes the RGB LED (PF1 - PF3)
 *
 * This function initializes the following RGB LED pins, configures the digital functionality for the pins,
 * and sets the direction of the pins as output. The RGB LED is off by default upon initialization.
 *  - LED_R     (PF1)
 *  - LED_B     (PF2)
 *  - LED_G     (PF3)
 *
 * @param None
 *
 * @return None
 */
void RGB_LED_Init(void);

/**
 * @brief The RGB_LED_Output function sets the output of the RGB LED.
 *
 * This function sets the output of the RGB LED based on the value of the input, led_value.
 * A bitwise AND operation (& 0xF1) is performed to mask the Bits 1 to 3 of the GPIOF's DATA register
 * to preserve the state of other pins connected to Port F while keeping the RGB LED pins unaffected.
 * Then, a bitwise OR operation is performed with led_value to set the RGB LED pins to the desired state
 * specified by led_value.
 *
 * @param led_value An 8-bit unsigned integer that determines the output of the RGB LED. To turn off
 *                  the RGB LED, set led_value to 0. The following values determine the color of the RGB LED:
 *
 *  Color       LED(s)   led_value
 *  Off         ---         0x00
 *  Red         R--         0x02
 *  Blue        -B-         0x04
 *  Green      	--G         0x08
 *
 * @return None
 */
void RGB_LED_Output(uint8_t led_value);

/**
 * @brief The RGB_LED_Status function indicates the status of the RGB LED
 * located at pins PF1, PF2, and PF3.
 *
 * @param None
 *
 * @return uint8_t The value representing the status of the RGB LED.
 *
 *  Color       LED(s)   led_value
 *  Off         ---         0x00
 *  Red         R--         0x02
 *  Blue        -B-         0x04
 *  Green       --G         0x08
 *
 */
uint8_t RGB_LED_Status(void);

/**
 * @brief The EduBase_LEDs_Init function initializes the EduBase Board LEDs (LED0 - LED3)
 *
 * This function initializes the following EduBase Board LEDs, configures the digital functionality for the pins,
 * and sets the direction of the pins as output. The EduBase Board LEDs are off by default upon initialization.
 *  - LED0		(PB0)
 *  - LED1		(PB1)
 *  - LED2		(PB2)
 *  - LED3		(PB3)
 *
 * @param None
 *
 * @return None
 */
void EduBase_LEDs_Init(void);

/**
 * @brief The EduBase_LEDs_Output function sets the output of the EduBase Board LEDs.
 *
 * This function sets the output of the EduBase Board LEDs based on the value of the input, led_value.
 * A bitwise AND operation (& 0xF0) is performed to mask the lower four bits (Bits 0 to 3) of the GPIOF's DATA register
 * to preserve the state of other pins connected to Port B while keeping the LED pins unaffected.
 * Then, a bitwise OR operation is performed with led_value to set the LED pins to the desired state
 * specified by led_value.
 *
 * @param led_value An 8-bit unsigned integer that determines the output of the EduBase Board LEDs.
 *
 * @return None
 */
void EduBase_LEDs_Output(uint8_t led_value);

/**
 * @brief The EduBase_Button_Init function initializes the EduBase Board buttons (SW2 - SW5).
 *
 * This function initializes the EduBase Board buttons connected to pins PD0, PD1, PD2, and PD3.
 * It enables digital functionality and configures the pins as GPIO input pins.
 *
 * @param None
 *
 * @return None
 */
void EduBase_Button_Init(void);

/**
 * @brief The Get_EduBase_Button_Status reads the status of the EduBase Board buttons (SW2 - SW5) and returns it.
 *
 * This function reads the status of the EduBase Board buttons connected to pins PD0, PD1, PD2, and PD3.
 * It indicates whether or not the buttons are pressed and returns the status.
 * A bitwise AND operation (& 0xF) is performed to mask the unused bits in the data register.
 *
 * @param None
 *
 * @return Indicates the status of the buttons. 
 *
 * For example:
 *  - 0x00: No buttons are pressed
 *  - 0x01: SW5 is pressed
 *  - 0x02: SW4 is pressed
 *  - 0x04: SW3 is pressed
 *  - 0x08: SW2 is pressed
 */
uint8_t Get_EduBase_Button_Status(void);
