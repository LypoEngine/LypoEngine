//
// Created by samuel on 7/24/24.
//

#ifdef HYVE_PLATFORM_LINUX
#include <cassert>

#include <core/logging/ConsoleLogger.h>

namespace hive {
    void ConsoleLogger::setColor(int R, int G, int B) {
        assert(R >= 0 && G >= 0 && B >= 0);
        assert(R <= 255 && G <= 255 && B <= 255);
        std::cout << "\033[38;2;" << R << ";" << G << ";" << B << "m";
    }

    void ConsoleLogger::resetColor() {
        std::cout << "\033[0m";
    }

}
#endif