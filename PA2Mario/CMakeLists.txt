cmake_minimum_required(VERSION 3.24)
project(PA2Mario)

set(CMAKE_CXX_STANDARD 17)

add_executable(PA2Mario main.cpp Levels.cpp Levels.h Mario.cpp Mario.h)
