/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** toupper
*/

#include "client.h"

char *command_toupper(char *line, size_t lenght)
{
    int j = 0;
    char *tmp = malloc(sizeof(char) * (lenght + 1));

    for (int i = 1; line[i] != '\0'; i++, j++)
        tmp[j] = toupper(line[i]);
    tmp[j] = '\0';
    return (tmp);
}
