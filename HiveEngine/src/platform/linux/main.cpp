//
// Created by lapor on 7/19/2024.
//


#include "lypch.h"
#include <core/logging/LoggingFactory.h>


int main() {
    auto logger = hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Info);
    logger->log("Hello World", hive::LogLevel::Info);
}
