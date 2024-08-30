//
// Created by lapor on 7/19/2024.
//

#include <core/logging/Logger.h>
#include <core/logging/ConsoleLogger.h>
#include "core/logging/FileLogger.h"

#include <memory>


template<typename T>
using SRef = std::shared_ptr<T>;

template<typename T>
using URef = std::unique_ptr<T>;


void initEngine(URef<hive::Logger> &logger) {
    logger = std::make_unique<hive::ConsoleLogger>(hive::LogLevel::Warning);

    // logger = std::make_unique<hive::FileLogger>("log.txt", hive::LogLevel::Info);
    if(!logger->isCorrect()) {
        //ERROR HERE
    }
}


int main() {
    URef<hive::Logger> logger;
    initEngine(logger);

    logger->log("Hello World", hive::LogLevel::Error);

}