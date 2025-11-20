/**
 * @file script_reader.c
 * @brief Uitvoering van script lees functionaliteit
 * @details Lees commando's uit UART en buffer ze
 * @author Melle
 * @date 20-11-2025
 */

#include "script_reader.h"
#include <stdio.h>
#include <string.h>

// TODO: Include LAAG3 UART/IO headers heir
// #include "../Laag3/API_io.h"

/**
 * @brief Initialiseer de reader (setup UART/terminal)
 * @details Initializes UART communicatie voor terminal I/O
 * @retval 0 bij success
 * @retval -1 bij error
 */
int script_reader_init(void)
{
    // TODO: Initialize UART dmv LAAG3 functions
    // Bijv.: API_init_io();

    return 0;
}

/**
 * @brief Check of er data is om te lezen
 * @details Check UART receive buffer status
 * @retval 1 als data beschikbaar is
 * @retval 0 als er GEEN data beschikbaar is
 */
int script_reader_available(void)
{
    // TODO: Check of er data is om te lezen
    // Bijv.: return API_io_available();

    return 0;
}

/**
 * @brief Lees een commando van terminal input
 * @details Lees chars tot newline of buffer vol
 * @param buffer Pointer naar opslag buffer input
 * @param max_length Max aantal chars dat gelezen kan worden
 * @retval Aantal gelezen chars
 * @retval 0 bij geen input
 * @retval -1 bij error
 */
int script_reader(char *buffer, uint16_t max_length)
{
    if (buffer == NULL || max_length == 0)
    {
        return -1;
    }

    uint16_t index = 0;
    char ch;

    // TODO: Implementeer UART reading met LAAG3 functions
    // voorbeeld implementatie:
    /*
    while (index < max_length - 1)
    {
        if (API_io_read(&ch) == 0)  // If character available
        {
            buffer[index++] = ch;

            // Echo character back to terminal
            API_io_write(ch);

            // Stop at newline
            if (ch == '\n' || ch == '\r')
            {
                break;
            }
        }
    }
    */

    buffer[index] = '\0';
    return index;
}
