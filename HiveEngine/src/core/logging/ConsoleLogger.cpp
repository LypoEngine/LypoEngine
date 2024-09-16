//
// Created by samuel on 8/29/24.
//

#include "ConsoleLogger.h"

namespace hive {
    ConsoleLogger::ConsoleLogger(const LogLevel level) {
        m_logLevel = level;
    }

    ConsoleLogger::~ConsoleLogger() {
        logImpl("Closing the console logger", LogLevel::Debug);
    }

    void ConsoleLogger::logImpl(const std::string &msg, LogLevel level) {
        if(m_logLevel <= level) {
            setLogLevelColor(level);
            std::cout << msg << std::endl;
            resetColor();
        }
    }

    bool ConsoleLogger::isCorrect() {
        return true;
    }


} // hive