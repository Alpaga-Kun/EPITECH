/*
** EPITECH PROJECT, 2022
** B-PSU-400-RUN-4-1-malloc-team.bodzen
** File description:
** allocation
*/

#include "../includes/memory.h"

static size_t space_left = 0;

void *action(size_t size)
{
    void *new = sbrk(size);
    return (new == (void*)-1 ? NULL : new);
}

size_t getpage(size_t size)
{
    size_t page = getpagesize() * 2;

    while (page < _BLOCKSIZE_(size))
        page += getpagesize() * 2;
    return (page);
}

void *init_memblock(size_t size)
{
    size_t tmp = getpage(size);
    _head = action(tmp);

    if (_head == NULL)
        return (NULL);
    space_left = tmp - _BLOCKSIZE_(size);
    _head->isFree = false;
    _head->_ptr = (char*)_head + sizeof(block_t);
    _head->_size = size;
    _head->next = NULL;
    return (_head->_ptr);
}

void *alloc(size_t size, void *pos)
{
    block_t *new = pos;
    size_t page = getpage(size);

    if (space_left < _BLOCKSIZE_(size)) {
        if (action(page) == NULL)
            return (NULL);
        space_left += page;
    }
    space_left -= _BLOCKSIZE_(size);
    new->isFree = false;
    new->_ptr = (char*)new + sizeof(block_t);
    new->_size = size;
    new->next = NULL;
    return (new);
}

block_t *search_memblock(block_t *_block, size_t size)
{
    block_t *prev = NULL;

    while (_block != NULL) {
        prev = _block;
        if (_block->isFree == true && _block->_size >= size) {
            _block->isFree = false;
            return (_block);
        }
        _block = _block->next;
    }
    prev->next = alloc(size, (void*)prev+_BLOCKSIZE_(prev->_size));
    return (prev->next);
}
