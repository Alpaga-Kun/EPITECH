/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "../Utils.hpp"
#include "../Log.hpp"
#include <iostream>

Kitchen::Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                                                        MessageQueue &queue)
{
    this->_multiplier = multiplier;
    this->_cookersNb = coockersNb;
    this->_stockRefillTime = stock;
    this->_isClosed = false;
    this->_id = id;
    this->_msgQueue = queue;
    this->_stock = new Refill(this, stock);
    this->fl = LogFile();
    for (std::size_t i = 0; i < coockersNb; i++)
        this->_cookersArr.push_back(new Cookers(this));
}

Kitchen::Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                std::string const &command, int rest, MessageQueue &queue)
{
    this->_multiplier = multiplier;
    this->_cookersNb = coockersNb;
    this->_stockRefillTime = stock;
    this->_isClosed = false;
    this->_id = id;
    this->_msgQueue = queue;
    this->_stock = new Refill(this, stock);
    this->fl = LogFile();
    std::vector<std::string> tmp = Utils::split(command, " ");
    for (int i = 0; i < rest; i++) {
        this->_commandQueue.push(Ticket(tmp[0], tmp[1], this->_multiplier, 0));
    }
    for (std::size_t i = 0; i < coockersNb; i++)
        this->_cookersArr.push_back(new Cookers(this));
}

Kitchen::Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                                            SharedMem &queue, char *ptr)
{
    this->_multiplier = multiplier;
    this->_cookersNb = coockersNb;
    this->_stockRefillTime = stock;
    this->_isClosed = false;
    this->_id = id;
    this->ptr = ptr;
    this->_sharedMem = queue;
    this->_stock = new Refill(this, stock);
    this->fl = LogFile();
    for (std::size_t i = 0; i < coockersNb; i++)
        this->_cookersArr.push_back(new Cookers(this));
}

Kitchen::Kitchen(double multiplier, std::size_t coockersNb, int stock, int id,
                std::string const &command, int rest, char *ptr)
{
    (void)command;
    (void)rest;
    this->_multiplier = multiplier;
    this->_cookersNb = coockersNb;
    this->_stockRefillTime = stock;
    this->_isClosed = false;
    this->_id = id;
    this->ptr = ptr;
    this->_stock = new Refill(this, stock);
    this->fl = LogFile();
    for (std::size_t i = 0; i < coockersNb; i++)
        this->_cookersArr.push_back(new Cookers(this));
}


Kitchen::~Kitchen()
{
    this->_isClosed = true;
    exit(0);
}

bool Kitchen::canTakeOrder()
{
    return !((this->_commandQueue.size() + this->cooking) >= (2 * this->_cookersNb));
}

double Kitchen::getMultiplier()
{
    return this->_multiplier;
}

bool Kitchen::isClosed()
{
    return this->_isClosed;
}

void Kitchen::update(Parser &parser)
{
    this->assignCookers();
    while (1) {
        long i = 0;

        if (std::string(ptr).find("exit") != std::string::npos) {
            this->doExit = true;
            break;
        }
        if (std::string(ptr).find("status") != std::string::npos) {
            std::vector<std::string> tab = Utils::split(ptr, " ");

            if ((int)this->_id == atoi(tab[1].c_str())) {
                std::cout << "-------------------- Kitchen " << this->_id << "--------------------" << std::endl;
                std::cout << "There is " << this->_cookersNb << " cookers in the Kitchen !" << std::endl;
                for (std::size_t i = 0; i < this->_cookersNb; i++)
                    this->_cookersArr[i]->status();
                this->_stock->status();
                this->_msgQueue.clearBuffer();
                strcpy(ptr, std::to_string(this->_id + 1).c_str());
                std::cout << "-------------------- end Kitchen " << this->_id << "--------------------\n" << std::endl;
                std::string str = "status " + std::to_string(this->_id + 1) + " " + std::to_string(std::stoul(tab[2]));
                if (this->_id != std::stoul(tab[2]))
                    strcpy(ptr, str.c_str());
                else
                    strcpy(ptr, "continue");
            }
        } else {
            parser.Deserialize(ptr);
            fillQueue(i, parser);
        }
    }
    for (std::size_t i = 0; i < this->_cookersNb; i++)
        this->_cookersArr[i]->join();
}

std::size_t Kitchen::getCommandQueueSize()
{
    return this->_commandQueue.size();
}

std::size_t Kitchen::getId()
{
    return this->_id;
}

void Kitchen::pushCommand(Ticket const &toPush)
{
    this->_commandQueue.push(toPush);
}

void Kitchen::popCommand()
{
    this->_commandQueue.pop();
}

Ticket const &Kitchen::getCommand()
{
    return this->_commandQueue.get();
}

void Kitchen::assignCookers()
{
    for (std::size_t i = 0; i < this->_cookersNb; i++) {
        this->_cookersArr[i]->setId(i);
        this->_cookersArr[i]->startWorking();
    }
}

void Kitchen::fillQueue(long &i, Parser &parser)
{
    if (this->_id == 0) {
        for (auto &it : parser._listCommand) {
            for (long tmp = 0; tmp < parser._numberOfPizzas[i]; tmp++) {
                if (this->canTakeOrder()) {
                    this->_commandQueue.push(Ticket(it.first, it.second, this->_multiplier, 0));
                    fl.clear("logs");
                    strcpy(ptr, "continue");
                } else {
                    fl.write("logs", std::to_string(this->_id + 1) + " " + it.first + " " + it.second + " " + std::to_string(parser._numberOfPizzas[i] - tmp ));
                    std::string data = std::to_string(this->_id + 1) + " " + it.first + " " + it.second + " " + std::to_string(parser._numberOfPizzas[i] - tmp);
                    strcpy(ptr, data.c_str());
                    clearData(parser);
                    return;
                }
            }
            i++;
        }
    }
    if (this->_id > 0 && fl.read("logs") > 0) {

        std::vector<std::string> tab = Utils::split(fl.getCommand("logs"), " ");

        try {
            std::size_t id = std::stoul(tab[0]);
            std::size_t nb = std::stoul(tab[3]);

            if (id == this->_id && nb > 0) {
                std::string first = tab[1];
                std::string second = tab[2];

                for (std::size_t i = 0; i < nb; i++) {
                    if (this->canTakeOrder()) {
                        this->_commandQueue.push(Ticket(first, second, this->_multiplier, 0));
                        fl.clear("logs");
                        strcpy(ptr, "continue");
                    } else {
                        fl.write("logs", std::to_string(this->_id + 1) + " " + first + " " + second + " " + std::to_string(nb - i) + " next");
                        std::string data = std::to_string(this->_id + 1) + " " + first + " " + second + " " + std::to_string(nb - i);
                        strcpy(ptr, data.c_str());
                        clearData(parser);
                    }
                }
                // fl.clear("logs");
            }
        } catch (const std::exception& e) {
            clearData(parser);
            return;
        }
    }
    clearData(parser);
}

bool Kitchen::takeFromStock(std::string const &pizzaName)
{
    return this->_stock->TakeFromStock(pizzaName);
}

void Kitchen::clearData(Parser &parser)
{
    parser._numberOfPizzas.clear();
    parser._listCommand.clear();
    this->_msgQueue.clearBuffer();
}