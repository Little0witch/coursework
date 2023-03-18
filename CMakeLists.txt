cmake_minimum_required(VERSION 3.24)
project(coursework)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(coursework main.cpp Sources/List.cpp Headers/List.h)
target_link_libraries(coursework sfml-graphics sfml-audio)