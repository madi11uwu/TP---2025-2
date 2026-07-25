//
// Created by Madi on 1/12/2025.
//

#ifndef INC_2025_1_TALLER1_NODOCURSO_HPP
#define INC_2025_1_TALLER1_NODOCURSO_HPP
#include "Curso.hpp"
struct NodoCurso {
    struct Curso dato;
    struct NodoCurso *siguiente;
};
#endif //INC_2025_1_TALLER1_NODOCURSO_HPP