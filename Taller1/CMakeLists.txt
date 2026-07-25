cmake_minimum_required(VERSION 4.0)
project(Taller1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller1 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/UsuarioConElLibro.hpp
        src/LibroEnSuPoder.hpp
        src/Libro.hpp
        src/UsuarioConElLibro.hpp)
