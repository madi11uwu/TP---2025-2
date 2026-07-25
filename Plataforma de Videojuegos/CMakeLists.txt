cmake_minimum_required(VERSION 4.0)
project(Plataforma_de_Videojuegos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Plataforma_de_Videojuegos main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
