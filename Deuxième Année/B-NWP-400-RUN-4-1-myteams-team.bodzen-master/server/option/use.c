/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** use
*/

#include "server.h"

void cmd_using(int fd, char **command, data_t *d)
{
    DIR *dp = NULL;
    int len = 0;
    char directory[PATH_MAX] = {0};

    for (int i = 1; command[i] != NULL; i++, len++);
    switch (len) {
        case 1: sprintf(directory, "./storage/%s/", command[1]); break;
        case 2: sprintf(directory, "./storage/%s/%s/",
            command[1], command[2]); break;
        case 3: sprintf(directory, "./storage/%s/%s/%s/", command[1],
            command[2], command[3]); break;
        default: sprintf(directory, "./storage/");break;
    }
    dp = opendir(directory);
    if (dp != NULL) {
        if (d->directory != NULL)
            free(d->directory);
        d->directory = strdup(directory);
        dprintf(fd, "%s", directory);
    } else
        dprintf(fd, "NULL");
    closedir(dp);
    return;
}
