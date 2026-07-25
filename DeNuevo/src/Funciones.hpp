//
// Created by Madi on 22/09/2025.
//

#ifndef DENUEVO_FUNCIONES_HPP
#define DENUEVO_FUNCIONES_HPP
#include "Utils.hpp"
void ProcesarDatos(const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_nombre (ofstream &write,ifstream &leer_registrada);
void imprimir_texto(char c,ofstream &write,ifstream &leer);
void imprimir_encabezadoEstatico(int DNI,ofstream &write,ifstream &leer_registrada,int compania);
void imprimir_tipo(ofstream &write,char c_placa);
void imprimir_encabezadoDinamico(ofstream &write,char c_placa,int num1,int num2,int placa);
void imprimir_encabezadoDinamico1(ofstream &write);
int AlmacenarFecha(ifstream &leer);
void imprimir_fecha (int fecha,ofstream &write);
void RecuperarFechaEInfraccion(char c_placa,int num1,int num2,ifstream &leer_infraccion,ifstream &leer_cometida,
    char &c_infraccion,int int_infraccion,int &fecha);
void imprimir_gravedad(char c_infraccion,ofstream &write);
void imprimir_multaYDescripcion(ifstream &leer_infracciones,ofstream &write,char c_infraccion,int int_infraccion);
void imprimir_datosDinamicos(ofstream &write,ifstream &leer_cometida,ifstream &leer_infracciones,char c_placa,int num1,int num2);
void imprimir_reporte(ofstream &write,ifstream &leer_registrada,ifstream &leer_infracciones,ifstream &leer_cometida);
#endif //DENUEVO_FUNCIONES_HPP