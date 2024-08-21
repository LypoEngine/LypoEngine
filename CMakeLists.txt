cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)

project(Hive)

include_directories(Hive/src)

#Dependencies include
add_subdirectory(Hive/dep/glfw)
include_directories(Hive/dep/glfw/include)

add_subdirectory(Hive/dep/glad)
include_directories(Hive/dep/glad/include)

add_subdirectory(Hive/dep/glm)
include_directories(Hive/dep/glm/glm)

add_subdirectory(Hive/dep/entt)
include_directories(Hive/dep/entt/single_include)

include_directories(Hive/dep/stb_image)
add_library(stb_image STATIC Hive/dep/stb_image/stb_image.cpp)

file(GLOB_RECURSE CORE_SOURCES Hive/src/core/*.cpp Hive/src/core/*.h)

add_compile_definitions(HIVE_PLATFORM_GLFW)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    file(GLOB_RECURSE PLATFORM_SOURCES Hive/src/platform/windows/*.cpp Hive/src/platform/windows/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES Hive/src/platform/opengl/*.cpp Hive/src/platform/opengl/*.h)
    file(GLOB_RECURSE INPUT_SOURCES Hive/src/platform/glfw/*.cpp Hive/src/platform/glfw/*.h)
    add_compile_definitions(LYPO_PLATFORM_WINDOWS)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    file(GLOB_RECURSE PLATFORM_SOURCES Hive/src/platform/linux/*.cpp Hive/src/platform/linux/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES Hive/src/platform/opengl/*.cpp Hive/src/platform/opengl/*.h)
    file(GLOB_RECURSE INPUT_SOURCES Hive/src/platform/glfw/*.cpp Hive/src/platform/glfw/*.h)
    add_compile_definitions(LYPO_PLATFORM_LINUX)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    file(GLOB_RECURSE PLATFORM_SOURCES Hive/src/platform/macos/*.cpp Hive/src/platform/macos/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES Hive/src/platform/opengl/*.cpp Hive/src/platform/opengl/*.h)
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif ()

add_executable(Hive ${CORE_SOURCES} ${PLATFORM_SOURCES} ${RENDERING_SOURCES} ${VENDOR_SOURCES} ${INPUT_SOURCES})

target_link_libraries(Hive glfw glad EnTT glm stb_image)