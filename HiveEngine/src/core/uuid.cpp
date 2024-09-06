#include "uuid.h"

#include <random>
#include <unordered_map>

namespace hive
{
    static std::random_device random_device;
    static std::mt19937_64 engine(random_device());
    static std::uniform_int_distribution<uint64_t> uniform_distribution;

    Uuid::Uuid() : uuid_(uniform_distribution(engine)) {}

    Uuid::Uuid(const uint64_t& uuid) : uuid_(uuid) {}
}