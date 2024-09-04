#pragma once

#include <entt/entt.hpp>

#include "components.h"

namespace hive
{
    class Entity;

    class Scene
    {
    public:
        Scene();
        ~Scene();

        Entity create_entity(const std::string& tag);

        void update();

        friend class Entity;
    private:
        entt::registry registry_;
        void print_tag();
        void print_system();
    };
}