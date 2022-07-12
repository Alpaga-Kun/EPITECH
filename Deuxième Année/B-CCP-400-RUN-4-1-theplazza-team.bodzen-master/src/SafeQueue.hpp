/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** SafeQueue
*/

#pragma once
#include <queue>
#include <mutex>

template <class T>
class SafeQueue {
    public:

        SafeQueue()
        {
        }

        ~SafeQueue()
        {
        }

        void push(T const &toPush)
        {
            std::lock_guard<std::mutex> lock(this->_mutex);
            this->_queue.push(toPush);
        }

        void pop()
        {
            std::lock_guard<std::mutex> lock(this->_mutex);
            this->_queue.pop();
        }

        std::size_t size()
        {
            std::lock_guard<std::mutex> lock(this->_mutex);
            return this->_queue.size();
        }

        T &get()
        {
            std::lock_guard<std::mutex> lock(this->_mutex);
            return this->_queue.front();
        }

        T &last()
        {
            std::lock_guard<std::mutex> lock(this->_mutex);
            return this->_queue.back();
        }


    protected:
    private:
        std::queue<T> _queue;
        std::mutex _mutex;
};
