/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** SharedMem
*/

#include "SharedMem.hpp"

SharedMem::SharedMem()
{
    key_t key = ftok("mem", 42);
    this->_id = shmget(key, 1024, 0666 | IPC_CREAT);
}

SharedMem::~SharedMem()
{
}

void *SharedMem::setMemShared()
{
    return shmat(this->_id, NULL, 0);
}

void *SharedMem::getAddr()
{
    return shmat(this->_id, NULL, 0);
}