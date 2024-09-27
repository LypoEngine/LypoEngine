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
        FUNCTION_PROFILING(hive::colors::Red);
        Entity entity = {registry_.create(), this};
        entity.addComponent<IDComponent>(id);
        auto& tag = entity.addComponent<TagComponent>();
        tag.Tag = name.empty() ? "Default Entity" : name;
        entities_[id] = &entity;
        END_BLOCK_PROFILING;
        return entity;
    }

    void Scene::destroyEntity(Entity entity) {
        FUNCTION_PROFILING(hive::colors::Red);
        entities_.erase(entity.getComponent<IDComponent>().ID);
        registry_.destroy(entity);
        END_BLOCK_PROFILING;
    }

    entt::registry& Scene::getRegistry() {
        return registry_;
    }

    std::string Scene::toString() const {
        FUNCTION_PROFILING(hive::colors::Red);
        std::string str = "Scene {\n";
        for (auto curr : entities_) {
            str += curr.second->toString() + "\n";
        }
        str += "}";
        END_BLOCK_PROFILING;
        return str;
    }
}