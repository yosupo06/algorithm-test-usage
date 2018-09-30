cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

include(GoogleTest)
add_subdirectory(algorithm-test)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../src)
include_directories(.)
enable_testing()

add_executable(LCATest lca_test.cpp)
target_link_libraries(LCATest gtest gtest_main)
gtest_discover_tests(LCATest)
