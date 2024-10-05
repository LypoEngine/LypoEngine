set(CMAKE_CXX_STANDARD 20)

set(PCH_HEADER src/lypch.h)

set(PCH_SOURCE src/lypch.cpp ${PCH_HEADER})

include_directories(src)

#Dependencies
add_subdirectory(dep/glfw)
include_directories(dep/glfw/include)

add_subdirectory(dep/glad)
include_directories(dep/glad/include)

add_subdirectory(dep/glm)
include_directories(dep/glm/glm)

add_subdirectory(dep/entt)
include_directories(dep/entt/single_include)

include_directories(dep/stb_image)
add_library(stb_image STATIC dep/stb_image/stb_image.cpp)

add_compile_definitions(HIVE_PLATFORM_GLFW)

file(GLOB_RECURSE SCENE_SOURCES src/scene/*.cpp src/scene/*.h)
file(GLOB_RECURSE CORE_SOURCES src/core/*.cpp src/core/*.h)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    file(GLOB_RECURSE PLATFORM_SOURCES src/platform/windows/*.cpp src/platform/windows/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES src/platform/opengl/*.cpp src/platform/opengl/*.h)
    file(GLOB_RECURSE WINDOW_BACKEND src/platform/glfw/*.cpp src/platform/glfw/*.h)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_compile_definitions(HIVE_PLATFORM_LINUX)
    file(GLOB_RECURSE PLATFORM_SOURCES src/platform/linux/*.cpp src/platform/linux/*.h)
    file(GLOB_RECURSE RENDERING_SOURCES src/platform/opengl/*.cpp src/platform/opengl/*.h)
    file(GLOB_RECURSE WINDOW_BACKEND src/platform/glfw/*.cpp src/platform/glfw/*.h)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif ()

add_library(HiveEngine ${CORE_SOURCES} ${PLATFORM_SOURCES} ${RENDERING_SOURCES} ${VENDOR_SOURCES} ${WINDOW_BACKEND} ${SCENE_SOURCES})
target_link_libraries(HiveEngine glfw glad EnTT glm stb_image)
target_precompile_headers(HiveEngine PRIVATE ${PCH_HEADER})
