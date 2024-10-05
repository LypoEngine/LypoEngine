set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(dep/googletest EXCLUDE_FROM_ALL)

enable_testing()
# Specify the test executable
file(GLOB_RECURSE TEST_SOURCES HiveEngine/*.cpp)
add_executable(maintest MainTest.cpp ${TEST_SOURCES})
target_include_directories(maintest PUBLIC ${CMAKE_SOURCE_DIR}/HiveEngine/src)
target_link_libraries(maintest gtest gtest_main HiveEngine)
add_test(NAME maintest COMMAND maintest)
