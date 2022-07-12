/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Log
*/

#pragma once

#include <iostream>
#include <mutex>
#include <cstdarg>

class Log {
    public:
        Log();
        ~Log();

        static void log(std::string const &print)
        {
            static std::mutex mtx;
            std::lock_guard<std::mutex> locker(mtx);
            std::cout << print << std::endl;
        }

    protected:
    private:
};
