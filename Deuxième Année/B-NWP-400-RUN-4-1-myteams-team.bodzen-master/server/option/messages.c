/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** messages
*/

#include "server.h"

void cmd_list_message(int fd, char **command, data_t *d)
{
    (void)d;
    char *message = 0;
    char directory[PATH_MAX] = {0};

    sprintf(directory, "storage/message/%s/user.csv", command[1]);
    if ((message = read_file(directory)) != NULL)
        dprintf(fd, "%s\n", message);
    return;
}
