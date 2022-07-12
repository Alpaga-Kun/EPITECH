/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** users
*/

#include "client.h"

void print_list(data_t *d, char *buff)
{
    char *uuid = 0;
    char *name = 0;
    char *status = 0;

    for (int i = 0, count = 0;; i++) {
        read(d->socket_fd, &buff[i], 1);
        if (buff[i] == '\n')
            count++;
        if (buff[i] == '\n' && buff[i - 1] == '\r')
            return;
        if (count == 3) {
            uuid = strtok(buff, "\n");
            name = strtok(NULL, "\n");
            status = strtok(NULL, "\n");
            client_print_users(uuid, name, strtol(status, NULL, 10));
            count = 0;
            i = -1;
        }
    }
}

void get_list_usr(char **command, data_t *d)
{
    (void)command;
    char buff[72] = {0};

    dprintf(d->socket_fd, "USERS\r\n");
    print_list(d, buff);
}
