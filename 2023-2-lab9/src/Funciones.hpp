//
// Created by Madi on 17/11/2025.
//

#ifndef INC_2023_2_LAB9_FUNCIONES_HPP
#define INC_2023_2_LAB9_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
void imprimir_encabezado(char *,ofstream &);
void imprimir_linea(int,char,ofstream &);
char *leer_str(ifstream &,char,int);
char *asignar_str(const char *);
int leer_int(ifstream &);
double leer_double (ifstream &);
void cargarEscalas(const char * str, struct Escala *&escala, int &n_escala);
char leer_char(ifstream &);
void cargarCursos(const char*,struct Curso *&curso,int &n);
void LeerMatricula(const char * str, struct Curso * curso, struct Escala * escala, int n_escala, int n_curso,char*);

#endif //INC_2023_2_LAB9_FUNCIONES_HPP