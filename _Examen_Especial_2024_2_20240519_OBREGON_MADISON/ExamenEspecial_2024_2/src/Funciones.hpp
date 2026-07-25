//
// Created by Madi on 30/11/2025.
//

#ifndef EXAMENESPECIAL_2024_2_FUNCIONES_HPP
#define EXAMENESPECIAL_2024_2_FUNCIONES_HPP
#include "Utils.hpp"
void cargarLexicon(const char * str, struct NodoLexicon *&nodo_lexicon);
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
char *leer_cadena(int,char,ifstream &);
int leer_int(ifstream &);
double leer_double(ifstream &);
char *asignar_cadena(const char *);
int almacenarHora(ifstream &);
void imprimirHora(int,ofstream &);
void probarLexicon(const char * str, struct NodoLexicon * lista, const char * text);
void imprimirLinea(int,char,ofstream &);
void imprimirEspacios(int,int,ofstream &);
void cargarPlatos(const char * str, struct NodoPlato *&lista);
void probarPlatos(const char * str, struct NodoPlato *lista, const char * text);
void cargarAtencion(const char *str,struct NodoAtencion *&lista,struct NodoPlato *listaPlato);
void CompletarAtencion(const char * str, struct NodoAtencion * listaAtencion, struct NodoLexicon * listaLexicon);
bool noEsMayusniMinus(char c);
void SepararPalabras(char * oracion,struct NodoAtencion *nodo,struct NodoLexicon *listaLexicon,int n);
void llenarPalabras(struct NodoAtencion * posicion, struct NodoLexicon * listaLexicon,char *oracion,int n);
void imprimirReporte(const char * str, struct NodoAtencion * nodo_atencion);

#endif //EXAMENESPECIAL_2024_2_FUNCIONES_HPP