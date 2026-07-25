cmake_minimum_required(VERSION 4.0)
project(otro_intento)

set(CMAKE_CXX_STANDARD 20)

add_executable(otro_intento main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
