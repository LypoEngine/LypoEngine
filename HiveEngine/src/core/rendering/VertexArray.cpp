

#include "VertexArray.hpp"
#include "Renderer.hpp"
#include "platform/opengl/OpenGlVertexArray.hpp"

namespace hive {

    VertexArray *VertexArray::create() {
        switch (Renderer::getApi()) {
            case RenderAPI::API::None:    LYPO_CORE_ERROR("RendererAPI::None is not supported") return nullptr;
            case RenderAPI::API::OpenGL:
                return new OpenGLVertexArray();
        }

        LYPO_CORE_ERROR("This API is not supported");
        return nullptr;
    }

}
