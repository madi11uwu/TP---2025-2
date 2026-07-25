//
// Created by Madi on 30/11/2025.
//

#ifndef TALLER_2025_1_NODOALUMNO_HPP
#define TALLER_2025_1_NODOALUMNO_HPP
#include "Alumno.hpp"
struct NodoAlumno {
    struct Alumno dato;
    struct NodoAlumno *siguiente;
};
#endif //TALLER_2025_1_NODOALUMNO_HPP