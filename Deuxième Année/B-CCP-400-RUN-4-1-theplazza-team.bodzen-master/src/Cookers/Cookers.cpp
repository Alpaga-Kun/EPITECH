/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Cookers
*/

#include "Cookers.hpp"
#include "../Log.hpp"
#include "../Clock.hpp"
#include <iostream>
#include <memory>

void task(Cookers *cookers, Kitchen *kitchen)
{
    Clock clock = Clock();
    static std::mutex mtx;
    {
        // Log::log("cookers " + std::to_string(cookers->getId()) +
        // " started working ! in Kitchen nb: " + std::to_string(kitchen->getId()));
        for (;;) {
            clock.startTick();
            mtx.lock();
            if (kitchen->getCommandQueueSize() > 0)
                cookers->takeOrder(kitchen->getCommand(), kitchen);
            if (cookers->getOrdersQueueSize() > 0)
                cookers->putInFurnace(clock.deltaTime, kitchen);
            if (kitchen->doExit)
                break;
            mtx.unlock();
            clock.endTick();
        }
    }
    return;
}

Cookers::Cookers(Kitchen *kit)
{
    this->_kitchen = kit;
    this->furnace = Furnace();
}

Cookers::~Cookers()
{
}

void Cookers::startWorking()
{
    this->_thread = std::thread(task, this, std::ref(this->_kitchen));
}

bool Cookers::canTakeOrder()
{
    return !(this->_pizzaQueu.size() > 2);
}

void Cookers::takeOrder(Ticket const &toTake, Kitchen *kitchen)
{
    if (this->canTakeOrder()) {
        this->_pizzaQueu.push(Pizza(
            toTake.getPizzaName(),
            toTake.getPizzaSize(),
            toTake.getPizzaMultiplayer(),
            toTake.getPizzaId()
        ));
        // Log::log("Cookers nb: " + std::to_string(this->_id) + "from kitchen nb " + std::to_string(kitchen->getId()) + "take order nb "
        //                             + std::to_string(toTake.getPizzaId()));
        kitchen->popCommand();
        kitchen->cooking += 1;
    }
}

void Cookers::setId(std::size_t id)
{
    this->_id = id;
}

std::size_t Cookers::getId()
{
    return this->_id;
}

std::size_t Cookers::getOrdersQueueSize()
{
    return this->_pizzaQueu.size();
}

SafeQueue<Pizza> &Cookers::getOrders()
{
    return this->_pizzaQueu;
}

void Cookers::putInFurnace(double deltaTime, Kitchen *kitchen)
{
    Pizza &pizza = this->_pizzaQueu.get();

    if (!pizza.isCooked()) {
        if (!this->furnace.Cooking()) {
            if (!kitchen->takeFromStock(pizza.getName())) {
                return;
            }
        }
        this->furnace.cookPizza(pizza, deltaTime);
    }
    if (pizza.isCooked()) {
        Log::log(pizza.getName() + " " + pizza.getFormat() + " is ready");
        this->_pizzaQueu.pop();
        kitchen->cooking -= 1;
    }
}

void Cookers::join()
{
    this->_thread.join();
}

void Cookers::status()
{
    std::cout << "Cookers nb " << this->getId() << " is cooking a " << this->_pizzaQueu.get().getName() << " " << this->_pizzaQueu.get().getFormat() << std::endl;
}