//
// Created by Madi on 27/11/2025.
//

#ifndef FUNCION_FUNCIONES_HPP
#define FUNCION_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
char *leer_cadena(char,int,ifstream &);
int leer_int(ifstream &);
char *procesar(char *);
char transformar(char );
void cargarPersonajes(const char*,struct Nodo *&lista);
void inicializarPersonaje(struct Personaje &p);
bool retornarEstado(int i);
void completarLista(const char * str, struct Nodo * lista);
struct Nodo *BuscarNodo (struct Nodo *lista,char *);
void procesarComentarios(char *comentario,struct Nodo *posicion);
void imprimirReporte(const char * str, struct Nodo * lista);
void imprimir_linea(int,char,ofstream &);
void procesarPalabras(const char * str, char **arr, int &nro_comentarios);

#endif //FUNCION_FUNCIONES_HPP