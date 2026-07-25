//
// Created by Madi on 8/09/2025.
//

#ifndef VARGUITAS_FUNCIONES_HPP
#define VARGUITAS_FUNCIONES_HPP
#include "Utils.hpp"
void imprimir_reporte();
void imprimir_encabezado();
void imprimir_info();
void imprimir_linea(int ,char );
void imprimir_orden(int DNI,int dd,int mm,int yyyy,int pais,int ciudad,int telefono,int h,int m,int s,double tarifa);
double convertir_hora(int h,int m,int s);
int convertir_fecha(int dd,int mm,int yyyy);
void imprimir_estadisticas(int ciudad214567);
void imprimir_estadisticas(int ciudad214567,double porcentaje,double tarifaProm,int DNIM,int DNIm);
#endif //VARGUITAS_FUNCIONES_HPP