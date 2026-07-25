//
// Created by Madi on 30/11/2025.
//

#ifndef TALLER_2025_1_FUNCIONES_HPP
#define TALLER_2025_1_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
char *leer_cadena(int,char,ifstream &);
int leer_int(ifstream &);
double leer_double(ifstream &);
void cargarCursos(const char * str, struct NodoCurso *&lista);
void cargarEscalas(const char * str, struct NodoEscala *&lista);
char leer_char(ifstream &);
void cargarAlumnos(const char * str, struct NodoAlumno *&lista,struct NodoEscala *listaEscala);
struct NodoEscala * BuscarNodo(char ca, struct NodoEscala * lista);
void ImprimirReporte(const char * str, struct NodoAlumno * lista,int,int);
void imprimirEncabezado(ofstream &,int anio,int ciclo);
void imprimirLinea(int,char,ofstream &);
void llenarAlumnos(const char * str, struct NodoEscala * nodo_escala, struct NodoAlumno * nodo_alumno, struct NodoCurso * nodo_curso,
    int,int);

#endif //TALLER_2025_1_FUNCIONES_HPP