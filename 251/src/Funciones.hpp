//
// Created by Madi on 7/09/2025.
//

#ifndef INC_251_FUNCIONES_HPP
#define INC_251_FUNCIONES_HPP
#include "Utils.hpp"

void imprimir_reporte();
void imprimir_encabezado();
void imprimir_fecha();
void imprimir_linea(int ,char );
void imprimir_info(double &,int &);
void transformarMayus(char &c);
void parte_estatica();
void leer_tipo(double &);
void leer_hora(int &);
void leer_fecha(int &fecha);
int convertirHora(int h,int m,int s);
int convertirFecha(int dd,int mm,int yyyy);
void Gravedad(double &monto);
void imprimir_info();
void imprimir_estadisticas(int DNIm,int DNIM,double menorPago,double mayorPago);
void imprimir(double montoTamaño,double montoFecha,double montoHora,double montoTotal);
void monto_calcular(int fecha,double &incrementoFecha,double &incrementoHora,int fechaI,int fechaF);
void monto_calcularHora(int hora,int mañanaF,int mañanaI,int tardeF,double &incrementoHora);
void calcular_montos(double &montoFecha,double &montoHora,double &montoTamaño,double &montoTotal,double monto,double incrementoFecha,
double incrementoHora,double porcentaje);
void imprimir_nombre();
void CalcularMayor(double totalPago,double &menorPago,int DNI,double &mayorpago,int &DNIm,int &DNIM);
#endif //INC_251_FUNCIONES_HPP
