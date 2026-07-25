//
// Created by Madi on 23/11/2025.
//

#ifndef LAB8_CON_LISTA_FUNCIONES_HPP
#define LAB8_CON_LISTA_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
char *leer_cadena(int,char,ifstream &);
char *asignar_cadena(const char*);
int leer_int(ifstream &);
int almacenarDuracion(ifstream &);
void imprimir_duracion(int,ofstream &);
void llenarLista(const char * str, struct Nodo *&nodo,char c);
void insertar_ordenado(struct Nodo *&lista, const struct Categoria & categoria);
void insertar_inicio(struct Nodo *&lista, const struct Categoria & categoria);
void insertar_final(struct Nodo *&lista, const struct Categoria & categoria);
void llenarCanales(const char * str, struct Nodo * lista);
double leer_double (ifstream &);
struct Nodo * BuscarNodo(char * codigo, struct Nodo *lista);
void EliminarPorDescripcion(struct Nodo *&nodo);
void inicializarCategoria(struct Categoria & categoria);
void imprimirReporte(const char * str, struct Nodo * nodo);
void imprimirEncabezado(ofstream &);
void imprimirLinea(int,char,ofstream &);
#endif //LAB8_CON_LISTA_FUNCIONES_HPP