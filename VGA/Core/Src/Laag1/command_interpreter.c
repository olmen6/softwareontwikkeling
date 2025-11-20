/**
 * @file command_interpreter.c
 * @brief Implementatie van command interpreter functionaliteit
 * @details Converteerd geparste commando's naar LAAG2 function calls
 * @author Melle
 * @date 20-11-2025
 */

#include "command_interpreter.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// TODO: Include LAAG2 headers
// #include "../Laag2/execute_command.h"
// #include "../Laag2/draw_line.h"
// #include "../Laag2/draw_rectangle.h"
// etc.


/**
 * @brief Converteerd string parameter naar integer
 * @param str String om te converteren
 * @param value Pointer om geconverteerde waarde op op te slaan
 * @retval 0 bij success
 * @retval -1 bij error
 */
int parse_int_param(const char *str, int *value)
{
    if (str == NULL || value == NULL)
    {
        return -1;
    }

    char *endptr;
    long result = strtol(str, &endptr, 10);

    // Check of conversie successvol was
    if (endptr == str || *endptr != '\0')
    {
        return -1;
    }

    *value = (int)result;
    return 0;
}


/**
 * @brief Interpreteer en voer uit het geparste commando
 * @details Stuurt commando's naar juiste LAAG2 functie
 * @param cmd Pointer naar parsed_command_t struct
 * @retval CMD_SUCCESS bij success
 * @retval CMD_ERROR_* bij error
 */
command_result_t command_interpreter(const parsed_command_t *cmd)
{
    if (cmd == NULL)
    {
        return CMD_ERROR_INVALID_COMMAND;
    }

    // Handle draw_line commando
    // Verwachte input: draw_line x1 y1 x2 y2 color
    if (strcmp(cmd->command, "draw_line") == 0)
    {
        if (cmd->param_count != 5)	//MAGIC nummer nog regelen
        {
            return CMD_ERROR_INVALID_PARAMS;
        }

        int x1, y1, x2, y2, color;
        if (parse_int_param(cmd->params[0], &x1) != 0 ||
            parse_int_param(cmd->params[1], &y1) != 0 ||
            parse_int_param(cmd->params[2], &x2) != 0 ||
            parse_int_param(cmd->params[3], &y2) != 0 ||
            parse_int_param(cmd->params[4], &color) != 0)
        {
            return CMD_ERROR_INVALID_PARAMS;
        }

        // TODO: Call LAAG2 functie
        // if (draw_line(x1, y1, x2, y2, color) != 0)
        // {
        //     return CMD_ERROR_EXECUTION_FAILED;
        // }

        return CMD_SUCCESS;
    }

    // Handle draw_rect commando
    // Verwachte input: draw_rect x y width height color
    if (strcmp(cmd->command, "draw_rect") == 0)
    {
        if (cmd->param_count != 5)			//MAGIC nummer
        {
            return CMD_ERROR_INVALID_PARAMS;
        }

        int x, y, width, height, color;
        if (parse_int_param(cmd->params[0], &x) != 0 ||
            parse_int_param(cmd->params[1], &y) != 0 ||
            parse_int_param(cmd->params[2], &width) != 0 ||
            parse_int_param(cmd->params[3], &height) != 0 ||
            parse_int_param(cmd->params[4], &color) != 0)
        {
            return CMD_ERROR_INVALID_PARAMS;
        }

        // TODO: Call LAAG2 functie
        // if (draw_rectangle(x, y, width, height, color) != 0)
        // {
        //     return CMD_ERROR_EXECUTION_FAILED;
        // }

        return CMD_SUCCESS;
    }

    // Handle draw_text commando
    // Verwachte input: draw_text x y "text" color
    if (strcmp(cmd->command, "draw_text") == 0)
    {
        if (cmd->param_count < 4)
        {
            return CMD_ERROR_INVALID_PARAMS;
        }

        int x, y, color;
        if (parse_int_param(cmd->params[0], &x) != 0 ||
            parse_int_param(cmd->params[1], &y) != 0 ||
            parse_int_param(cmd->params[3], &color) != 0)
        {
            return CMD_ERROR_INVALID_PARAMS;
        }

        // TODO: Call LAAG2 functie
        // if (draw_text(x, y, cmd->params[2], color) != 0)
        // {
        //     return CMD_ERROR_EXECUTION_FAILED;
        // }

        return CMD_SUCCESS;
    }

    // Handle clear commando
    if (strcmp(cmd->command, "clear") == 0)
    {
        // TODO: Call LAAG2 functie
        // if (clear_screen() != 0)
        // {
        //     return CMD_ERROR_EXECUTION_FAILED;
        // }

        return CMD_SUCCESS;
    }

    // Handle help commando
    if (strcmp(cmd->command, "help") == 0)
    {
        // TODO: Display help informatie
        return CMD_SUCCESS;
    }

    // Handle exit commando
    if (strcmp(cmd->command, "exit") == 0)
    {
        // TODO: Handle exit
        return CMD_SUCCESS;
    }

    return CMD_ERROR_INVALID_COMMAND;
}
