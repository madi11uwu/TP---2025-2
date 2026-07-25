//
// Created by Madi on 14/09/2025.
//

#ifndef LAB2_241__FUNCIONES_HPP
#define LAB2_241__FUNCIONES_HPP
#include "Utils.hpp"
void procesar_datos_imprimir(const char *entrada,const char *salida);
void apertura_salida(ofstream &write,const char *salida);
void apertura_entrada(ifstream &leer,const char *entrada);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_encabezado2(ofstream &write);
bool DuracionValida(int duracion);
int leer_calcularFecha(ifstream &leer);
int leer_calcularDuracion(ifstream &leer);
void imprimir_fecha(int fecha,ofstream &write);
void imprimir_duracion(int duracion,ofstream &write);
void imprimir_gastoTotal(double pagoTotal,ofstream &write);
void estadisticas_totales(int RegistroR,int RegistroT,ofstream &write) ;
void imprimir_datos(int DNI,int duracionF,int duracionI,int duracionT,int fecha,ofstream &write,double desc,
    double &pago,double tarifa,double monto);
void leer_imprimirDatosDinamicos(ifstream &leer,ofstream &write);
void imprimir_todo(ifstream &leer,ofstream &write);
#endif //LAB2_241__FUNCIONES_HPP