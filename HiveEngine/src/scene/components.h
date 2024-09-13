//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once

#include <string>
#include "core/uuid.h"

namespace hive
{
    struct IDComponent
    {
        UUID ID;

        IDComponent() = default;
        IDComponent(const IDComponent&) = default;
    };

    struct TagComponent
    {
        std::string Tag;

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        explicit TagComponent(const std::string& tag) : Tag(tag) {}
    };

    struct ScriptComponent
    {
        std::string ClassName;

        ScriptComponent() = default;
        ScriptComponent(const ScriptComponent&) = default;
    };
    
}