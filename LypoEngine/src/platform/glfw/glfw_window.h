//
// Created by GuillaumeIsCoding on 7/26/2024.
//
#pragma once

#include "core/window.h"
#include "platform/glfw/inputs/glfw_input_manager.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <cstdint>

namespace hive 
{
        /**
         * @brief Windows concrete class of core::Window
         */
        class GlfwWindow : public hive::Window
        {
        public:
            GlfwWindow(const std::string& title, const uint32_t& width, const uint32_t& height, const hive::WindowFlags& flag = hive::WindowFlags::DEFAULT) noexcept;
            GlfwWindow(const hive::WindowProperties& properties) noexcept;
            virtual ~GlfwWindow() noexcept override;

            void onUpdate() override;

            uint32_t getWidth() const override;
            uint32_t getHeight() const override;

            void setVSync(bool enabled) override;
            bool isVSync() const override; 

            void* getNativeWindow() const;
            void setWindowIcon(unsigned char *data, int width, int height) const override;
        private:
            void initialize() noexcept;
            void shutdown() noexcept;

        public:

        private:
            struct DataImpl;
            std::unique_ptr<DataImpl> p_data_impl_;
        };
}