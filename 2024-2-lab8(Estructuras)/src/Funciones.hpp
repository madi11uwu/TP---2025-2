//
// Created by Madi on 9/11/2025.
//

#ifndef INC_2024_2_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#define INC_2024_2_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void cargar_distrito(const char * str, struct Distrito * distrito, int &n_distrito);
void cargar_platos(const char * str, struct Plato * plato, int &n_plato);
void cargar_cliente(const char * str, struct Cliente * cliente, int &n_clientes);
int leer_int(ifstream &leer);
double leer_double(ifstream &leer);
char *leer_string(ifstream &leer,char delim,int n);
void probar_distrito(const char * str, struct Distrito * distrito, int n_distrito);
void probar_platos(const char * str, struct Plato * distrito, int n_distrito);
void probar_cliente(const char * str, struct Cliente * cliente, int n_distrito);
void imprimir_linea(int,char,ofstream &);
void llenarArregloCliente(const char * str, struct Distrito * distrito, struct Plato * plato, struct Cliente * cliente, int n_distrito, int n_clientes,
                         int n_plato);
int BuscarCliente(int dni, struct Cliente * cliente, int n_clientes);
int BuscarPlato(char * codplato, struct Plato * plato, int n_plato);
void swapStructClientes(struct Cliente &a,struct Cliente &b);
void swapStructPlatos(struct PlatoPedido &a,struct PlatoPedido &b);
void imprimir_encabezadoPrincipal(ofstream &);
void imprimir_encabezadoSecundario(ofstream &);
void ordenarCliente(struct Cliente *cliente,int n);
void ordenarPlatosPedidos(struct Cliente *cliente,int n_cliente);
void imprimir_reporte(struct Cliente *,struct Plato *,struct Cliente *);
char *leer_cadena_exacta(ifstream &read);
char *asignar_cadena(const char *c);
#endif //INC_2024_2_LAB8_ESTRUCTURAS__FUNCIONES_HPP