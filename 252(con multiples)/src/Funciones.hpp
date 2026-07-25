//
// Created by Madi on 21/09/2025.
//

#ifndef INC_252_CON_MULTIPLES__FUNCIONES_HPP
#define INC_252_CON_MULTIPLES__FUNCIONES_HPP
#include "Utils.hpp"
void imprimir_ProcesarDatos(const char*,const char*,const char*,const char*);
void apertura_entrada(const char*,ifstream &);
void apertura_salida(const char*,ofstream &);
void imprimir_encabezadoPrincipal(ofstream &,int,int,double,double);
void imprimir_linea(int,char,ofstream &);
int AlmacenarFecha(ifstream &);
int AlmacenarDuracion(ifstream &);
void imprimir_fecha(int,ofstream &);
void imprimir_duracion(int,ofstream &);
bool ValidarFecha(int fecha,int fecha1,int fecha2);
void imprimir_nombre(ifstream &leer,ofstream &write);
void imprimir_datosEstaticos(ofstream &write,ifstream &leer_canales,char &c_canal,int &int_canal,int fecha,ifstream &leer_categoria);
void buscar_imprimirCategoria(int int_canal,char c_canal,ofstream &write);
void imprimir_categoria(ofstream &write,ifstream &leer_categoria);
void imprimir_datosDinamicos(ofstream &write,ifstream &leer_streams,char c_canal,int int_canal,double Trepro,double Tduracion,
    int &DuracionTotal,int &TotalReproCanal,double &ingresoDuracionCanal,double &ingresoReproCanal);
void imprimir_EncabezadoDinamico(ofstream &write);
void buscar_imprimirCategoria(int int_canal,char c_canal,ofstream &write,ifstream &leer_categoria);
void imprimir_reporte(ofstream &write,ifstream &leer_canales,ifstream &leer_streams,ifstream &leer_categorias,int fecha1,int fecha2,
    double Trepro,double Tduracion);
#endif //INC_252_CON_MULTIPLES__FUNCIONES_HPP