//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once

#include <entt/entt.hpp>
#include "core/object.h"
#include "components.h"
#include <unordered_map>
#include <entt/entt.hpp>
#include "core/object.h"
#include <unordered_map>

namespace hive
{
    class Entity;
    class UUID;

    class Scene : public Object {
    public:
        Scene() = default;
        ~Scene() override = default;

        Entity createEntity(const std::string& name = std::string());
        Entity createEntityWithID(UUID id, const std::string& name = std::string());
        void destroyEntity(Entity entity);

        entt::registry& getRegistry();

        std::string toString() const override;
    private:
        friend class Entity;
        std::unordered_map<UUID, Entity*> entities_;
        entt::registry registry_;
    };
}