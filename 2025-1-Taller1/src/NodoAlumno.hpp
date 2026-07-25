//
// Created by Madi on 1/12/2025.
//

#ifndef INC_2025_1_TALLER1_NODOALUMNO_HPP
#define INC_2025_1_TALLER1_NODOALUMNO_HPP
#include "Alumno.hpp"
struct NodoAlumno {
    struct Alumno dato;
    struct NodoAlumno *siguiente;
};
#endif //INC_2025_1_TALLER1_NODOALUMNO_HPP