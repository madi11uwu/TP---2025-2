//
// Created by Madi on 2/11/2025.
//

#ifndef LAB6_23_2_FUNCIONES_HPP
#define LAB6_23_2_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &,int,int);
void cargar_alumnosOrdenado(const char * str, int *arr, char *text, int &n_alumnos);
void insertar_ordenado(int * codigos, char * escalas, int &n_alumnos, int codigo, char escala);
void cargar_cursosOrdenado(const char * str, int * arr, char ** nombre_curso, double * precio_credito, int &n_cursos);
char *leerCadenaExacta(ifstream &);
void insertar_ordenado2(int * codigo_curso, char ** nombre_curso, double * precio_credito, int &n_cursos, int codigo, double credito,
                       char * nombre);
void cargar_escalas(const char * str, int * arr, int * semestre, char * text, double * precio_credito, int &n_escalas);
void llenarArreglos(const char *matricula, int anio, int ciclo, int *codigo_alumnos,
                    char *escalas, int n_alumnos, int *codigo_curso, double *NumCredito,
                    int n_cursos, int *year, int *semestre, char *Escalas,
                    double *PrecioCredito,double *cantCreditos,
                    int n_escalas,int *cantCursos,double *MontoPagado);
int BuscarBinariaAlumno(int *codigo_alumnos, int n_alumnos,
                         int codigo_alumno);
void imprimir_reporte(const char*,const char * str, const char * text, int * arr, char * string, int n_alumnos, double * cant_creditos,
                     int * cant_cursos, double * monto_pagado,int,int);
char * modificaTexto(char *cadena1,char *cadena2);
void cargarApellidos(ifstream & leer, char ** apellido,int &n_apellidos);
void cargarNombres(ifstream & leer, int * codAlumno, char ** nombre,int &n_nombres);
#endif //LAB6_23_2_FUNCIONES_HPP