//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <ostream>
#include <entt/entt.hpp>
#include "components.h"
#include "unordered_map"

namespace hive
{
    class Entity;
    class UUID;

    class Scene {
    public:
        Scene() = default;
        ~Scene() = default;

        Entity createEntity(const std::string& name = std::string());
        Entity createEntityWithID(UUID id, const std::string& name = std::string());
        void destroyEntity(Entity entity);

        entt::registry& getRegistry();
    private:
        friend class Entity;
        entt::registry registry_;
    };
}