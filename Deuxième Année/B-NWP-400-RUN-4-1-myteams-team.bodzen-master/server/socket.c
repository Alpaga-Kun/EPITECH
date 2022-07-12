/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** socket
*/

#include "server.h"

int create_socket(data_t *d, char *port)
{
    struct sockaddr *sockaddr = (struct sockaddr *)&d->sockaddr;

    d->socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    d->sockaddr.sin_family = AF_INET;
    d->sockaddr.sin_port = htons(strtol(port, NULL, 10));
    d->sock_len = sizeof(d->sockaddr);
    if (d->socket_fd < 0)
        return (-1);
    setsockopt(d->socket_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
    inet_aton("127.0.0.1", &d->sockaddr.sin_addr);
    if (bind(d->socket_fd, sockaddr, d->sock_len) == -1)
        return (-1);
    if (listen(d->socket_fd, FD_SETSIZE) == -1)
        return (-1);
    return (0);
}

int check_fd_set(data_t *d)
{
    int i = 0;
    int cli_fd = 0;
    struct sockaddr *sockaddr = (struct sockaddr *)&d->cliaddr;

    while (i < FD_SETSIZE) {
        if (FD_ISSET(i, &d->readfds_cpy) && i == d->socket_fd) {
            cli_fd = accept(d->socket_fd, sockaddr, &d->sock_len);
            FD_SET(cli_fd, &d->readfds);
        } else if (FD_ISSET(i, &d->readfds_cpy))
            get_commands(i, d);
        i++;
    }
    return (0);
}

int check_connection(data_t *d)
{
    if (select(FD_SETSIZE, &d->readfds_cpy, &d->writefds_cpy, 0, &d->tv) > 0)
        check_fd_set(d);
    return (0);
}

int run_server(data_t *d)
{
    FD_ZERO(&d->readfds);
    FD_ZERO(&d->writefds);
    FD_SET(d->socket_fd, &d->readfds);
    while (42) {
        d->tv = (struct timeval) {30, 0};
        d->readfds_cpy = d->readfds;
        d->writefds_cpy = d->writefds;
        check_connection(d);
    }
    close(d->socket_fd);
    return (0);
}
