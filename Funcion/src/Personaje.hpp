//
// Created by Madi on 27/11/2025.
//

#ifndef FUNCION_PERSONAJE_HPP
#define FUNCION_PERSONAJE_HPP
#include "Comentario.hpp"
struct Personaje {
    char *nombre;
    bool Estado;
    struct Comentario *comentario;
    char **palabrasMayuscula;
    char **palabrasMinuscula;
    int CantidadComentarios;
};
#endif //FUNCION_PERSONAJE_HPP