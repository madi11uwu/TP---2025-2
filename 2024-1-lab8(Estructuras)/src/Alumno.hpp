//
// Created by Madi on 10/11/2025.
//

#ifndef INC_2024_1_LAB8_ESTRUCTURAS__ALUMNO_HPP
#define INC_2024_1_LAB8_ESTRUCTURAS__ALUMNO_HPP
#include "Facultad .hpp"
struct Alumno {
    int codigo;
    char *nombre;
    int numCursos;
    double sumaPonderada;
    double numCreditos;
    double promedioPonderado;
    struct Facultad facultad;
};
#endif //INC_2024_1_LAB8_ESTRUCTURAS__ALUMNO_HPP