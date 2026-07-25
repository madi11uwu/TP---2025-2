//
// Created by Madi on 1/12/2025.
//

#ifndef LAB8_2025_2_FUNCIONES_HPP
#define LAB8_2025_2_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
char* leer_cadena(int,char,ifstream &);
double leer_double (ifstream &);
int almacenarDuracion(ifstream &);
void imprimirDuracion(int,ofstream &);
void CargarCategorias(const char * str, struct Categoria *&categoria, int &cantidad_categorias);
void probarCategorias(const char * str, struct Categoria * categoria, int cantidad_categorias);
void imprimirLinea(int,char,ofstream &);
void llenarReproducciones(const char * str, struct Categoria * categoria, int cantidad_categorias);
void ordenarArreglo(struct Categoria * categoria,int);
void swapStructCategoria(struct Categoria &a,struct Categoria &b);
void llenarComentarios(const char * str, struct Categoria * categoria, int cantidad_categorias);
void insertar_ordenado(struct Categoria *&categoria, char *cod_categoria,
                       int &cantidad_categorias,char *,char *,
                       struct Reproduccion *reproduccion);
#endif //LAB8_2025_2_FUNCIONES_HPP