#include <memory>

#include "core/inputs/input.h"
#include "core/logging/Logger.h"
#include "core/logging/LoggingFactory.h"
#include "core/window/window.h"
#include "core/window/window_configuration.h"
#include "core/window/window_factory.h"

int main()
{

    //Init Logging
    hive::Logger::setLogger(hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Debug));

    //Init Window
    hive::WindowConfiguration configuration;
    configuration.set(hive::WindowConfigurationOptions::CURSOR_DISABLED, true);
    const auto window = std::unique_ptr<hive::Window>(hive::WindowFactory::Create("Hive Engine", 800, 600, configuration));

    //Init Input
    hive::Input::init(window->getNativeWindow());

    while(!window->shouldClose()) {
        window->onUpdate();

        if(hive::Input::getKeyDown(hive::KeyCode::KEY_SPACE)) {
            hive::Logger::log("Space was pressed", hive::LogLevel::Info);
        }
    }

    //Shutdown Input
    hive::Input::shutdown();
    //Shutdown Window (automatic in this case)
    //Shutdown Logger (automatic in this case)
    return 0;
}
