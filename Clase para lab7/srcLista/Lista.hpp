//
// Created by Madi on 15/11/2025.
//

#ifndef CLASE_PARA_LAB7_LISTA_HPP
#define CLASE_PARA_LAB7_LISTA_HPP
#include <cmath>

#include "../src/funciones.hpp"
#include "Nodo.hpp"
void crear_lista(struct Nodo *&lista,const char *file_name);
void insertar(struct Nodo *&nodo, int valor);
void insertar_inicio(struct Nodo *&lista,int valor);
void creador_lista_ordenada(struct Nodo *&lista,const char *);
void insertar_ordenado(struct Nodo *&lista,int dato);
void imprimir_lista(struct Nodo *lista,const char *file_na);
void remover_elemento_lista(struct Nodo *lista,int dato);
void crear_lista_TAD(struct Lista &lista, const char *file_name);
#endif //CLASE_PARA_LAB7_LISTA_HPP