//
// Created by GuillaumeIsCoding on 9/6/2024
//
#pragma once

namespace hive
{
    class TimeStep
    {
    public:
        TimeStep(const float& time = 0.0f) : time_(time) {}
        
        operator float() const {return time_;}
        
        float getSeconds() const {return time_;}
        float getMilliseconds() const {return time_ * 1000.0f;}
    private:
        float time_;
    };
}