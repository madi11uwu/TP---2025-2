//
// Created by Madi on 1/12/2025.
//

#ifndef INC_2025_1_TALLER1_FUNCIONES_HPP
#define INC_2025_1_TALLER1_FUNCIONES_HPP
#include "Utils.hpp"
void cargarCursos(const char * str, struct NodoCurso *&lista);
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
int leer_int(ifstream &);
char *leer_cadena(int,char,ifstream &);
double leer_double (ifstream &);
void insertarNodo(struct NodoCurso *&lista, struct Curso curso);
void cargarEscala(const char * str, struct NodoEscala *&lista);
char leer_char(ifstream &);
void insertarNodoEscala(struct NodoEscala *&lista, struct Escala escala);
void cargarAlumnos(const char * str, struct NodoAlumno *&lista);
void insertarNodoAlumno(struct NodoAlumno *&lista,struct Alumno alumno);
void imprimirLinea(int,char,ofstream &);
void imprimirReporte(const char *str, struct NodoAlumno *nodo_alumno,
                     const char *text, const char *string, char str1,
                     int anio, int ciclo);
void CompletarAlumnos(const char * str, struct NodoAlumno * nodo_alumno, struct NodoCurso * nodo_curso, struct NodoEscala * nodo_escala, int anio, int ciclo);
void EliminarNodos(struct NodoAlumno * lista, int ciclo, int anio);

#endif //INC_2025_1_TALLER1_FUNCIONES_HPP