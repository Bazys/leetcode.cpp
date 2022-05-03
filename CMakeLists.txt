message(STATUS ${CPLUS_INCLUDE_PATH})
cmake_policy(SET CMP0048 NEW)
project(leetcode VERSION 1.0.0)
# CMake version >= 3.10 due to gtest_discover_tests()
# See https://cmake.org/cmake/help/git-stage/module/GoogleTest.html
cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(include)

add_subdirectory(src)
