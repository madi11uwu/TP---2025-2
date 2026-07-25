//
// Created by Madi on 20/09/2025.
//

#ifndef INC_2025_1_LAB3_FUNCIONES_HPP
#define INC_2025_1_LAB3_FUNCIONES_HPP
#include "Utils.hpp"
void calcular_imprimirReporte(const char*,const char*,const char*,const char*);
void apertura_entrada(const char *file,ifstream &leer);
void apertura_salida(const char *file,ofstream &write);
void imprimir_linea(int, char, ofstream &);
void imprimir_encabezadoPrincipal(ofstream &);
void imprimir_encabezadoEstatico(int compania,ifstream &leer_registrada,ofstream &write,int DNI);
void imprimir_nombre (ifstream &leer_registrada,ofstream &write);
void imprimir_distrito(ifstream &leer_registrada,ofstream &write);
void imprimir_tipo(char c_placa,ofstream &write);
void imprimir_gravedad(char c_inf,ofstream &write,int &cantL,int &cantG,int &cantM);
void imprimir_encabezadoDinamico(ofstream &write);
int convertirFecha(ifstream &leer);
void imprimir_fecha(int fecha,ofstream &write);
double encontrar_multa(char c_infr,int int_inf,ifstream &leer);
void imprimir_descripcion(ifstream &leer,ofstream &write) ;
void imprimir_fecha_inf(char c_placa,int num1,int num2,ifstream &leer_cometida,ofstream &write,int vehiculo,ifstream &leer_infracciones);
void imprimir_Dinamico(ifstream &leer_registrada,ofstream &write,ifstream &leer_infracciones,ifstream &leer_cometida);
void encabezadoDinamico1(ofstream &write,int vehiculo,char c_placa,int num1,int num2);
#endif //INC_2025_1_LAB3_FUNCIONES_HPP