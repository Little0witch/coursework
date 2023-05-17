cmake_minimum_required(VERSION 3.24)
project(coursework)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(coursework Sources/main.cpp Headers/ListOfCoord.h Sources/ListOfCoord.cpp Headers/BotHard.h Headers/Array.h Sources/Array.cpp Headers/BotSoft.h Headers/ListOfShips.h Sources/ListOfShips.cpp Headers/main_menu.h Sources/main_menu.cpp Headers/dif_levels.h Sources/dif_levels.cpp Headers/instruction_manual.h Sources/instruction_manual.cpp Headers/play_window.h Sources/play_window.cpp Headers/placement_field.h Sources/placement_field.cpp Headers/window_exit.h Sources/window_exit.cpp Headers/Player.h Sources/Player.cpp Headers/window_win.h Sources/window_win.cpp Headers/window_lose.h Sources/window_lose.cpp Headers/connect_type.h Sources/connect_type.cpp Headers/input_code.h Sources/input_code.cpp Headers/get_code.h Sources/get_code.cpp Headers/socket.h Sources/socket.cpp Headers/logs.h Sources/logs.cpp Headers/netw_status.h Sources/netw_status.cpp)
target_link_libraries(coursework sfml-graphics sfml-audio)