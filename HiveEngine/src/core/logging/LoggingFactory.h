//
// Created by samuel on 9/1/24.
//

#ifndef LOGGINGFACTORY_H
#define LOGGINGFACTORY_H

#include "Logger.h"

#include <lypch.h>

namespace hive {

    enum class LogOutputType {
        Console, File
    };

    class LoggingFactory {
    public:
        static Logger* createLogger(LogOutputType type, LogLevel logLevel);
    };

}



#endif //LOGGINGFACTORY_H
