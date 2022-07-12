/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Cookers
*/

#pragma once
#include <thread>
#include <queue>
#include <mutex>
#include <memory>
#include "../Pizza.hpp"
#include "../Kitchen/Kitchen.hpp"
#include "../Kitchen/Ticket.hpp"
#include "Furnace.hpp"

class Kitchen;

class Cookers {
    public:
        std::mutex _mtx;
        Furnace furnace;
        bool exit = false;

        Cookers(Kitchen *kitchen);
        ~Cookers();

        void startWorking();
        bool canTakeOrder();
        void takeOrder(Ticket const &toTake, Kitchen *kitchen);

        void status();
        void join();
        void setId(std::size_t id);
        void setKitchen(Kitchen *kitchen);
        std::size_t getId();
        std::size_t getOrdersQueueSize();

        SafeQueue<Pizza> &getOrders();
        void putInFurnace(double deltaTime, Kitchen *kitchen);

    protected:
    private:
        std::thread _thread;
        SafeQueue<Pizza> _pizzaQueu;
        Kitchen * _kitchen;
        std::size_t _id;
};
