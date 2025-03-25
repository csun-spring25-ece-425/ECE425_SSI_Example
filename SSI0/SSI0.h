/**
 * @file SSI0.h
 *
 * @brief Header file for the SSI0 driver.
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

#include "TM4C123GH6PM.h"

#define SSI0_BUSY_BIT_MASK (0x10)
#define SSI0_RX_FIFO_NOT_EMPTY_BIT_MASK (0x04)
#define SSI0_TX_FIFO_EMPTY_BIT_MASK (0x01)

/**
 * @brief
 *
 * @param None
 *
 * @return None
 */
void SSI0_Init(void);

/**
 * @brief
 *
 * @param None
 *
 * @return uint8_t
 */
uint8_t SSI0_Input_Data(void);

/**
 * @brief
 *
 * @param uint8_t data
 *
 * @return None
 */
void SSI0_Output_Data(uint8_t data);
