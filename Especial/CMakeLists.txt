cmake_minimum_required(VERSION 4.0)
project(Especial)

set(CMAKE_CXX_STANDARD 20)

add_executable(Especial main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Nodo.hpp
        src/PilaTAD.hpp)
