cmake_minimum_required(VERSION 4.0)
project(ClaseArreglos)

set(CMAKE_CXX_STANDARD 20)

add_executable(ClaseArreglos main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
