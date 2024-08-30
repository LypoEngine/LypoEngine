//
// Created by samuel on 8/29/24.
//

#include "ConsoleLogger.h"

namespace hive {
    ConsoleLogger::ConsoleLogger(const LogLevel level) {
        m_logLevel = level;
    }

    void ConsoleLogger::log(const std::string &msg, LogLevel level) {
        if(m_logLevel <= level) {
            setLogLevelColor(level);
            std::cout << msg << std::endl;
            resetColor();
        }
    }

    bool ConsoleLogger::isCorrect() {
        return true;
    }

    void ConsoleLogger::setLogLevelColor(LogLevel level) {
        switch(level) {
            case LogLevel::Debug:
                setColor(173, 216, 230);
                break;
            case LogLevel::Info:
                setColor(144, 238, 144);
                break;
            case LogLevel::Warning:
                setColor(255, 255, 224);
                break;
            case LogLevel::Error:
                setColor(240, 128, 128);
                break;
            case LogLevel::Fatal:
                setColor(255, 99, 71);
                break;
        }
    }
} // hive