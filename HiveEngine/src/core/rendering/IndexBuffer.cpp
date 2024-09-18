
#include "Renderer.hpp"
#include "IndexBuffer.hpp"

#include "platform/opengl/OpenGlIndexBuffer.hpp"

namespace hive {
    IndexBuffer* IndexBuffer::create(uint32_t * indices, uint32_t count)
    {
        switch (Renderer::getApi())
        {
            case RenderAPI::API::None:   Logger::log("RendererAPI::None is not supported", LogLevel::Warning); return nullptr;
            case RenderAPI::API::OpenGL:  return new OpenGlIndexBuffer(indices, count);
        }

        Logger::log("This API is not supported", LogLevel::Error);
        return nullptr;
    }
}
