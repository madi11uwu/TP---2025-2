//
// Created by Madi on 26/10/2025.
//

#ifndef EX1_P2_FUNCIONES_HPP
#define EX1_P2_FUNCIONES_HPP
#include "Utils.hpp"
void cargar_ordenado_streams(const char*,int * arr, int * duracion_stream, int * codigo_idioma, char * str, int * int_categoria,
                            int n_stremas);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
int almacenar_duracion(ifstream &leer);
int almacenar_fecha(ifstream &);
void insertar_ordenado(int codigo, int duracion, int idioma, char c_categoria, int categoria_int, int * codigo_stream,
                      int * codigo_idioma, char * char_categoria, int * int_categoria, int n_streams);
#endif //EX1_P2_FUNCIONES_HPP