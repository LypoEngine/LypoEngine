//
// Created by mathe on 02/10/2024.
//

#include "Renderer2D.h"
#include "platform/opengl/opengl_shader.h"
#include "RenderCommand.h"
#include <glm/gtc/matrix_transform.hpp>


namespace hive {

    static Renderer2DStorage* render2dData =nullptr;

    void Renderer2D::init()
    {
        float quadVertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
        };

        uint32_t quadIndices[6] = { 0, 1, 2, 2, 3, 0 };

        render2dData = new hive::Renderer2DStorage();

        render2dData->QuadVertexArray.reset(hive::VertexArray::create());
        SRef<hive::VertexBuffer> quadVB;
        quadVB.reset(hive::VertexBuffer::create(quadVertices, sizeof(quadVertices)));
        quadVB->setLayout({
            { hive::ShaderDataType::Float3, "a_Position" },
            { ShaderDataType::Float2, "a_TexCoord" }
        });
        render2dData->QuadVertexArray->addVertexBuffer(quadVB);

        SRef<hive::IndexBuffer> quadIB;
        quadIB.reset(hive::IndexBuffer::create(quadIndices, sizeof(quadIndices)));
        render2dData->QuadVertexArray->setIndexBuffer(quadIB);

        std::string fragmentPathflatColor = "../HiveEngine/assets/shaders/flatColor.frag.glsl";
        std::string vertexPathflatColor = "../HiveEngine/assets/shaders/flatColor.vert.glsl";

        render2dData->FlatColorShader = std::make_shared<hive::OpenglShader>(vertexPathflatColor, fragmentPathflatColor);

        std::string fragmentPathTexture = "../HiveEngine/assets/shaders/texture.frag.glsl";
        std::string vertexPathTexture = "../HiveEngine/assets/shaders/texture.vert.glsl";

        render2dData->TextureShader = std::make_shared<hive::OpenglShader>(vertexPathTexture, fragmentPathTexture);
        render2dData->TextureShader->bind();
        render2dData->TextureShader->uploadUniformInt("u_Texture", 0);
    }
    void Renderer2D::shutdown()
    {
        delete render2dData;
    }
    void Renderer2D::beginScene(const OrthographicCamera& camera)
    {
        render2dData->FlatColorShader->bind();
        render2dData->FlatColorShader->uploadUniformMat4("u_ViewProjection", camera.getViewProjectionMatrix());
        render2dData->TextureShader->bind();
        render2dData->TextureShader->uploadUniformMat4("u_ViewProjection", camera.getViewProjectionMatrix());
    }
    void Renderer2D::endScene()
    {
    }
    void Renderer2D::drawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color)
    {
        drawQuad({ position.x, position.y, 0.0f }, size, color);
    }
    void Renderer2D::drawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color)
    {
        render2dData->FlatColorShader->bind();
        render2dData->FlatColorShader->uploadUniformFloat4("u_Color", color);

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
        render2dData->FlatColorShader->uploadUniformMat4("u_Transform", transform);

        render2dData->QuadVertexArray->bind();
        hive::RenderCommand::drawVertexArray(render2dData->QuadVertexArray);
    }

    void Renderer2D::drawQuad(const glm::vec2& position, const glm::vec2& size, const SRef<Texture2D>& texture)
    {
        drawQuad({ position.x, position.y, 0.0f }, size, texture);
    }

    void Renderer2D::drawQuad(const glm::vec3& position, const glm::vec2& size, const SRef<Texture2D>& texture)
    {
        render2dData->TextureShader->bind();

        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), { size.x, size.y, 1.0f });
        render2dData->TextureShader->uploadUniformMat4("u_Transform", transform);

        texture->bind();
        render2dData->QuadVertexArray->bind();
        RenderCommand::drawVertexArray(render2dData->QuadVertexArray);
    }
}