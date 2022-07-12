/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** logout
*/

#include "client.h"

void get_disconnect(char **command, data_t *d)
{
    (void)command;
    char buff[50] = {0};
    char uuid[37] = {0};

    dprintf(d->socket_fd, "LOGOUT\r\n");
    read(d->socket_fd, buff, 50);
    if (strcmp("LOGOUT\r\n", buff) == 0)
        d->is_con = false;
    uuid_unparse_upper(d->uuid, uuid);
    client_event_logged_out(uuid, d->name);
    exit(0);
}
