/**
 * @file UART0.h
 *
 * @brief Header file for the UART0 driver.
 *
 * This file contains the function definitions for the UART0 driver.
 *
 * @note For more information regarding the UART module, refer to the
 * Universal Asynchronous Receivers / Transmitters (UARTs) section
 * of the TM4C123GH6PM Microcontroller Datasheet.
 *   - Link: https://www.ti.com/lit/gpn/TM4C123GH6PM
 *
 * @note Assumes that the frequency of the system clock is 50 MHz.
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"

#define UART0_RECEIVE_FIFO_EMPTY_BIT_MASK 0x10
#define UART0_TRANSMIT_FIFO_FULL_BIT_MASK 0x20

/**
 * @brief Carriage return character
 */
#define UART0_CR   0x0D
/**
 * @brief Line feed character
 */
#define UART0_LF   0x0A
/**
 * @brief Back space character
 */
#define UART0_BS   0x08
/**
 * @brief escape character
 */
#define UART0_ESC  0x1B
/**
 * @brief space character
 */
#define UART0_SP   0x20
/**
 * @brief delete character
 */
#define UART0_DEL  0x7F

/**
 * @brief The UART0_Init function initializes the UART0 module.
 *
 * This function configures the UART0 module with the following configuration:
 *
 * - Parity: Disabled
 * - Bit Order: Least Significant Bit (LSB) first
 * - Character Length: 8 data bits
 * - Stop Bits: 1
 * - UART Clock Source: System Clock (50 MHz) Divided By 16
 * - Baud Rate: 115200
 *
 * @note The PA1 (TX) and PA0 (RX) pins are used for UART communication via USB.
 *
 * @return None
 */
void UART0_Init(void);

/**
 * @brief The UART0_Input_Character function reads a character from the UART data register.
 *
 * This function waits until a character is available in the UART receive buffer
 * from the serial terminal input and returns the received character as a char type.
 *
 * @param None
 *
 * @return The received character from the serial terminal as a char type.
 */
char UART0_Input_Character(void);

/**
 * @brief The UART0_Output_Character function transmits a character via UART to the serial terminal.
 *
 * This function waits until the UART transmit buffer is ready to accept
 * a new character and then writes the specified character in the transmit buffer to the serial terminal.
 *
 * @param data The character to be transmitted to the serial terminal.
 *
 * @return None
 */
void UART0_Output_Character(char data);

/**
 * @brief The UART0_Input_String function reads a string from the UART receive buffer.
 *
 * This function reads characters from the UART receive buffer in the serial terminal
 * until a carriage return (CR) character is encountered.
 * The characters are stored in the provided buffer (buffer_pointer) up to the specified maximum length (buffer_size).
 * The function supports backspace (BS) character for deleting characters from the buffer.
 *
 * @param buffer_pointer Pointer to the buffer where the received string will be stored.
 * @param buffer_size Maximum length of the buffer.
 *
 * @return None
 */
void UART0_Input_String(char *buffer_pointer, uint16_t buffer_size);

/**
 * @brief The UART0_Output_String function transmits a null-terminated string via UART to the serial terminal.
 *
 * This function transmits characters from the provided string (pt) via UART to the serial terminal
 * until a null character is encountered.
 *
 * @param pt Pointer to the null-terminated string to be transmitted.
 *
 * @return None
 */
void UART0_Output_String(char *pt);

/**
 * @brief The UART0_Input_Unsigned_Decimal function reads an unsigned decimal number from the UART receive buffer.
 *
 * This function reads characters from the UART receive buffer in the serial terminal
 * until a carriage return (CR) character is encountered.
 * It converts the received characters into an unsigned decimal number and returns the result.
 * The function supports backspace (BS) character for deleting digits from the number during input.
 *
 * @param None
 *
 * @return The received unsigned decimal number from the serial terminal as a uint32_t type.
 */
uint32_t UART0_Input_Unsigned_Decimal(void);

/**
 * @brief The UART0_Output_Unsigned_Decimal function transmits an unsigned decimal number via UART to the serial terminal.
 *
 * This function transmits the provided unsigned decimal number (n) via UART to the serial terminal.
 *
 * @param n The unsigned decimal number to be transmitted to the serial terminal.
 *
 * @return None
 */
void UART0_Output_Unsigned_Decimal(uint32_t n);

/**
 * @brief The UART0_Input_Unsigned_Hexadecimal function reads an unsigned hexadecimal number from the UART receive buffer.
 *
 * This function reads characters from the UART receive buffer in the serial terminal
 * until a carriage return (CR) character is encountered.
 * It converts the received characters into an unsigned hexadecimal number and returns the result.
 * The function supports backspace (BS) character for deleting digits from the number during input.
 * The input characters 'A' to 'F' (uppercase or lowercase) are considered valid hexadecimal digits.
 *
 * @param None
 *
 * @return The received unsigned hexadecimal number from teh serial terminal as a uint32_t type.
 */
uint32_t UART0_Input_Unsigned_Hexadecimal(void);

/**
 * @brief The UART0_Output_Unsigned_Hexadecimal function transmits an unsigned hexadecimal number via UART to the serial terminal.
 *
 * This function transmits the provided unsigned hexadecimal number (number) via UART to the serial terminal.
 * The number is converted into a hexadecimal ASCII string and transmitted character by character.
 *
 * @param number The unsigned hexadecimal number to be transmitted to the serial terminal.
 *
 * @return None
 */
void UART0_Output_Unsigned_Hexadecimal(uint32_t number);

/**
 * @brief The UART0_Output_Newline function transmits the carriage return (CR) and line feed (LF) to go to a new line.
 *
 * @param None
 *
 * @return None
 */
void UART0_Output_Newline(void);
