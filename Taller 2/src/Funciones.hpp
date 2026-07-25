//
// Created by Madi on 29/11/2025.
//

#ifndef TALLER_2_FUNCIONES_HPP
#define TALLER_2_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void cargarUsuarios(const char * str, struct NodoUsuario *&nodo_usuario);
int leer_int(ifstream &);
char leer_char(ifstream &);
double leer_double(ifstream &);
char *leer_cadena(int,char,ifstream &);
char *asignar_cadena(char *name);
void probarUsuarios(const char * str, struct NodoUsuario * nodo_usuario,const char *);
void imprimirLinea(int,char,ofstream &);
void imprimirEspacios(int,int,ofstream &);
void ActualizarLista(const char * str, struct NodoUsuario * lista);
int almacenarFecha(ifstream &);
void imprimirFecha(int,ofstream &);
void cargarMorosos(const char * str, struct NodoUsuarioMoroso *&lista);
void probarMorosos(const char * str, struct NodoUsuarioMoroso * lista);
void insertarNodoMoroso(struct NodoUsuarioMoroso *&lista, int dni);
void EliminarMorosos(struct NodoUsuario *&nodo_usuario, struct NodoUsuarioMoroso * nodo_usuario_moroso, struct NodoUsuario *&listo_moroso);

#endif //TALLER_2_FUNCIONES_HPP