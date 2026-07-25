//
// Created by Madi on 30/11/2025.
//

#ifndef HP_EJERCICIO_NODOPERSONAJE_HPP
#define HP_EJERCICIO_NODOPERSONAJE_HPP
#include "Personaje.hpp"
struct NodoPersonaje {
    struct Personaje dato;
    struct NodoPersonaje *siguiente;
};
#endif //HP_EJERCICIO_NODOPERSONAJE_HPP