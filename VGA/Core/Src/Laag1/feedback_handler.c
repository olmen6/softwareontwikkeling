/**
 * @file feedback_handler.c
 * @brief Implementatie van feedback handler functionality
 * @details Format en displayed feedback messages
 * @author Melle
 * @date 20-11-2025
 */

#include "feedback_handler.h"
#include <stdio.h>
#include <string.h>

// TODO: Include LAAG3 UART headers
// #include "../Laag3/API_io.h"

/**
 * @brief Init feedback handler
 * @details Setup UART voor feedback output
 * @retval 0 bij success
 * @retval -1 bij error
 */
int feedback_handler_init(void)
{
    // TODO: Init UART als nodig is
    return 0;
}

/**
 * @brief Weergeef feedback message op terminal
 * @details Format message als juiste type
 * @param type Type van feedback message
 * @param message Message om te weergeven
 */
void feedback_handler(feedback_type_t type, const char *message)
{
    if (message == NULL)
    {
        return;
    }

    char buffer[256];
    const char *prefix;

    switch (type)
    {
        case FEEDBACK_INFO:
            prefix = "[INFO]";
            break;
        case FEEDBACK_SUCCESS:
            prefix = "[OK]";
            break;
        case FEEDBACK_WARNING:
            prefix = "[WARN]";
            break;
        case FEEDBACK_PROMPT:
            prefix = ">";
            break;
        default:
            prefix = "";
            break;
    }

    snprintf(buffer, sizeof(buffer), "%s %s\r\n", prefix, message);

    // TODO: Stuur via UART d.m.v. LAAG3
    // API_write_string(buffer);

    printf("%s", buffer);
}

/**
 * @brief Weergeef welkom message
 * @details Laat system informatie and beschikbare commando's zien
 */
void feedback_display_welcome(void)
{
    const char *welcome =
        "\r\n"
        "====================================\r\n"
        "  VESOFTON VGA Terminal v1.0\r\n"
        "====================================\r\n"
        "Type 'help' for available commands\r\n"
        "\r\n";

    // TODO: Stuur via UART
    // API_write_string(welkom);

    printf("%s", welcome);
}

/**
 * @brief weergeef command prompt
 * @details Laat input prompt aan gebruiker zien
 */
void feedback_display_prompt(void)
{
    const char *prompt = "> ";

    // TODO: stuur via UART
    // API_write_string(prompt);

    printf("%s", prompt);
}

/**
 * @brief Laat help informatie zien
 * @details Lists van alle beschikbare commando's en hun syntax
 */
void feedback_display_help(void)
{
    const char *help =
        "\r\n"
        "Beschikbare Commando's:\r\n"
        "------------------\r\n"
        "draw_line x1 y1 x2 y2 color    - Teken een lijn\r\n"
        "draw_rect x y width height color - Teken een rechthoek\r\n"
        "draw_text x y \"text\" color      - Teken tekst\r\n"
        "draw_bitmap x y bitmap_id      - Teken een bitmap\r\n"
        "clear                          - Clear screen\r\n"
        "help                           - Show help\r\n"
        "exit                           - Exit programma\r\n"
        "\r\n"
        "Voorbeeld: draw_line 10 10 100 100 255\r\n"
        "\r\n";

    // TODO: Stuur via UART
    // API_write_string(help);

    printf("%s", help);
}
