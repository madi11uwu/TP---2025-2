//
// Created by Madi on 27/09/2025.
//

#ifndef KPOP__ARREGLOS__FUNCIONES_HPP
#define KPOP__ARREGLOS__FUNCIONES_HPP
#include "Utils.hpp"
void cargar_artistas(const char *,int *,char *,int *,
        double *,int &n);
void probar_artistas(const char *,int *,char *,int *,
        double *,int n);
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
int Almacenar_fecha(ifstream &leer);
void leer_Nombre_Artistas (ifstream &leer,ofstream &write);
void ignorar(ifstream &leer,char car);
void imprimir_linea(int n,char c,ofstream &write);
void imprimir_fecha (ofstream &write,int fecha);
void cargar_canciones(const char *,int *codigos_canciones,int *duracion_canciones,int &n_canciones);
void probar_canciones(const char *,int *codigos_canciones,int *duracion_canciones,int n_canciones);
int AlmacenarDuracion(ifstream &leer);
void  generar_reporte(const char *,int *fecha_artistas,char *codigo_char_artistas,int *codigo_int_artistas,double *rating,
        int *codigos_canciones,int *duracion_canciones,int *reproducciones_tiempo_total,double *Revenue,int *TotalReproducciones);
int buscar(int *codigo_int_artistas,int codigo_intLeido,int n_artistas);
#endif //KPOP__ARREGLOS__FUNCIONES_HPP