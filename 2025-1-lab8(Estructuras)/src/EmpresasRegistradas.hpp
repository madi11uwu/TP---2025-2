//
// Created by Madi on 9/11/2025.
//

#ifndef INC_2025_1_LAB8_ESTRUCTURAS__EMPRESASREGISTRADAS_HPP
#define INC_2025_1_LAB8_ESTRUCTURAS__EMPRESASREGISTRADAS_HPP
#include "Fecha.hpp"
struct EmpresasRegistradas {
    int dni;
    char *nombre;
    char *distrito;
    char *placas[10];
    int numPlacas;
    struct Fecha fechaDeInfraccion;
    struct Fecha fechaDePago;
    double totalDeMultas;
    double totalPagado;
    double totalAdeudado;
    int cantidadDeFaltas;
};
#endif //INC_2025_1_LAB8_ESTRUCTURAS__EMPRESASREGISTRADAS_HPP