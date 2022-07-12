/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-team.bodzen
** File description:
** villagers
*/

#include "../includes/inc.h"

void vilstart(int id)
{
    fprintf(stdout, "Villager %d: Going into battle!\n", id);
}

void vdrink(int id, int nb_servings_left)
{
    fprintf(stdout, "Villager %d: I need a drink... ", id);
    fprintf(stdout, "I see %d servings left.\n", nb_servings_left);
}

void vrefill(int id)
{
    fprintf(stdout, "Villager %d: Hey Pano wake up! ", id);
    fprintf(stdout, "We need more potion.\n");
}

void vfight(int id, int fight)
{
    fprintf(stdout, "Villager %d: Take that roman scum!", id);
    fprintf(stdout, " Only %d left.\n", fight);
}

void vfinish(int id)
{
    fprintf(stdout, "Villager %d: I'm going to sleep now.\n", id);
}
