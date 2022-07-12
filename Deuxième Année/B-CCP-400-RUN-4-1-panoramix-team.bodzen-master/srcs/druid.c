/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-team.bodzen
** File description:
** druid
*/

#include "../includes/inc.h"

void dstart(void)
{
    fprintf(stdout, "Druid: I'm ready... but sleepy...\n");
}

void drefill(int refill)
{
    fprintf(stdout, "Druid: Ah! Yes, yes, I'm awake! Working on it! ");
    fprintf(stdout, "Beware I can only make ");
    fprintf(stdout, "%d more refills after this one.\n", refill);
}

void dfinish(void)
{
    fprintf(stdout, "Druid: I'm out of viscum. I'm going back to... zZz\n");
}
