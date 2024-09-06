//
// Created by GuillaumeIsCoding on 9/6/2024
//
#pragma once

#include <stdlib.h>
#include <stdint.h>

// From TheCherno

namespace hive
{
    class Uuid
    {
    public:
        Uuid();
        Uuid(const uint64_t& uuid);
        Uuid(const Uuid&) = default;

        operator uint64_t() const { return uuid_; }
    private:
        uint64_t uuid_;
    };
}

namespace std
{
    template<typename T> struct hash;
    
    template<>
    struct hash<hive::Uuid>
    {
        size_t operator()(const hive::Uuid& uuid) const
        {
            return (uint64_t)uuid;
        }
    };
    
}