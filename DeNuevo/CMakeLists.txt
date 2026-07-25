cmake_minimum_required(VERSION 4.0)
project(DeNuevo)

set(CMAKE_CXX_STANDARD 20)

add_executable(DeNuevo main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
