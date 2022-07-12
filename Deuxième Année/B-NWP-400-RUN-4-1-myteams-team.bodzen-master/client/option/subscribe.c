/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** subscribe
*/

#include "client.h"

void get_sub(char **command, data_t *d)
{
    char buff[50] = {0};
    char usr_uuid[37] = {0};

    dprintf(d->socket_fd, "SUB %s\r\n", command[1]);
    read(d->socket_fd, buff, 50);
    if (strcmp(buff, "UNKNOWN\r\n") == 0) {
        client_error_unknown_team(command[1]);
        return;
    } else if (strcmp(buff, "OK\r\n") == 0) {
        uuid_unparse_upper(d->uuid, usr_uuid);
        client_print_subscribed(usr_uuid, command[1]);
    }
}
