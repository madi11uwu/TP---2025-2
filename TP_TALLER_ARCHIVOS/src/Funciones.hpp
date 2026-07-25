//
// Created by Madi on 10/10/2025.
//

#ifndef TP_TALLER_ARCHIVOS_FUNCIONES_HPP
#define TP_TALLER_ARCHIVOS_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
void generarReporte(int fechaInicial,int fechaFinal,const char*,const char*,const char*,const char*);
void imprimir_EncabezadoPrincipal(int,int,ofstream &);
void imprimir_linea(int,char,ofstream &);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(int,ofstream &);
void leer_nombres(ifstream &,char,char,ofstream &);
void imprimir_parteEstatica(ifstream &leer_libros,ofstream &write,double precio);
void imprimir_reporte(int fechaInicial, int fechaFinal,ifstream &leer_clientes,
                      ifstream &leer_libros,ifstream &leer_ventas,ofstream &write);
void imprimir_encabezadoSecundario(ofstream &);
bool ValidarFecha(int fechaInicial,int fechaFinal,int fecha);
void BuscarCliente(ifstream &leer_clientes,int DNI,ofstream &write);
void imprimir_datosDinamicos(ifstream &leer_clientes,ifstream &leer_ventas,ofstream &write,
                            int codigo_libreria,int fecha,int codigo,int &nroVentas);
void imprimir_parteDinamica(ifstream &leer_clientes,ifstream &leer_ventas,ofstream &write,int codigo,
                            int fechaInicial,int fechaFinal);
#endif //TP_TALLER_ARCHIVOS_FUNCIONES_HPP