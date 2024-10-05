//
// Created by samuel on 8/30/24.
//
//
// Created by lapor on 7/19/2024.
//
#include <GLFW/glfw3.h>

#include "core/window.h"
#include "core/mouse.h"

#include <iostream>

#include "core/rendering/VertexBuffer.hpp"
#include "core/rendering/IndexBuffer.hpp"
#include "core/rendering/VertexArray.hpp"
#include "core/rendering/BufferUtils.h"
#include "core/rendering/Texture.h"
#include "core/rendering/shader.h"
#include "core/rendering/Renderer.hpp"
#include "core/rendering/orthographic_camera.h"

#include "core/events/event_bus.h"

#include "platform/opengl/opengl_shader.h"
#include "platform/opengl/GLCheck.h"
#include "core/logging/ConsoleLogger.h"
#include "core/logging/Logger.h"
#include "core/logging/LoggingFactory.h"

#include "scene/components.h"
#include "scene/entity.h"

#include "scene/scene.h"

unsigned int createBasicShader();
unsigned int createTextureShader();

int main(void)
{
	hive::Logger::setLogger(hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Info));

    auto window = hive::Window::create("Windows Window", 600, 700, hive::WindowFlags::DEFAULT);

	// int width, height;
	// auto data = stbi_load("../HiveEngine/assets/icon.png", &width, &height, nullptr, 0);
	// window->setWindowIcon(data, width, height);

    // auto mouse = hive::Mouse::create(window->getNativeWindow());

    //from learnopengl.com
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /*unsigned int shaderProgram = createBasicShader();
    unsigned int textureShader = createTextureShader();*/

    hive::OrthographicCamera m_Camera(-1.0f, 1.0f, -1.0f, 1.0f);

    std::string fragmentPath = "../HiveEngine/assets/shaders/basicColorShader.frag.glsl";
    std::string vertexPath = "../HiveEngine/assets/shaders/basicColorShader.vert.glsl";

    std::shared_ptr<hive::OpenglShader> colorShader = std::make_shared<hive::OpenglShader>(vertexPath, fragmentPath);

    fragmentPath = "../HiveEngine/assets/shaders/textureShader.frag.glsl";
    vertexPath = "../HiveEngine/assets/shaders/textureShader.vert.glsl";

    std::shared_ptr<hive::OpenglShader> textureShader = std::make_shared<hive::OpenglShader>(vertexPath, fragmentPath);

    std::shared_ptr<hive::VertexArray> vertexArray;
    std::shared_ptr<hive::VertexArray> squareVA;

    vertexArray.reset(hive::VertexArray::create());

    float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
            0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
            0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
    };

    std::shared_ptr<hive::VertexBuffer> vertexBuffer = std::shared_ptr<hive::VertexBuffer>(hive::VertexBuffer::create(vertices, sizeof(vertices)));
    hive::BufferLayout layout = {
            { hive::ShaderDataType::Float3, "a_Position" },
            { hive::ShaderDataType::Float4, "a_Color" }
    };
    vertexBuffer->setLayout(layout);

    vertexArray->addVertexBuffer(vertexBuffer);

    uint32_t indices[3] = { 0, 1, 2 };
    std::shared_ptr<hive::IndexBuffer> indexBuffer;
    indexBuffer.reset(hive::IndexBuffer::create(indices, sizeof(indices)));
    vertexArray->setIndexBuffer(indexBuffer);

    squareVA.reset(hive::VertexArray::create());

    float squareVertices[5 * 4] = {
            -0.75f, -0.75f, 0.0f,  0.0f, 0.0f,
            0.75f, -0.75f, 0.0f,  1.0f, 0.0f,
            0.75f,  0.75f, 0.0f,  1.0f, 1.0f,
            -0.75f,  0.75f, 0.0f, 0.0f, 1.0f
    };

    std::shared_ptr<hive::VertexBuffer> squareVB = std::shared_ptr<hive::VertexBuffer>(hive::VertexBuffer::create(squareVertices, sizeof(squareVertices)));
    squareVB->setLayout({
                                {hive::ShaderDataType::Float3, "a_Position"},
                                { hive::ShaderDataType::Float2, "a_TexCoord" }
                        });
    squareVA->addVertexBuffer(squareVB);

    uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
    std::shared_ptr<hive::IndexBuffer> squareIB;
    squareIB.reset(hive::IndexBuffer::create(squareIndices, sizeof(squareIndices)));
    squareVA->setIndexBuffer(squareIB);

    std::shared_ptr<hive::Texture2D> m_Texture = hive::Texture2D::Create("../HiveEngine/assets/textures/Checkerboard.png");

    textureShader->bind();
    textureShader->uploadUniformInt("u_Texture", 0);
  
    // TEST ECS
	  hive::Scene scene;
	  hive::Entity entity = scene.createEntity("Test");
	  hive::Entity entity_no_name = scene.createEntity();
	  std::cout << entity.toString() << std::endl;
	  std::cout << entity_no_name.toString() << std::endl;
	  auto& tag = entity_no_name.replaceComponent<hive::TagComponent>();
	  tag.Tag = "Replace";
	  std::cout << scene.toString() << std::endl;
   float angle = 0.0f;
  
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(reinterpret_cast<GLFWwindow*>(window->getNativeWindow())))
    {
        angle += 0.5f;

        m_Camera.setPosition({ 0.5f, 0.0f, 0.0f });
        m_Camera.setRotation(angle);

        hive::Renderer::beginScene(m_Camera);

        m_Texture->bind();
        hive::Renderer::submitGeometryToDraw(squareVA, textureShader);

        hive::Renderer::submitGeometryToDraw(vertexArray, colorShader);

        hive::Renderer::endScene();


        /* Poll for and process events */
        double xpos, ypos;
        // mouse->getPosition(xpos, ypos);

        // if (mouse->isButtonPressed(hive::ButtonValue::BUTTON_RIGHT))
        // {
            // std::cout << " Right mouse button pressed" << std::endl;
        // }
        window->onUpdate();
    }
    return 0;
}

