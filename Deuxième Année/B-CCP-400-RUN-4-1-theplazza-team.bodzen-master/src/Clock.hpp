#pragma once
#include <chrono>

typedef std::chrono::_V2::steady_clock::time_point clockValue;

class Clock {
    public:
        double deltaTime;

        Clock() = default;
        ~Clock() = default;

        float getClocknano();
        auto getEltime(clockValue start, clockValue end);
        double getElpasedTime();
        void startTick();
        void endTick();
        std::chrono::time_point<std::chrono::high_resolution_clock> _time = std::chrono::high_resolution_clock::now();

    private:
        clockValue _start;
        clockValue _end;
    };

class PizzaState {
public :
    bool setState();
    bool isready = false;
};