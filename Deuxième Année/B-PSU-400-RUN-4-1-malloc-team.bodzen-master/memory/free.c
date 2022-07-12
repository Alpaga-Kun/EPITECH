/*
** EPITECH PROJECT, 2022
** B-PSU-400-RUN-4-1-malloc-team.bodzen
** File description:
** free
*/

#include "../includes/memory.h"

void free(void *ptr)
{
    block_t *block = ptr - sizeof(block_t);

    if (!ptr)
        return;
    block->isFree = true;
}
