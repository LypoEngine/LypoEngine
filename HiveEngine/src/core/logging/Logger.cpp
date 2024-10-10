//
// Created by samuel on 9/11/24.
//
#include "Logger.h"

URef<hive::Logger> hive::Logger::s_instance = nullptr;

void hive::Logger::init(Logger *logger) {
    s_instance = std::unique_ptr<Logger>(logger);
}

void hive::Logger::shutdown()
{
    s_instance.reset();
}

void hive::Logger::log(const std::string &msg, const LogLevel level) {
    if(s_instance == nullptr)
    {
        return;
    }
    s_instance->logImpl(msg, level);
}
