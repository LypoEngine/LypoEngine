// Description: Precompiled header file for LypoEngine

#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "core/console_log.h"

template<typename T>
using URef = std::unique_ptr<T>;

template<typename T>
using SRef = std::shared_ptr<T>;
