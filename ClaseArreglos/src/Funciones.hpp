//
// Created by Madi on 25/09/2025.
//

#ifndef CLASEARREGLOS_FUNCIONES_HPP
#define CLASEARREGLOS_FUNCIONES_HPP
#include "Utils.hpp"
void printArray(int *arr,int size);
void leer_codigos(int *codigos, int &n, const char *file);
void apertura_lectura(ifstream &,const char*);
int linearSearch(int *codigos,int n,int codigo);
#endif //CLASEARREGLOS_FUNCIONES_HPP