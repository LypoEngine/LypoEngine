//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <entt/entt.hpp>
#include <functional>
#include <algorithm>
#include "components.h"
#include "scene.h"

namespace hive
{
    class Entity {
    public:
        Entity() = default;
        Entity(entt::entity entity, Scene* scene) : handler_(entity), scene_(scene) {}

        template<typename T, typename... Args>
        T& addComponent(Args&&...args) {
            return scene_->registry_.emplace<T>(handler_, std::forward<Args>(args)...);
        }

        template<typename T>
        T& getComponent() {
            return scene_->registry_.get<T>(handler_);
        }

    private:
        entt::entity handler_ = {entt::null};
        Scene* scene_ = nullptr;
    };
}