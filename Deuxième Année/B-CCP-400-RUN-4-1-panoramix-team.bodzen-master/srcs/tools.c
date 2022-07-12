/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-team.bodzen
** File description:
** tools
*/

#include "../includes/inc.h"

static bool isDigit(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            continue;
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool verify_args(char **av)
{
    for (int i = 1; av[i] != NULL; i++) {
        if (!isDigit(av[i])) {
            fprintf(stderr, "Must be a positive digit.\n");
            return (false);
        }
        if (atoi(av[i]) < 1) {
            fprintf(stderr, "%sMust be >0.\n", Usage);
            return (false);
        }
    }
    return (true);
}
