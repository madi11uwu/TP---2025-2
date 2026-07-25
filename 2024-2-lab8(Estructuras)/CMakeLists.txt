cmake_minimum_required(VERSION 4.0)
project(2024_2_lab8_Estructuras_)

set(CMAKE_CXX_STANDARD 20)

add_executable(2024_2_lab8_Estructuras_ main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp
        src/Distrito.hpp
        src/Plato.hpp
        src/PlatoPedido.hpp
        src/Cliente.hpp)
