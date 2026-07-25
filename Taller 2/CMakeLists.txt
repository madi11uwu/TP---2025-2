cmake_minimum_required(VERSION 4.0)
project(Taller_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_2 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/LibroEnSuPoder.hpp
        src/Usuario.hpp
        src/NodoUsuario.hpp
        src/NodoUsuarioMoroso.hpp)
