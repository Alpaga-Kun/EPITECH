/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Ticket
*/

#include "Ticket.hpp"

Ticket::Ticket(std::string const &name, std::string const &size,
                    double multiplayer, std::size_t id)
{
    this->_pizzaName = name;
    this->_pizzaSize = size;
    this->_multiplayer = multiplayer;
    this->_id = id;
}

Ticket::~Ticket()
{
}

std::string Ticket::getPizzaName() const
{
    return this->_pizzaName;
}

std::string Ticket::getPizzaSize() const
{
    return this->_pizzaSize;
}

double Ticket::getPizzaMultiplayer() const
{
    return this->_multiplayer;
}

std::size_t Ticket::getPizzaId() const
{
    return this->_id;
}