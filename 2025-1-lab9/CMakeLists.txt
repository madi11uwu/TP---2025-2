cmake_minimum_required(VERSION 4.0)
project(2025_1_lab9)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_1_lab9 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Fecha.hpp
        src/TablaDeInfracciones.hpp
        src/InfraccionCometida.hpp
        src/EmpresasRegistradas.hpp)
