cmake_minimum_required(VERSION 3.10)
PROJECT(Game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Ressources/Bin)

link_directories(${CMAKE_SOURCE_DIR}/Ressources/Lib)
include_directories(${CMAKE_SOURCE_DIR}/Ressources)

add_subdirectory(src)