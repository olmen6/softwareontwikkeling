/**
 * @file error_display.c
 * @brief Implementatie van error display functionaliteit
 * @details Format en displayen van error berichten/codes naar terminal
 * @author Melle
 * @date 20-11-2025
 */

#include "error_display.h"
#include <stdio.h>
#include <string.h>

// TODO: Include LAAG3 UART headers
// #include "../Laag3/API_io.h"

/**
 * @brief Init error display systeem
 * @details Maakt UART klaar voor error output
 * @retval 0 bij success
 * @retval -1 bij error
 */
int error_display_init(void)
{
    // TODO: Init UART als als nodig
    return 0;
}

/**
 * @brief Ontvang error message string
 * @param error_code De error code
 * @return Pointer naar error message string
 */
static const char* get_error_message(error_code_t error_code)
{
    switch (error_code)
    {
        case ERR_NONE:
            return "Geen error";
        case ERR_INVALID_PARAM:
            return "Ongeldige parameter";
        case ERR_OUT_OF_BOUNDS:
            return "Out of bounds";
        case ERR_HARDWARE_FAILURE:
            return "Hardware failure";
        case ERR_TIMEOUT:
            return "Timeout";
        case ERR_UNKNOWN:
        default:
            return "Onbekende error";
    }
}


/**
 * @brief Display de error message op terminal
 * @details Format en stuur error message via UART
 * @param error_code De error code om te displayen
 * @param function_name Naam van de functie waar de error is ontstaan
 */
void error_display(error_code_t error_code, const char *function_name)
{
    if (error_code == ERR_NONE)
    {
        return;
    }

    char error_buffer[256];
    snprintf(error_buffer, sizeof(error_buffer),
             "[ERROR] %s in %s\r\n",
             get_error_message(error_code),
             function_name ? function_name : "unknown");

    // TODO: Stuur via UART via LAAG3 (HW aansturing dus)
    // API_write_string(error_buffer);

    // Voor nu, gebruik printf (werkt alleen in debug/simulation)
    printf("%s", error_buffer);
}


/**
 * @brief Display commando uitvoering result
 * @details Toont user-friendly message over errors
 * @param result Commando resultaat code (error of geen error / status)
 */
void display_command_result(command_result_t result)
{
    const char *message;

    switch (result)
    {
        case CMD_SUCCESS:
            message = "[OK] Command succesvol uitgevoerd\r\n";
            break;
        case CMD_ERROR_INVALID_COMMAND:
            message = "[ERROR] Ongeldig commando\r\n";
            break;
        case CMD_ERROR_INVALID_PARAMS:
            message = "[ERROR] Ongeldige parameters\r\n";
            break;
        case CMD_ERROR_EXECUTION_FAILED:
            message = "[ERROR] Commando uitvoering mislukt\r\n";
            break;
        default:
            message = "[ERROR] Onbekende error\r\n";
            break;
    }

    // TODO: Stuur via UART vanuit LAAG3 (hw aansturing)
    // API_write_string(message);

    printf("%s", message);
}
