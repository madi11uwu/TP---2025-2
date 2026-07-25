//
// Created by Madi on 23/11/2025.
//

#ifndef LAB8_CON_LISTA_CATEGORIA_HPP
#define LAB8_CON_LISTA_CATEGORIA_HPP
#include "Canal.hpp"
struct Categoria {
    char *codigo;
    char *nombre;
    char *descripcion;
    struct Canal *canal;
    int cantidadCanales;
};
#endif //LAB8_CON_LISTA_CATEGORIA_HPP