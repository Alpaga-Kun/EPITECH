/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** use
*/

#include "client.h"

void use_fnc(char **command, data_t *d)
{
    size_t lenght = 0;
    char buff[PATH_MAX] = {0};

    bzero(buff, PATH_MAX);
    for (; command[lenght] != NULL; lenght++);
    switch (lenght) {
    case 3: dprintf(d->socket_fd, "%s %s %s\r\n",
        command_toupper(command[0], strlen(command[0])), command[1],
        command[2]); break;
    case 4: dprintf(d->socket_fd, "%s %s %s %s\r\n",
        command_toupper(command[0], strlen(command[0])), command[1],
        command[2], command[3]); break;
    default: dprintf(d->socket_fd, "%s %s\r\n",
        command_toupper(command[0], strlen(command[0])), command[1]); break;
    }
    read(d->socket_fd, buff, PATH_MAX);
    if (d->directory != NULL)
        free(d->directory);
    d->directory = strdup(buff);
    return;
}
