//
// Created by GuillaumeIsCoding on 9/6/2024
//
#pragma once
#include <string>

namespace hive
{
    class UUID
    {
    public:
        UUID();
        UUID(uint64_t uuid);
        UUID(const UUID&) = default;

        operator uint64_t() const { return uuid_; }
        operator std::string() const {return std::to_string(uuid_);}
    private:
        uint64_t uuid_;
    };
}

namespace std
{
    template<typename T> struct hash;
    
    template<>
    struct hash<hive::UUID>
    {
        std::size_t operator()(const hive::UUID& uuid) const
        {
            return (uint64_t)uuid;
        }
    };
}