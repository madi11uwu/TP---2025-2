cmake_minimum_required(VERSION 4.0)
project(lab10_20251)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab10_20251 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Cuenta.hpp
        src/Nodo.hpp)
