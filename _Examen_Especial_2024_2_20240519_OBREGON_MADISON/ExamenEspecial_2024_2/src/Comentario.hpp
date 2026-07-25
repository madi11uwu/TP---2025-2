//
// Created by Madi on 30/11/2025.
//

#ifndef EXAMENESPECIAL_2024_2_COMENTARIO_HPP
#define EXAMENESPECIAL_2024_2_COMENTARIO_HPP
#include "Palabra.hpp"
struct Comentario {
    char *texto;
    char *pre_procesado;
    struct Palabra palabras[20]{};
    int cantidad_palabras;
    int polaridad_total;
};
#endif //EXAMENESPECIAL_2024_2_COMENTARIO_HPP