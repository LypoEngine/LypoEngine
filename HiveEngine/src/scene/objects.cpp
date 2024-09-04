#include "objects.h"

namespace hive
{
    void create_object(Scene& scene, const double& x, const double& y, const std::string& tag)
    {
        Entity entity = scene.create_entity(tag);
        entity.add_component<PositionComponent>(x, y);
    }
    
    void create_object(Scene& scene, const double& x, const double& y, const std::string& type, const std::string& tag)
    {
        Entity entity = scene.create_entity(tag);
        entity.add_component<PositionComponent>(x, y);
        entity.add_component<TypeComponent>(type);
    }
}