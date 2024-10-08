// Description: Precompiled header file for LypoEngine

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <core/logging/Logger.h>
#include <core/Profiling/profiler.h>
#include <core/Profiling/profiler_colors.h>

template<typename T>
using URef = std::unique_ptr<T>;

template<typename T>
using SRef = std::shared_ptr<T>;
