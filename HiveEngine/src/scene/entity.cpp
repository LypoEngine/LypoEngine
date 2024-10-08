#include "lypch.h"
#include "entity.h"

namespace hive {

    bool Entity::operator==(const Entity &other) const {
        return handler_ == other.handler_ && scene_ == other.scene_;
    }

    bool Entity::operator!=(const Entity &other) const {
        return !(*this == other);
    }

    Entity::operator entt::entity() const {return handler_;}

    Entity::operator bool() const {return handler_ != entt::null;}

    Entity::operator unsigned() const {return static_cast<uint32_t>(handler_);}

    std::string Entity::toString() const {
        std::string temp = "";
        entt::registry& reg = scene_->getRegistry();
        for(auto&& curr : reg.storage()) {
            if (auto& storage = curr.second; storage.contains(handler_)) {
                temp += reinterpret_cast<IComponent*>(storage.value(handler_))->toString();
            }
        }
        return temp;
    }
}
