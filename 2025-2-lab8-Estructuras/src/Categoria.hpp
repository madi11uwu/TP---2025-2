//
// Created by Madi on 17/11/2025.
//

#ifndef INC_2025_2_LAB8_ESTRUCTURAS_CATEGORIA_HPP
#define INC_2025_2_LAB8_ESTRUCTURAS_CATEGORIA_HPP
#include "Reproduccion.hpp"
struct Categoria {
    char *codigo;
    char *nombre;
    struct Reproduccion *reproducciones;
    int numReproducciones;
    double promedioRating;
    int duracionTotal;
};
#endif //INC_2025_2_LAB8_ESTRUCTURAS_CATEGORIA_HPP