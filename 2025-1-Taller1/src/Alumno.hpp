//
// Created by Madi on 1/12/2025.
//

#ifndef INC_2025_1_TALLER1_ALUMNO_HPP
#define INC_2025_1_TALLER1_ALUMNO_HPP
#include "Escala.hpp"
#include "Curso.hpp"
struct Alumno {
    int codAlumno;
    char *nombre;
    struct Escala escAlumno;
    struct Curso *cursos; //Maximo 8 cursos
    int cantidadCursos;
    double totalCreditos;
    double totalPago;
};
#endif //INC_2025_1_TALLER1_ALUMNO_HPP