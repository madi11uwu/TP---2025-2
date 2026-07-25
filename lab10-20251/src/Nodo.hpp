//
// Created by Madi on 24/11/2025.
//

#ifndef LAB10_20251_NODO_HPP
#define LAB10_20251_NODO_HPP
#include "Cuenta.hpp"
struct Nodo {
    struct Cuenta cuenta;
    struct Nodo*siguiente;
};
#endif //LAB10_20251_NODO_HPP