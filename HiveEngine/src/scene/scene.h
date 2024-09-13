//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <entt/entt.hpp>
#include "lypch.h"

#include <unordered_map>

namespace hive
{
    class Entity;
    class UUID;

    class Scene
    {
    public:
        Scene() = default;
        ~Scene() {};

        Entity createEntity(const std::string& tag = std::string());
        Entity createEntityWithUUID(const UUID& uuid, const std::string& tag = std::string());

        void destroyEntity(Entity entity);

        Entity findEntityByTag(const std::string& tag);
        //Entity findEntityByUUID(const UUID& uuid);
        
        template<typename ...T>
        auto getEntitiesWith()
        {
            return registry_.view<T...>();
        }

    private:
        entt::registry registry_;
        //std::unordered_map<UUID, Entity> entities_map_;
        friend class Entity;
    };
}