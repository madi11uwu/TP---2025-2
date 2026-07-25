//
// Created by Madi on 9/11/2025.
//

#ifndef INC_2024_2_LAB8_ESTRUCTURAS__CLIENTE_HPP
#define INC_2024_2_LAB8_ESTRUCTURAS__CLIENTE_HPP
#include "Distrito.hpp"
#include "PlatoPedido.hpp"

struct Cliente {
    int dni;
    char *nombre;
    struct Distrito distrito;
    struct PlatoPedido plato_estatico[MAX_PLATOSPEDIDOS];
    int cantidadDePedidos;
    double montoTotal;
    int cantPlatos;
};
#endif //INC_2024_2_LAB8_ESTRUCTURAS__CLIENTE_HPP