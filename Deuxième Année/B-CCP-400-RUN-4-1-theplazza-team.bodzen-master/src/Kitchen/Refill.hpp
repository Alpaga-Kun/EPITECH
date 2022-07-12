/*
** EPITECH PROJECT, 522
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Refill
*/


#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <functional>
#include <map>
#include <unordered_map>
#include <string>
#include <thread>
#include "Kitchen.hpp"

class Kitchen;

class Refill {
    public:
        double currentTime = 0;

        Refill() = default;
        Refill(Kitchen *kitchen, int ms);
        ~Refill();
        bool TakeFromStock(std::string);
        void Treatment(std::string);
        double getRefillTime();
        void addInStock();
        void status();

    protected:
    private:
        std::thread _thread;
        Kitchen *_kitchen;
        double _refillTime;
        std::map<std::pair<std::string, std::string>, int> ingredients = {
            {{"doe", "margarita;regina;americana;fantasia"}, 5},
            {{"tomato", "margarita;regina;americana;fantasia"}, 5},
            {{"gruyere", "margarita;regina;americana"}, 5},
            {{"ham", "regina"}, 5},
            {{"mushrooms", "regina"}, 5},
            {{"steak", "americana"}, 5},
            {{"eggplant", "fantasia"}, 5},
            {{"goat", "fantasia"}, 5},
            {{"cheese", "fantasia"}, 5},
            {{"chief love", "fantasia"}, 5}
    };
};
