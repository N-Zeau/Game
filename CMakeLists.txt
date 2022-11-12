cmake_minimum_required(VERSION 3.17)
PROJECT(Game)

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Game src/main.cpp)
target_link_libraries(Game ${SDL2_LIBRARIES})