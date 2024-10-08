//
// Created by lapor on 7/26/2024.
//

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H
#include <string>

#include "core/rendering/shader.h"


namespace hive
{
    class OpenglShader final : public Shader
    {
    public:
        OpenglShader(const std::string &vertex_path, const std::string &fragment_path);

        void bind() const override;

        void unbind() const override;

        void uploadUniformMat4(const std::string& name, const glm::mat4& matrix) const override;

        void uploadUniformInt(const std::string& name, int value) const override;

        void uploadUniformFloat(const std::string& name, float value) const override;

        void uploadUniformFloat4(const std::string& name, glm::vec4 value) const override;

    private:
        unsigned int program_id = 0;
    };

}



#endif //OPENGL_SHADER_H
