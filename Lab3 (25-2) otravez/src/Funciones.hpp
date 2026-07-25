//
// Created by Madi on 29/09/2025.
//

#ifndef LAB3__25_2__OTRAVEZ_FUNCIONES_HPP
#define LAB3__25_2__OTRAVEZ_FUNCIONES_HPP
#include "Utils.hpp"
void cargarCanales(const char*,int *fechaCreacion,char *c_canal,int *int_canal,double *rating_canal,int &n_canales);
void probarCanales(const char*,int *fechaCreacion,char *c_canal,int *int_canal,double *rating_canal,int n_canales);
void apertura_escritura(const char*,ofstream &);
void apertura_lectura(const char*,ifstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezadoPrincipal(ofstream &,double);
int AlmacenarFecha(ifstream &leer);
void ignorar (ifstream &leer,char c);
void imprimir_fecha(ofstream &write,int fecha);
void cargarEtiquetas(const char*,int *etiquetas,int *duracion,int &n_etiquetas);
void probarEtiquetas(const char*,int *etiquetas,int *duracion,int n_etiquetas);
int AlmacenarDuracion(ifstream &leer);
void imprimir_duracion(ofstream &write,int duracion,char c);
int buscar_canal(char codigo_c_canal,int codigo_int_canal,char *c_canal,int *int_canal,int n_canales);
int buscar_etiqueta(int *etiquetas,int etiquetaLeida,int n_etiquetas);
void imprimir_encabezadoCanales(ofstream &write,int canal);
void imprimir_reporte(const char *reporte,int *etiquetas, int *duracionTotalEtiqueta, int n_etiquetas,
                    char *c_canal, int *int_canal,int *duracion,int n_canales,double *rating_canal,
                    int *reproTotalPorEtiqueta,int *reproTotalCanal,int *fechaCreacion,double tarifa,double *ingresosDuracionEtiquetas);
void imprimir_encabezadoEtiquetas(ofstream &write);
void ArmarArreglos(const char*repro,int *etiquetas, int *duracionTotalEtiqueta, int n_etiquetas,
                   char *c_canal, int *int_canal,int *duracion,int n_canales,
                   int *reproTotalPorEtiqueta,int *reproTotalCanal,double tarifa,
                   double *ingresosDuracionEtiquetas);
#endif //LAB3__25_2__OTRAVEZ_FUNCIONES_HPP