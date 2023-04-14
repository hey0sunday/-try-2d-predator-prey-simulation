cmake_minimum_required(VERSION 3.24)
project(2dword)

set(CMAKE_CXX_STANDARD 11)

add_executable(test main.cpp World.cpp Ant.cpp Doodlebug.cpp Organism.cpp Config.h)
