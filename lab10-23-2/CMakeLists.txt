cmake_minimum_required(VERSION 4.0)
project(lab10_23_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab10_23_2 main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Vendedor.hpp
        src/Nodo.hpp
)
