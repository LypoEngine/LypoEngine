//
// Created by GuillaumeIsCoding on 7/28/2024.
//
#include "core/mouse.h"

#ifdef HIVE_PLATFORM_GLFW
#include "platform/glfw/glfw_mouse.h"
#endif

namespace core
{
    std::unique_ptr<Mouse> Mouse::create(void* window, const MouseStates& configuration)
    {
        #ifdef HIVE_PLATFORM_GLFW
        return std::make_unique<platform::GlfwMouse>(window, configuration);
        #else
            LYPO_CORE_ERROR("Unknown platform");
            return nullptr;
        #endif
    }
}