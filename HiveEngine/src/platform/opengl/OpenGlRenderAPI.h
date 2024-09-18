//
// Created by mathe on 14/08/2024.
//

#pragma once
#include "core/rendering/RenderAPI.h"

namespace hive {
    class OpenGlRenderAPI : public RenderAPI
    {
        public:
            virtual void setClearColor(glm::vec4) override;
            virtual void clear() override;
            void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray) override;
    };
}


