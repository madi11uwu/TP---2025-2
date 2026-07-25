//
// Created by Madi on 5/10/2025.
//

#ifndef VIDEOJUEGOS__OTRA_VEZ__FUNCIONES_HPP
#define VIDEOJUEGOS__OTRA_VEZ__FUNCIONES_HPP
#include "Utils.hpp"
void cargar_logros(const char*,int *codigo_logro,int *tiempoPromedio,int &n_logros);
void probar_logros(const char*,int *codigo_logro,int *tiempoPromedio,int n_logros);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
int AlmacenarDuracion(ifstream &);
int AlmacenarFecha(ifstream &);
void imprimir_duracion(int,char,ofstream &);
void imprimir_fecha(int,ofstream &);
void ignorar(ifstream &,char);
void cargar_juegos(const char*,int *FechaLanzamiento,char *c_juego,int *int_juego,double *rating,int &n_juego);
void probar_juegos(const char*,int *FechaLanzamiento,char *c_juego,int *int_juego,double *rating,int n_juego);
void swapInt(int &a,int &b);
void swapDouble(double &a,double &b);
void ordenarLogros(int *codigo_logro,int *tiempoPromedio,int n_logros);
void imprimir_reporte(const char *,int *codigo_logro,int *tiempoPromedio,int n_logros);
void imprimir_encabezadoJuegos(ofstream &write);
int buscarLogro(int *codigo_logro,int n_logros,int logro);
int buscarJuego(char *c_juego,int *int_juego,int n_juego,char char_juego,int int1_juego);
#endif //VIDEOJUEGOS__OTRA_VEZ__FUNCIONES_HPP