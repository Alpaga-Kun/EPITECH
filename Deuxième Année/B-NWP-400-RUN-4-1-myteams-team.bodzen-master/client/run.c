/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** run
*/

#include "client.h"

void check_fd(data_t *d)
{
    ssize_t state = 0;
    int i = 0;
    char buff[1024] = {0};

    while (i < FD_SETSIZE) {
        if (FD_ISSET(i, &d->readfds_cpy) && i == 0) {
            state = read(0, buff, 1024);
            switch (state) {
                case 0: exit(0); break;
                case 1: continue; break;
                default: check_command(buff, d); break;
            }
        }
        i++;
    }
}

int run_client(data_t *d)
{
    FD_ZERO(&d->readfds);
    FD_ZERO(&d->writefds);
    FD_SET(d->socket_fd, &d->readfds);
    FD_SET(0, &d->readfds);
    while (42) {
        d->tv = (struct timeval) {30, 0};
        d->readfds_cpy = d->readfds;
        d->writefds_cpy = d->writefds;
        if (select(FD_SETSIZE, &d->readfds_cpy, &d->writefds_cpy, 0, &d->tv) >
        0)
            check_fd(d);
    }
    return (0);
}
