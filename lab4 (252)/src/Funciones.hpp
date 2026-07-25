//
// Created by Madi on 1/10/2025.
//

#ifndef LAB4__252__FUNCIONES_HPP
#define LAB4__252__FUNCIONES_HPP
#include "Utils.hpp"
void cargarCanales(const char*,int *fechaCreacion,char *cCanal,int *int_canal,double *rating,int &n_canal);
void probarCanales(const char*,int *fechaCreacion,char *cCanal,int *int_canal,double *rating,int n_canal);
void apertura_escritura(const char*,ofstream &);
void apertura_lectura(const char*,ifstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezado(ofstream &,double);
int AlmacenarFecha(ifstream &leer);
void imprimir_fecha(ofstream &write,int fecha);
void ignorar(ifstream &leer,char c);
void cargarEtiquetas(const char*,int *codigoEtiqueta,int *duracionEtiqueta,int &n_etiquetas);
void probarEtiquetas(const char*,int *codigoEtiqueta,int *duracionEtiqueta,int n_etiquetas);
int AlmacenarDuracion(ifstream &leer);
void imprimir_duracion(ofstream &write,int duracion,char c);
int buscar_canal(char *cCanal,int *int_canal,int n,char c_canal, int entero_canal);
int buscar_etiqueta(int *codigoEtiqueta,int n,int c_etiqueta);
int DevolverPorcentajeCalidad(double rating);
void ArmarEtiquetas(const char *repro,int *codigoEtiqueta, int *duracionEtiqueta, int n_etiquetas,
                    char *cCanal, int *int_canal, int n_canal,
                    int *TotalReproEtiqueta,int *TotalTiempoReproEtiqueta,int *TotalReproCanal,
                    int *TotalTiempoReproCanal);
void imprimirEncabezadoCanales(ofstream &write);
void imprimirEncabezadoEtiquetas(ofstream &write);
void imprimir_reporte(const char*reporte,int *codigoEtiqueta, int *duracionEtiqueta, int n_etiquetas,
                        int *fechaCreacion, char *cCanal, int *int_canal, double *rating, int n_canal,
                        int *TotalReproEtiqueta,int *TotalTiempoReproEtiqueta,int *TotalReproCanal,
                    int *TotalTiempoReproCanal,double tarifa);
#endif //LAB4__252__FUNCIONES_HPP