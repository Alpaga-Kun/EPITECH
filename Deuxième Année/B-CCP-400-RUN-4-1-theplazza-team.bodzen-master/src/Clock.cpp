/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Clock
*/

#include "Clock.hpp"
#include <iostream>

void Clock::startTick()
{
    this->_start = std::chrono::steady_clock::now();
}

void Clock::endTick()
{
    this->_end = std::chrono::steady_clock::now();
    this->getElpasedTime();
}

double Clock::getElpasedTime()
{
    this->deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(this->_end - this->_start).count() / 1000000000.0f;
    return this->deltaTime;
}

float Clock::getClocknano()
{
    auto cl = std::chrono::high_resolution_clock::now().time_since_epoch() - _time.time_since_epoch();
    return (std::chrono::duration_cast<std::chrono::nanoseconds>(cl).count());
}

auto Clock::getEltime(clockValue start, clockValue end)
{
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return (time);
}
