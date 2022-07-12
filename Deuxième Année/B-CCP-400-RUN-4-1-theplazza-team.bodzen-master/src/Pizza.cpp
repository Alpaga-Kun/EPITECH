/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Pizza
*/

#include "Pizza.hpp"
#include "Log.hpp"
#include <string>

static prep_time_t times[4] = {
    {"Margarita", 1},
    {"Regina", 2},
    {"Americana", 2},
    {"Fantasia", 4}
};

Pizza::Pizza(std::string const &name, std::string const &format,
                double const &multiplayer, std::size_t const &id)
{
    this->_name = name;
    this->_size = format;
    this->_multiplayer = multiplayer;
    this->_id = id;
    this->setPreparationTime();
}

Pizza::~Pizza()
{
}

void Pizza::setPreparationTime()
{
    auto cmp = [](char const first, char const second)
    {
        return first == second || tolower(first) == second || toupper(first) == second;
    };
    for (std::size_t i = 0; i < PIZZAS; i++) {
        for (std::size_t j = 0; j < this->_name.size(); j++) {
            if (!cmp(this->_name[j], times[i].pizzaName[j]))
                break;
            if (j == this->_name.size() - 1) {
                this->_prepTime = times[i].prepTime * this->_multiplayer;
                return;
            }
        }
    }
}

bool Pizza::isCooked()
{
    return this->_cooked;
}

void Pizza::setCooked(bool isCooked)
{
    this->_cooked = isCooked;
}

int Pizza::getPrepTime()
{
    return this->_prepTime;
}

std::string &Pizza::getName()
{
    return this->_name;
}

std::string &Pizza::getFormat()
{
    return this->_size;
}