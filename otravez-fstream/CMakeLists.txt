cmake_minimum_required(VERSION 4.0)
project(otravez_fstream)

set(CMAKE_CXX_STANDARD 20)

add_executable(otravez_fstream main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
