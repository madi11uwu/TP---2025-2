//
// Created by Madi on 13/10/2025.
//

#ifndef INC_25_1_P2_ARREGLOS_FUNCIONES_HPP
#define INC_25_1_P2_ARREGLOS_FUNCIONES_HPP
#include "Utils.hpp"
void cargarInfracciones(const char*,char *c_infraccion,
                        int *int_infraccion,double *,int &n_infraccion);
void probarInfracciones(const char*,char *c_infraccion,
                        int *int_infraccion,double *,int n_infraccion);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimirEncabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezadoSecundario(ofstream &write);
void ignorar(ifstream &,char);
#endif //INC_25_1_P2_ARREGLOS_FUNCIONES_HPP