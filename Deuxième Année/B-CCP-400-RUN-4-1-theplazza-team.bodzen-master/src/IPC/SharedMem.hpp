/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** SharedMem
*/

#pragma once
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


class SharedMem {
    public:
        SharedMem();
        ~SharedMem();

        void *setMemShared();
        void *getAddr();

    protected:
    private:
        int _id;

};
