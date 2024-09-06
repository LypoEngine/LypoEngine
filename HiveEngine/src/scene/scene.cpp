#include "scene.h"
#include "entity.h"
#include <iostream>

namespace hive
{
    Scene::Scene() {}

    Scene::~Scene() {}

    Entity Scene::create_entity(const std::string& name)
    {
        Entity entity(registry_.create(), this);
        entity.add_component<TagComponent>(name);
        return entity;
    }

    void Scene::print_tag()
    {
    }

    void Scene::print_system()
    {
    }

    void Scene::update()
    {
        print_tag();
        print_system();
    }
}