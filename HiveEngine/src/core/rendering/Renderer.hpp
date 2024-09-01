#pragma once
#include "lypch.h"
#include "VertexArray.hpp"
#include "shader.h"
#include "RenderCommand.h"

namespace hive {

	class Renderer
	{
	public:
        static void beginScene();
        static void beginScene(float r, float g, float b, float a);
        static void endScene();

        static void submitGeometryToDraw(const std::shared_ptr<VertexArray>& vertexArray);

        static void submitGeometryToDraw(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader);

		inline static RenderAPI::API getApi() { return RenderAPI::getAPI(); }
	};


}