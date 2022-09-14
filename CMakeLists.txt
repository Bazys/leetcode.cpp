message(STATUS ${CPLUS_INCLUDE_PATH})
cmake_policy(SET CMP0048 NEW)
project(leetcode VERSION 1.0.0)
cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(include)

add_subdirectory(src)
