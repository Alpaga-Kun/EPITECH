/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** login
*/

#include "client.h"

bool is_logged(data_t *d)
{
    if (d->is_con == true)
        return (true);
    return (false);
}

void set_log(char **command, data_t *d)
{
    if (strlen(command[1]) > MAX_NAME_LENGTH) {
        return;
    }
    if ((command[1][0] == '\"' &&
        command[1][strlen(command[1]) - 1] == '\"') && is_logged(d) == false)
            get_login(command, d);
}

int get_login(char **command, data_t *d)
{
    char buff[37] = {0};
    size_t lenght = strlen(command[1]);

    dprintf(d->socket_fd, "%s %s\r\n",
        command_toupper(command[0], lenght), strtok(command[1], "\""));
    read(d->socket_fd, buff, 36);
    snprintf(d->name, 32, "%s", strtok(command[1], "\""));
    uuid_parse(buff, d->uuid);
    d->is_con = true;
    client_event_logged_in(buff, d->name);
    strcpy(d->user_uuid, buff);
    read(d->socket_fd, buff, 5);
    return (0);
}
