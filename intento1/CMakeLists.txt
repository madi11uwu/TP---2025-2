cmake_minimum_required(VERSION 4.0)
project(intento1)

set(CMAKE_CXX_STANDARD 20)

add_executable(intento1 main.cpp
        src/Utils.hpp
        src/Functions.cpp
        src/Functions.hpp)
