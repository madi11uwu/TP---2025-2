//
// Created by Madi on 3/11/2025.
//

#ifndef LAB6_24_2_FUNCIONES_HPP
#define LAB6_24_2_FUNCIONES_HPP
#include "Utils.hpp"
void imprimir_linea(int,char,ofstream&);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &);
void cargar_ordenado_repartos(const char * str, int * arr, int * arr_num_platos_vendidos, int &n_platos);
int BuscarBinaria(int *arreglo,int n,int buscar);
void insertar_ordenado(int * arr_codigo_platos, int * arr_num_platos_vendidos, int &n_platos, int codigo_plato, int cantidad);
void probar_repartos(const char * str, int * arr, int * arr_num_platos_vendidos, int n_platos);
void llenarArreglos(const char * str, double * arr, double * arr_ingreso_bruto, double * arr_descuento,
    bool * arr_tiene_descuento, double * arr_total,char **,char **,
    int *,int *,int);
char *lectura_cadena_exacta(ifstream &leer) ;
char *ModificarCadena(char *cadena1,char *cadena2,bool descuento);
void imprimir_reporte(const char * str, double * arr, double * arr_ingreso_bruto, double * arr_descuento, bool * arr_tiene_descuento, double * arr_total,
                     char ** descripcion, char ** categoria, int * arr_codigo_platos, int * arr_num_platos_vendidos, int n_platos);
#endif //LAB6_24_2_FUNCIONES_HPP