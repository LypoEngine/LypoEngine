//
// Created by samuel on 8/30/24.
//

#ifndef FILELOGGER_H
#define FILELOGGER_H
#include "Logger.h"

#include <fstream>
#include <string>

namespace hive {
    class FileLogger final : public Logger {
    public:
        explicit FileLogger(const std::string &filePath, const LogLevel logLevel);

        ~FileLogger() override;
        void log(const std::string &msg, LogLevel level) override;

        bool isCorrect() override;

    private:
        std::ofstream m_fileStream;
    };

} // hive

#endif //FILELOGGER_H
