//
// Created by samuel on 7/24/24.
//

#ifdef HIVE_PLATFORM_LINUX
#include <cassert>

#include <core/logging/ConsoleLogger.h>

namespace hive {


    void setColor(int R, int G, int B) {
        assert(R >= 0 && G >= 0 && B >= 0);
        assert(R <= 255 && G <= 255 && B <= 255);
        std::cout << "\033[38;2;" << R << ";" << G << ";" << B << "m";
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

    void ConsoleLogger::resetColor() {
        std::cout << "\033[0m";
    }

}
#endif