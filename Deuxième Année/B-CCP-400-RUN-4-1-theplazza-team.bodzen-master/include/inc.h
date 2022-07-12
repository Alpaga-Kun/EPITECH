/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** inc
*/

#pragma once

#include <algorithm>
#include <sys/wait.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <mutex>
#include <map>
#include <queue>
#include <semaphore.h>
#include <ctype.h>
#include <cctype>
#include <vector>
#include <condition_variable>
#include <chrono>


enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

void get_data();

