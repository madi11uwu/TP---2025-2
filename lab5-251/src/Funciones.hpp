//
// Created by Madi on 29/09/2025.
//

#ifndef LAB5_251_FUNCIONES_HPP
#define LAB5_251_FUNCIONES_HPP
#include "Utils.hpp"
void cargarInfracciones(const char*,char *c_infraccion,int *int_infraccion,double *multas,int &n_infracciones);
void probarInfracciones(const char*,char *c_infraccion,int *int_infraccion,double *multas,int n_infracciones);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void ignorar(ifstream &leer,char c);
void cargarEmpresas(const char*,int *DNIRepre,int &n_empresas);
void probarEmpresas(const char*,int *DNIRepre,int n_empresas);
#endif //LAB5_251_FUNCIONES_HPP