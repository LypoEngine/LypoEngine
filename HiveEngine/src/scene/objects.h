#pragma once

#include "scene.h"
#include "entity.h"

namespace hive
{
        void create_object(Scene& scene, const double& x, const double& y, const std::string& tag);
        void create_object(Scene& scene, const double& x, const double& y, const std::string& type, const std::string& tag);
}