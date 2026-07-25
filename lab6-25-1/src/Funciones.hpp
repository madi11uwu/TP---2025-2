//
// Created by Madi on 27/10/2025.
//

#ifndef LAB6_25_1_FUNCIONES_HPP
#define LAB6_25_1_FUNCIONES_HPP
#include "Utils.hpp"
void cargar_ordenado_infraccion(const char * str, int * arr, double * arr_multas_infraccion, int &n_tabla_infraccion);
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void ignorar(ifstream &,char );
void insertar_ordenado(int * arr_codigo_infraccion, double * arr_multas_infraccion, int &n_tabla_infraccion, int codigo, double multa);
void probar_ordenado_infraccion(const char *Infraccion, int *arrCodigoInfraccion,
                                double *arr_multas_infraccion, int n_tabla_infraccion);
void llenarArreglos(const char *infracciones, int *arrDNI, int *arrMasMultaAntigua,
                    double *arrMultasInfraccion,int *arrUltimaPendiente, double *arrTotalMultas,
                    double *arrTotalPagadas,int *,
                    double *arrTotalPendientes,int n_tablaInfraccion);
int BusquedaBinaria(int *arrDNI,int DNI,int n_tablaInfraccion);
int AlmacenarFecha(ifstream &);
#endif //LAB6_25_1_FUNCIONES_HPP