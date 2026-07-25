//
// Created by Madi on 21/09/2025.
//

#ifndef INC_241_MULTIPLES__FUNCIONES_HPP
#define INC_241_MULTIPLES__FUNCIONES_HPP
#include "Utils.hpp"
void ProcesarDatos(const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_nombre (ifstream &,ofstream &);
int almacenarDuracion(ifstream &);
void imprimir_duracion(ofstream &write,int duracion);
#endif //INC_241_MULTIPLES__FUNCIONES_HPP