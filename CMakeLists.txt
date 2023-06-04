cmake_minimum_required(VERSION 3.24)
project(coursework)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(coursework Sources/main.cpp Headers/ListOfCoord.h Sources/ListOfCoord.cpp Headers/BotHard.h Headers/Array.h Sources/Array.cpp Headers/BotSoft.h Headers/ListOfShips.h Sources/ListOfShips.cpp Headers/MainMenu.h Sources/MainMenu.cpp Headers/DifLevels.h Sources/DifLevels.cpp Headers/InstructionManual.h Sources/InstructionManual.cpp Headers/PlayWindow.h Sources/PlayWindow.cpp Headers/PlacementField.h Sources/PlacementField.cpp Headers/WindowExit.h Sources/WindowExit.cpp Headers/Player.h Sources/Player.cpp Headers/WindowWin.h Sources/WindowWin.cpp Headers/WindowLose.h Sources/WindowLose.cpp Headers/ConnectType.h Sources/ConnectType.cpp Headers/InputCode.h Sources/InputCode.cpp Headers/GetCode.h Sources/GetCode.cpp Headers/Socket.h Sources/Socket.cpp Headers/Logs.h Sources/Logs.cpp Headers/NetwStatus.h Sources/NetwStatus.cpp Sources/BotHard.cpp Sources/BotSoft.cpp)
target_link_libraries(coursework sfml-graphics sfml-audio)