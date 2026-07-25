//
// Created by Madi on 12/10/2025.
//

#ifndef EX1_24_2_2_FUNCIONES_HPP
#define EX1_24_2_2_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void cargarClientes(const char*,int *DNICliente,int *codigo_distrito,char *tipo_vehiculo,
                    double *descuento,int &n_clientes);
void probarClientes(const char*,int *DNICliente,int *codigo_distrito,char *tipo_vehiculo,
                    double *descuento,int n_clientes);
void cargarPlatos(const char*,int *codigo_plato,double *precioPlato,int *cantidadHecha,
                    double *descuentoPlato,int &n_platos);
void probarPlatos(const char*,int *codigo_plato,double *precioPlato,int *cantidadHecha,
                    double *descuentoPlato,int &n_platos);
void ignorar(ifstream &,char);
#endif //EX1_24_2_2_FUNCIONES_HPP