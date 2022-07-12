/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** MessageQueue
*/

#include "MessageQueue.hpp"

MessageQueue::MessageQueue()
{
}

MessageQueue::~MessageQueue()
{
}

int MessageQueue::init(key_t key)
{
    this->_id = msgget(key, IPC_CREAT | 0666);
    if (this->_id < 0) {
        perror("msgget");
        exit(84);
    }
    return 0;
}

void MessageQueue::sendMessage(long mtype, char const *msg)
{
    int ret = 0;

    strcpy(this->_buffer.mtext, msg);
    this->_buffer.mtype = mtype;
    ret = msgsnd(this->_id, &this->_buffer, BUFF_SIZE, IPC_NOWAIT);
    if (ret < 0) {
        perror("msgsend");
        exit(84);
    }
}

void MessageQueue::receiveMessage()
{
    int ret = 0;

    ret = msgrcv(this->_id, &this->_buffer, BUFF_SIZE, 0, 0);
    if (ret < 0) {
        perror("msgrcv");
        exit(84);
    }
}

void MessageQueue::msgControl()
{
    int ret = 0;

    ret = msgctl(this->_id, IPC_RMID, NULL);
    if (ret < 0) {
        perror("msgctl");
        exit(84);
    }
}

void MessageQueue::clearBuffer()
{
    strcpy(this->_buffer.mtext, "");
}

std::ostream &operator<<(std::ostream &os, MessageQueue &queue)
{
    os << "Message: " << queue._buffer.mtext;
    return os;
}

std::istream &operator>>(std::istream &is, MessageQueue &queue)
{
    is >> queue._buffer.mtext;
    return is;
}