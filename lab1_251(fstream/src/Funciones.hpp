//
// Created by Madi on 14/09/2025.
//

#ifndef LAB1_251_FSTREAM_FUNCIONES_HPP
#define LAB1_251_FSTREAM_FUNCIONES_HPP
#include "Utils.hpp"

void imprimir_procesar_datos(const char *entrada, const char *salida);
void apertura_lectura(ifstream &,const char *entrada);
void apertura_escritura(ofstream &write, const char *salida);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabeza(ofstream &write, ifstream &leer,int &fecha1,int &fecha2);
int leer_calcularFecha(ifstream &leer) ;
void imprimir_fecha(int fecha,ofstream &write);
void imprimir_encabezadoEstatico(ofstream &write,int compañia) ;
void leer_nombre(ifstream &leer,ofstream &write) ;
void imprimir_encabezadoDinamico(ofstream &write);
void imprimir_tipo(char tipo,ofstream &write);
void imprimir_placa(ifstream &leer,ofstream &write,char tipo);
void leer_imprimirHora(ofstream &write,ifstream &leer,int &hora);
void incrementos_Gravedad(ofstream &write,int hora,char gravedad,char tipo,int fecha1,int fecha2,double &incG,
    double &incT,double &incH,double &incF,int fecha,double &incrementoTotal);
void imprimir_incrementos(ofstream &write,double incG,double incT,double incH,double incF,double &incrementoTotal);
void imprimir_compañiaGastoMayor(ofstream &write,double MayorPago,double MenorPago,int DNIM,int DNIm);
void imprimirTodo(ofstream &write,ifstream &leer);

#endif //LAB1_251_FSTREAM_FUNCIONES_HPP
