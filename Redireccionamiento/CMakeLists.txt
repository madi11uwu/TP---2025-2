cmake_minimum_required(VERSION 4.0)
project(Redireccionamiento)

set(CMAKE_CXX_STANDARD 20)

add_executable(Redireccionamiento main.cpp
        src/Utils.hpp
        src/AuxiliaryFunciones.cpp
        src/AuxiliaryFunciones.hpp)
