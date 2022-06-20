cmake_minimum_required(VERSION 2.20)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET identifiers)

file(GLOB SOURCE_FILES *.cpp)

add_library(${TARGET} ${SOURCE_FILES})
