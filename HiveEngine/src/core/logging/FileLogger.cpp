//
// Created by samuel on 8/30/24.
//

#include "FileLogger.h"

namespace hive {
    FileLogger::FileLogger(const std::string &filePath, const LogLevel logLevel) {
        m_logLevel = logLevel;

        m_fileStream = std::ofstream(filePath, std::ios::out | std::ios::app);
        if (!m_fileStream.is_open()) {
            //ERROR LOG HERE
        }
    }

    FileLogger::~FileLogger() {
        m_fileStream.close();
    }

    void FileLogger::logImpl(const std::string &msg, LogLevel level) {
        m_fileStream << msg << std::endl;
    }

    bool FileLogger::isCorrect() {
        return m_fileStream.is_open();
    }
} // hive