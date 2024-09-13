//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once

#include <entt/entt.hpp>

namespace hive
{
    class Scene;
    class UUID;

    class Entity
    {
    public:
        Entity() = default;
        Entity(const Entity&) = default;
        Entity(entt::entity entity_handler, Scene* scene) : entity_handler_(entity_handler), scene_(scene) {}

        template<typename T, typename ...Args>
        T& addComponent(Args&&... args);

        template<typename T, typename ...Args>
        T& replaceComponent(Args&& ...args);

        template<typename T>
        T& getComponent();

        template<typename T>
        [[nodiscard]] bool hasComponent() const;

        [[nodiscard]] UUID getUUID();

        [[nodiscard]] const std::string& getTag();

        operator bool() const;
        operator entt::entity();
        operator uint32_t() const;

        bool operator ==(const Entity& other);
        bool operator !=(const Entity& other);
    private:
        entt::entity entity_handler_ = {entt::null};
        Scene* scene_ = nullptr;
    };
}