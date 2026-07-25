//
// Created by Madi on 22/09/2025.
//

#ifndef EJERCICIORANDOM_FUNCIONES_HPP
#define EJERCICIORANDOM_FUNCIONES_HPP
#include "Utils.hpp"
void ProcesarDatos(const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezadoPrincipal(ofstream &);
void imprimir_nombre(ofstream &write,ifstream &leer);
void imprimir_distrito(ifstream &leer,ofstream &write);
void imprimir_encabezadoEstatico(ifstream &leer,ofstream &write,int canal,int DNI);
void imprimir_tipo(ofstream &write,char c_placa);
void imprimir_encabezadoDinamico(ofstream &write,int i,char c_placa,int num1,int num2);
int AlmacenarFecha(ifstream &leer);
void imprimir_fecha(int fecha,ofstream &write);
void imprimir_gravedad(ofstream &write,char c_infraccion);
void imprimir_descripcion(ofstream &write,ifstream &leer);
void imprimir_datosDinamicos(ofstream &write,ifstream &leer_registrada,ifstream &leer_cometida,ifstream &leer_infracciones);
void imprimir_multaYDescripcion(char c_infraccion,int int_infraccion,ofstream &write,ifstream &leer_infracciones);
void encontrar_fecha_infr_grav_mult_desc(ofstream &write,ifstream &leer_cometida,char c_placa,int num1,int num2,ifstream &leer_infracciones);
void imprimir_reporte(ifstream &leer_registrada, ofstream &write,ifstream &leer_infracciones,ifstream &leer_cometida);
#endif //EJERCICIORANDOM_FUNCIONES_HPP