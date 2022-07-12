/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** main
*/

#include "server.h"

data_t *setter(data_t *d)
{
    d->directory = NULL;
    d->sock_len = 0;
    d->socket_fd = 0;
    return (d);
}

void free_ptr(data_t *d)
{
    if (d->directory != NULL)
        free(d->directory);
    free(d);
}

int main(int ac, char **av)
{
    data_t *d = malloc(sizeof(data_t));
    d = setter(d);

    if (ac < 2)
        return (84);
    if (is_storage_exist() == -1)
        return (84);
    if (create_socket(d, av[1]) == -1)
        return (84);
    run_server(d);
    free_ptr(d);
    return 0;
}
