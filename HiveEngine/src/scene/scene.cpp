#include "components.h"
#include "scene.h"
#include "entity.h"
#include "core/uuid.h"

#include <iostream>

namespace hive
{
    Entity Scene::createEntity(const std::string &tag) {
        return createEntityWithUUID(UUID(), tag);
    }

    Entity Scene::createEntityWithUUID(const UUID &uuid, const std::string &tag) {
        Entity entity = { registry_.create(), this};
        entity.addComponent<IDComponent>(uuid);
        auto& tagComponent = entity.addComponent<TagComponent>();
        tagComponent.Tag = tag.empty() ? "Entity" : tag;
        //entities_map_[uuid] = entity;
        return entity;
    }

    void Scene::destroyEntity(Entity entity) {
        //entities_map_.erase(entity.getUUID());
        registry_.destroy(entity);
    }

    Entity Scene::findEntityByTag(const std::string &tag) {
        auto entities_view = registry_.view<TagComponent>();

        for (auto entity : entities_view)
        {
            const TagComponent& tc = entities_view.get<TagComponent>(entity);
            if (tc.Tag == tag) {
                return Entity{entity, this};
            }
        }
        return {};
    }
}