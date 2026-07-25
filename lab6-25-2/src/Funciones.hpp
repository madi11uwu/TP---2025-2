//
// Created by Madi on 9/11/2025.
//

#ifndef LAB6_25_2_FUNCIONES_HPP
#define LAB6_25_2_FUNCIONES_HPP
#include "Utils.hpp"
void cargar_reproducciones(const char * str, int * arr, char ** arr_nombre_canal, char ** arr_codigo_categoria, double * arr_rating, double * arr_tasa,
                          int * arr_duracion, int &n_reproducciones);
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(char,int,ofstream &);
int almacenarFecha(ifstream &);
int almacenarDuracion(ifstream &);
void imprimir_fecha(int,ofstream &);
void imprimir_duracion(int,ofstream &);
char *leer_cadena_exacta(ifstream &);
void probar_reproducciones(const char * str, int * arr, char ** arr_nombre_canal, char ** arr_codigo_categoria, double * arr_rating, double * arr_tasa,
                          int * arr_duracion, int n_reproducciones);
void cargar_categorias(const char * str, char ** arr, char ** arrnombre_categoria, int &n_categoria);
void probar_categorias(const char * str, char ** arr, char ** arrnombre_categoria, int n_categoria);
void generaArchivoEnlace(char *categoria,char *&nombArch,char *&enlace);
void imprimir_reportes(char **arrCodCategoria, char **arrnombreCategoria,
                       int *arr_fecha_repro,char **arrCodigoCategoria,
                       char **arr_nombre_canal, double *arr_rating,
                       double *arr_tasa, int *arr_duracion, int n_categoria,
                       int n_reproducciones);
void imprimir_encabezado(ofstream &write);
void imprimir_estadisticas(int sumaDuracion, int totalCategoria,
                           double sumaRating, double sumaTasa,
                           ofstream &write);
void imprimir_reporte(char *nombArch,char *categoria, int *arr_fecha_repro,
                      char **arr_nombre_canal, char *nombreCategoria,
                      char *enlace, double *arr_rating,
                      double *arr_tasa, int *arr_duracion,
                      int n_reproducciones,char **arrCodigoCategoria);
#endif //LAB6_25_2_FUNCIONES_HPP