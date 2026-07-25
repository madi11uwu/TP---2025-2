//
// Created by Madi on 2/11/2025.
//

#ifndef LABORATORIO6_24_2_FUNCIONES_HPP
#define LABORATORIO6_24_2_FUNCIONES_HPP
#include "Utils.hpp"
void cargar_ordenado_repartos(const char * str, int * arr, int * arr_num_platos_vendidos, int &n_platos);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void insertar_ordenado(int *,int,int);

#endif //LABORATORIO6_24_2_FUNCIONES_HPP