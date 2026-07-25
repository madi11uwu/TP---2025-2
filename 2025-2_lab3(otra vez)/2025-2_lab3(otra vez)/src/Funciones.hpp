//
// Created by Madi on 27/09/2025.
//
#include "Utils.hpp"
#ifndef INC_2025_2_LAB3_OTRA_VEZ__FUNCIONES_HPP
#define INC_2025_2_LAB3_OTRA_VEZ__FUNCIONES_HPP
void ProcesarDatos(const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezadoPrincipal(ofstream &,double);
int AlmacenarFecha(ifstream &leer);
void imprimir_encabezadoDinamico(ofstream &write);
int AlmacenarFecha(ifstream &leer);
void imprimir_encabezadoEstatico(int canal,ofstream &write);
void imprimir_nombre(ifstream &leer,ofstream &write);
void imprimir_duracion(ofstream &write,int duracion,char c);
int AlmacenarDuracion(ifstream &leer);
void imprimir_fecha (ofstream &write,int fecha);
void imprimir_datosEstaticos(ofstream &write,ifstream &leer_canales,int canal,int fecha,char &c_canal,int &int_canal,double &rating);
void RecogerFechayCantidadRepro(int &fecha,int &repro,ifstream &leer_reproducciones,int int_canal,char c_canal,int etiqueta);
void imprimir_texto(ifstream &leer,ofstream &write);
void imprimir_descripcionYDuracion(int etiqueta,ofstream &write,ifstream &leer_etiquetas,int &duracion) ;
void imprimir_datosDinamicos(ofstream &write,ifstream &leer_reproducciones,ifstream &leer_etiquetas,int etiqueta,int nro_etiqueta,char c_canal,int int_canal,int &reproTotalEtiqueta);
void imprimir_porcentaje(double rating,ofstream &write);
void imprimir_Estadisticas(int TiempoTotalCanal,double rating,double tarifa,ofstream &write);
void imprimir_reporte(ofstream &write,ifstream &leer_canales,ifstream &leer_reproducciones,ifstream &leer_etiquetas,double tarifa);
#endif //INC_2025_2_LAB3_OTRA_VEZ__FUNCIONES_HPP