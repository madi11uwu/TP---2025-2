//
// Created by Madi on 10/11/2025.
//

#ifndef INC_2023_2_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#define INC_2023_2_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &,char *semestre);
void imprimir_linea(char,int,ofstream &);
void cargarAlumnos(const char * str, struct Alumno * &alumno, int &n_alumno);
void cargarCursos(const char * str, struct Curso * &curso, int &n_alumno);
void cargarEscalas(const char * str, struct Escala * &escala, int &n_escala);
char *leer_cadena(ifstream &,int n,char delim);
char leer_char(ifstream &);
int leer_int(ifstream &);
double leer_double(ifstream &);
char *asignarCadena(const char *);
void completarCursos(const char *str, struct Curso *curso, int n_curso,char *,
                     struct Escala *escala, int n_escala, struct Alumno *alumno,
                     int n_alumno);
int BuscarCurso(int cod,struct Curso *curso,int n);
int BuscarAlumno(int cod,struct Alumno *alumno,int n);
int BuscarEscala(char *semestre,char c,struct Escala *escala,int n);
void ordenarCursos(struct Curso *alumno,int n);
void swapStruct(struct Curso &a,struct Curso &b);
void imprimir_reporte(const char*, struct Escala *, struct Curso *,
                      struct Alumno *,int,int,int,char *);
char *modificarCadena(char *cadena);
void imprimirEspacios(int ,int,ofstream &);
#endif //INC_2023_2_LAB8_ESTRUCTURAS__FUNCIONES_HPP