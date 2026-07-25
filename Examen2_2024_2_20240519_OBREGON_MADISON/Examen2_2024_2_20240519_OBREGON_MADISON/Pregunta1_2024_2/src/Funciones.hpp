//
// Created by Madi on 30/11/2025.
//

#ifndef PREGUNTA1_2024_2_FUNCIONES_HPP
#define PREGUNTA1_2024_2_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
char *leer_cadena(int,char,ifstream &);
int leer_int(ifstream &);
double leer_double (ifstream &);
int almacenarHora(ifstream &);
void imprimirHora(int,ofstream &);
void cargarPalabra(const char * str, struct Palabra *lexicon, int&n_lexicon);
void cargarPlato(const char * str, struct Plato *&plato, int&n_platos);
void cargarAtencion(const char * str, struct Atencion *atenciones, int &n_atencion, struct Plato * plato,int);
char *asignar_cadena(const char *);
void CompletarAtencion(const char * str, struct Atencion * atencions, struct Palabra * lexicon, int n_atencion, int n_lexicon);
bool esMinusOMayus(char c);
char * PreProcesar(char * oracion);
void completarPalabras(struct Comentario & comentario, struct Palabra * palabra, int n_lexicon, char * oracion_procesada);
void imprimirReporte(const char * str, struct Atencion * atencions, int n_atencion);
void imprimirLinea(int,char,ofstream &);
#endif //PREGUNTA1_2024_2_FUNCIONES_HPP