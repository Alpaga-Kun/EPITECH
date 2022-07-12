/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Reception
*/

#pragma once

#include "inc.h"
#include "../src/Kitchen/Kitchen.hpp"
#include "../IPC/MessageQueue.hpp"
#include "../IPC/SharedMem.hpp"
#include "../Process.hpp"
#include "../Parser.hpp"

#define MAX_PROCESSES 1024

class Parser;

class Reception {
    public:
        Reception(float multiplier, std::size_t _cookerNb, int stockTime);
        ~Reception();

        /*
        * Create a process and call a Kitchen instance
        */
        void createKitchen(Parser &parser, MessageQueue &queue);
        void createKitchen(Parser &parser, std::string const &command, int nb,
                                                        MessageQueue &queue);
        void createKitchen(Parser &parser, SharedMem &queue, char *ptr);
        void createKitchen(Parser &parser, std::string const &command,
                                                        char *ptr);

    private:
        std::vector<Process> _processes;
        float _multiplier = 1.0f;
        std::size_t _coockerNb = 2;
        int _stockResetTime = 1000;
};
