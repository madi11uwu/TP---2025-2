//
// Created by Madi on 1/12/2025.
//

#ifndef TALLER_2_DE_NUEVO_NODOUSUARIO_HPP
#define TALLER_2_DE_NUEVO_NODOUSUARIO_HPP
#include "Usuario.hpp"
struct NodoUsuario {
    struct Usuario usuario;
    struct NodoUsuario *siguiente;
};
#endif //TALLER_2_DE_NUEVO_NODOUSUARIO_HPP