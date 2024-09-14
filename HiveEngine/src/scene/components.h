//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <ostream>
#include <string>
#include "core/uuid.h"

namespace hive
{
    struct IComponent {
        virtual ~IComponent() = default;
        virtual std::ostream& print(std::ostream& os) = 0;
    };

    struct IDComponent : public IComponent
    {
        UUID ID;

        IDComponent() = default;
        IDComponent(const IDComponent&) = default;
        IDComponent(const UUID& uuid) : ID(uuid) {};

        ~IDComponent() = default;

        std::ostream& print(std::ostream& os) override {
            return os << "UUID : " << ID << " ";
        }

    };

    struct TagComponent : public IComponent
    {
        std::string Tag = "";

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag) : Tag(tag) {}

        ~TagComponent() = default;

        std::ostream& print(std::ostream& os) override {
            return os << "Tag : " << Tag << " ";
        }
    };

    struct ScriptComponent
    {
        std::string ClassName;

        ScriptComponent() = default;
        ScriptComponent(const ScriptComponent&) = default;
    };
    
}