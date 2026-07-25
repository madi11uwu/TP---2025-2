//
// Created by Madi on 11/10/2025.
//

#ifndef EX1_24_2_FUNCIONES_HPP
#define EX1_24_2_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void generarReporte(const char*,const char*,
                    const char*,const char*,
                    const char*);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezado(ofstream &);
void leer_nombres(ifstream &,ofstream &,char);
void imprimirDatosEstaticos(ifstream &leer_clientes, ofstream &write,int DNI,int &codigo_distrito);
void imprimir_reporte(ifstream &,ifstream &,ifstream &,ifstream &,ofstream &);
void escribir_vehiculo(ofstream &write,char c);
void imprimir_encabezadoPedido(ofstream &write);
void imprimirPlatoyBuscarPrecio(int codigo_plato,ifstream &leer_platos,ofstream &write,
                                double &precio,double &descuento);
void imprimir_Dinamico(ifstream &leer_platos,int cantidad,
                        int codigo_plato,ofstream &write,int nro_plato,double &subtotal,
                        double &plato_descuento);
void imprimir_datosDinamicos(int &nro_pedido,ofstream &write,int DNI,ifstream &leer_repartos,
                            ifstream &leer_platos,double &subTotalCliente,double descuentoClienteTotal);
int DevolverPorcentajeRepartidor(char c);
void imprimirEstadisticasPedido(double subTotalCliente,double descuentoClienteTotal,
                                double descuento,char c_vehiculo,ofstream &write,
                                double &TotalPagagoCliente,double &pagoRepartidor);
#endif //EX1_24_2_FUNCIONES_HPP