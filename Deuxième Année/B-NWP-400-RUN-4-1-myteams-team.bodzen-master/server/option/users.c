/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** users
*/

#include "server.h"

int get_con(char *str, data_t *d)
{
    uuid_t uuid;
    char *str2 = strdup(str);

    str2 = strtok(str2, ",");
    uuid_parse(str2, uuid);
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (uuid_compare(uuid, d->client_tab[i].cli) == 0) {
            free(str2);
            return d->client_tab[i].status == CONNECTED ? 1 : 0;
        }
    }
    free(str2);
    return (0);
}

void cmd_list_usr(int fd, char **command, data_t *d)
{
    (void)command;
    char *buffer = NULL;
    char **username = NULL;

    buffer = read_file("storage/user/users.csv");
    username = strtab(buffer, ",\r\n");
    for (int i = 0; username[i] != NULL; i += 2) {
        dprintf(fd, "%.36s\n%s\n", username[i], username[i + 1]);
        dprintf(fd, "%d\n", get_con(username[i], d));
    }
    dprintf(fd, "\r\n");
    freetab(username);
    if (buffer != NULL)
        free(buffer);
}
