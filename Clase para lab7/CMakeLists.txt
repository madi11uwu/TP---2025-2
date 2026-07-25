cmake_minimum_required(VERSION 4.0)
project(Clase_para_lab7)

set(CMAKE_CXX_STANDARD 20)

add_executable(Clase_para_lab7 main.cpp
        src/funciones.cpp
        src/funciones.hpp
        src/utils.hpp
        srcLista/Nodo.hpp
        srcLista/Lista.cpp
        srcLista/Lista.hpp
        srcLista/ListaTAD.hpp
)
