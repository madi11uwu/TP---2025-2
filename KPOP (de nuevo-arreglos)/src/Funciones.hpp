//
// Created by Madi on 28/09/2025.
//

#ifndef KPOP__DE_NUEVO_ARREGLOS__FUNCIONES_HPP
#define KPOP__DE_NUEVO_ARREGLOS__FUNCIONES_HPP
#include "Utils.hpp"
void cargar_artistas(const char*,int *int_artista,double *rating,int &n_artistas);
void probar_artistas(const char*,int *int_artista,double *rating,int n_artistas);
void cargar_canciones(const char *,int *codigo_canciones,int *duracion,int &n_canciones);
void probar_canciones(const char *,int *codigo_canciones,int *duracion,int n_canciones);
void apertura_lectura(ifstream &,const char *);
void apertura_escritura(ofstream &,const char *);
void ignorar(ifstream &leer,char car);
int AlmacenarFecha(ifstream &leer);
void imprimir_linea (int n,char c,ofstream &write);
int AlmacenarDuracion(ifstream &leer);
void imprimir_duracion (ofstream &write,int duracion,char c) ;
int BuscarInfo(int *arreglo,int n,int busqueda);
void procesarDatosReproducciones(const char *repro, int *int_artista, int *codigo_canciones, int *reproduccionesArtista,
                                int *reproduccionesCanciones, int *fecha_registroCanciones, int *duracion,
                                int *tiempoTotalReproduccionCancion, double *GananciaPorArtista,
                                int n_artistas, int n_canciones, double tarifa);
void imprimir_reporte(const char*,int *int_artista,double *rating,int *codigo_canciones,int *duracion,int *reproduccionesArtista,
                    int *reproduccionesCanciones,int *fecha_registroCanciones,int *tiempoTotalReproduccionCancion,double *GananciaPorArtista,
                    int n_canciones,int n_artistas,double tarifa);
void imprimir_encabezado(ofstream &write,double tarifa);
void imprimir_encabezadoArtista(ofstream &write);
void imprimir_encabezadoCanciones(ofstream &write);
void imprimir_fecha(ofstream &write,int fecha);
#endif //KPOP__DE_NUEVO_ARREGLOS__FUNCIONES_HPP