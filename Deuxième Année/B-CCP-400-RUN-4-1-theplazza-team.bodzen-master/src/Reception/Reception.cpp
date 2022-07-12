/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Reception
*/

#include "Reception.hpp"
#include "../IPC/MessageQueue.hpp"
#include <unistd.h>
#include <string>
#include <iostream>
#include <map>
#include <string>

Reception::Reception(float multiplier, std::size_t _cookerNb, int stockTime)
{
    this->_multiplier = multiplier;
    this->_coockerNb = _cookerNb;
    this->_stockResetTime = stockTime;
    for (std::size_t i = 0; i < MAX_PROCESSES; i++) {
        this->_processes.push_back(Process());
    }
}

Reception::~Reception()
{
}

void Reception::createKitchen(Parser &parser, MessageQueue &queue)
{
    std::size_t index = 0;

    for (; index < MAX_PROCESSES; index++) {
        if (this->_processes[index].getPid() == -1)
            break;
    }
    if (index >= MAX_PROCESSES) {
        std::cerr << "Cannot create more kitchen" << std::endl;
        return;
    }
    this->_processes[index].createProcess();
    if (this->_processes[index].getPid() == -1) {
        std::cerr << "Cannot fork !" << std::endl;
        return;
    }
    if (this->_processes[index].getPid() == 0) {
        Kitchen kitchen(this->_multiplier, this->_coockerNb,
                                this->_stockResetTime, index, queue);
        kitchen.update(parser);
    } else
        parser._kitchenIdx++;
}

void Reception::createKitchen(Parser &parser, std::string const &command,
                                            int nb, MessageQueue &queue)
{
    std::size_t index = 0;

    for (; index < MAX_PROCESSES; index++) {
        if (this->_processes[index].getPid() == -1)
            break;
    }
    if (index >= MAX_PROCESSES) {
        std::cerr << "Cannot create more kitchen" << std::endl;
        return;
    }
    this->_processes[index].createProcess();
    if (this->_processes[index].getPid() == -1) {
        std::cerr << "Cannot fork !" << std::endl;
        return;
    }
    if (this->_processes[index].getPid() == 0) {
        Kitchen kitchen(this->_multiplier, this->_coockerNb,
                this->_stockResetTime, index, command, nb, queue);
        kitchen.update(parser);
    } else
        parser._kitchenIdx++;
}

void Reception::createKitchen(Parser &parser, SharedMem &queue, char *ptr)
{
    std::size_t index = 0;

    for (; index < MAX_PROCESSES; index++) {
        if (this->_processes[index].getPid() == -1)
            break;
    }
    if (index >= MAX_PROCESSES) {
        std::cerr << "Cannot create more kitchen" << std::endl;
        return;
    }
    this->_processes[index].createProcess();
    if (this->_processes[index].getPid() == -1) {
        std::cerr << "Cannot fork !" << std::endl;
        return;
    }
    if (this->_processes[index].getPid() == 0) {
        Kitchen kitchen(this->_multiplier, this->_coockerNb,
                                this->_stockResetTime, index, queue, ptr);
        kitchen.update(parser);
    } else
        parser._kitchenIdx++;
}

void Reception::createKitchen(Parser &parser, std::string const &command,
                                            char *ptr)
{
    std::size_t index = 0;

    for (; index < MAX_PROCESSES; index++) {
        if (this->_processes[index].getPid() == -1)
            break;
    }
    if (index >= MAX_PROCESSES) {
        std::cerr << "Cannot create more kitchen" << std::endl;
        return;
    }
    this->_processes[index].createProcess();
    if (this->_processes[index].getPid() == -1) {
        std::cerr << "Cannot fork !" << std::endl;
        return;
    }
    if (this->_processes[index].getPid() == 0) {
        Kitchen kitchen(this->_multiplier, this->_coockerNb,
                this->_stockResetTime, index, command, 0, ptr);
        kitchen.update(parser);
    } else
        parser._kitchenIdx++;
}