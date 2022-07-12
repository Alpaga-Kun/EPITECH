/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Process
*/

#include "Process.hpp"

Process::Process()
{
}

Process::~Process()
{
}


pid_t Process::getPid()
{
    return this->_pid;
}

void Process::createProcess()
{
    this->_pid = fork();
}

Process &Process::operator=(const Process &proc)
{
    this->_pid = proc._pid;
    return *this;
}