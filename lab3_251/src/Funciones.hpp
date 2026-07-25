//
// Created by Madi on 18/09/2025.
//

#ifndef LAB3_251_FUNCIONES_HPP
#define LAB3_251_FUNCIONES_HPP
#include "Utils.hpp"
void procesar_datos_infracciones(const char *infracciones,const char *registradas,
                                const char *cometidas,const char *salida);
void apertura_archivo_lectura(ifstream &leer,const char *file_name);
void apertura_archivo_salida(ofstream &write,const char *file_name);
void imprimir_encabezadoPrincipal(ofstream &write);
void imprimir_linea(int,char,ofstream &);
void leer_nombreCamelizacion(ifstream &leer,ofstream &write);
void leer_Distrito(ifstream &leer,ofstream &write);
void imprimir_Encabezado1(ofstream &write,ifstream &leer_registradas,int canal,int DNI);
int CalcularFecha(ifstream &leer_cometidas);
void imprimir_tipo(ofstream &write,char letra);
void imprimir_fecha(int fecha,ofstream &write);
void imprimir_encabezado2(ofstream &write);
void imprimir_descripcion(ofstream &write,ifstream &leer);
void imprimir_codigoInfraccion(char infraccion,ofstream &write);
void imprimir_descripcion(ofstream &write,ifstream &leer);
void datosDinamicos(ifstream &leer_infracciones,ifstream &leer_registradas,ifstream &leer_cometidas,ofstream &write);
#endif //LAB3_251_FUNCIONES_HPP