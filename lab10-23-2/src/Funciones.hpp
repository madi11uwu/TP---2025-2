//
// Created by Madi on 24/11/2025.
//

#ifndef LAB10_23_2_FUNCIONES_HPP
#define LAB10_23_2_FUNCIONES_HPP
#include "Utils.hpp"
void crear_lista_ordenada(const char * str, struct Nodo *&lista);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
char *leer_cadena(int,char,ifstream &);
char *modificarCadena(char*);
char *asignarCadena(const char*);
double leer_double (ifstream &);
int leer_int (ifstream &);
void insertar_ordenado(struct Nodo *&lista, const struct Vendedor & vendedor);
void inicializarVendedor(struct Vendedor & vendedor);
void completarLista(const char * str, struct Nodo *&lista);
void imprimirReporte(const char * str, struct Nodo * lista);
void imprimirEncabezado(ofstream &);
void imprimirLinea(int,char,ofstream &);
void EliminarInformacion(struct Nodo *&lista);

#endif //LAB10_23_2_FUNCIONES_HPP