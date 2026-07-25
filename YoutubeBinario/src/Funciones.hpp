//
// Created by Madi on 27/10/2025.
//

#ifndef YOUTUBEBINARIO_FUNCIONES_HPP
#define YOUTUBEBINARIO_FUNCIONES_HPP
#include "Utils.hpp"
void cargar_ordenado_videos(const char * str, int * arr, int * duracion_video, int * codigo_idioma, char * text, int * int_categoria,
                           int &n_videos);
void apertura_lectura(const char *,ifstream &);
void apertura_escritura(const char *,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
int almacenar_duracion(ifstream &leer);
int almacenar_fecha(ifstream &l);
void insertar_ordenado( int *codigo_video, int *duracion_video, int *codigo_idioma,
                       char *char_categoria, int *int_categoria,
                       int &n_videos, int codigo, int duracion,
                       int idioma,
                       char c_categoria, int categoria_int) ;
void probar_videos(const char *reporte_videos, int *codigo_video, int *duracion_video,
                   int *codigo_idioma,
                   char *char_categoria, int *int_categoria,
                   int n_videos);
void imprimir_duracion(int duracion,ofstream &write);
void imprimir_fecha(int fecha,ofstream &write);
void llenarArreglos(const char *canales, int *codigo_video,
                    int n_videos,int *ReproAntigua,int *ReproReciente,int *cantVideo,
                    double *sumaRating,double *sumaTasa);
void ignorar(ifstream &leer,char c);
int BusquedaBinaria(int *codigo_video,
                    int n_videos,int codigo) ;
void imprimir_reporte(const char * str, int * arr, int * duracion_video, int * codigo_idioma, char * text, int * int_categoria,
                     int n_videos, int * repro_antigua, int * repro_reciente, int * cant_video, double * suma_rating, double * suma_tasa);
void imprimirEstadisticas(int mayorDuracion, int menorDuracion,
                          int mayorVideo, int menorVideo,ofstream &write);
#endif //YOUTUBEBINARIO_FUNCIONES_HPP