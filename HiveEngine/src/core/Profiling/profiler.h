//
// Created by guill on 2024-09-27.
//

#ifndef PROFILER_H
#define PROFILER_H

#include <easy/profiler.h>
#include "profiler_configurations.h"

#define INIT_PROFILING          \
    EASY_PROFILER_ENABLE;       \
    profiler::startListen();
#define FUNCTION_PROFILING(color) EASY_FUNCTION(color)
#define BLOCK_PROFILING(name) EASY_BLOCK(name)
#define END_BLOCK_PROFILING EASY_END_BLOCK
#define DUMP_PROFILING(path) profiler::dumpBlocksToFile(path);

#endif //PROFILER_H
