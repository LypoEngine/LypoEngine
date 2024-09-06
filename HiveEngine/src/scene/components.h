//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once

#include <string>

#include "core/uuid.h"
#include "core/rendering/Texture.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include<glm/gtx/quaternion.hpp>

namespace hive
{
    struct IDComponent
    {
        Uuid ID;

        IDComponent() = default;
        IDComponent(const IDComponent&) = default;
    };

    struct TagComponent
    {
        std::string Tag;

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag) : Tag(tag) {}
    };

    struct ScriptComponent
    {
        std::string ClassName;

        ScriptComponent() = default;
        ScriptComponent(const ScriptComponent&) = default;
    };
    
}