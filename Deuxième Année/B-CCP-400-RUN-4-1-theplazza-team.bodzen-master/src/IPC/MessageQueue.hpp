/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** MessageQueue
*/

#pragma once
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

#define BUFF_SIZE 1024

typedef struct msgbuf_t {
    long mtype;
    char mtext[BUFF_SIZE];
} msgbuf_t;

class MessageQueue {
    public:
        msgbuf_t _buffer;
        MessageQueue();
        ~MessageQueue();

        int init(key_t key);
        void sendMessage(long mtype, char const *msg);
        void receiveMessage();
        void msgControl();
        void clearBuffer();

    protected:
    private:
        int _id = 0;
};

std::ostream &operator<<(std::ostream &os, MessageQueue &queue);
std::istream &operator>>(std::istream &is, MessageQueue &queue);
