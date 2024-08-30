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

        void log(const std::string &msg, LogLevel level) override;
        bool isCorrect() override;
    private:
        static void setLogLevelColor(LogLevel level);

        //Those function is platform specific, it's implementation should be located in platform_console_logger.cpp
        static void setColor(int R, int G, int B);
        static void resetColor();

    public:
    };


} // hive

#endif //CONSOLELOGGER_H
