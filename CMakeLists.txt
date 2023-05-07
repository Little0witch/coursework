cmake_minimum_required(VERSION 3.24)
project(coursework)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(coursework coursework.cpp Headers/ListOfCoord.h Sources/ListOfCoord.cpp Headers/BotHard.h Headers/Array.h Sources/Array.cpp Headers/Game.h Sources/Game.cpp Headers/BotSoft.h Headers/ListOfShips.h Sources/ListOfShips.cpp Headers/main_menu.h Sources/main_menu.cpp Headers/dif_levels.h Sources/dif_levels.cpp Headers/instruction_manual.h Sources/instruction_manual.cpp Headers/play_window.h Sources/play_window.cpp Headers/placement_field.h Sources/placement_field.cpp Headers/window_exit.h Sources/window_exit.cpp Headers/Player.h Sources/Player.cpp)
target_link_libraries(coursework sfml-graphics sfml-audio)