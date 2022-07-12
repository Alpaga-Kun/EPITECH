/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Pizza
*/

#pragma once

#include <string>

#define PIZZAS 4

typedef struct prep_time_s {
    std::string pizzaName;
    double prepTime;
} prep_time_t;

class Pizza {
    public:
        bool isCooking = false;

        Pizza(std::string const &name, std::string const &format,
                    double const &prepTime, std::size_t const &id);
        ~Pizza();

        int getPrepTime();
        bool isCooked();
        void setCooked(bool isCooked);
        std::string &getName();
        std::string &getFormat();

    private:
        void setPreparationTime();

    private:
        std::string _name;
        std::string _size;
        std::size_t _id;
        double _multiplayer;
        double _prepTime;
        bool _cooked = false;
};
