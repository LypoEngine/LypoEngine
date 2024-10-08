//
// Created by mathe on 02/10/2024.
//

#ifndef RENDERER2D_H
#define RENDERER2D_H

#include "orthographic_camera.h"
#include "VertexArray.hpp"
#include "shader.h"
#include "Texture.h"

namespace hive {

    struct Renderer2DStorage
    {
        SRef<VertexArray> QuadVertexArray;
        SRef<Shader> FlatColorShader;
        SRef<Shader> TextureShader;
    };

    class Renderer2D {

        public:
            static void init();
            static void shutdown();
            static void beginScene(const OrthographicCamera& camera);
            static void endScene();

            static void drawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
            static void drawQuad(const glm::vec3 &positionWithZValue, const glm::vec2 &size, const glm::vec4 &color);

            static void drawQuad(const glm::vec2& position, const glm::vec2& size, const SRef<Texture2D>& texture);
            static void drawQuad(const glm::vec3& positionWithZValue, const glm::vec2& size, const SRef<Texture2D>& texture);
    };
}



#endif //RENDERER2D_H
