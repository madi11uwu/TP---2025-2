//
// Created by Madi on 17/11/2025.
//

#ifndef INC_2025_2_LAB8_ESTRUCTURAS_FUNCIONES_HPP
#define INC_2025_2_LAB8_ESTRUCTURAS_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char *,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void cargarCategorias(const char * str, struct Categoria *&categoria, int &cantidad_categorias);
char *leer_str(int,char,ifstream &);
int leer_int(ifstream &);
double leer_double (ifstream &);
char *asignar_str(const char *);
void probarCategoras(const char * str, struct Categoria * categoria, int cantidad_categorias);
void imprimir_duracion(int,ofstream &);
int almacenarDuracion(ifstream &);
char *modificarCadena(char *);
void llenarCategorias(const char * str, struct Categoria * categoria, int cantidad_categorias);
int buscarCategoria(char *codigo,struct Categoria *&categoria,int n);
void ordenarCategorias(struct Categoria * categoria, int cantidad_categorias);
void swapStructCategorias(struct Categoria &a,struct Categoria &b);
void CalcularPromedios(struct Categoria * categoria, int cantidad_categorias);
void imprimir_reporte(const char * str, struct Categoria * categoria, int cantidad_categorias);
void ordenarCanales(struct Categoria * categoria, int cantidad_categorias);
void swapStructReproduccion(struct Reproduccion &a,struct Reproduccion &b);
#endif //INC_2025_2_LAB8_ESTRUCTURAS_FUNCIONES_HPP