/*
** EPITECH PROJECT, 2022
** B-PSU-400-RUN-4-1-malloc-team.bodzen
** File description:
** my_malloc
*/

#include "../includes/memory.h"

block_t *_head = NULL;

void *malloc(size_t size)
{
    block_t *memblock = NULL;

    if (!size)
        return (NULL);
    if (_head == NULL)
        return (init_memblock(size));
    memblock = search_memblock(_head, size);
    if (memblock != NULL)
        return (memblock->_ptr);
    return (NULL);
}
