
add_executable(Sandbox main.cpp)
target_include_directories(Sandbox PUBLIC ${CMAKE_SOURCE_DIR}/HiveEngine/src)
target_link_libraries(Sandbox HiveEngine)