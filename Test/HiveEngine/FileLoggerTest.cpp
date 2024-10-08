//
// Created by samuel on 10/7/24.
//

#include <bits/fs_fwd.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core/logging/FileLogger.h"
#include "core/logging/Logger.h"
#include "core/logging/LoggingFactory.h"


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
	hive::Logger *logger = hive::LoggingFactory::createLogger(hive::LogOutputType::File, hive::LogLevel::Debug);
	hive::Logger::init(logger);
	hive::Logger::log("Basic test", hive::LogLevel::Info);
	hive::Logger::shutdown();

	std::string content = readFile("log.txt");

	EXPECT_STREQ("Basic test\n", content.c_str());
}


// TEST(Logger, ConsoleLoggerShouldLogLevelEqualOrAbove)
// {
// 	hive::Logger *logger = hive::LoggingFactory::createLogger(hive::LogOutputType::File, hive::LogLevel::Warning);
// 	hive::Logger::setLogger(logger);
//
// 	{
// 		testing::internal::CaptureStdout();
// 		hive::Logger::log("Basic test", hive::LogLevel::Info);
// 		std::string output = testing::internal::GetCapturedStdout();
// 		EXPECT_EQ(output, "");
// 	}
//
// 	{
// 		testing::internal::CaptureStdout();
// 		hive::Logger::log("Basic test", hive::LogLevel::Warning);
// 		std::string output = testing::internal::GetCapturedStdout();
// 		EXPECT_NE(output.find("Basic test"), std::string::npos);
// 	}
//
//
// 	{
// 		testing::internal::CaptureStdout();
// 		hive::Logger::log("Basic test", hive::LogLevel::Error);
// 		std::string output = testing::internal::GetCapturedStdout();
// 		EXPECT_NE(output.find("Basic test"), std::string::npos);
// 	}
// }

