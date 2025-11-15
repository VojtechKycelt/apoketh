cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main

   "src/main.cpp"
   "src/game/game.h"
   "src/game/game.cpp"
   "src/game/ship/ship.h"
   "src/game/ship/ship.cpp"
   "src/game/weapon/weapon.h"
   "src/game/weapon/weapon.cpp"
   "src/game/weapon/pistol.h"
   "src/game/weapon/pistol.cpp"
   "src/game/weapon/bullet.h"
   "src/game/weapon/bullet.cpp"
   "src/util/util.cpp"
   "src/util/logger/logger.h"
   "src/input/input_manager.h"
   "src/input/input_manager.cpp"
   "src/game/enemy/enemy.h"
   "src/game/enemy/enemy.cpp"
   "src/game/enemy/enemy_square.h"
   "src/game/enemy/enemy_square.cpp"
   "src/game/level/level_manager.h"
   "src/game/enemy/enemy_manager.h"
   "src/game/enemy/enemy_manager.cpp"

 "src/util/globals.h" "src/util/util.h")
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)

