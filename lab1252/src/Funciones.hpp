//
// Created by Madi on 11/09/2025.
//

#ifndef LAB1252_FUNCIONES_HPP
#define LAB1252_FUNCIONES_HPP
#include "Utils.hpp"
void imprimir_calcular_reporte();
void imprimir_linea(int,char);
void imprimir_encabezado();
void imprimir_estatico(int);
void  imprimir_fecha(int );
void imprimir_nombreMayus(char &);
void imprimir_segundoEncabezado();
void lectura_de_datosDinamicos();
void leer_hora_Imprimir(int &hora);
void imprimir_datos();
void imprimir_datos_estaticos(int fecha,char letra,int codigo);
int calcularFecha();
bool validarFecha(int fecha);
void imprimir_hora(int hora);
void imprimir_datosDinamicos(int &TotalRepro,int &TotalHora,double &ingresos,int &fechaMayor,int &streams);
void imprimir_estadisticasPorCanal(int ReproTotal,int fecha,double ingresos,int TotalHora);
void imprimir_estadisticasGlobales(double ingresoMayor,char mayorLetra,int MayorCodigo,int TotalRepro,int TotalHoras,int streams,double TotalIngreso);
#endif //LAB1252_FUNCIONES_HPP