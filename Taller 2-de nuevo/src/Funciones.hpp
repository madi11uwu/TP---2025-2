//
// Created by Madi on 1/12/2025.
//

#ifndef TALLER_2_DE_NUEVO_FUNCIONES_HPP
#define TALLER_2_DE_NUEVO_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
void cargarUsuarios(const char * str, struct NodoUsuario *&nodo_usuario);
int leer_int(ifstream &);
char *leer_cadena(char,int,ifstream &);
char leer_char(ifstream &);
double leer_double(ifstream &);
void probarUsuarios(const char * str, struct NodoUsuario * lista,const char *titulo);
void imprimirLinea(int,char,ofstream &);
void imprimirEspacios(int,int,ofstream &);
void ActualizarUsuarios(const char * str, struct NodoUsuario * lista);
int almacenarFecha(ifstream &);
void imprimirFecha(int,ofstream &);
struct NodoUsuario * BuscarUsuario(int dni, struct NodoUsuario * lista);
void cargarMorosos(const char * str, struct NodoUsuarioMoroso *&lista_moroso);
void probarMorosos(const char * str, struct NodoUsuarioMoroso * lista_moroso);
void eliminarNodos(struct NodoUsuario * nodo_usuario, struct NodoUsuarioMoroso * lista_moroso, struct NodoUsuario *&lista_ordenada);
bool esMoroso(int dni, struct NodoUsuarioMoroso * lista_moroso);
void insertarOrdenado(struct Usuario usuario, struct NodoUsuario *&listaUsuario);

#endif //TALLER_2_DE_NUEVO_FUNCIONES_HPP