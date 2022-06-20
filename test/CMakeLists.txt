cmake_minimum_required(VERSION 3.20)
set(TARGET identifiers_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES *.cpp)

add_executable(${TARGET} ${SOURCE_FILES})
target_link_libraries(${TARGET} PUBLIC identifiers gtest_main)

add_test(NAME ${TARGET} COMMAND ${TARGET})
