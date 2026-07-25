cmake_minimum_required(VERSION 4.0)
project(Spotify)

set(CMAKE_CXX_STANDARD 20)

add_executable(Spotify main.cpp
        src/Funciones.cpp
        src/Funciones.hpp
        src/Utils.hpp)
