//
// Created by Madi on 16/11/2025.
//

#ifndef INC_2025_1_LAB9_INFRACCIONCOMETIDA_HPP
#define INC_2025_1_LAB9_INFRACCIONCOMETIDA_HPP
#include "Fecha.hpp"
struct InfraccionCometida {
    struct Fecha fechaDeInfraccion;
    char *placa;
    char *codigoDeLaInfraccion;
    double multa;
    char *descripcion;
    bool multaPagada;
    struct Fecha fechaDePago;
};
#endif //INC_2025_1_LAB9_INFRACCIONCOMETIDA_HPP