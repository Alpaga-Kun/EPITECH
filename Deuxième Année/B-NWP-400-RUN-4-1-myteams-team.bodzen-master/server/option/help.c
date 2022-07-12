/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** help
*/

#include "server.h"

void cmd_help(int fd, char **command, data_t *d)
{
    (void)d;
    (void)command;
    char *buffer = read_file("./include/help");

    if (buffer == NULL) {
        dprintf(fd, "UNKNOWN\r\n");
        return;
    }
    dprintf(fd, "%s\r\n", buffer);
    return;
}
