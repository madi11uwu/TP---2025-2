//
// Created by Madi on 27/11/2025.
//

#ifndef FUNCION_NODO_HPP
#define FUNCION_NODO_HPP
#include "Personaje.hpp"
struct Nodo {
    struct Personaje personaje;
    struct Nodo *siguiente;
};
#endif //FUNCION_NODO_HPP