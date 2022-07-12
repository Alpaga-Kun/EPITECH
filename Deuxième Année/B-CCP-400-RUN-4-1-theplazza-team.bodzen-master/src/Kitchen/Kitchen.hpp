/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Kitchen
*/

#pragma once

#include <cstddef>
#include <queue>
#include <memory>
#include <vector>
#include <mutex>
#include "../Pizza.hpp"
#include "../SafeQueue.hpp"
#include "../Cookers/Cookers.hpp"
#include "../Parser.hpp"
#include "../IPC/MessageQueue.hpp"
#include "../IPC/SharedMem.hpp"
#include "../IPC/LogFile.hpp"
#include "../Clock.hpp"
#include "Ticket.hpp"
#include "Refill.hpp"

class Cookers;
class Parser;
class Refill;

class Kitchen {
    public:
        std::mutex _mtx;
        std::size_t cooking = 0;
        bool doExit = false;

    public:
        Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                                                        MessageQueue &queue);
        Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                    std::string const &command, int rest, MessageQueue &queue);
        Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                                                SharedMem &queue, char *ptr);
        Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                    std::string const &command, int rest, char *ptr);
        Kitchen() = default;
        ~Kitchen();

        bool canTakeOrder();
        double getMultiplier();
        bool isClosed();
        void update(Parser &parser);
        std::size_t getId();
        std::size_t getCommandQueueSize();
        void popCommand();
        void pushCommand(Ticket const &toPush);
        bool takeFromStock(std::string const &pizzaName);
        Ticket const &getCommand();

    private:
        void assignCookers();
        void fillQueue(long &i, Parser &parser);
        void clearData(Parser &parser);

    private:
        SafeQueue<Ticket> _commandQueue;
        std::size_t _cookersNb;
        double _multiplier;
        int _stockRefillTime;
        bool _isClosed = true;
        std::vector<Cookers *> _cookersArr;
        std::size_t _id;
        MessageQueue _msgQueue;
        SharedMem _sharedMem;
        Refill *_stock;
        LogFile fl;
        char *ptr = NULL;
};