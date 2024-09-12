
#include "Renderer.hpp"
#include "VertexBuffer.hpp"
#include "platform/opengl/OpenGlVertexBuffer.hpp"

namespace hive {
	VertexBuffer* VertexBuffer::create(float* vertices, uint32_t size)
	{
		switch (Renderer::getApi())
		{
			case RenderAPI::API::None:   Logger::log("RendererAPI::None is not supported", LogLevel::Warning); return nullptr;
            case RenderAPI::API::OpenGL:  return new OpenGlVertexBuffer(vertices, size);
		}

        Logger::log("This API is not supported", LogLevel::Error);
		return nullptr;
	}
}
