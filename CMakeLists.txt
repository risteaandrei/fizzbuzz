cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED system)

file(GLOB_RECURSE SRCS src/*.cpp)

add_executable(main ${SRCS})
TARGET_LINK_LIBRARIES(main LINK_PUBLIC ${Boost_LIBRARIES} )
