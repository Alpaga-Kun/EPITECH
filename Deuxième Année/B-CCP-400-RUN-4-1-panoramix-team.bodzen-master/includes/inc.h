/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-team.bodzen
** File description:
** inc
*/

#pragma once

#define Usage "USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>\n"

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include<pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <semaphore.h>
typedef struct data_s
{
    int id;
    long int nb_villagers;
    long int pot_size;
    long int pot_max;
    long int nb_fights;
    long int nb_refills;
} data_t;

void init(char **av);
int process(void);

bool verify_args(char **av);

void dstart(void);
void drefill(int refill);
void dfinish(void);

void vilstart(int id);
void vdrink(int id, int nb_servings_left);
void vrefill(int id);
void vfight(int id, int fight);
void vfinish(int id);
