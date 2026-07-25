//
// Created by Madi on 28/11/2025.
//

#ifndef TALLER1_FUNCIONES_HPP
#define TALLER1_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void cargarLibros(const char * str, struct Libro *&libro, int &n_libros);
char *leer_cadena(int,char,ifstream &);
char *asignarCadena(char *);
char leer_char(ifstream &);
int leer_int(ifstream &);
double leer_double(ifstream &);
void probarLibros(const char * str, struct Libro * libro, int n_libros);
void imprimirLinea(int,char,ofstream &);
void cargarUsuarios(const char * str, struct Usuario *&usuario, int &n_usuarios);
void probarUsuarios(const char * str, struct Usuario * usuario, int n_usuarios);
void imprimirEspacios(int,int,ofstream &);
void CompletarPrestamos(const char * str, struct Usuario * usuario, struct Libro * libro,int,int);
int almacenarFecha(ifstream &);
void imprimirFecha(int,ofstream &);
void ordenarLibro(struct Libro * libro, int n_libros);
void swapStruct(struct Libro &a,struct Libro &b);
void swapUsuario(struct UsuarioConElLibro &a,struct UsuarioConElLibro &b);
#endif //TALLER1_FUNCIONES_HPP