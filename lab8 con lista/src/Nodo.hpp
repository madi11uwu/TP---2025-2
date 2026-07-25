//
// Created by Madi on 23/11/2025.
//

#ifndef LAB8_CON_LISTA_NODO_HPP
#define LAB8_CON_LISTA_NODO_HPP
#include "Categoria.hpp"
struct Nodo {
    struct Categoria categoria;
    struct Nodo *siguiente;
};
#endif //LAB8_CON_LISTA_NODO_HPP