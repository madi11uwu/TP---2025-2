//
// Created by Madi on 5/10/2025.
//

#ifndef LAB5_25_1__LO_DOY_TODO__FUNCIONES_HPP
#define LAB5_25_1__LO_DOY_TODO__FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_EncabezadoPrincipal(ofstream &);
void imprimir_encabezadoMultas(ofstream &);
void imprimir_encabezadoCompanias(ofstream &);
void ignorar(ifstream &,char );
void cargar_Empresas(const char*,int *DNI,int &n_empresas);
void probar_empresas(const char*,int *DNI,int n_empresas);
void cargar_TablaInfracciones(const char*,char *c_infraccion,int *int_infraccion,double *multas,
                            int &n_tablaInfracciones);
void probar_TablaInfracciones(const char*,char *c_infraccion,int *int_infraccion,double *multas,
                            int n_tablaInfracciones);

#endif //LAB5_25_1__LO_DOY_TODO__FUNCIONES_HPP