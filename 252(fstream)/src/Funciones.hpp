//
// Created by Madi on 15/09/2025.
//

#ifndef INC_252_FSTREAM__FUNCIONES_HPP
#define INC_252_FSTREAM__FUNCIONES_HPP
#include "Utils.hpp"
void ProcesarDatos(const char *entrada,const char *salida);
void apertura_entrada(const char *entrada,ifstream &leer);
void apertura_salida(const char *salida,ofstream &write);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &,int,int);
void imprimir_fecha(int fecha,ofstream &write);
bool ValidarFecha(int fecha,int fecha1,int fecha2);
int leer_fechaAlmacenar(ifstream &leer);
void imprimir_nombre(ifstream &leer,ofstream &write);
void imprimir_datosEstaticos(ifstream &leer,ofstream &write,int &codigo,char &letra,int fecha,int i);
int CalcularDuracion (ifstream &leer);
void imprimir_duracion(int duracion,ofstream &write);
void imprimir_leer_datosDinamicos(ifstream &leer,ofstream &write,int &ReproCanal,int &DuracionCanal,int &mayorFecha,int &streams,double &ingresos);
void imprimir_estadisticasCanal(ofstream &write,int ReproCanal,int DuracionCanal,int mayorFecha,double ingresos);
void imprimir_estadisticasGlobales(ofstream &write,int streams,int DuracionGlobal,double ingresoGlobal,double mayorIngreso,char mayorLetra,int mayorCodigo);
void imprimir_reporte(ifstream &leer,ofstream &write,int fecha1,int fecha2);
#endif //INC_252_FSTREAM__FUNCIONES_HPP