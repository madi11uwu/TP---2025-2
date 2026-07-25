cmake_minimum_required(VERSION 4.0)
project(Estructuras)

set(CMAKE_CXX_STANDARD 20)

add_executable(Estructuras main.cpp
        src/VideoJuego.hpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Empresa.hpp)
