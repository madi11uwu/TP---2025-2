//
// Created by Madi on 28/11/2025.
//

#ifndef TALLER1_LIBRO_HPP
#define TALLER1_LIBRO_HPP
#include "UsuarioConElLibro.hpp"
struct Libro {
    char *codigo;
    char *titulo;
    char *autor;
    int cantidad;
    double precio;
    struct UsuarioConElLibro *usuario;
    int cantUsuarios;
};
#endif //TALLER1_LIBRO_HPP