#include <memory>
#include <core/rendering/Renderer.hpp>
#include <core/rendering/VertexArray.hpp>

#include "core/inputs/input.h"
#include "core/logging/Logger.h"
#include "core/logging/LoggingFactory.h"
#include "core/window/window.h"
#include "core/window/window_configuration.h"
#include "core/window/window_factory.h"

#include "scene/components.h"
#include "scene/entity.h"

#include "core/rendering/VertexBuffer.hpp"
#include "core/rendering/IndexBuffer.hpp"
#include "core/rendering/VertexArray.hpp"
#include "core/rendering/BufferUtils.h"
#include "core/rendering/Texture.h"
#include "core/rendering/shader.h"
#include "core/rendering/Renderer.hpp"
#include "core/rendering/orthographic_camera.h"
#include "scene/scene.h"

#include "core/Profiling/profiler.h"
#include "core/rendering/orthographic_camera.h"
#include "core/rendering/Texture.h"
#include "GLFW/glfw3.h"
#include "platform/opengl/opengl_shader.h"
#include "stb_image.h"
#include "core/rendering/Renderer2D.h"

unsigned int createBasicShader();
unsigned int createTextureShader();

int main(void)
{
	ENABLE_PROFILING;
	hive::Logger::setLogger(hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Info));

    //Init Logging
    hive::Logger::setLogger(hive::LoggingFactory::createLogger(hive::LogOutputType::Console, hive::LogLevel::Debug));

    //Init Window
    hive::WindowConfiguration configuration;
    configuration.set(hive::WindowConfigurationOptions::CURSOR_DISABLED, true);
    const auto window = std::unique_ptr<hive::Window>(hive::WindowFactory::Create("Hive Engine", 800, 600, configuration));

    //Init Input
    hive::Input::init(window->getNativeWindow());


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
            -0.5f, -0.5f, -0.1f, 0.8f, 0.2f, 0.8f, 1.0f,
            0.5f, -0.5f, -0.1f, 0.2f, 0.3f, 0.8f, 1.0f,
            0.0f,  0.5f, -0.1f, 0.8f, 0.8f, 0.2f, 1.0f
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
            -0.75f, -0.75f, -0.2f,  0.0f, 0.0f,
            0.75f, -0.75f, -0.2f,  1.0f, 0.0f,
            0.75f,  0.75f, -0.2f,  1.0f, 1.0f,
            -0.75f,  0.75f, -0.2f, 0.0f, 1.0f
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
    std::shared_ptr<hive::Texture2D> grassTexture = hive::Texture2D::Create("../HiveEngine/assets/textures/grass.jpg");

    textureShader->bind();
    textureShader->uploadUniformInt("u_Texture", 0);
  
    // TEST ECS
	hive::Scene scene = {};
	hive::Entity entity = scene.createEntity("Test");
	hive::Entity entity_no_name = scene.createEntity();
	std::cout << entity.toString() << std::endl;
	std::cout << entity_no_name.toString() << std::endl;
	auto& tag = entity_no_name.replaceComponent<hive::TagComponent>();
	tag.Tag = "Replace";
	std::cout << scene.toString() << std::endl;
  
    float angle = 0.0f;


    hive::Renderer::init();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(reinterpret_cast<GLFWwindow*>(window->getNativeWindow())))
    {
    	BLOCK_PROFILING("BLOCK TEST", hive::BlockStatus::ON, hive::colors::Green);
        angle += 0.005f;

        m_Camera.setPosition({ 0.5f, 0.0f, 0.0f });
        m_Camera.setRotation(angle);

        hive::Renderer::beginScene(m_Camera);

        m_Texture->bind();
        hive::Renderer::submitGeometryToDraw(squareVA, textureShader);
        hive::Renderer::submitGeometryToDraw(vertexArray, colorShader);

        hive::Renderer2D::beginScene(m_Camera);
        hive::Renderer2D::drawQuad({ 0.0f, -0.5f }, { 1.0f, 0.5f }, { 0.8f, 0.2f, 0.8f, 1.0f });

        hive::Renderer2D::drawQuad({ 0.0f, 0.0f, -0.3f }, { 10.0f, 10.0f }, grassTexture);


        hive::Renderer::endScene();
        hive::Renderer2D::endScene();


        /* Poll for and process events */
        window->onUpdate();
    	END_BLOCK_PROFILING;
    }
	DUMP_PROFILING("test.prof");
    hive::Input::shutdown();
    return 0;
}
