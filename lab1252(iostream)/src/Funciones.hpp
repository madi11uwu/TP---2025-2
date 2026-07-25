//
// Created by Madi on 14/09/2025.
//

#ifndef LAB1252_IOSTREAM__FUNCIONES_HPP
#define LAB1252_IOSTREAM__FUNCIONES_HPP
#include "Utils.hpp"
void leer_procesar_canalesTwitch(const char *,const char *);
void apertura_archivo_lectura(ifstream&,const char *entrada);
void apertura_archivo_escritura(ofstream&,const char *salida);
void imprimir_fecha(ofstream &write,int fecha);
void imprimir_linea(int n,char c,ofstream &write);
int calcularFecha(ifstream &leer);
bool validar_fecha (int fechaInicio,int fechaFinal,int fecha);
void imprimir_encabezadoEstatico(ofstream &write,int canal);
void leer_Nombre(ifstream &leer,ofstream &write);
void imprimir_datos_estaticos(ifstream &leer,ofstream &write,int canal,int fecha,char &letraCod,int &codigo);
void leer_datos_dinamicos_y_escribir(ifstream &leer,ofstream &write,int &duracionCanal,int &reproduccionesCanal,double &ingresos,int &mayorFecha,int &streams);
void leer_imprimir_duracion(ifstream &leer,ofstream &write,int &duracion);
void imprimir_duracion(ofstream &write,int duracion);
void imprimir_estadisticas_canal(ofstream &write,int duracionCanal,int mayorFecha,int reproduccionesCanal,double ingresos);
void imprimir_estadisticasGlobales(ofstream &write,int streams,double mayorIngreso,char mayorLetra,int mayorCod,double ingresoGlobal,int duracionGlobal);
void imprimir_encabezado(ofstream &write,int fechaInicial,int fechaFinal);
void imprimir_datos(ofstream &write,ifstream &leer,int fechaInicio,int fechaFinal);
#endif //LAB1252_IOSTREAM__FUNCIONES_HPP