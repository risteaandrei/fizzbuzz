cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED system thread)

file(GLOB_RECURSE SERVER_SRCS src/server/*.cpp)
add_executable(server ${SERVER_SRCS})
TARGET_LINK_LIBRARIES(server LINK_PUBLIC ${Boost_LIBRARIES} )

file(GLOB_RECURSE CLIENT_SRCS src/client/*.cpp)
add_executable(client ${CLIENT_SRCS})
TARGET_LINK_LIBRARIES(client LINK_PUBLIC ${Boost_LIBRARIES} )
