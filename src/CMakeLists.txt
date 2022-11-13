include_directories(${CMAKE_SOURCE_DIR}/Game/Ressources)

file(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)
file(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h)

add_executable(AimBoost ${ENGINE_SOURCES} ${ENGINE_HEADERS} game.cpp game.h)

target_link_libraries(AimBoost sdl2)