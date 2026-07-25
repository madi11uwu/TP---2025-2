//
// Created by Madi on 9/10/2025.
//

#ifndef VIDEOJUEGOS_FUNCIONES_HPP
#define VIDEOJUEGOS_FUNCIONES_HPP
#include "Utils.hpp"
void cargarJuegos(const char *,int *FechaCreacion,char *c_juego,int *int_juego,
                double *rating,int &n_juego);
void probarJuegos(const char *,int *FechaCreacion,char *c_juego,int *int_juego,
                double *rating,int n_juego);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(int,ofstream &);
void ignorar(ifstream &,char);
void imprimir_linea(int,char,ofstream &);
void cargarLogros(const char*,int *codigo_logro,int *tiempo_promedio,int &n_logro);
void probarLogros(const char*,int *codigo_logro,int *tiempo_promedio,int n_logro);
void imprimir_duracion(int duracion,ofstream &write,char c);
int AlmacenarDuracion(ifstream &leer);
void cargarLogrosEnJuegos(const char*,char *char_juego,int *num_juego,
                            int *c_logros,int &n_logrosEnJuegos);
void probarLogrosEnJuegos(const char*,char *char_juego,int *num_juego,
                            int *c_logros,int n_logrosEnJuegos);
#endif //VIDEOJUEGOS_FUNCIONES_HPP