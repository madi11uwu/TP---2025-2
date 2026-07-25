//
// Created by Madi on 22/09/2025.
//

#ifndef EJERCICIOKPOP_FUNCIONES_HPP
#define EJERCICIOKPOP_FUNCIONES_HPP
#include "Utils.hpp"
void ProcesarDatosKpop(const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea (int,char,ofstream &);
void imprimir_encabezadoPrincipal(ofstream &,double);
int AlmacenarFecha (ifstream &leer);
void imprimir_fecha(ofstream &,int);
int AlmacenarDuracion (ifstream &leer);
void imprimir_duracion(int duracion,ofstream &write);
void imprimir_nombre(ifstream &leer,ofstream &write) ;
void imprimir_datosEstaticos(ofstream &write,int contador,int fecha,ifstream &leer_artistas,char &c_artista,int &int_artista);
void imprimir_encabezadoEstatico(ofstream &write,int contador);
void imprimir_encabezadoDinamico(ofstream &write);
void imprimir_reporte(ofstream &write,ifstream &leer_canciones,ifstream &leer_reproducciones,
    ifstream &leer_artistas);
void RecuperarFechayReproducciones(ifstream &leer,int int_artista,char c_artista,int int_cancion,int &fechaLeida,long long &reproducciones);
void imprimir_datosDinamicos(ofstream &write,ifstream &leer_canciones,int cancion,ifstream &leer_reproducciones,int int_artista,
    char c_artista,int int_cancion);
void imprimir_nombreCancionyDuracion(ofstream &write,ifstream &leer_canciones,int int_cancion,int &duracion);
void imprimir_duracionTotal(int duracionTotal,ofstream &write);
#endif //EJERCICIOKPOP_FUNCIONES_HPP