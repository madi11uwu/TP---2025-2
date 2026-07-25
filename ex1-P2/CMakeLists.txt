cmake_minimum_required(VERSION 4.0)
project(ex1_P2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ex1_P2 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
