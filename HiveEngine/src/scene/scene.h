//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <entt/entt.hpp>
#include "components.h"

namespace hive
{
    class Entity;

    class Scene {
    public:
        Scene() = default;
        ~Scene() = default;

        Entity createEntity(const std::string& name = std::string());
    private:
        friend class Entity;
        entt::registry registry_;
    };
}