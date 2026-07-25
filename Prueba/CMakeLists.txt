cmake_minimum_required(VERSION 4.0)
project(Prueba)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba main.cpp
        Funciones.cpp
        Funciones.hpp
        cmake-build-debug/Persona.hpp)
