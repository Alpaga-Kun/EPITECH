/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** user
*/

#include "client.h"

void get_info_usr(char **command, data_t *d)
{
    char buff[72] = {0};
    char *uuid = 0;
    char *name = 0;
    char *status = 0;

    if (command[1][0] == '\"' && command[1][strlen(command[1]) - 1] == '\"') {
        dprintf(d->socket_fd, "USER %s\r\n", strtok(command[1], "\""));
        read(d->socket_fd, buff, 72);
        if (strcmp(buff, "UNKNOW\r\n") == 0) {
            client_error_unknown_user(strtok(command[1], "\""));
            return;
        }
        uuid = strtok(buff, ",");
        name = strtok(NULL, " ");
        status = strtok(NULL, "\r");
        client_print_user(uuid, name, strtol(status, NULL, 10));
    }
}
