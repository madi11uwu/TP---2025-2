//
// Created by Madi on 30/11/2025.
//

#ifndef TALLER_2025_1_ALUMNOS_HPP
#define TALLER_2025_1_ALUMNOS_HPP
#include "Escala.hpp"
#include "Curso.hpp"
struct Alumno {
    int codAlumno;
    char *nombre;
    struct Escala escAlumno;
    struct Curso *cursos; //8 cursos
    int cantidadCursos;
    double totalCreditos;
    double totalPago;
};
#endif //TALLER_2025_1_ALUMNOS_HPP