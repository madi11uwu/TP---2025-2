cmake_minimum_required(VERSION 4.0)
project(ExamenEspecial_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ExamenEspecial_2024_2 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Palabra.hpp
        src/Comentario.hpp
        src/Plato.hpp
        src/Atencion.hpp
        src/NodoLexicon.hpp
        src/NodoPlato.hpp
        src/NodoAtencion.hpp)
