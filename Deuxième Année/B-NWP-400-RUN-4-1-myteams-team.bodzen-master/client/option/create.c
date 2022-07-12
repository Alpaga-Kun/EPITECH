/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** create
*/

#include "client.h"

bool path_use(data_t *d, char const *format)
{
    int occ = 0;
    if (strstr(format, "team") != NULL)
        return (true);
    if (d->directory != NULL) {
        for (int i = 0; d->directory[i] != '\0'; i++)
            (d->directory[i] == '/' ? occ++ : 0);
        occ--;
        if (strstr(format, "channel") != NULL && occ == 2)
            return (true);
        if (strstr(format, "thread") != NULL && occ == 3)
            return (true);
    }
    return (false);
}

void event_creation(char **stock, char **cmd)
{
    if (strcmp(stock[0], "team") == 0)
        client_event_team_created(stock[2], stock[1], (cmd[2] == NULL ?
            "None" : cmd[2]));
    if (strcmp(stock[0], "channel") == 0)
        client_event_channel_created(stock[2], stock[1],
            (cmd[2] == NULL ? "None" : cmd[2]));
    if (strcmp(stock[0], "thread") == 0)
        client_event_thread_created(stock[2], "user_uuid", time(NULL),
            stock[1], cmd[2]);
}

void creating(char **cmd, data_t *d)
{
    size_t size = (strlen(cmd[1]) - 1) + 37;
    char buff[size + 3];
    char **stock = NULL;
    bzero(buff, sizeof(buff));

    if (strncmp(cmd[1], "thread", strlen("thread")) == 0)
        if (cmd[2] == NULL)
            return;
    if (path_use(d, cmd[1]) == false)
        return;
    dprintf(d->socket_fd, "%s %s %s\r\n", command_toupper(cmd[0],
        strlen(cmd[0])), cmd[1], (cmd[2] == NULL ? "None" : cmd[2]));
    read(d->socket_fd, buff, sizeof(buff));
    stock = strtab(buff, "\n ");
    event_creation(stock, cmd);
    freetab(stock);
}
