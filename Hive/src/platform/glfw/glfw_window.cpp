//
// Created by GuillaumeIsCoding on 7/26/2024.
//
#include "glfw_window.h"

namespace hive
{
    struct GlfwWindow::DataImpl
    {
        DataImpl(const std::string& title, const uint32_t& width, const uint32_t& height, const hive::WindowFlags& flag, bool vSync, 
            GLFWwindow* window = nullptr, GLFWmonitor* monitor = nullptr, const GLFWvidmode* mode = nullptr)
            : title(title), width(width), height(height), flag(flag), vSync(vSync), window(window), monitor(monitor), mode(mode) {}
        std::string title;
        uint32_t width, height;
        bool vSync;
        hive::WindowFlags flag;
        GLFWwindow* window;
        GLFWmonitor* monitor;
        const GLFWvidmode* mode;
    };

    GlfwWindow::GlfwWindow(const hive::WindowProperties& properties) noexcept : GlfwWindow(properties.title, properties.width, properties.height, properties.flag) {}

    GlfwWindow::GlfwWindow(const std::string& title, const uint32_t& width, const uint32_t& height, const hive::WindowFlags& flag) noexcept 
        : p_data_impl_(std::make_unique<GlfwWindow::DataImpl>(title, width, height, flag, false, nullptr, nullptr, nullptr))
    {
        initialize();
    }
        
    GlfwWindow::~GlfwWindow() noexcept
    {
        shutdown();
    }

    void GlfwWindow::initialize() noexcept
    {  
        if (!glfwInit())
        {
            LYPO_CORE_ERROR("Unable to initialize glfw");
            return ;
        }

        switch (p_data_impl_->flag)
        {
            case hive::WindowFlags::FULLSCREEN:
                p_data_impl_->monitor = glfwGetPrimaryMonitor();
            case hive::WindowFlags::DEFAULT:
                p_data_impl_->window = glfwCreateWindow(p_data_impl_->width, p_data_impl_->height, p_data_impl_->title.c_str(), p_data_impl_->monitor, NULL);
                break;
            case hive::WindowFlags::WINDOWED_FULLSCREEN:
                p_data_impl_->window = glfwCreateWindow(p_data_impl_->width, p_data_impl_->height, p_data_impl_->title.c_str(), p_data_impl_->monitor, NULL);
                p_data_impl_->monitor = glfwGetPrimaryMonitor();
                p_data_impl_->mode = glfwGetVideoMode(p_data_impl_->monitor);
                glfwSetWindowMonitor(p_data_impl_->window, p_data_impl_->monitor, 0, 0, p_data_impl_->mode->width, p_data_impl_->mode->height, p_data_impl_->mode->refreshRate);
                break;
            }

        if (!p_data_impl_->window)
        {
            LYPO_CORE_ERROR("Unable to initialize the window");
            return;
        }

        glfwMakeContextCurrent(p_data_impl_->window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            LYPO_CORE_ERROR("Unable to load glad");
            return;
        }

        hive::GlfwInputManager im = hive::GlfwInputManager(p_data_impl_->window);
        glfwSetKeyCallback(p_data_impl_->window, im.key_callback);

        glfwSetWindowUserPointer(p_data_impl_->window, &p_data_impl_);
        setVSync(true);
    }

    void GlfwWindow::shutdown() noexcept
    { 
        glfwDestroyWindow(p_data_impl_->window);
        glfwTerminate();
    }

    void GlfwWindow::onUpdate()
    {
        /* Swap front and back buffers */
        glfwSwapBuffers(p_data_impl_->window);

        glfwPollEvents();
    }

    void GlfwWindow::setVSync(bool enabled)
    {
        glfwSwapInterval(enabled ? 1 : 0);
        p_data_impl_->vSync = enabled;
    }

    bool GlfwWindow::isVSync() const 
    {
        return p_data_impl_->vSync;
    }

    uint32_t GlfwWindow::getWidth() const 
    {
        return p_data_impl_->width;
    }

    uint32_t GlfwWindow::getHeight() const 
    {
        return p_data_impl_->height;
    }

    void* GlfwWindow::getNativeWindow() const
    {
        return p_data_impl_->window;
    }

    void GlfwWindow::setWindowIcon(unsigned char *data, int width, int height) const
    {
        GLFWimage images;
        images.pixels = data;
        images.width = width;
        images.height = height;
        auto window = static_cast<GLFWwindow *>(getNativeWindow());

        glfwSetWindowIcon(window, 1, &images);
    }
}
