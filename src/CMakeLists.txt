include_directories(${CMAKE_SOURCE_DIR}/Game/Ressources/SDL2)

file(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)
file(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h)

add_executable(AimBoost ${ENGINE_SOURCES} ${ENGINE_HEADERS})
target_link_libraries(AimBoost SDL2)