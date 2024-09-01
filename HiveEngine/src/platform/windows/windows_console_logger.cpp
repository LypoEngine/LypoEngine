//
// Created by lapor on 7/26/2024.
//

#include <windows.h>
#include <cassert>

#include <core/logging/ConsoleLogger.h>

namespace hive {

    enum WindowsColor
    {
        BLACK = 0,
        BLUE = 1,
        GREEN = 2,
        AQUA = 3,
        RED = 4,
        PURPLE = 5,
        YELLOW = 6,
        WHITE = 7,
    };

    void setWindowsConsoleColor(WORD color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    //Windows console only have a limited set of color
    void ConsoleLogger::setLogLevelColor(LogLevel level)
    {
        switch(level) {
            case LogLevel::Debug:
                setWindowsConsoleColor(WindowsColor::WHITE); //WHITE
                break;
            case LogLevel::Info:
                setWindowsConsoleColor(WindowsColor::GREEN);
                break;
            case LogLevel::Warning:
                setWindowsConsoleColor(WindowsColor::YELLOW);
                break;
            case LogLevel::Error:
                setWindowsConsoleColor(WindowsColor::RED);
                break;
            case LogLevel::Fatal:
                setWindowsConsoleColor(WindowsColor::PURPLE);
                break;
        }
    }
    void ConsoleLogger::resetColor() {
        setWindowsConsoleColor(WindowsColor::WHITE);
    }

}