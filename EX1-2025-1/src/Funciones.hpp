//
// Created by Madi on 11/10/2025.
//

#ifndef EX1_2025_1_FUNCIONES_HPP
#define EX1_2025_1_FUNCIONES_HPP
#include "Utils.hpp"
void GenerarReporte(const char*,const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezado(ofstream &);
void leer_nombres(ifstream &leer,ofstream &write,char c,char c1);
void imprimirDatosEstaticos(ofstream &write,ifstream &leer_empresas,int nroCompania,int DNI);
void imprimir_reporte(ofstream &write,ifstream &leer_empresas,
                        ifstream &leer_infracciones,ifstream &leer_placas,
                        ifstream &leer_tablaDeInfracciones);
#endif //EX1_2025_1_FUNCIONES_HPP