cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(textfeature)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_definitions("-Wall -g")


# find protobuf
INCLUDE_DIRECTORIES(
    ../3rdparty/include
)

TARGET_LINK_LIBRARIES(
    ../3rdparty/lib/libprotobuf.so.17
)
