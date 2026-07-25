//
// Created by Madi on 4/10/2025.
//

#ifndef PLATAFORMA_DE_VIDEOJUEGOS_FUNCIONES_HPP
#define PLATAFORMA_DE_VIDEOJUEGOS_FUNCIONES_HPP
#include "Utils.hpp"
void cargar_juegos(const char*,int *fechas_juegos,char *codigo_juegos_char,int *codigos_juegos_int,
                  double *rating,int &n_juegos);
void probar_juegos(const char*,int *fechas_juegos,char *codigo_juegos_char,int *codigos_juegos_int,
                  double *rating,int n_juegos);
void cargar_logros(const char*,int *codigos_logros,int *duracionPromedio,int &n_logros);
void probar_logros(const char*,int *codigos_logros,int *duracionPromedio,int n_logros);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(ofstream &,int);
int AlmacenarDuracion(ifstream &);
void imprimir_duracion(ofstream &,int,char);
void cargar_logros_juegos(const char*,char *codigos_char_juegos_logros,
                        int *codigos_int_juegos_logros,int *codigos_logros_juegos_logros,
                        int *cantidad_juegos_logros,int &n_logros_juegos,int,int*);
int buscar_codigo_logro(int *codigos_logros,int n_logros,int codigo_logro);
void ordenar_arreglos_logros(const char*,int *codigos_logros,int *duracionPromedio,int *n_logros,int);
void swapInt(int &num1,int &num2);
void swapDouble(int &num1,int &num2);
#endif //PLATAFORMA_DE_VIDEOJUEGOS_FUNCIONES_HPP