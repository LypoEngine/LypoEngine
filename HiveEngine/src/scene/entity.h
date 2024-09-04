#pragma once

#include <entt/entt.hpp>
#include "scene.h"

namespace hive 
{
    class Entity
    {
    public:
        Entity(entt::entity handler, Scene* scene) : handler_(handler), scene_(scene) {}

        entt::entity get_handle() { return handler_;}

        template<typename T, typename... Args> 
        T& add_component(Args&&... args)
        {
            return scene_->registry_.emplace<T>(handler_, std::forward<Args>(args)...);
        }
        
        template<typename T>
        T& get_component()
        {
            return scene_->registry_.get<T>(handler_);
        }

        template<typename T>
        void remove_component()
        {
            return scene_->registry_.remove<T>(handler_);
        }

        template<typename T>
        bool has_component()
        {
            return scene_->registry_.all_of<T>(handler_);
        }

    private:
        entt::entity handler_ = entt::null;
        hive::Scene* scene_ = nullptr;
    };
}