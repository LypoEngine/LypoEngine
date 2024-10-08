//
// Created by samuel on 10/7/24.
//

#include <gtest/gtest.h>

#include "core/logging/Logger.h"
#include "core/logging/LoggingFactory.h"


TEST(Logger, ConsoleLoggerShouldLogToConsole)
{
	hive::Logger *logger = hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Debug);
	hive::Logger::init(logger);

	testing::internal::CaptureStdout();

	hive::Logger::log("Basic test", hive::LogLevel::Info);

	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("Basic test"), std::string::npos);

	hive::Logger::shutdown();
}


TEST(Logger, ConsoleLoggerShouldLogLevelEqualOrAbove)
{
	hive::Logger *logger = hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Warning);
	hive::Logger::init(logger);

	{
		testing::internal::CaptureStdout();
		hive::Logger::log("Basic test", hive::LogLevel::Info);
		std::string output = testing::internal::GetCapturedStdout();
		EXPECT_EQ(output, "");
	}

	{
		testing::internal::CaptureStdout();
		hive::Logger::log("Basic test", hive::LogLevel::Warning);
		std::string output = testing::internal::GetCapturedStdout();
		EXPECT_NE(output.find("Basic test"), std::string::npos);
	}


	{
		testing::internal::CaptureStdout();
		hive::Logger::log("Basic test", hive::LogLevel::Error);
		std::string output = testing::internal::GetCapturedStdout();
		EXPECT_NE(output.find("Basic test"), std::string::npos);
	}


}

