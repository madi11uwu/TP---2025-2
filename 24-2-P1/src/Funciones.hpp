//
// Created by Madi on 13/10/2025.
//

#ifndef INC_24_2_P1_FUNCIONES_HPP
#define INC_24_2_P1_FUNCIONES_HPP
#include "Utils.hpp"
void generarReporteRepartos(const char*,const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezado(ofstream &);
void leer_nombre(ifstream &leer,ofstream &write,char c,char c1);
void DevolverVehiculo(ofstream &write,char c);
void imprimirParteEstatica(ifstream &leer_clientes,ofstream &write,int DNI,double &descuento_cliente,int &);
void imprimir_reporte(ifstream &leer_repartos,ifstream &leer_platos,
                    ifstream &leer_clientes,ifstream &leer_repartidores,
                    ofstream &write);
void imprimirEncabezadoPlatos(ofstream &write);
void buscarDescripcionPrecioyDescuentoPlato(ifstream &leer,double &precio,double &descuento_plato,
                                            int codigo_plato,ofstream &write) ;
void imprimirDatosDinamicos(ofstream &write,ifstream &leer_repartos,
                            int cantidad,int codigo_plato,ifstream &leer_platos,
                            double &precio,double &descuento_plato,double &subtotal,
                            double &descuentoDelPlato);
void imprimirParteDinamica(ifstream &leer_platos,ifstream &leer_repartos,ifstream &leer_repartidores,
                            int nroPedido,ofstream &write,int DNI);
#endif //INC_24_2_P1_FUNCIONES_HPP