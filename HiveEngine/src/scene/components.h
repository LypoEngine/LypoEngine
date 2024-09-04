#pragma once

#include <string>

namespace hive
{
    struct TagComponent
    {
        std::string tag;
    };

    struct PositionComponent
    {
        double x, y;
    };

    struct TypeComponent
    {
        std::string type;
    };
    
}