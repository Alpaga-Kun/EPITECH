/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Process
*/

#pragma once

#include <unistd.h>

class Process {
    public:
        Process();
        ~Process();

        pid_t getPid();
        void createProcess();

        Process &operator=(const Process &proc);

    protected:
    private:
        pid_t _pid = -1;
};
