// Description: Precompiled header file for LypoEngine

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <core/logging/Logger.h>

template<typename T>
using URef = std::unique_ptr<T>;

template<typename T>
using SRef = std::shared_ptr<T>;

