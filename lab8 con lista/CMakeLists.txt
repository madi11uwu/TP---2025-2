cmake_minimum_required(VERSION 4.0)
project(lab8_con_lista)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab8_con_lista main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Nodo.hpp
        src/Categoria.hpp
        src/Canal.hpp)
