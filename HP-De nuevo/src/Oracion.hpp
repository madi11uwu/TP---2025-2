//
// Created by Madi on 1/12/2025.
//

#ifndef HP_DE_NUEVO_ORACION_HPP
#define HP_DE_NUEVO_ORACION_HPP
#include "Palabra.hpp"
struct Oracion {
    int sentimiento;
    char *oracion;
    int pelicula;
    struct Palabra *palabras;
};
#endif //HP_DE_NUEVO_ORACION_HPP