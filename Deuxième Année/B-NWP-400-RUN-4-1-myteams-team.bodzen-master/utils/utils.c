/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** utils
*/

#include "server.h"

char *rm_end(char *cmd)
{
    int i = 0;
    char *s = malloc(sizeof(char) * (strlen(cmd)));

    for (; cmd[i] != '\n'; i++)
        s[i] = cmd[i];
    s[i] = '\0';
    return s;
}

char *get_team_id(char *team_name)
{
    char dest[37] = {0};

    strncat(dest, team_name, 36);
    return strdup(dest);
}
