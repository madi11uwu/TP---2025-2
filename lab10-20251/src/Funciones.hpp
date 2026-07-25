//
// Created by Madi on 24/11/2025.
//

#ifndef LAB10_20251_FUNCIONES_HPP
#define LAB10_20251_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimirEncabezado(ofstream &);
char *leer_cadena(int,char,ifstream &);
char *asignar_cadena(const char*);
int leer_int(ifstream &);
double leer_double (ifstream &);
int almacenarFecha(ifstream &);
void crear_lista(const char*,struct Nodo *&lista);
void imprimirFecha(int fecha,ofstream &);
void imprimirLinea(int,char,ofstream &);
void inicializarCuenta(struct Cuenta & cuenta);
void CompletarLista(const char * str, struct Nodo * lista);
void imprimir_reporte(const char * str, struct Nodo * lista);
void EliminarCuentasPositivas(struct Nodo *&lista);
void eliminarUnElemento(struct Nodo *&lista,int codigo);
#endif //LAB10_20251_FUNCIONES_HPP