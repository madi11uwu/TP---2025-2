//
// Created by Madi on 16/11/2025.
//

#ifndef INC_2024_1_LAB9_FUNCIONES_HPP
#define INC_2024_1_LAB9_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void cargarCliente(const char * str, struct Cliente * &cliente, int &n_clientes);
char *leer_cadena(ifstream &,int n,char c);
char *asignar_cadena(const char *name);
char *modificar_cadena(char *cadena);
void cargarLibros(const char * str, struct Libro * &libro, int &n_libros);
int leer_int(ifstream &);
double leer_double (ifstream &);
void completarLibros(const char * str, struct Libro * libro, int n_libros);
int almacenarFecha(int dd,int mm,int aa);
int BuscarLibro(char *codigo,struct Libro *libro,int n_libros);
void calcularRanking(struct Libro * libro, int n_libros);
void ordenarLibros(struct Libro * libro, int n_libros);
void swapStruct(struct Libro &a,struct Libro &b);
void imprimir_reporte(const char*,struct Libro * libro, int n_libros, struct Cliente * cliente, int n_clientes);
void imprimir_primeraParte(int n, char *codigo, char *titulo,
                           char *autor, double precio, int libros,
                           int ranking,ofstream &write);
int BuscarCliente(int dni,struct Cliente *cliente,int n_clientes);
void imprimir_encabezadoSecundario(ofstream &write);
#endif //INC_2024_1_LAB9_FUNCIONES_HPP