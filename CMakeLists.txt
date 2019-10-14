cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE SRCS p*.cpp)
file(GLOB_RECURSE TEST_SRCS test_*.cpp) 

SET (TEST_SRCS ${SRCS} ${TEST_SRCS} gtest/all_tests.cpp)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ${TEST_SRCS})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
