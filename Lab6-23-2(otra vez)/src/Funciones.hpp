//
// Created by Madi on 3/11/2025.
//

#ifndef LAB6_23_2_OTRA_VEZ__FUNCIONES_HPP
#define LAB6_23_2_OTRA_VEZ__FUNCIONES_HPP
#include "Utils.hpp"
void ignorar(ifstream &,char);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(int,ofstream &);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void insertar_ordenado(int , double multas, int * codigo_infraccion, double * multa, int &n_infraciones);
void cargar_ordenado(const char * str, int * arr, double * multa, int &n_infraciones);
void prueba_infracciones(const char * str, int * arr, double * multa, int n_infraciones);


#endif //LAB6_23_2_OTRA_VEZ__FUNCIONES_HPP