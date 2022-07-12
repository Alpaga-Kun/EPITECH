/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Furnace
*/

#pragma once
#include "../Pizza.hpp"
#include <thread>

class Furnace {
    public:
        Furnace();
        ~Furnace();

        void cookPizza(Pizza &toCook, double deltaTime);
        bool Cooking();

    protected:
    private:
        double currentTime = 0;
        bool isCooking = false;
};
