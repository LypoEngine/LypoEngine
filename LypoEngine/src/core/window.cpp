//
// Created by GuillaumeIsCoding on 8/05/2024
//
#include "core/window.h"

#ifdef HIVE_PLATFORM_GLFW
#include "platform/glfw/glfw_window.h"
#endif

namespace core
{
    std::unique_ptr<Window> Window::create(const WindowProperties& props) noexcept
    {
        return Window::create(props.title, props.width, props.height, props.flag);
    }

    std::unique_ptr<Window> Window::create(const std::string& title, const uint32_t& width, const uint32_t& height, const WindowFlags& flag) noexcept
    {
        #ifdef HIVE_PLATFORM_GLFW
        return std::make_unique<platform::GlfwWindow>(title, width, height, flag);
        #else
            LYPO_CORE_ERROR("Unknown platform");
            return nullptr;
        #endif
    }
}