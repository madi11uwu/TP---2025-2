cmake_minimum_required(VERSION 4.0)
project(Funcion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Funcion main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Personaje.hpp
        src/Comentario.hpp
        src/Nodo.hpp)
