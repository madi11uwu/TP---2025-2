//
// Created by Madi on 15/09/2025.
//

#ifndef INC_251_FSTREAM__FUNCIONES_HPP
#define INC_251_FSTREAM__FUNCIONES_HPP
#include "Utils.hpp"
void procesarDatosTwitch(const char *entrada,const char *salida);
void apertura_lectura(ifstream &read,const char *entrada);
void apertura_salida(ofstream &write,const char *salida) ;
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &write,int fecha1,int fecha2);
void imprimir_fecha(int fecha,ofstream &write);
int leer_almacenarFecha(ifstream &read);
void leer_imprimir_nombre(ofstream &write,ifstream &read) ;
void imprimir_encabezado1(ofstream &write) ;
bool ValidarFecha(int fecha,int fecha1,int fecha2);
int AlmacenarDuracion(ifstream &read);
void imprimir_duracion(int duracion,ofstream &write);
void imprimir_datosEstaticos(ofstream &write,ifstream &read,int fecha,int &codigo,char &letraCod);
void imprimir_datosDinamicos(ofstream &write,ifstream &read,int &reproCanal,int &mayorFecha,
    int &totalDuracion,double &ingresos,int &streams);
void imprimir_estadisticasCanal(int totalDuracion,int mayorFecha,int reproCanal,double ingresos,ofstream &write) ;
void imprimir_estadisticasGlobales(ofstream &write,int streams,int DuracionGlobal,double ingresoGlobal,int mayorCodigo,
    char mayorLetra,double mayorIngreso);
void imprimir_reporte(int fecha1,int fecha2,ifstream &read,ofstream &write);
#endif //INC_251_FSTREAM__FUNCIONES_HPP