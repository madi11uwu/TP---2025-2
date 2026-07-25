cmake_minimum_required(VERSION 4.0)
project(intento2)

set(CMAKE_CXX_STANDARD 20)

add_executable(intento2 main.cpp
        cmake-build-debug/src/Functions.cpp
        cmake-build-debug/src/Functions.hpp
        cmake-build-debug/src/Utils.hpp
        src/Functions.cpp
        src/Functions.hpp
        src/Utils.hpp)
