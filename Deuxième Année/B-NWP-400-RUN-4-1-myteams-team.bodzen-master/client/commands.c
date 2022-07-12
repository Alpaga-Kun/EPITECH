/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** commands
*/

#include "client.h"

static bool verify_quotes(char **command)
{
    int end = 0;
    char dump[256] = {0};
    char *res = NULL;

    if (command[0] == NULL)
        return (false);
    if (command[1] != NULL) {
        for (int i = 1; command[i] != NULL; i++) {
            strcpy(dump, command[i]);
            res = strtok(dump, "\"");
            if (!res)
                return (false);
            end = strlen(command[i]) - 1;
            if (!(command[i][0] == '\"' && command[i][end] == '\"'))
                return (false);
        }
    }
    return (true);
}

static bool verify_args(char **command)
{
    char **tmp = NULL;

    if (strcmp("/create", command[0]) == 0 && command[1] != NULL) {
        tmp = strtab(strdup(command[1]), "\"_");
        if (tmp[1] != NULL) {
            freetab(tmp);
            return (true);
        }
        freetab(tmp);
        return (false);
    }
    return (true);
}

void selection(char **command, data_t *d)
{
    ptr_option option[] = {
        {"/help", &show_help}, {"/login", &set_log},
        {"/logout", &get_disconnect}, {"/users", &get_list_usr},
        {"/user", &get_info_usr}, {"/send", &send_message},
        {"/messages", &list_message}, {"/subscribe", &get_sub},
        {"/subscribed", &list_sub}, {"/unsubscribe", &get_unsub},
        {"/use", &use_fnc}, {"/create", &creating},
        {"/list", &listing}, {"/info", &get_info}
    };
    for (int i = 0; i != 14; i++) {
        if (strcmp(command[0], option[i].option) == 0) {
            ((d->is_con == true || strcmp(command[0], "/login") == 0) &&
            verify_args(command) == true) ?
                option[i].ptr(command, d) : 0;
        }
    }
}

int check_command(char *str, data_t *d)
{
    size_t len = 0;
    char **command = strtab(str, "\n\t ");

    if (verify_quotes(command) == true) {
        for (; command[len]; len++);
        if ((len > 1 && len < 6) || (strcmp(command[0], "/list") == 0
            || strcmp(command[0], "/info") == 0)
            || (strcmp(command[0], "/help") == 0)
            || (strcmp(command[0], "/logout") == 0)
            || (strcmp(command[0], "/users") == 0)
            || (strcmp(command[0], "/subscribed") == 0))
            selection(command, d);
        freetab(command);
        if (d->is_con == false)
            return 0;
        update_message(d);
    }
    return (0);
}
