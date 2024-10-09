add_executable(localSandbox main.cpp)
target_link_libraries(localSandbox HiveEngine)
target_include_directories(localSandbox PUBLIC ${CMAKE_SOURCE_DIR}/HiveEngine/src)