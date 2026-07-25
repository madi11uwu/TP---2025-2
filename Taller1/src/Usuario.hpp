//
// Created by Madi on 28/11/2025.
//

#ifndef TALLER1_USUARIO_HPP
#define TALLER1_USUARIO_HPP
#include "LibroEnSuPoder.hpp"
struct Usuario {
    int dni;
    char *nombre;
    char categoria;
    double calificacion;
    struct LibroEnSuPoder *libros;
    int cantLibros;
};
#endif //TALLER1_USUARIO_HPP