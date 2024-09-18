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

        bool isCorrect() override;

    protected:
        void logImpl(const std::string &msg, LogLevel level) override;

    private:
        std::ofstream m_fileStream;
    };

} // hive

#endif //FILELOGGER_H
