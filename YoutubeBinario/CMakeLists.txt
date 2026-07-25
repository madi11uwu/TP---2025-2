cmake_minimum_required(VERSION 4.0)
project(YoutubeBinario)

set(CMAKE_CXX_STANDARD 20)

add_executable(YoutubeBinario main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
