/*
** EPITECH PROJECT, 2022
** B-PSU-400-RUN-4-1-malloc-team.bodzen
** File description:
** my_realloc
*/

#include "../includes/memory.h"

void *realloc(void *ptr, size_t size)
{
    void *tmp = NULL;

    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (malloc(size));
    tmp = malloc(size);
    if (tmp)
        memcpy(tmp, ptr, size);
    if (ptr)
        free(ptr);
    return (tmp);
}
