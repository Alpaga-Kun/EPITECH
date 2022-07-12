/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Parser
*/

#pragma once

#include "./inc.h"
#include "Reception/Reception.hpp"
#include "IPC/LogFile.hpp"
#include "IPC/MessageQueue.hpp"
#include "IPC/SharedMem.hpp"
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

class Reception;

class Parser {
    public:
        std::vector<std::string> _queue;
        std::size_t _kitchenIdx = 0;
        std::string input;
        std::vector<long> _numberOfPizzas;
        std::multimap<std::string, std::string> _listCommand;
        bool createKitchen = false;
        std::string save;

        Parser();
        ~Parser();
        void Treatment(std::string);

        void Serialize(std::vector<std::string>);
        void Deserialize(std::string str);
        void attributionType(int, int);

        void update(Reception *reception);
        void checkKitchen(LogFile &fl, Reception *reception);
        void pop();
        void clear();
        void sendMessage(std::string const &msg);
        std::vector<std::string> &getQueue();
        std::vector<std::string> getQueueR();

        void scanObject(size_t);
        void ErrorHandling(std::string);

    protected:
    private:
        std::string _objSerialized;
        std::string _objDeserialized;
        std::thread _checkLogs;
};
