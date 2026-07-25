//
// Created by Madi on 13/10/2025.
//

#ifndef YOUTUBEEJERCICIO_FUNCIONES_HPP
#define YOUTUBEEJERCICIO_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(int,ofstream &);
void cargarVideos(const char*,int *codigo_video,
                    int *duracion,int *codigo_idioma,int &n_videos);
void probarVideos(const char*,int *codigo_video,
                    int *duracion,int *codigo_idioma,int n_videos);
int AlmacenarDuracion(ifstream &);
void imprimirDuracion(int,ofstream &);
void ignorar(ifstream &,char);
void GenerarArreglos(const char*,int *codigo_video,
                    int *duracion,int *codigo_idioma,int n_videos);
int BuscarVideo(int *codigo_video,int n_videos,int codigo);
void swapInt(int &a,int &b);
void swapDouble(double &a,double &b);
void ordenarArreglos(int *codigo_video, int *duracion,
                    int *codigo_idioma, int n_videos,int *UltimaFecha,
                    int *FechaAntigua,int *veces,double *sumaRating,
                    double *sumatasas);
void imprimirEncabezado(ofstream &);
void imprimirSegundoEncabezado(ofstream &);
void GenerarArreglos(const char *canales, int *codigo_video,
                    int n_videos,int *UltimaFecha,
                    int *FechaAntigua,int *veces,double *sumaRating,
                    double *sumatasas);
void imprimirReporte(const char*reporte,int *codigo_video, int *duracion,
                     int *codigo_idioma, int n_videos,int *UltimaFecha,
                     int *FechaAntigua,int *veces,double *sumaRating,
                     double *sumatasas);
#endif //YOUTUBEEJERCICIO_FUNCIONES_HPP