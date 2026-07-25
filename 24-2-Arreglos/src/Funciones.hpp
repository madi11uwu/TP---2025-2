//
// Created by Madi on 12/10/2025.
//

#ifndef INC_24_2_ARREGLOS_FUNCIONES_HPP
#define INC_24_2_ARREGLOS_FUNCIONES_HPP
#include "Utils.hpp"
void cargarClientes(const char*,int *DNICliente,int *codigo_distrito,char *c_vehiculo,
                    double *descuento,int &n_clientes);
void probarClientes(const char*,int *DNICliente,int *codigo_distrito,char *c_vehiculo,
                    double *descuento,int n_clientes);
void apertuta_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezado(ofstream &);
void ignorar(ifstream &,char);
void cargarPlatos(const char*,int *codigo_plato,double *precio_plato,int *cantidadHecha,
                double *descuento_plato,int &n_platos);
void probarPlatos(const char*,int *codigo_plato,double *precio_plato,int *cantidadHecha,
                double *descuento_plato,int n_platos);
void GenerarArreglos(const char*,int *DNICliente,int *codigo_distrito,char *c_vehiculo,
                    double *descuento,int n_clientes,int *codigo_plato,double *precio_plato,int *cantidadHecha,
                    double *descuento_plato,int &n_platos);
int Buscar(int *DNICliente,int n_clientes,int DNILeido);
void GenerarArreglos(const char *repartos, int *DNICliente,double *descuento,
                    int n_clientes, int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
                    int n_platos,int *cantidadAtentida,int *cantidadNoAtendida,double *MontoEsperado,
                    double *montoBruto,double *montoRecibido);
void swapInt(int &a,int &b);
void swapDouble(double &a,double &b);
void ordenarArreglos(int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
                    int n_platos,int *cantidadAtentida,int *cantidadNoAtendida,double *MontoEsperado,
                    double *montoBruto,double *montoRecibido);
void imprimirReporte(const char*,int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
                    int n_platos,int *cantidadAtentida,int *cantidadNoAtendida,double *MontoEsperado,
                    double *montoBruto,double *montoRecibido);
void imprimir_Totales(ofstream &write,double TotalEsperado,double totalBruto,double totalRecibido);
void LimpiarArreglos(int *codigo_plato, double *precio_plato, int *cantidadHecha, double *descuento_plato,
                    int n_platos,int *cantidadAtentida,int *cantidadNoAtendida,double *MontoEsperado,
                    double *montoBruto,double *montoRecibido);
#endif //INC_24_2_ARREGLOS_FUNCIONES_HPP