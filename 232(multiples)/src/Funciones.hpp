//
// Created by Madi on 21/09/2025.
//

#ifndef INC_232_MULTIPLES__FUNCIONES_HPP
#define INC_232_MULTIPLES__FUNCIONES_HPP
#include "Utils.hpp"
void ProcesarDatos(const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void leer_canal(ifstream &leer,ofstream &write);
void imprimir_nombreCamelizacion(ifstream &leer,ofstream &write);
int convertir_Fecha(ifstream &leer);
void imprimir_categoria(int fecha,ofstream &write,int &jovenes,int &adultos,int &menores);
void imprimir_sexo(char sexo,ofstream &write);
void imprimir_compania(char compania,ofstream &write);
void name_sex_category_compania(ifstream &leer_televidentes,int DNI,ofstream &write,int &jovenes,int &adultos,int &menores);
void imprimir_fecha (int fecha,ofstream &write);
void imprimir_duracion (int duracion,ofstream &write);
int almacenarDuracion(ifstream &leer) ;
void imprimir_encabezadoEstatico2(ofstream &write);
void imprimir_encabezadoEstatico(ifstream &leer_canales,ofstream &write,int canal);
void imprimir_datosDinamicos(ifstream &leer_preferencias,ofstream &write,int canal,ifstream &leer_televidentes,int &televidentes,int &DuracionTotal,int &jovenes,int &menores,int &adultos);
void imprimir_reporte(ifstream &leer_canales,ofstream &write,ifstream &leer_preferencias,ifstream &leer_televidentes);
void imprimir_estadisticaCanal(ofstream &write,int DuracionTotal,int televidentes,int jovenes,int adultos,int menores) ;
#endif //INC_232_MULTIPLES__FUNCIONES_HPP