//
// Created by mathe on 12/08/2024.
//

#include "lypch.h"
#include "RenderAPI.h"
#include <glm/glm.hpp>

namespace hive
{
    class RenderCommand
    {
        public:
            inline static void setClearColor(glm::vec4 color)
            {
                renderAPI_->setClearColor(color);
            }

            inline static void clear()
            {
                renderAPI_->clear();
            }

            inline static void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray)
            {
                renderAPI_->drawVertexArray(vertexArray);
            }

            inline static void init()
            {
                renderAPI_->init();
            }

        private:
            static RenderAPI* renderAPI_;
    };
}