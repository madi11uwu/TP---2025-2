//
// Created by Madi on 12/09/2025.
//

#ifndef INC_232_OTRAVEZ_FUNCIONES_HPP
#define INC_232_OTRAVEZ_FUNCIONES_HPP
#include "Utils.hpp"
void imprimir_calcular_reporte(const char *,const char *);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void apertura_archivo_lectura(ifstream &input,const char *file);
void apertura_archivo_escritura(ofstream &output,const char *file);
void leer_datos_imprimir_datos(ifstream &leer,ofstream &escr,int DNI,char sexo);
void leer_nombre_imprimir(ifstream &leer,ofstream &);
void convertirMayus(ofstream &escr);
void convertirMayus(ofstream &escr,char &);
int calcularFecha(ifstream &leer);
void imprimir_compañia(char compañia,ofstream &escr);
void imprimir_categoria(int fecha,ofstream &escr);
void imprimir_sexo (char sexo,ofstream &escr);
void imprimir_hora(ofstream &escr,ifstream &leer,int &duracion);
void leer_canal_horas(ifstream &leer,ofstream &escr,int &duracionTotal);
void acumular_datos(int &i,int duracion,char fecha,char sexo,char compañia,int &duracionTotal,int &cantAdultosYMenores,int &cantMujeres,int &cantMujeresTVPUCP);
leer_datos_imprimir_datos(ifstream &leer,ofstream &escr,int DNI,char sexo,int &i,int &duracion,int &fecha,char &compañia);
#endif //INC_232_OTRAVEZ_FUNCIONES_HPP