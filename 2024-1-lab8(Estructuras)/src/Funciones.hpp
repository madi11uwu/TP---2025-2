//
// Created by Madi on 10/11/2025.
//

#ifndef INC_2024_1_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#define INC_2024_1_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &,char *);
void cargarAlumnos(const char * str, struct Alumno * &alumno, int &n_alumnos);
void imprimir_linea(int,char,ofstream &);
void imprimirEspacios(int size,int ancho,ofstream &);
char *leer_cadena_exacta(ifstream &);
char *leer_cadena_csv(ifstream &,char delim,int );
int BuscarAlumnos(int cod,struct Alumno *,int n);
void llenarAlumnos(const char * str, struct Alumno * alumno, int n_alumnos);
void llenarAlumnosPorDos(const char * str, struct Alumno * alumno, int n_alumnos);
char *modificarCadena(char *);
char *asignarCadena(const char*);
#endif //INC_2024_1_LAB8_ESTRUCTURAS__FUNCIONES_HPP