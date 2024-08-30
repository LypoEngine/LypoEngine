cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

project(hive_engine)

# PCH
set(PCH_HEADER
    HiveEngine/src/lypch.h)

set(PCH_SOURCE
    HiveEngine/src/lypch.cpp
    ${PCH_HEADER}
    )

include_directories(HiveEngine/src)

# Dependencies include
add_subdirectory(HiveEngine/dep/glfw)
include_directories(HiveEngine/dep/glfw/include)

add_subdirectory(HiveEngine/dep/glad)
include_directories(HiveEngine/dep/glad/include)

add_subdirectory(HiveEngine/dep/glm)
include_directories(HiveEngine/dep/glm/glm)

add_subdirectory(HiveEngine/dep/entt)
include_directories(HiveEngine/dep/entt/single_include)

include_directories(HiveEngine/dep/stb_image)
add_library(stb_image STATIC HiveEngine/dep/stb_image/stb_image.cpp)

file(GLOB_RECURSE CORE_SOURCES HiveEngine/src/core/*.cpp HiveEngine/src/core/*.h)



add_compile_definitions(HIVE_PLATFORM_GLFW)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    file(GLOB_RECURSE PLATFORM_SOURCES HiveEngine/src/platform/windows/*.cpp HiveEngine/src/platform/windows/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES HiveEngine/src/platform/opengl/*.cpp HiveEngine/src/platform/opengl/*.h)
    file(GLOB_RECURSE INPUT_SOURCES HiveEngine/src/platform/glfw/*.cpp HiveEngine/src/platform/glfw/*.h)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    file(GLOB_RECURSE PLATFORM_SOURCES HiveEngine/src/platform/linux/*.cpp HiveEngine/src/platform/linux/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES HiveEngine/src/platform/opengl/*.cpp HiveEngine/src/platform/opengl/*.h)
    file(GLOB_RECURSE INPUT_SOURCES HiveEngine/src/platform/glfw/*.cpp HiveEngine/src/platform/glfw/*.h)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    file(GLOB_RECURSE PLATFORM_SOURCES HiveEngine/src/platform/macos/*.cpp HiveEngine/src/platform/macos/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES HiveEngine/src/platform/opengl/*.cpp HiveEngine/src/platform/opengl/*.h)
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif ()

add_executable(hive_engine ${CORE_SOURCES} ${PLATFORM_SOURCES} ${RENDERING_SOURCES} ${VENDOR_SOURCES} ${INPUT_SOURCES} ${PCH_SOURCE})

target_link_libraries(hive_engine glfw glad EnTT glm stb_image)

target_precompile_headers(hive_engine PRIVATE ${PCH_HEADER})