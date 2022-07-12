/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-panoramix-team.bodzen
** File description:
** main
*/

#include "../includes/inc.h"

static int panoramix(char **av)
{
    if (!verify_args(av))
        return (84);
    init(av);
    process();
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp("-h", av[1]) == 0) {
        fprintf(stdout, "%s", Usage);
        return (0);
    } else if (ac != 5) {
        fprintf(stderr, "To %s arguments.\n", (ac < 5) ? "few" : "much");
        return (84);
    } else
        return (panoramix(av));
    return (0);
}
