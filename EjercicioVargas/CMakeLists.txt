cmake_minimum_required(VERSION 4.0)
project(EjercicioVargas)

set(CMAKE_CXX_STANDARD 20)

add_executable(EjercicioVargas main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
