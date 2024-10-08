#include "lypch.h"
#include "components.h"
#include "scene.h"
#include "entity.h"
#include "core/uuid.h"

namespace hive {
    Entity Scene::createEntity(const std::string &name) {
        return createEntityWithID(UUID(), name);
    }

    Entity Scene::createEntityWithID(UUID id, const std::string &name) {
        Entity entity = {registry_.create(), this};
        entity.addComponent<IDComponent>(id);
        auto& tag = entity.addComponent<TagComponent>();
        tag.Tag = name.empty() ? "Default Entity" : name;
        entities_[id] = &entity;
        return entity;
    }

    void Scene::destroyEntity(Entity entity) {
        entities_.erase(entity.getComponent<IDComponent>().ID);
        registry_.destroy(entity);
    }

    entt::registry& Scene::getRegistry() {
        return registry_;
    }

    std::string Scene::toString() const {
        std::string str = "Scene {\n";
        for (auto curr : entities_) {
            str += curr.second->toString() + "\n";
        }
        str += "}";
        return str;
    }
}