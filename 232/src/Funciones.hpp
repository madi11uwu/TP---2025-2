//
// Created by Madi on 7/09/2025.
//

#ifndef INC_232_FUNCIONES_HPP
#define INC_232_FUNCIONES_HPP
#include "Utils.hpp"
void imprimir_reporte();
void imprimir_encabezado();
void imprimir_linea(int ,char );
void imprimir_estático();
int calcular_hora(int h,int m,int s);
void leer_sexo(char &S);
void leer_fechaDeNacimiento(int &año);
void leer_hora(int &tiempo);
double duracion(int tiempoF,int tiempoI);
void duracionEnHMS(double duracion);
void leerCanales(int &canal1,int &canal2,int &canal3,int &cantCanales);
void leer_compania(char &c);
void imprimir();
#endif //INC_232_FUNCIONES_HPP