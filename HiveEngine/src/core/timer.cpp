//
// Created by guill on 2024-09-25.
//
#include "timer.h"
#include <ostream>

namespace hive {
    Timer::Timer() {
        startTimePoint_ = std::chrono::high_resolution_clock::now();
    }

    Timer::~Timer() {
        stop();
    }

    void Timer::stop() {
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint_).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        double duration = (end - start) * 0.001;
        std::cout << duration << " ms" << std::endl;
    }
}