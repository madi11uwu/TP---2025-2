//
// Created by Madi on 8/09/2025.
//

#ifndef INC_241_FUNCIONES_HPP
#define INC_241_FUNCIONES_HPP
#include "Utils.hpp"

void imprimir_reporte();
void imprimir_encabezado();
void imprimir_linea(int n,char c);
void estatico();
void imprimir_leer_info();
void imprimir_estadisticas(double PromS,double PromDerma,double porcentajeN,double porcentajePediatra,int PacCardio,double PorcenNYGasto);
void almacenar_y_leer_fecha(int &fecha,int &dd,int &mm,int &yyyy);
void leerDNI();
void leer_y_calcularHora(double &horas);
void imprimirDuracion (double duracion);
void leerEImprimirEspecialidad(char &c);
void imprimir_gastos(double gastos);
#endif //INC_241_FUNCIONES_HPP