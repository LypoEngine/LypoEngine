//
// Created by samuel on 8/29/24.
//

#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include <iostream>

#include "Logger.h"

namespace hive {

    class ConsoleLogger final : public Logger {
    public:
        explicit ConsoleLogger(LogLevel level = LogLevel::Info);
        ~ConsoleLogger();

        bool isCorrect() override;
    private:

        //Those function is platform specific, it's implementation should be located in platform_console_logger.cpp
        static void setLogLevelColor(LogLevel level);
        static void resetColor();

    protected:
        void logImpl(const std::string &msg, LogLevel level) override;

    public:
    };


} // hive

#endif //CONSOLELOGGER_H
