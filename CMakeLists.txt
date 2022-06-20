cmake_minimum_required(VERSION 3.20)
project(identifiers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

set(INCLUDE_DIR
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/exceptions")

include_directories(${INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(lib/googletest)

set(GTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest/googletest/include")
include_directories(${GTEST_INCLUDE_DIR})

add_subdirectory(test)
