INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/Header)

file(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)
file(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h *.inl)

add_executable       (game ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_link_libraries(game glfw3 glew32)