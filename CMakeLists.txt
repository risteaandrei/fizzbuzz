cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
 
# Locate GTest
find_package(Boost 1.40.0 REQUIRED system)

file(GLOB_RECURSE SRCS *.cpp)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(main ${SRCS})
