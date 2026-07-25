//
// Created by Madi on 14/09/2025.
//

#ifndef OTRAVEZ_FSTREAM_FUNCIONES_HPP
#define OTRAVEZ_FSTREAM_FUNCIONES_HPP
#include "Utils.hpp"
void imprimir_procesar_datos(const char *entrada,const char *salida);
void procesar_datos_entrada(ifstream &leer,const char *entrada);
void procesar_datos_salida(ofstream &write,const char *salida);
void imprimirEncabezado(int Inicio,int Salida,ofstream &write);
void imprimirFecha(int fecha,ofstream &write);
void imprimir_linea(int,char,ofstream &write);
int leer_convertirFecha(ifstream &leer);
bool Validar_fecha(int fecha,int Inicio,int Salida) ;
void leer_imprimir_nombre(ofstream &write,ifstream &leer,char car);
void imprimir_leer_duracion(ifstream &leer,int &duracion,ofstream &write);
void imprimir_leer_datosDinamicos(ofstream &write,ifstream &leer,int &duracionCanal,int &fechaFinal,int &reproCanal,double &ingresos,int &streams);
void imprimir_leer_datos_estaticos(int &codigo,int fecha,char &letra,ifstream &leer,ofstream &write,int canal);
void imprimir_todo(ofstream &write,ifstream &leer,int Inicio,int Salida);
void imprimir_estadisticasCanal(int duracionCanal,int fechaFinal,int reproCanal,double ingresos, ifstream &leer,ofstream &write);
void imprimir_duracion(int duracion,ofstream &write);
void imprimir_estadisticasGlobal(int duracionGlobal,double ingresoGlobal,int streams,int mayorCodigo,char MayorLetra,double MayorIngreso,
        ifstream &leer,ofstream &write);
#endif //OTRAVEZ_FSTREAM_FUNCIONES_HPP