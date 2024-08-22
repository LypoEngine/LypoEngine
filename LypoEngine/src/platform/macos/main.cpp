//
// Created by Justin Abourjaili-Bilodeau on 7/20/2024.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "core/window.h"
#include "core/engine/engine.h"

int main(void)
{
    hive::Engine engine("New Window", 1280, 720);
    engine.run();

    return 0;
}