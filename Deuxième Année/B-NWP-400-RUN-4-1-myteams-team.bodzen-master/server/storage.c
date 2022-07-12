/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** storage
*/

#include "server.h"
#include <ctype.h>

void print_saved_user(void)
{
    char *buffer = NULL;
    char **username = NULL;

    buffer = read_file("storage/user/users.csv");
    username = strtab(buffer, ",\r\n");
    for (int i = 0; username[i] != NULL; i += 2)
        server_event_user_loaded(username[i], username[i + 1]);
    freetab(username);
    if (buffer != NULL)
        free(buffer);
}

int is_storage_exist(void)
{
    DIR *dp = NULL;

    if ((dp = opendir("storage")) == NULL) {
        if (mkdir("storage", 0700) == -1)
            return (-1);
    } else
        print_saved_user();
    closedir(dp);
    return (0);
}
