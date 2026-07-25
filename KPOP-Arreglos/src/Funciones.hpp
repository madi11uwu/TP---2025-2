//
// Created by Madi on 29/09/2025.
//

#ifndef KPOP_ARREGLOS_FUNCIONES_HPP
#define KPOP_ARREGLOS_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &,double);
void cargarArtistas(const char*,int *fechaDebut,int *int_codigo,double *rating,int &n_artistas);
void probarArtistas(const char*,int *fechaDebut,int *int_codigo,double *rating,int n_artistas);
int AlmacenarFecha(ifstream &leer);
void ignorar(ifstream &leer,char c);
void imprimir_fecha(ofstream &write,int fecha);
void cargarCanciones(const char*,int *c_cancion,int *duracion,int &n_canciones);
void probarCanciones(const char*,int *c_cancion,int *duracion,int n_canciones);
int AlmacenarDuracion(ifstream &leer);
void imprimir_duracion(ofstream &write,int duracion,char c);
int buscar(int *arreglos,int n,int busqueda);
void imprimir_encabezadoArtista(ofstream &write);
void imprimir_encabezadoCanciones(ofstream &write);
void armarArreglos(const char*reproducciones,int *c_cancion, int *duracion, int n_canciones,
                    int *fechaDebut, int *int_codigo, double *rating, int n_artistas,double tarifa,
                    int *FechaCanciones,int *ReproduccionesCancion,int *ReproduccionesArtista,
                    double *GananciaArtista,int *DuracionTotal);
void imprimir_reporte(const char*reporte,int *c_cancion, int *duracion, int n_canciones,
                    int *fechaDebut, int *int_codigo, double *rating, int n_artistas,double tarifa,
                    int *FechaCanciones,int *ReproduccionesCancion,int *ReproduccionesArtista,
                    double *GananciaArtista,int *DuracionTotal);
#endif //KPOP_ARREGLOS_FUNCIONES_HPP