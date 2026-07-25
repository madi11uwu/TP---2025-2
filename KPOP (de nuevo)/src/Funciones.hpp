//
// Created by Madi on 27/09/2025.
//

#ifndef KPOP__DE_NUEVO__FUNCIONES_HPP
#define KPOP__DE_NUEVO__FUNCIONES_HPP
#include "Utils.hpp"
void cargar_artistas(int *fecha_artista,int *codigo_int_artista,double *rating_artista,int &n_artistas,const char*);
void probar_artistas(int *fecha_artista,int *codigo_int_artista,double *rating_artista,int n_artistas,const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea (int,char,ofstream &);
int AlmacenarFecha(ifstream &leer);
void ignorar(ifstream &leer,char car);
void imprimir_fecha(ofstream &write,int fecha);
void cargar_canciones(int *codigo_cancion,int *duracion_cancion,int &n_canciones,const char*);
void probar_canciones(int *codigo_cancion,int *duracion_cancion,int n_canciones,const char*);
int Almacenar_duracion(ifstream &leer) ;
void imprimir_duracion(int duracion,ofstream &write,char c);
void ordenarInformacion(int *fecha_registro,int *reproducciones,int *reproduccionesTotalesTiempo,double *gananciasRepro,int *codigo_cancion,int *codigo_int_artista,
        int n_canciones,int n_artistas,int *);
void BuscarFechaYRepro(int *fecha_registro,int *reproducciones,int *codigo_cancion,const char *fileRepro,
    int n_canciones);
#endif //KPOP__DE_NUEVO__FUNCIONES_HPP