cmake_minimum_required(VERSION 4.0)
project(2024_1_lab9)

set(CMAKE_CXX_STANDARD 20)

add_executable(2024_1_lab9 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Cliente.hpp
        src/Fecha.hpp
        src/Venta.hpp
        src/Libro.hpp)
