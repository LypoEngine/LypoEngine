
#include "Renderer.hpp"
#include "VertexBuffer.hpp"
#include "platform/opengl/OpenGlVertexBuffer.hpp"

namespace hive {
	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size)
	{
		switch (Renderer::getApi())
		{
            case RenderAPI::API::None:   LYPO_CORE_ERROR("RendererAPI::None is not supported") return nullptr;
            case RenderAPI::API::OpenGL:  return new OpenGlVertexBuffer(vertices, size);
		}

        LYPO_CORE_ERROR("This API is not supported");
		return nullptr;
	}
}
