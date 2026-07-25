//
// Created by Madi on 1/12/2025.
//

#ifndef HP_DE_NUEVO_FUNCIONES_HPP
#define HP_DE_NUEVO_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
char *leer_cadena(int,char,ifstream &);
int leer_int(ifstream &);
void cargarPersonaje(const char *,struct NodoPersonaje *&lista);
#endif //HP_DE_NUEVO_FUNCIONES_HPP