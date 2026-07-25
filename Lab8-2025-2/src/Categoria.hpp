//
// Created by Madi on 1/12/2025.
//

#ifndef LAB8_2025_2_CATEGORIA_HPP
#define LAB8_2025_2_CATEGORIA_HPP
struct Categoria {
    char *codigo;
    char *nombre;
    char *descripcion;
    struct Reproduccion *reproducciones; //15
    int numReproducciones;
    double promedioRating;
    int duracionTotal;
};
#endif //LAB8_2025_2_CATEGORIA_HPP