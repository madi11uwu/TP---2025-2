//
// Created by Madi on 23/11/2025.
//

#ifndef INC_2025_1_LAB10_FUNCIONES_HPP
#define INC_2025_1_LAB10_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_escritura(const char*,ofstream &);
void apertura_lectura(const char*,ifstream &);
char *leer_cadena(int,char,ifstream &);
char *asignar_cadena(const char*);
int leer_int(ifstream &read);
double leer_double(ifstream &read);
int devolverFecha(ifstream &);
void imprimirEncabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirFecha(int fecha,ofstream &);
void imprimirEspacios(int ancho,int size,ofstream &write);
#endif //INC_2025_1_LAB10_FUNCIONES_HPP