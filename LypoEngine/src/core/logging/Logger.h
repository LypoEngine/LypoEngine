//
// Created by samuel on 8/29/24.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
namespace hive {
    enum class LogLevel {
        Debug, Info, Warning, Error, Fatal
    };

    enum class LogOutputType {
        Console, File
    };


    class Logger {
    public:
        virtual ~Logger() = default;

        virtual void log(const std::string &msg, LogLevel level) = 0;
        virtual bool isCorrect() = 0;

    protected:
        LogLevel m_logLevel = LogLevel::Info;
    };

} // hive

#endif //LOGGER_H
