//
// Created by guill on 2024-09-27.
//

#ifndef PROFILER_H
#define PROFILER_H

#include <easy/profiler.h>

namespace hive
{
    #define FUNCTION_NAME __func__
    
    #ifndef DEFAULT_PORT
        #define DEFAULT_PORT profiler::DEFAULT_PORT            
    #endif 

    enum BlockStatus : uint8_t 
    {
        OFF = 0,                                              // The block is OFF
        ON  = 1,                                              // The block is ON (but if it's parent block is off recursively then this block will be off too)
        FORCE_ON = ON | 2,                                    // The block is ALWAYS ON (even if it's parent has turned off all children)
        OFF_RECURSIVE = 4,                                    // The block is OFF and all of it's children by call-stack are also OFF.
        ON_WITHOUT_CHILDREN = ON | OFF_RECURSIVE,             // The block is ON but all of it's children are OFF.
        FORCE_ON_WITHOUT_CHILDREN = FORCE_ON | OFF_RECURSIVE, // The block is ALWAYS ON but all of it's children are OFF.   
    };

    /**
     * Enable Profiling Tools
     */
    #define ENABLE_PROFILING            EASY_PROFILER_ENABLE;
    /**
     * Disable Profiling Tools
     */
    #define DISABLE_PROFILING           EASY_PROFILER_DISABLE;
    /**
     * Initialization of Profiling Tools. Block will be send via network
     * @param DEFAULT_PORT If not defined the value will be 28077
     */
    #define INIT_NETWORK_PROFILING  \
        ENABLE_PROFILING;           \
        profiler::startListen(DEFAULT_PORT);
    /**
     * Stops profiling via newtwok
     */
    #define STOP_NETWORK_PROFILING      profiler::stopListen();
    /**
     * Dumps block into a file
     * @param filename name of the file where blocks will be save
     */
    #define DUMP_PROFILING(filename)    profiler::dumpBlocksToFile(filename);
    /**
     * 
     * @param name Name of the profling block
     * @param color Color of the profiling block
     */
    #define BLOCK_PROFILING(name, ...)  EASY_BLOCK(name, ## __VA_ARGS__)
    /**
     * 
     * @param  color Color of the profiling block
     */
    #define FUNCTION_PROFILING(...)     BLOCK_PROFILING(FUNCTION_NAME, ## __VA_ARGS__);
    /**
     * 
     */
    #define MARKER_PROFILING(name, ...) EASY_EVENT(name, ## __VA_ARGS__);
    /**
     * 
     */
    #define END_BLOCK_PROFILING EASY_END_BLOCK


}

#endif //PROFILER_H
