//
// Created by Madi on 8/09/2025.
//

#ifndef PRECIPITACIONES_FUNCIONES_HPP
#define PRECIPITACIONES_FUNCIONES_HPP
#include "Utils.hpp"

void imprimir_reporte();
void imprimir_encabezado();
void convertir_mayus(char car);
void convertir_fecha(int &fecha);
void leer_hora(int &hora);
int calcular_hora(int h,int m,int s);
int calcular_fecha(int dd,int mm,int yyyy);
void imprimir_estadisticas();
void imprimir_info();
void imprimir_hora(int hora);
void imprimir_estadisticas(int fechaI,int fechaF,int dias,int tiempoLlovido,double totalLlovido,int fechaMayor,double mayorPrecipitacion);
void imprimir_parteestatica();

#endif //PRECIPITACIONES_FUNCIONES_HPP