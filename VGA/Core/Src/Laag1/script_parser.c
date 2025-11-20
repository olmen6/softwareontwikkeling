/**
 * @file script_parser.c
 * @brief Uitvoering van script parsing fubnctionaliteit
 * @author Melle
 */

#include "script_parser.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Parse een script command string naar command en parameters
 * @param input raw input string
 * @param cmd Pointer naar parsed_command_t structure om te vullen
 * @retval 0 bij success
 * @retval -1 bij parse error
 */
int script_parser(const char *input, parsed_command_t *cmd)
{
	// Controleer of er input is
    if (input == NULL || cmd == NULL)
    {
        return -1;
    }

    // Wis oude data
    clear_parsed_command(cmd);

    // Kopieer de inhoud van de input naar een buffer
    // Dit is omdat met strtok straks de string aangepast moet worden
    // Strtok splitst de string op spaties en plaatst er \0
    char buffer[MAX_COMMAND_LENGTH];
    strncpy(buffer, input, MAX_COMMAND_LENGTH - 1);
    buffer[MAX_COMMAND_LENGTH - 1] = '\0';

    // Negeer newline als die aanwezig is
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }

    // Skip lege commands
    if (strlen(buffer) == 0)
    {
        return -1;
    }

    // Eerste token van string is commando ID
    char *token = strtok(buffer, " ");
    if (token == NULL)
    {
        return -1;
    }

    // Slaan het commando ID op
    strncpy(cmd->command, token, MAX_COMMAND_LENGTH - 1);
    cmd->command[MAX_COMMAND_LENGTH - 1] = '\0';

    // Overgebleven tokens worden als argumenten geparsed en opgeslagen
    // Gebruik van Malloc omdat params moeten blijven betsaan na het verlaten van deze functie
    // De bufferverdwijnt dan namelijk, dus kopieer params naar dynamisch geheugen malloc
    cmd->param_count = 0;
    while ((token = strtok(NULL, " ")) != NULL && cmd->param_count < MAX_PARAMS)
    {
        cmd->params[cmd->param_count] = malloc(strlen(token) + 1);
        if (cmd->params[cmd->param_count] == NULL)
        {
            return -1;
        }
        strcpy(cmd->params[cmd->param_count], token);
        cmd->param_count++;
    }

    return validate_command_syntax(cmd);
}


/**
 * @brief Valideer de commando syntax
 * @details Checks if command is recognized
 * @param cmd Pointer naar parsed_command_t structure
 * @retval 1 als valid
 * @retval 0 als invalid
 */
int validate_command_syntax(const parsed_command_t *cmd)
{
    // Lijst met herkende commando's
    const char *valid_commands[] =
    {
        "draw_line",
        "draw_rect",
        "draw_text",
        "draw_bitmap",
        "clear",
        "help",
        "exit",
        NULL
    };

    for (int i = 0; valid_commands[i] != NULL; i++)
    {
        if (strcmp(cmd->command, valid_commands[i]) == 0)
        {
            return 0;  // Succes
        }
    }
    return -1;  // Ongeldige command
}

/**
 * @brief Clear/reset a parsed command structure
 * @details Frees allocated memory and resets structure
 * @param cmd Pointer to parsed_command_t structure
 */
/**
 * @brief Clear/reset geparsed command struct
 * @details Geeft malloc nvan opgeslagen gommands weer vrij
 * @param cmd Pointer naar parsed_command_t struct
 */
void clear_parsed_command(parsed_command_t *cmd)
{
    if (cmd == NULL)
    {
        return;
    }

    // Geef parameter memory vrij
    for (int i = 0; i < cmd->param_count; i++)
    {
        if (cmd->params[i] != NULL)
        {
            free(cmd->params[i]);
            cmd->params[i] = NULL;
        }
    }
    cmd->param_count = 0;
    cmd->command[0] = '\0';
}
