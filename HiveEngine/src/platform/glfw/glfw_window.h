//
// Created by GuillaumeIsCoding on 7/26/2024.
//
#pragma once

#include "core/window/window.h"
#include "core/window/window_configuration.h"
#include <GLFW/glfw3.h>

namespace hive 
{

        /**
         * @brief Windows concrete class of core::Window
         */
        class GlfwWindow final : public Window
        {
        public:
            GlfwWindow(const std::string &title, int width, int height, WindowConfiguration configuration);

            ~GlfwWindow() override;

            [[nodiscard]] int getWidth() const override;

            [[nodiscard]] int getHeight() const override;

            [[nodiscard]] void *getNativeWindow() const override;

            void setIcon(unsigned char *data, int width, int height) const override;

            void updateConfiguration(WindowConfiguration configuration) override;

            void onUpdate() const override;

            [[nodiscard]] bool shouldClose() const override;

        private:
            int m_Width, m_Height;
            GLFWwindow *m_Window;
            WindowConfiguration m_Configuration;
        };
}
