//
// Created by Madi on 30/11/2025.
//

#ifndef PREGUNTA2_2024_2_ATENCION_HPP
#define PREGUNTA2_2024_2_ATENCION_HPP
#include "Comentario.hpp"
struct Atencion {
    int codigo;
    double total_venta;
    int hora;
    struct Comentario comentarios[20];
    int cantidad_comentarios;
};
#endif //PREGUNTA2_2024_2_ATENCION_HPP