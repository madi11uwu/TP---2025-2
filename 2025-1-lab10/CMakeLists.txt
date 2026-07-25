cmake_minimum_required(VERSION 4.0)
project(2025_1_lab10)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_1_lab10 main.cpp
        src/BibliotecasListas/Lista.cpp
        src/BibliotecasListas/Lista.hpp
        src/BibliotecasListas/Nodo.hpp
        src/BibliotecasFunciones/Funciones.cpp
        src/BibliotecasFunciones/Funciones.hpp
        src/BibliotecasFunciones/Utils.hpp
        src/BibliotecasListas/Cuenta.hpp)
