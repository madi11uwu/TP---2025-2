//
// Created by Madi on 16/11/2025.
//

#ifndef INC_2025_1_LAB9_EMPRESASREGISTRADAS_HPP
#define INC_2025_1_LAB9_EMPRESASREGISTRADAS_HPP
#include "InfraccionCometida.hpp"
struct EmpresasRegistradas {
    int dni;
    char *nombre;
    char *distrito;
    char *placas[10];
    int numPlacas;
    struct InfraccionCometida *infraccion;
    int cantidadDeInfracciones;
    double totalPagado;
    double totalAdeudado;
};
#endif //INC_2025_1_LAB9_EMPRESASREGISTRADAS_HPP