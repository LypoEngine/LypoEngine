//
// Created by samuel on 10/8/24.

#include "core/logging/Logger.h"
#include "core/logging/LoggerFactory.h"
#include "core/window/window.h"
#include "core/window/window_configuration.h"
#include "core/window/window_factory.h"




/**
 * Base class of the engine. The correct usage is to inherit from it and extends it's functions like init and shutdown
 * Responsible to startup the basic system required for a game or an application
 */
class Engine
{
public:
	virtual ~Engine() = default;

	virtual void init(const std::string &application_name)
	{
		hive::Logger::init(hive::LoggerFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Info));

		hive::WindowConfiguration window_configuration;
		window_ = hive::WindowFactory::Create(application_name, 700, 600, window_configuration);

	}

	virtual void shutdown()
	{
		hive::Logger::shutdown();
	}

	virtual void run()
	{
		while(!window_->shouldClose())
		{
			window_->onUpdate();
		}
	}

protected:
	hive::Window *window_ = nullptr;

};



class Editor final : public Engine
{
public:
	void init()
	{
		Engine::init("Engine Editor");
		hive::Logger::log("Initializing the editor", hive::LogLevel::Info);
		//Register some system here for example
	}

	void shutdown() override
	{
		Engine::shutdown();

	}
};

int main()
{
	Editor editor;

	editor.init();
	editor.run();
	editor.shutdown();
}