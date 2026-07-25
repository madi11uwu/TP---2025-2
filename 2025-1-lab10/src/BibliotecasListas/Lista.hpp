//
// Created by Madi on 23/11/2025.
//

#ifndef INC_2025_1_LAB10_LISTA_HPP
#define INC_2025_1_LAB10_LISTA_HPP
#include "../BibliotecasFunciones/Funciones.hpp"
#include "Nodo.hpp"
void llenarOrdenado(const char * str, struct Nodo *&lista);
void insertar_ordenado(struct Nodo *&lista,struct Cuenta &cuenta);
void CompletarDatos(const char * str, struct Nodo * nodo);
struct Nodo *buscarNumeroDeCuenta(int num_cuenta,struct Nodo *lista);
void imprimirReporte(const char * str, struct Nodo * nodo);
void llenarInicio(const char * str, struct Nodo *&listaInicio);
void llenarFinal(const char * str, struct Nodo *&listaFinal);
void inicializarCuenta(struct Cuenta & cuenta);
void insertarFinal(const struct Cuenta & cuenta, struct Nodo *&lista);
void insertar_inicio(const struct Cuenta &cuenta, struct Nodo *&lista);
void EliminarElementos(struct Nodo *&lista);
#endif //INC_2025_1_LAB10_LISTA_HPP