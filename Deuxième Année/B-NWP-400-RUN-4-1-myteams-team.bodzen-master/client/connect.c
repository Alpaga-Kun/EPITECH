/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** main
*/

#include "client.h"

int connect_server(data_t *d, char **av)
{
    struct sockaddr *sockaddr = (struct sockaddr *)&d->sockaddr;

    d->socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    d->sockaddr.sin_family = AF_INET;
    d->sockaddr.sin_port = htons(strtol(av[2], NULL, 10));
    d->sock_len = sizeof(d->sockaddr);
    if (d->socket_fd < 0)
        return (-1);
    setsockopt(d->socket_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
    inet_aton(av[1], &d->sockaddr.sin_addr);
    if (connect(d->socket_fd, sockaddr, d->sock_len) == -1)
        return -1;
    return (0);
}
