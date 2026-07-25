cmake_minimum_required(VERSION 4.0)
project(242)

set(CMAKE_CXX_STANDARD 20)

add_executable(242 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
