//
// Created by guill on 2024-09-25.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>

namespace hive {
    class Timer {
    public:
        Timer();
        ~Timer();
        void stop();
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint_;
    };
}

#endif //TIMER_H
