include_directories(${CMAKE_SOURCE_DIR}/Game/Ressources)

file(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)
file(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h)

add_executable(AimBoost ${ENGINE_SOURCES} ${ENGINE_HEADERS} Sources/game.cpp Headers/game.h Sources/map.cpp Headers/map.h Sources/player.cpp Headers/player.h Headers/main.h Sources/menu.cpp Headers/menu.h)

target_link_libraries(AimBoost sdl2)