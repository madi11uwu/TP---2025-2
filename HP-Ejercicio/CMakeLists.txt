cmake_minimum_required(VERSION 4.0)
project(HP_Ejercicio)

set(CMAKE_CXX_STANDARD 20)

add_executable(HP_Ejercicio main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Palabra.hpp
        src/Oracion.hpp
        src/Personaje.hpp
        src/NodoPersonaje.hpp)
