cmake_minimum_required(VERSION 3.28)

project(DungeonEscape)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(DungeonEscape src/main.cpp src/Entity.cpp src/Player.cpp src/Enemy.cpp src/Chaser.cpp src/Stalker.cpp src/utils.cpp src/Game.cpp src/item.cpp src/WaveManager.cpp src/Bullet.cpp)

target_include_directories(DungeonEscape PRIVATE include)

target_link_libraries(DungeonEscape sfml-graphics sfml-window sfml-system )

