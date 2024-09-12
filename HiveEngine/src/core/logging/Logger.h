//
// Created by samuel on 8/29/24.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

#include <lypch.h>
namespace hive {
    enum class LogLevel {
        Debug, Info, Warning, Error, Fatal
    };



    class Logger {
    public:
        virtual ~Logger() = default;

        static void setLogger(Logger* logger);
        static void log(const std::string &msg, LogLevel level);
        virtual bool isCorrect() = 0;

    protected:
        virtual void logImpl(const std::string &msg, LogLevel level) = 0;
        LogLevel m_logLevel = LogLevel::Info;

    private:
        static URef<Logger> s_instance;
    };

} // hive

#endif //LOGGER_H
