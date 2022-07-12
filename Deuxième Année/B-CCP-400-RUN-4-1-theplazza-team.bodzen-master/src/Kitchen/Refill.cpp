/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Refill
*/

#include "Refill.hpp"

void update(Refill *stock, Kitchen *kitchen)
{
    Clock clock = Clock();

    (void)kitchen;
    for (;;) {
        clock.startTick();
        if (stock->currentTime >= stock->getRefillTime()) {
            stock->currentTime = 0;
            stock->addInStock();
        }
        stock->currentTime += clock.deltaTime;
        clock.endTick();
    }
}

Refill::Refill(Kitchen *kitchen, int ms)
{
    this->_kitchen = kitchen;
    this->_refillTime = ms / 1000;
    this->_thread = std::thread(update, this, std::ref(this->_kitchen));
}

Refill::~Refill()
{
    this->_thread.join();
}

double Refill::getRefillTime()
{
    return this->_refillTime;
}

void Refill::Treatment(std::string input)
{
    std::stringstream ss(input);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> token(begin, end);

    this->TakeFromStock(token[0]);
}

bool Refill::TakeFromStock(std::string input)
{
    for (auto &it : this->ingredients) {
        if (it.first.second.find(input) != std::string::npos) {
            if (it.second <= 0)
                return false;
            it.second -= 1;
        }
    }
    return true;
}

void Refill::status()
{
    std::cout << "░░░░░░░░░░░ Stock ░░░░░░░░░░░" << std::endl;
    for (auto &it : this->ingredients)
        std::cout << "Name: " << it.first.first << " nb: " << it.second << std::endl;
    std::cout << "░░░░░░░░░░░ End Stock ░░░░░░░░░░░" << std::endl;
}

void Refill::addInStock()
{
    for (auto &it : this->ingredients) {
        it.second++;
    }
}