//
// Created by samuel on 10/7/24.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core/logging/FileLogger.h"
#include "core/logging/Logger.h"
#include "core/logging/LoggerFactory.h"


#include <filesystem>
class FileLoggerTest : public testing::Test
{

public:
	static std::string readFile(const std::string& filePath)
	{
		std::ifstream file(filePath);
		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	}
protected:
	void SetUp() override
	{
		std::filesystem::path filepath("log.txt");
		std::filesystem::remove(filepath);
	}
};


TEST_F(FileLoggerTest, FileLoggerShouldLogToFile)
{
	hive::Logger *logger = hive::LoggerFactory::createLogger(hive::LogOutputType::File, hive::LogLevel::Debug);
	hive::Logger::init(logger);
	hive::Logger::log("Basic test", hive::LogLevel::Info);
	hive::Logger::shutdown();

	std::string content = readFile("log.txt");

	EXPECT_STREQ("Basic test\n", content.c_str());
}


TEST_F(FileLoggerTest, FileLoggerShouldLogLevelEqualOrAbove)
{
	hive::Logger *logger = hive::LoggerFactory::createLogger(hive::LogOutputType::File, hive::LogLevel::Warning);
	EXPECT_TRUE(logger->isCorrect());

	hive::Logger::init(logger);

	hive::Logger::log("Basic test", hive::LogLevel::Debug);
	hive::Logger::log("Basic test", hive::LogLevel::Info);
	hive::Logger::log("Basic test", hive::LogLevel::Warning);
	hive::Logger::log("Basic test", hive::LogLevel::Error);
	hive::Logger::log("Basic test", hive::LogLevel::Fatal);

	hive::Logger::shutdown();

	std::string content = readFile("log.txt");
	EXPECT_STREQ("Basic test\nBasic test\nBasic test\n", content.c_str());
}

