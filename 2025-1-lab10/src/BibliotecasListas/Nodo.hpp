//
// Created by Madi on 23/11/2025.
//

#ifndef INC_2025_1_LAB10_NODO_HPP
#define INC_2025_1_LAB10_NODO_HPP
#include "Cuenta.hpp"
struct Nodo {
    struct Cuenta cuenta;
    struct Nodo *siguiente;
};
#endif //INC_2025_1_LAB10_NODO_HPP