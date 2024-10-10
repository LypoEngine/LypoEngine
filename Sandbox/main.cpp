#include <memory>

#include "core/inputs/input.h"
#include "core/logging/Logger.h"
#include "core/logging/LoggerFactory.h"
#include "core/window/window.h"
#include "core/window/WindowManager.h"
#include "core/window/window_configuration.h"
#include "core/window/window_factory.h"
#include "scene/components.h"
#include "scene/ECS.h"
#include "scene/query_builder.h"
#include "scene/system_manager.h"



struct myData : hive::IComponent
{
    float x, y;

    std::string toString() override
    {
        return std::string(std::to_string(x) + " " + std::to_string(y));
    }
};

class TestSystem : public hive::System::System
{

public:
    void update(float deltaTime) override
    {
        if(hive::Input::getKeyDown(hive::KEY_SPACE))
        {
            auto window = hive::WindowManager::getCurrentWindow();
            auto config = window->getConfiguration();

            config.toggle(hive::WindowConfigurationOptions::CURSOR_DISABLED);
            window->updateConfiguration(config);
        }
    }
};


void setupLogger(const hive::LogOutputType type, const hive::LogLevel level)
{
    hive::Logger::init(hive::LoggerFactory::createLogger(type, level));
}

void setupWindow(const hive::WindowConfiguration configuration)
{
    auto window = std::shared_ptr<hive::Window>(hive::WindowFactory::Create("Hive Engine", 800, 600, configuration));
    hive::WindowManager::setCurrentWindow(window);
}

void setupInput()
{
    auto window = hive::WindowManager::getCurrentWindow();
    hive::Input::init(window->getNativeWindowData());
}

void setupEcs()
{
    //ECS
    hive::ECS::init();

    auto entity = hive::ECS::createEntity();
    hive::ECS::addComponent<myData>(entity);

    hive::ECS::registerSystem(new TestSystem(), "TestSystem");
}


void shutdown()
{
    hive::ECS::shutdown();
    hive::Input::shutdown();
    hive::WindowManager::setCurrentWindow(nullptr);
    hive::Logger::shutdown();
}

void init()
{
    setupLogger(hive::LogOutputType::Console, hive::LogLevel::Debug);

    hive::WindowConfiguration configuration;
    // configuration.set(hive::WindowConfigurationOptions::CURSOR_DISABLED, true);
    setupWindow(configuration);

    setupInput();

    setupEcs();
}

int main()
{
    init();

    //Game loop
    auto window = hive::WindowManager::getCurrentWindow();
    while(!window->shouldClose()) {
        //Swap the buffer
        window->onUpdate();

        //Run all the systems
        hive::ECS::updateSystems(0);
    }

    window.reset();

    shutdown();

    return 0;
}
