//
// Created by Madi on 1/12/2025.
//

#ifndef HP_DE_NUEVO_PALABRA_HPP
#define HP_DE_NUEVO_PALABRA_HPP
#include "Lexicon.hpp"
struct Palabra {
    int numCaracteres;
    char *mayusculas;
    char *minusculas;
    struct Lexicon palabra;
};
#endif //HP_DE_NUEVO_PALABRA_HPP