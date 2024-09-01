//
// Created by mathe on 12/08/2024.
//

#include "lypch.h"
#include "RenderAPI.h"

namespace hive
{
    class RenderCommand
    {
        public:
            inline static void setClearColor(float r, float g, float b, float a)
            {
                renderAPI_->setClearColor(r, g, b, a);
            }

            inline static void clear()
            {
                renderAPI_->clear();
            }

            inline static void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray)
            {
                renderAPI_->drawVertexArray(vertexArray);
            }

        private:
            static RenderAPI* renderAPI_;
    };
}