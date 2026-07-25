//
// Created by Madi on 30/11/2025.
//

#ifndef EXAMENESPECIAL_2024_2_NODOATENCION_HPP
#define EXAMENESPECIAL_2024_2_NODOATENCION_HPP
#include "Atencion.hpp"
struct NodoAtencion {
    struct Atencion dato;
    struct NodoAtencion *siguiente;
};
#endif //EXAMENESPECIAL_2024_2_NODOATENCION_HPP