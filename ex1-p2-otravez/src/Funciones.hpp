//
// Created by Madi on 27/10/2025.
//

#ifndef EX1_P2_OTRAVEZ_FUNCIONES_HPP
#define EX1_P2_OTRAVEZ_FUNCIONES_HPP
#include "Utils.hpp"
void cargar_ordenado_streams(const char * str, int * arr, int * duracion_stream, int * codigo_idioma, char * text,
                            int * int_categoria, int &n_streams);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
int almacenar_duracion(ifstream &);
int almacenar_fecha(ifstream &);
void insertar_ordenado(int * codigo_stream, int * duracion_stream, int * codigo_idioma, char * c_categoria, int * int_categoria, int &n_streams,
                      int codigo, int duracion, int idioma, char char_categoria, int categoria_int);
void imprimir_duracion(int,ofstream &);
void imprimir_fecha(int,ofstream &);
void probar_ordenado_streams (const char *reporteStreams, int *codigo_stream, int *duracion_stream,
                             int *codigo_idioma, char *c_categoria,
                             int *int_categoria, int n_streams);
#endif //EX1_P2_OTRAVEZ_FUNCIONES_HPP