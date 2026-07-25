//
// Created by Madi on 30/11/2025.
//

#ifndef HP_EJERCICIO_PERSONAJE_HPP
#define HP_EJERCICIO_PERSONAJE_HPP
#include "Oracion.hpp"
struct Personaje {
    char *nombre;
    struct Oracion *oraciones;
    int cantidadOraciones;
};
#endif //HP_EJERCICIO_PERSONAJE_HPP