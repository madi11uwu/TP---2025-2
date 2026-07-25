//
// Created by Madi on 9/10/2025.
//

#ifndef CLASE_PRE_PARCIAL_FUNCIONES_HPP
#define CLASE_PRE_PARCIAL_FUNCIONES_HPP
#include "Utils.hpp"
void cargarVideos(const char*,int *codigoVideos,int *duracion,
                    int *codigoIdioma,int &n_videos);
void probarVideos(const char*,int *codigoVideos,int *duracion,
                    int *codigoIdioma,int n_videos);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
int AlmacenarDuracion(ifstream &);
void imprimir_duracion(int,ofstream &);
void ignorar(ifstream &,char);
void imprimir_linea(int,char,ofstream &);
void GenerarArreglos(const char*,int *RepAntigua,int *RepReciente,
                    double *promedioRating,double *promedioTasaAbandono,int*);
int AlmacenarFecha(ifstream &);
#endif //CLASE_PRE_PARCIAL_FUNCIONES_HPP