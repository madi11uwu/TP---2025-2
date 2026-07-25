//
// Created by Madi on 24/11/2025.
//

#ifndef LAB10_23_2_NODO_HPP
#define LAB10_23_2_NODO_HPP
#include "Vendedor.hpp"
struct Nodo {
    struct Vendedor vendedor;
    struct Nodo *siguiente;
};
#endif //LAB10_23_2_NODO_HPP