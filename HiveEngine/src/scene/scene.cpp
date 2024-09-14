#include "scene.h"
#include "entity.h"

namespace hive {
    Entity Scene::createEntity(const std::string &name) {
        Entity entity = {registry_.create(), this};
        auto& tag = entity.addComponent<TagComponent>();
        tag.Tag = name.empty() ? "Entity" : name;
        return entity;
    }

}