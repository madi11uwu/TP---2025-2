//
// Created by Madi on 30/11/2025.
//

#ifndef PREGUNTA2_2024_2_COMENTARIO_HPP
#define PREGUNTA2_2024_2_COMENTARIO_HPP
#include "Palabra.hpp"
struct Comentario {
    char texto[100];
    char pre_procesado[100];
    struct Palabra palabras[20]{};
    int cantidad_palabras;
    int polaridad_total;
};
#endif //PREGUNTA2_2024_2_COMENTARIO_HPP