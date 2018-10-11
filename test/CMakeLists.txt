cmake_minimum_required(VERSION 3.10)

# -std=c++11
set(CMAKE_CXX_STANDARD 11)

# gtest_discover_testsを使えるように
include(GoogleTest)

# algorithm-testを使えるように
add_subdirectory(algorithm-test)
include_directories(algorithm-test)

# ../srcをincludeできるように
include_directories(../src)

# ctestをenable
enable_testing()

# lca_test.cppをテスト対象に
add_executable(LCATest lca_test.cpp)
target_link_libraries(LCATest gtest gtest_main)
gtest_discover_tests(LCATest)
