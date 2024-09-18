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

    struct IDComponent : IComponent
    {
        UUID ID;

        IDComponent() = default;
        IDComponent(const IDComponent&) = default;
        IDComponent(const UUID& uuid) : ID(uuid) {};

        ~IDComponent() override = default;

        std::ostream& print(std::ostream& os) override {
            return os << "UUID : " << ID << " ";
        }
    };

    struct TagComponent : IComponent
    {
        std::string Tag = "";

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag) : Tag(tag) {}

        ~TagComponent() override = default;

        std::ostream& print(std::ostream& os) override {
            return os << "Tag : " << Tag << " ";
        }
    };
}