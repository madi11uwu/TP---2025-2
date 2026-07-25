cmake_minimum_required(VERSION 4.0)
project(streamers__textosMultiples_)

set(CMAKE_CXX_STANDARD 20)

add_executable(streamers__textosMultiples_ main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
