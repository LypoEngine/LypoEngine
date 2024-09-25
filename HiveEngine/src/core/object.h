//
// Created by guill on 2024-09-21.
//

#ifndef OBJECT_H
#define OBJECT_H
#include <string>

namespace hive {
    class Object {
    public:
        virtual ~Object() = default;
        [[nodiscard]] virtual std::string toString() const = 0;
    };
}

#endif //OBJECT_H
