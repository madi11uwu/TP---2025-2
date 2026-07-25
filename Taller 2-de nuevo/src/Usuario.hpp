//
// Created by Madi on 1/12/2025.
//

#ifndef TALLER_2_DE_NUEVO_USUARIO_HPP
#define TALLER_2_DE_NUEVO_USUARIO_HPP
#include "LibroEnSuPoder.hpp"
struct Usuario {
    int dni;
    char *nombre;
    char categoria;
    double calificacion;
    struct LibroEnSuPoder *libros; //Máximo 6
    int cantLibros;
    bool moroso;
};
#endif //TALLER_2_DE_NUEVO_USUARIO_HPP