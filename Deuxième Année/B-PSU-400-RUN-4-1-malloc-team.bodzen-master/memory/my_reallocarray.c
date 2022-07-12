/*
** EPITECH PROJECT, 2022
** B-PSU-400-RUN-4-1-malloc-team.bodzen
** File description:
** my_reallocarray
*/

#include "../includes/memory.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}
