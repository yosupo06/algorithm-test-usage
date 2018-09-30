cmake_minimum_required(VERSION 3.10)

# -std=c++11
set(CMAKE_CXX_STANDARD 11)

# gtest / algorithm-testを使えるように
include(GoogleTest)
add_subdirectory(algorithm-test)

# ../srcをincludeできるように
include_directories(../src)

# ctestをenable
enable_testing()

# lca_test.cppをテスト対象に
add_executable(LCATest lca_test.cpp)
target_link_libraries(LCATest gtest gtest_main)
gtest_discover_tests(LCATest)
