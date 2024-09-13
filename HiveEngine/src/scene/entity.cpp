#include "core/uuid.h"
#include "scene.h"
#include "components.h"

#include "entity.h"

namespace hive {
    template<typename T, typename... Args>
    T& Entity::addComponent(Args &&... args) {
        T& component = scene_->registry_.emplace<T>(entity_handler_, std::forward<Args>(args)...);
        return component;
    }

    template<typename T, typename... Args>
    T& Entity::replaceComponent(Args &&... args) {
        T& component = scene_->registry_.emplace_or_replace<T>(entity_handler_, std::forward<Args>(args)...);
        return component;
    }

    template<typename T>
    T& Entity::getComponent() {
        return scene_->registry_.get<T>(entity_handler_);
    }

    template<typename T>
    bool Entity::hasComponent() const {
        return scene_->registry_.all_of<T>(entity_handler_);
    }

    UUID Entity::getUUID() {
        return getComponent<IDComponent>().ID;
    }

    const std::string& Entity::getTag() {
        return getComponent<TagComponent>().Tag;
    }

    Entity::operator bool() const {
        return (entity_handler_ != entt::null);
    }

    Entity::operator entt::entity() {
        return entity_handler_;
    }

    Entity::operator uint32_t() const {
        return static_cast<uint32_t>(entity_handler_);
    }

    bool Entity::operator==(const Entity &other) {
        return (entity_handler_ == other.entity_handler_) && (scene_ == other.scene_);
    }

    bool Entity::operator!=(const Entity &other) {
        return !(*this == other);
    }
}
