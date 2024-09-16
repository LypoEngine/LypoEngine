//
// Created by samuel on 9/16/24.
//

#include "window_factory.h"

#include "window_configuration.h"
#include "platform/glfw/glfw_window.h"

hive::Window *hive::WindowFactory::Create(std::string &title, int width, int height,
                                          const WindowConfiguration configuration) {
    return new GlfwWindow(title, width, height, configuration);
}

hive::Window * hive::WindowFactory::
Create(const char *title, int width, int height, WindowConfiguration configuration) {
    return new GlfwWindow(title, width, height, configuration);
}
