//
// Created by samuel on 9/16/24.
//

#include "window_factory.h"

#include "window_configuration.h"
#include "platform/glfw/glfw_window.h"

hive::Window *hive::WindowFactory::Create(const std::string &title, const int width, const int height,
                                          const WindowConfiguration configuration) {
    return Create(title.c_str(), width, height, configuration);
}

hive::Window * hive::WindowFactory::
Create(const char *title, const int width, const int height, const WindowConfiguration configuration) {
    return new GlfwWindow(title, width, height, configuration);
}
