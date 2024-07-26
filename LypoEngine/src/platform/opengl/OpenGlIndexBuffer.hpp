#pragma once

#include "core/rendering/IndexBuffer.hpp"

namespace Lypo {
    class OpenGlIndexBuffer : public IndexBuffer {
    public:
        OpenGlIndexBuffer(uint32_t *indices, uint32_t count);

        ~OpenGlIndexBuffer();

        void Bind() const override;

        void Unbind() const override;

        virtual uint32_t GetCount() const { return _Count; }

    private:
        uint32_t _BufferID;
        uint32_t _Count;
    };
}