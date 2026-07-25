//
// Created by Madi on 30/11/2025.
//

#ifndef HP_EJERCICIO_FUNCIONES_HPP
#define HP_EJERCICIO_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
char *leer_cadena(int,char,ifstream &);
void cargarPersonajes(const char *,struct NodoPersonaje *&lista);
int leer_int(ifstream &);
#endif //HP_EJERCICIO_FUNCIONES_HPP