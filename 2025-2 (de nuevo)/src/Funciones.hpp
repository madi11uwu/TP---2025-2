//
// Created by Madi on 21/09/2025.
//

#ifndef INC_2025_2__DE_NUEVO__FUNCIONES_HPP
#define INC_2025_2__DE_NUEVO__FUNCIONES_HPP
#include "Utils.hpp"
void Calcular_ProcesarDatos(const char*,const char*);
void apertura_lectura(ifstream &leer,const char *file);
void apertura_salida(ofstream &write,const char *file);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &write,int fecha1,int fecha2,double Trepro,double Tduracion);
void imprimir_fecha(int fecha,ofstream &write) ;
void imprimir_encabezadoEstatico(ofstream &write,int canal);
int AlmacenarFecha(ifstream &leer);
void imprimir_nombre (ifstream &leer,ofstream &write);
void imprimir_encabezadoDinamico(ofstream &write);
int AlmacenarDuracion(ifstream &leer);
void imprimir_duracion(int duracion,ofstream &write);
void imprimir_datosEstaticos(ofstream &write,ifstream &leer,int fecha,long long seguidores,long long visitas,
    long long espectadores);
void imprimir_datosDinamicos(ofstream &write,ifstream &leer,double Tduracion,double Trepro,int &TotalReproducciones,
    int &TotalDuracion,double &IngresototalDuracion,double &ingresoPublicidad,int &streams);
void imprimir_estadisticasCanal(ofstream &write,int TotalReproducciones,double IngresototalDuracion,int TotalDuracion,double ingresoPublicidad,
    long long seguidores,long long visitas,long long espectadores);
void imprimir_estadisticaGlobal(ofstream &write,double ingresoGlobalRepro,int DuracionGlobal,double ingresoGlobalDuracion,int streams);
void imprimir_reporte(ifstream &leer,ofstream &write,double Tduracion,double Trepro,int fecha1,int fecha2);
bool ValidarFecha(int fecha,int fecha1,int fecha2);
#endif //INC_2025_2__DE_NUEVO__FUNCIONES_HPP