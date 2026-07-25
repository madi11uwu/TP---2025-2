//
// Created by Madi on 6/10/2025.
//

#ifndef INC_2025_2_LAB05_ARREGLOS_ORDENACION_FUNCIONES_HPP
#define INC_2025_2_LAB05_ARREGLOS_ORDENACION_FUNCIONES_HPP
#include "Utils.hpp"
void cargarCanales(const char*,int *FechaCreacion,
                   char *c_canal, int *int_canal, double *rating, int &n_canales);
void probarCanales(const char*,int *FechaCreacion,
                    char *c_canal,int *int_canal,double *rating,int n_canales);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimirEncabezadoPrincipal(ofstream &,double);
void imprimir_linea(int,char,ofstream &);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(int,ofstream &);
void ignorar(ifstream &,char);
void cargarEtiquetas(const char*,int *codigo_etiqueta,int *duracion,int &n_equiquetas);
void probarEtiquetas(const char*,int *codigo_etiqueta,int *duracion,int n_equiquetas);
int AlmacenarDuracion(ifstream &);
void imprimirDuracion(int,ofstream &,char);
void imprimir_encabezadoCanales(ofstream &);
void cargarEtiquetasEnCanales(const char*,char *char_canal,int*,
                            int *etiqueta,int &n_etiquetasEnCanales);
void probarEtiquetasEnCanales(const char*,char *char_canal,int*,
                            int *etiqueta,int n_etiquetasEnCanales);
void swapInt(int &a,int &b);
void ordenarEtiquetas(int *codigo_etiqueta, int *duracion, int n_etiquetas);
int BuscarEtiqueta(int *codigo_etiqueta,int n,int cod_etiqueta);
int BuscarCanal(char *c_canal,int *int_canal,int n,char c,int canal);
int BuscarCanalYEtiqueta(char *char_canal,int*codigo_canal,
                    int *etiqueta,int n_etiquetasEnCanales,
                    char c,int canal,int cod_etiqueta);
int DevolverPorcentaje(double promedioRating);
void imprimir_resumenEtiqueta(int TotalReproEtiqueta,int TotalDuracionEtiqueta,
                                double promedioRating,double tarifa,ofstream &write);
void imprimir_CanalesEtiquetayEstadisticas(int etiquetaBuscar,char *c_canal,
                                        int *int_canal,double *rating,
                                        int n_canales,int *codigo_etiqueta,
                                        int *duracion,int n_etiquetas,double tarifa,
                                        int *NumeroTotalRepros,int *DuracionTotalRepros,
                                        char *char_canal,int*codigo_canal,
                                        int *etiqueta,int n_etiquetasEnCanales,ofstream &write) ;
void GenerarArreglos(const char*reproducciones,int *codigo_etiqueta,int *duracion,
                    int n_etiquetas,char *char_canal,int*codigo_canal,
                    int *etiqueta,int n_etiquetasEnCanales,
                    int *NumeroTotalRepros,int *DuracionTotalRepros);
void imprimir_reporte(const char *reporte,char *c_canal,
                        int *int_canal,double *rating,
                        int n_canales,int *codigo_etiqueta,
                        int *duracion,int n_etiquetas,double tarifa,
                        int *NumeroTotalRepros,int *DuracionTotalRepros,
                        char *char_canal,int*codigo_canal,
                        int *etiqueta,int n_etiquetasEnCanales);
#endif //INC_2025_2_LAB05_ARREGLOS_ORDENACION_FUNCIONES_HPP