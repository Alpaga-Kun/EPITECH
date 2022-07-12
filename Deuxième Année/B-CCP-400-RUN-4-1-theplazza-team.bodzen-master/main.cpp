/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** main
*/

#include "inc.h"
#include "src/Reception/Reception.hpp"
#include "src/Clock.hpp"
#include "src/SafeQueue.hpp"

void check_digit(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
        for (int y = 0; av[i][y] != '\0'; y++)
            if (!isdigit(av[i][y]))
                throw std::invalid_argument("Error: Only digits expected");
}

int main(int ac, char **av)
{
    clockValue start;
    clockValue end;
    std::string command = "Regina";

    if (ac != 4) {
        std::cerr << "Too " << (ac < 4 ? "few" : "much") << " arguments" << std::endl;
        std::exit(84);
    }
    try {
        float multiplier = std::atof(av[1]);
        std::size_t nbCooker = std::atoi(av[2]);
        float time = std::atof(av[3]);

        check_digit(ac, av);
        Reception *reception = new Reception(multiplier, nbCooker, time);
        Parser *parser = new Parser();

        parser->update(reception);
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        std::exit(84);
    }
    return (0);
}
