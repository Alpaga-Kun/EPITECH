/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** totab
*/

#include "client.h"

void freetab(char **tabs)
{
    if (tabs != NULL) {
        for (int i = 0; tabs[i] != NULL; i++)
            free(tabs[i]);
        free(tabs);
    }
}

char **strtab(char *line, char const *delim)
{
    char *ptr = NULL;
    char **tabs = NULL;
    size_t i = 0;

    ptr = strtok(line, delim);

    while (ptr != NULL) {
        tabs = realloc(tabs, ((i + 1) * sizeof(char *)));
        tabs[i] = strdup(ptr);
        ptr = strtok(NULL, delim);
        i = i + 1;
    }
    tabs = realloc(tabs, ((i + 1) * sizeof(char *)));
    tabs[i] = NULL;
    return (tabs);
}
