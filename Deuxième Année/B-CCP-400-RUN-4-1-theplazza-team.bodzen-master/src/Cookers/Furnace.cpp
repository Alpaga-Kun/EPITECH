/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Furnace
*/

#include "../Log.hpp"
#include "Furnace.hpp"
#include <chrono>

Furnace::Furnace()
{
}

Furnace::~Furnace()
{
}

void Furnace::cookPizza(Pizza &toCook, double deltaTime)
{
    this->isCooking = true;
    if (this->currentTime >= toCook.getPrepTime()) {
        toCook.setCooked(true);
        this->currentTime = 0;
        this->isCooking = false;
        return;
    }
    this->currentTime += deltaTime;
}

bool Furnace::Cooking()
{
    return this->isCooking;
}