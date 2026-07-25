cmake_minimum_required(VERSION 4.0)
project(2025_1_Taller1)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_1_Taller1 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Curso.hpp
        src/Escala.hpp
        src/Alumno.hpp
        src/NodoCurso.hpp
        src/NodoEscala.hpp
        src/NodoAlumno.hpp)
