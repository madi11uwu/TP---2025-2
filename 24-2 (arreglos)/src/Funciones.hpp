//
// Created by Madi on 28/09/2025.
//

#ifndef INC_24_2__ARREGLOS__FUNCIONES_HPP
#define INC_24_2__ARREGLOS__FUNCIONES_HPP
#include "Utils.hpp"
void cargarPlatosOfrecidos(const char*,int *codigo_platos,double *precio_platos,int &n_platos);
void probarPlatosOfrecidos(const char*,int *codigo_platos,double *precio_platos,int n_platos);
void apertura_escritura(const char*,ofstream &);
void apertura_lectura(const char*,ifstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void ignorar(ifstream &leer,char c);
void cargarRepartidores(const char*,int *DNI_repartidores,int *codigo_distrito,int &n_repartidores);
void probarRepartidores(const char*,int *DNI_repartidores,int *codigo_distrito,int n_repartidores);
int buscar(int *arreglo,int n,int busqueda);
#endif //INC_24_2__ARREGLOS__FUNCIONES_HPP