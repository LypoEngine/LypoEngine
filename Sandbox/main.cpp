#include <memory>

#include "core/window/window.h"
#include "core/window/window_configuration.h"
#include "core/window/window_factory.h"

int main(void)
{
    hive::WindowConfiguration configuration;

    auto window = std::unique_ptr<hive::Window>(hive::WindowFactory::Create("Hive Engine", 800, 600, configuration));

    while(!window->shouldClose()) {
        window->onUpdate();
    }

    return 0;
}
