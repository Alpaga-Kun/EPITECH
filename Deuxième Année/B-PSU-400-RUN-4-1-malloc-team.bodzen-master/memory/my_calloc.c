/*
** EPITECH PROJECT, 2022
** B-PSU-400-RUN-4-1-malloc-team.bodzen
** File description:
** my_calloc
*/

#include "../includes/memory.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    if (ptr == NULL)
        return (NULL);
    memset(ptr, 0, nmemb * size);
    return (ptr);
}
