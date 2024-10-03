#include <memory>

#include "core/inputs/input.h"
#include "core/logging/Logger.h"
#include "core/logging/LoggingFactory.h"
#include "core/window/window.h"
#include "core/window/window_configuration.h"
#include "core/window/window_factory.h"
#include "scene/components.h"
#include "scene/ecs.h"
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
    void update(float deltaTime) override
    {
        if (hive::Input::getKeyDown(hive::KeyCode::KEY_SPACE))
        {
            hive::Logger::log("Space was pressed", hive::LogLevel::Info);
            hive::QueryBuilder<myData> query;

            for(auto [entity, data]: query.each()) {
                hive::Logger::log(data.toString(), hive::LogLevel::Info);
                data.x += 1;
            }
        }
    }
};

void setupEcs()
{
    //ECS
    hive::ECS::init();

    auto entity = hive::ECS::createEntity();
    hive::ECS::addComponent<myData>(entity);

    hive::ECS::registerSystem(new TestSystem(), "TestSystem");
}

int main()
{

    //Init Logging
    hive::Logger::setLogger(hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Debug));

    //Init Window
    hive::WindowConfiguration configuration;
    // configuration.set(hive::WindowConfigurationOptions::CURSOR_DISABLED, true);
    const auto window = std::unique_ptr<hive::Window>(hive::WindowFactory::Create("Hive Engine", 800, 600, configuration));

    //Init Input
    hive::Input::init(window->getNativeWindow());


    setupEcs();
    //Game loop
    while(!window->shouldClose()) {
        //Swap the buffer
        window->onUpdate();

        //Run all the systems
        hive::ECS::updateSystems(0);
    }

    hive::ECS::shutdown();

    //Shutdown Input
    hive::Input::shutdown();
    //Shutdown Window (automatic in this case)
    //Shutdown Logger (automatic in this case)
    return 0;
}
