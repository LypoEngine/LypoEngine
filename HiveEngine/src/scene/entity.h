//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <entt/entt.hpp>
#include <functional>
#include <algorithm>
#include "core/object.h"
#include "components.h"
#include "scene.h"

namespace hive
{
    class Entity : public Object {
    public:
        Entity() = default;
        Entity(entt::entity entity, Scene* scene) : handler_(entity), scene_(scene) {}
        Entity(const Entity& other) = default;

        ~Entity() override = default;
        
        template<typename T, typename... Args>
        T& addComponent(Args&&...args) {
            assert(!hasComponent<T>());
            return scene_->registry_.emplace<T>(handler_, std::forward<Args>(args)...);
        }

        template<typename T, typename... Args>
        T& replaceComponent(Args&&...args) {
            return scene_->registry_.emplace_or_replace<T>(handler_, std::forward<Args>(args)...);
        }

        template<typename T>
        void removeComponent() {
            assert(hasComponent<T>());
            scene_->registry_.remove<T>(handler_);
        }

        template<typename T>
        T& getComponent() {
            assert(hasComponent<T>());
            return scene_->registry_.get<T>(handler_);
        }

        template<typename T>
        bool hasComponent() const {
            return scene_->registry_.all_of<T>(handler_);
        }

        bool operator==(const Entity& other) const;

        bool operator!=(const Entity& other) const;

        operator entt::entity() const;
        operator bool() const;
        operator uint32_t() const;

        [[nodiscard]] std::string toString() const override;

    private:
        entt::entity handler_ = {entt::null};
        Scene* scene_ = nullptr;
    };
}