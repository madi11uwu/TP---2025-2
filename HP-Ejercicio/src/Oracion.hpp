//
// Created by Madi on 30/11/2025.
//

#ifndef HP_EJERCICIO_ORACION_HPP
#define HP_EJERCICIO_ORACION_HPP
#include "Palabra.hpp"
struct Oracion {
    int temporada;
    char *oracion;
    struct Palabra palabra[30];
    int cantPalabras;
    int sentimiento;
};
#endif //HP_EJERCICIO_ORACION_HPP