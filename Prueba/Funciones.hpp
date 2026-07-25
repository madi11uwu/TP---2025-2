//
// Created by Madi on 17/11/2025.
//

#ifndef PRUEBA_FUNCIONES_HPP
#define PRUEBA_FUNCIONES_HPP
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void apertura_lectura(const char *,ifstream &);
void cargarPersona(const char * str, struct Persona persona, int n_personas);
char *read_str(int n,char c,ifstream &read);
#endif //PRUEBA_FUNCIONES_HPP