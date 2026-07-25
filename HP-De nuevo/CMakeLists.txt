cmake_minimum_required(VERSION 4.0)
project(HP_De_nuevo)

set(CMAKE_CXX_STANDARD 20)

add_executable(HP_De_nuevo main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Palabra.hpp
        src/Oracion.hpp
        src/Personaje.hpp
        src/NodoPersonaje.hpp
        src/NodoLexicon.hpp
        src/Lexicon.hpp)
