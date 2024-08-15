#include "OpenGlVertexArray.hpp"

#include <glad/glad.h>
#include "GLCheck.h"

namespace hive {
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
            case hive::ShaderDataType::Float:    return GL_FLOAT;
            case hive::ShaderDataType::Float2:   return GL_FLOAT;
            case hive::ShaderDataType::Float3:   return GL_FLOAT;
            case hive::ShaderDataType::Float4:   return GL_FLOAT;
            case hive::ShaderDataType::Mat3:     return GL_FLOAT;
            case hive::ShaderDataType::Mat4:     return GL_FLOAT;
            case hive::ShaderDataType::Int:      return GL_INT;
            case hive::ShaderDataType::Int2:     return GL_INT;
            case hive::ShaderDataType::Int3:     return GL_INT;
            case hive::ShaderDataType::Int4:     return GL_INT;
            case hive::ShaderDataType::Bool:     return GL_BOOL;
        }

        //TODO: log error: Unknown ShaderDataType
        return 0;
    }

    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &rendererID_);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &rendererID_);
    }

    void OpenGLVertexArray::bind() const
    {
        glBindVertexArray(rendererID_);
    }

    void OpenGLVertexArray::unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) {
        if (vertexBuffer->getLayout().getElements().size() == 0) {
            //TODO: log error: VertexBuffer has no layout
        }

        glBindVertexArray(rendererID_);
        vertexBuffer->bind();

        uint32_t index = 0;
        const auto& layout = vertexBuffer->getLayout();
        for (const auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index,
                                  element.getComponentCount(),
                                  ShaderDataTypeToOpenGLBaseType(element.Type),
                                  element.Normalized ? GL_TRUE : GL_FALSE,
                                  layout.getStride(),
                                  (const void*)element.Offset);
            index++;
        }

        vertexBuffers_.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(rendererID_);
        indexBuffer->bind();

        indexBuffer_ = indexBuffer;
    }
}