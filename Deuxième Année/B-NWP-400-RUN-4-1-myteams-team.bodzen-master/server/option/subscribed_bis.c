/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** subscribed_bis
*/

#include "server.h"

char *create_pathname(char *team_name)
{
    char start[] = "storage/";
    char end[] = "/team_desc.csv";
    char dest[70] = {0};

    strcat(dest, start);
    strcat(dest, team_name);
    strcat(dest, end);
    return strdup(dest);
}

char *get_username(char *user)
{
    int i = 0;
    char *buffer = read_file("storage/user/users.csv");
    char **username = NULL;

    if (buffer == NULL) {
        printf("ERROR READ\n");
        return "";
    }
    username = strtab(buffer, ",\r\n");
    for (; username[i] != NULL; i += 1) {
        if (strcmp(user, username[i]) == 0)
            return (username[++i]);
    }
    freetab(username);
    if (buffer != NULL)
        free(buffer);
    return "None";
}
