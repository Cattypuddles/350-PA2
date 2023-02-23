cmake_minimum_required(VERSION 3.24)
project(PA2)

set(CMAKE_CXX_STANDARD 17)

add_executable(PA2 main.cpp CreateWorld.cpp CreateWorld.h CreateLevel.cpp CreateLevel.h CreateMario.cpp CreateMario.h Enemies.cpp Enemies.h Boss.cpp Boss.h)
