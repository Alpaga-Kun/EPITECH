/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** main
*/

#include "client.h"

data_t *setter(data_t *d)
{
    d->directory = NULL;
    d->is_con = false;
    d->new_msg = false;
    d->old = 0;
    d->sock_len = 0;
    d->socket_fd = 0;
    return (d);
}

int main(int ac, char **av)
{
    data_t *d = malloc(sizeof(data_t));
    d = setter(d);

    if (ac < 3)
        return (84);
    if (connect_server(d, av) == -1)
        return 84;
    run_client(d);
    if (d->directory != NULL)
        free(d->directory);
    free(d);
    return 0;
}
