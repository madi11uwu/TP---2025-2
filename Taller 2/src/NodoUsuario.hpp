//
// Created by Madi on 29/11/2025.
//

#ifndef TALLER_2_NODOUSUARIO_HPP
#define TALLER_2_NODOUSUARIO_HPP
#include "Usuario.hpp"
struct NodoUsuario {
    struct Usuario usuario;
    struct NodoUsuario *siguiente;
};
#endif //TALLER_2_NODOUSUARIO_HPP