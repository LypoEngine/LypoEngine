//
// Created by Justin Abourjaili-Bilodeau on 8/19/24.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "engine.h"
#include "core/events/event.h"

namespace hive {

    Engine::Engine(const std::string &title, const uint32_t &width, const uint32_t &height,
                   const WindowFlags &flag) {
        window = hive::Window::create(title, width, height, flag);
        init();
    }

    Engine::~Engine() {

    }

    void Engine::init() {

    }

    void Engine::mainLoop() {
        while (!window->shouldClose())
        {
            /* Render here TEMP */
            glClear(GL_COLOR_BUFFER_BIT);
            /* Poll for and process events */
            window->onUpdate();
        }
    }

    void Engine::run() {
        mainLoop();
    }


} // hive