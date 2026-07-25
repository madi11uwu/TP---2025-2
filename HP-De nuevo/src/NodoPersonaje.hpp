//
// Created by Madi on 1/12/2025.
//

#ifndef HP_DE_NUEVO_NODOPERSONAJE_HPP
#define HP_DE_NUEVO_NODOPERSONAJE_HPP
#include "Personaje.hpp"
struct NodoPersonaje {
    struct Personaje dato;
    struct NodoPersonaje *siguiente;
};
#endif //HP_DE_NUEVO_NODOPERSONAJE_HPP