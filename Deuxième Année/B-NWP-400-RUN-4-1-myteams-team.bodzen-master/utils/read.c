/*
** EPITECH PROJECT, 2022
** B-NWP-400-RUN-4-1-myteams-team.bodzen
** File description:
** read
*/

#include "server.h"

char *read_file(char const *path)
{
    FILE *infile = NULL;
    char *buffer = NULL;
    long numbytes = 0;
    infile = fopen(path, "r+");

    if (infile == NULL)
        return (NULL);
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);
    fseek(infile, 0L, SEEK_SET);
    buffer = malloc(sizeof(char) * (numbytes + 1));
    if (buffer == NULL)
        return (NULL);
    fread(buffer, sizeof(char), numbytes, infile);
    buffer[numbytes] = 0;
    fclose(infile);
    return (buffer);
}
