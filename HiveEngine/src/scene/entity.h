//
// Created by GuillaumeIsCoding on 9/4/2024
//
#pragma once
#include <entt/entt.hpp>
#include <functional>
#include <algorithm>
#include <ostream>
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

        template<typename T, typename... Args>
        T& replaceComponent(Args&&...args) {
            return scene_->registry_.emplace_or_replace<T>(handler_, std::forward<Args>(args)...);
        }

        template<typename T>
        void removeComponent() {
            if(hasComponent<T>()) {
                scene_->registry_.remove<T>(handler_);
            }
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

        UUID getID() {return getComponent<IDComponent>().ID;}
        const std::string& getTag() {return getComponent<TagComponent>().Tag;}

        bool operator==(const Entity& other) {
            return handler_ == other.handler_ && scene_ == other.scene_;
        }

        bool operator!=(const Entity& other) {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& os, const Entity& entity) {
            entt::registry& reg = entity.scene_->registry_;

            for(auto&& curr : reg.storage()) {
               if (auto& storage = curr.second; storage.contains(entity.handler_)) {
                   reinterpret_cast<IComponent*>(storage.value(entity.handler_))->print(os);
               }
            }
            return os;
        }
    private:
        entt::entity handler_ = {entt::null};
        Scene* scene_ = nullptr;
    };
}