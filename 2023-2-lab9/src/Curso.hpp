//
// Created by Madi on 17/11/2025.
//

#ifndef INC_2023_2_LAB9_CURSO_HPP
#define INC_2023_2_LAB9_CURSO_HPP
#include "Alumno.hpp"
struct Curso {
    int codigoCurso;
    char *nombreCurso;
    double numCreditos;
    struct Alumno *alumnos;
    int cantidadAlumnos;
    double totalIngresos;
};
#endif //INC_2023_2_LAB9_CURSO_HPP