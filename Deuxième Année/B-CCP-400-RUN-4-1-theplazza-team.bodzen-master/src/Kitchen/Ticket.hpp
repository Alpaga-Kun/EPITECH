/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Ticket
*/

#pragma once
#include <string>


class Ticket {
    public:
        Ticket(std::string const &name, std::string const &size,
                                double multiplayer, std::size_t id);
        ~Ticket();

        std::string getPizzaName() const;
        std::string getPizzaSize() const;
        double getPizzaMultiplayer() const;
        std::size_t getPizzaId() const;

    protected:
    private:
        std::string _pizzaName;
        std::string _pizzaSize;
        double _multiplayer;
        std::size_t _id;
};
