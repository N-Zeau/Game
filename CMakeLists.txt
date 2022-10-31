cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 14)
set(SDL2_INCLUDE_DIR D:/libs/SDL/include)
set(SDL2_LIB_DIR D:/libs/SDL/lib/x86)

include_directories(src)
include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})


add_executable(Game src/main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
