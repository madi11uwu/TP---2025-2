cmake_minimum_required(VERSION 4.0)
project(taller_2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(taller_2025_1 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Curso.hpp
        src/Escala.hpp
        src/Alumno.hpp
        src/NodoCurso.hpp
        src/NodoEscala.hpp
        src/NodoAlumno.hpp)
