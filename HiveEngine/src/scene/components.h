//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <string>
#include "core/uuid.h"

namespace hive
{
    struct IComponent {
        virtual ~IComponent() = default;
        virtual std::string toString() = 0;
    };

    struct IDComponent : IComponent
    {
        UUID ID;

        IDComponent() = default;
        IDComponent(const IDComponent&) = default;
        IDComponent(const UUID& uuid) : ID(uuid) {};

        ~IDComponent() override = default;

        std::string toString() override {
            return "UUID : " + std::string(ID) + " ";
        }
    };

    struct TagComponent : IComponent
    {
        std::string Tag = "";

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag) : Tag(tag) {}

        ~TagComponent() override = default;

        std::string toString() override {
            return "Tag : " + Tag + " ";
        }
    };
}