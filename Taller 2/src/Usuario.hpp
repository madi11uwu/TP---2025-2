//
// Created by Madi on 29/11/2025.
//

#ifndef TALLER_2_USUARIO_HPP
#define TALLER_2_USUARIO_HPP
#include "LibroEnSuPoder.hpp"
struct Usuario {
    int dni;
    char *nombre;
    char categoria;
    double calificacion;
    struct LibroEnSuPoder *libros;
    int cantLibros;
    bool moroso;
};
#endif //TALLER_2_USUARIO_HPP