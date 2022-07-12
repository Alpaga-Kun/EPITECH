/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** help
*/

#include "client.h"

void show_help(char **command, data_t *d)
{
    char buff[1024] = {0};

    (void)command;
    dprintf(d->socket_fd, "HELP\r\n");
    read(d->socket_fd, buff, 1024);
    if (strcmp("UNKNOWN\r\n", buff) == 0) {
        printf("Cannot display help. Please retyr later.\n");
        fflush(stdout);
    } else
        printf("HELP:\n%s", buff);
}
