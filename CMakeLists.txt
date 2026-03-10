cmake_minimum_required(VERSION 3.28)

project(DungeonEscape)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(DungeonEscape src/main.cpp)

target_link_libraries(DungeonEscape sfml-graphics sfml-window sfml-system )

