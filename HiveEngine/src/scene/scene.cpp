#include "scene.h"
#include "entity.h"
#include <iostream>

namespace hive
{
    Scene::Scene() {}

    Scene::~Scene() {}

    Entity Scene::create_entity(const std::string& tag)
    {
        Entity entity(registry_.create(), this);
        entity.add_component<TagComponent>(tag);
        return entity;
    }

    void Scene::print_tag()
    {

        for ( 
            auto [entity, nameTag] :
            registry_.view<TagComponent>().each())
            {
                std::cout << "tag : " << nameTag.tag << std::endl;
            }
    }

    void Scene::print_system()
    {
        for (
            auto [entity, pos, type] :
            registry_.view<PositionComponent, TypeComponent>().each()
        )
        {
            std::cout << "Position (x, y) : (" << pos.x << ", " << pos.y << ") & Type : " << type.type << std::endl;
        }
    }

    void Scene::update()
    {
        print_tag();
        print_system();
    }
}