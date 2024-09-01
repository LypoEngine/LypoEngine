//
// Created by mathe on 14/08/2024.
//

#pragma once
#include "VertexArray.hpp"

namespace hive
{
    class RenderAPI
    {
        public:
            enum class API
            {
                None = 0, OpenGL = 1
            };

            virtual void setClearColor(float r, float g, float b, float a) = 0;
            virtual void clear() = 0;
            virtual void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray) = 0;

            inline static API getAPI() { return api_; }
            static void setAPI(API api) { api_ = api; }

        private:
            static API api_;
    };
}
