cmake_minimum_required(VERSION 3.10)
project(Snake)

set(CMAKE_CXX_STANDARD 11)

add_executable(Snake main.cpp Snake.h Snake.cpp World.h Window.h World.cpp Window.cpp Game.h Game.cpp Textbox.h Textbox.cpp)