//
// Created by samuel on 9/1/24.
//

#include "LoggingFactory.h"

#include "ConsoleLogger.h"
#include "FileLogger.h"
const char* LOG_FILE_OUTPUT = "log.txt";

hive::ConsoleLogger* createConsoleLogger(hive::LogLevel level) {
    return new hive::ConsoleLogger(level);
}

hive::FileLogger* createFileLogger(hive::LogLevel level) {
    return new hive::FileLogger(LOG_FILE_OUTPUT, level);
}

hive::Logger *hive::LoggingFactory::createLogger(LogOutputType type, LogLevel level) {
    switch (type) {
        case LogOutputType::File:
            return createFileLogger(level);
        case LogOutputType::Console:
        default:
            return createConsoleLogger(level);
    }
}
