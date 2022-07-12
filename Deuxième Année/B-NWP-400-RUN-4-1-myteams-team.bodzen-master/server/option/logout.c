/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** logout
*/

#include "server.h"

void cmd_disc(int fd, char **command, data_t *d)
{
    (void)command;
    char uuid[36] = {0};

    dprintf(fd, "LOGOUT\r\n");
    FD_CLR(fd, &d->readfds);
    d->client_tab[fd].status = DISCONNECTED;
    d->client_tab[fd].name[0] = 0;
    uuid_unparse_upper(d->client_tab[fd].cli, uuid);
    server_event_user_logged_out(uuid);
    uuid_clear(d->client_tab[fd].team);
    uuid_clear(d->client_tab[fd].channel);
    uuid_clear(d->client_tab[fd].thread);
    uuid_clear(d->client_tab[fd].cli);
    d->client_tab[fd].use_cont = UNDEFINE;
    close(fd);
}
