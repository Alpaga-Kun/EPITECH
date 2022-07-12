/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** subscribed
*/

#include "client.h"

void print_teams(data_t *d, char *buff)
{
    char *team_uuid = NULL;
    char *team_name = NULL;
    char *team_descr = NULL;

    for (int i = 0, count = 0;; i++) {
        read(d->socket_fd, &buff[i], 1);
        if (buff[i] == '\n')
            count++;
        if (buff[i] == '\n' && buff[i - 1] == '\r')
            return;
        if (count == 3) {
            team_uuid = strtok(buff, "\n");
            team_name = strtok(NULL, "\n");
            team_descr = strtok(NULL, "\n");
            client_print_teams(team_uuid, team_name, team_descr);
            count = 0;
            i = -1;
        }
    }
}

void print_subs(data_t *d, char *buff)
{
    char *uuid = 0;
    char *name = 0;
    char *status = 0;

    for (int i = 0, count = 0;; i++) {
        read(d->socket_fd, &buff[i], 1);
        if (buff[i - 1] == '\r' && buff[i] == '\n')
            break;
        if (buff[i] == '\n')
            count++;
        if (count == 3) {
            uuid = strtok(buff, "\n");
            name = strtok(NULL, "\n");
            status = strtok(NULL, "\n");
            client_print_users(uuid, name, strtol(status, NULL, 10));
            count = 0;
            i = -1;
        }
    }
}

void list_sub(char **command, data_t *d)
{
    char buff[1024] = {0};
    memset(buff, '\0', 1024);

    dprintf(d->socket_fd, "SUBD %s\r\n", (command[1] == NULL ? "NULL" :
        command[1]));
    if (command[1] == NULL) {
        print_teams(d, buff);
        return;
    } else {
        read(d->socket_fd, buff, 10);
        if (strcmp(buff, "OK\r\n") == 0) {
            print_subs(d, buff);
            return;
        } else if (strcmp(buff, "UNKNOWN\r\n") == 0)
            client_error_unknown_team(command[1]);
    }
}
