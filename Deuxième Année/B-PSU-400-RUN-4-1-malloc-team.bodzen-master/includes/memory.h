/*
** EPITECH PROJECT, 2022
** B-PSU-400-RUN-4-1-malloc-team.bodzen
** File description:
** memory
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define _BLOCKSIZE_(size) (sizeof(block_t)+size)

void *malloc(size_t size);
void free (void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
typedef struct block_s
{
    bool isFree;
    void *_ptr;
    size_t _size;
    struct block_s *next;
} block_t;

extern block_t *_head;

void *alloc(size_t size, void *pos);
void *init_memblock(size_t size);
block_t *search_memblock(block_t *_block, size_t size);
