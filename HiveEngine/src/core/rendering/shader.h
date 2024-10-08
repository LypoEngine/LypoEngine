//
// Created by lapor on 7/26/2024.
//

#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>

namespace hive
{
    enum ShaderType
    {
        Vertex, Fragment
    };

    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void bind() const = 0;

        virtual void unbind() const = 0;

        virtual void uploadUniformMat4(const std::string& name, const glm::mat4& matrix) const = 0;

        virtual void uploadUniformInt(const std::string& name, int value) const = 0;

        virtual void uploadUniformFloat(const std::string& name, float value) const = 0;

        virtual void uploadUniformFloat4(const std::string& name, glm::vec4 value) const = 0;


    };
}

#endif //SHADER_H
