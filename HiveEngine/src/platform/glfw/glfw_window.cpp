//
// Created by GuillaumeIsCoding on 7/26/2024.
//

#include <glad/glad.h>
#include "glfw_window.h"


#include "core/window/window_configuration.h"

namespace hive
{

    GlfwWindow::GlfwWindow(const std::string &title, const int width, const int height, WindowConfiguration configuration): m_Width(width), m_Height(height), m_Window(nullptr) {
        if(!glfwInit()) {
            //TODO LOG message
            Logger::log("Unable to initialize glfw", LogLevel::Error);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        m_Window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if(m_Window == nullptr) {
            Logger::log("Unable to create a glfw window", LogLevel::Error);
        }


        glfwMakeContextCurrent(m_Window);

        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            Logger::log("Unable to init glad", LogLevel::Error);
        }
        updateConfiguration(configuration);
    }

    GlfwWindow::~GlfwWindow() {
        Logger::log("Destructor GLFWWindow", LogLevel::Debug);
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    int GlfwWindow::getWidth() const {
        return m_Width;
    }

    int GlfwWindow::getHeight() const {
        return m_Height;
    }

    void * GlfwWindow::getNativeWindow() const {
        return m_Window;;
    }


    void GlfwWindow::setIcon(unsigned char *data, const int width, const int height) const
    {
        GLFWimage images;
        images.pixels = data;
        images.width = width;
        images.height = height;

        glfwSetWindowIcon(m_Window, 1, &images);
    }

    void GlfwWindow::updateConfiguration(WindowConfiguration configuration) {
        auto diff_config = m_Configuration ^ configuration;
        m_Configuration = configuration;

        for(int i = 0; i < WindowConfiguration::MAX_BIT; i++) {
            //Iterate through all the config that was changed
            auto flag = static_cast<WindowConfigurationOptions>(i);

            //TODO Find a cleaner way to write this
            if(diff_config.has(flag)) {
                //There is a difference in the config
                switch(flag) {
                    case WindowConfigurationOptions::FULLSCREEN: {
                        if(m_Configuration.has(flag)) {
                            auto monitor = glfwGetPrimaryMonitor();
                            auto mode = glfwGetVideoMode(monitor);
                            glfwSetWindowMonitor(m_Window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
                            //TODO Resize the framebuffer here
                        } else {
                            glfwSetWindowMonitor(m_Window, nullptr, 0, 0, m_Width, m_Height, GLFW_DONT_CARE);
                            //TODO Resize the framebuffer here
                        }
                        break;
                    }
                    case WindowConfigurationOptions::CURSOR_DISABLED: {
                        if(m_Configuration.has(flag)) {
                            glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                        } else {
                            glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                        }
                        break;
                    }
                    default:
                        //TODO ASSERT that we never end up here. This would mean that a config is not supported
                        break;
                }
            }
        }

    }

    void GlfwWindow::onUpdate() const {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    bool GlfwWindow::shouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }
}
