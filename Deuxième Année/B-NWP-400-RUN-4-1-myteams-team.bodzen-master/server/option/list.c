/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** list
*/

#include "server.h"

void cmd_listing(int fd, char **command, data_t *d)
{
    (void)fd;
    (void)command;
    (void)d;
    int count = 0;
    struct dirent *dir = {0};
    DIR *fold = opendir("./storage/");

    if (fold == NULL) {
        return;
    }
    while ((dir = readdir(fold)) != NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;
        count++;
    }
    closedir(fold);
    if (count == 0) {
        return;
    }
}
