//
// Created by Madi on 27/09/2025.
//

#ifndef EJERCICIOVARGAS__ARREGLOS__FUNCIONES_HPP
#define EJERCICIOVARGAS__ARREGLOS__FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado1(ofstream &);
void imprimir_encabezado2(ofstream &);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(ofstream &,int);
int AlmacenarHora(ifstream &);
void imprimir_hora(ofstream &,int);
void imprimir_hora(ofstream &,int);
void cargar_citasMedicas(const char*,int *fecha_cita,double *descuento,int *HoraInicial,int *,int &n_citasMedicas);
void probar_citasMedicas(const char*,int *fecha_cita,double *descuento,int *HoraInicial,int *,int n_citasMedicas);
void ignorar(ifstream &leer,char car);
void cargar_Medicos(const char *,int *codigos_medicos,double *Tarifas,int &n_medicos);
void probar_Medicos(const char *,int *codigos_medicos,double *Tarifas,int n_medicos);
void cargar_Medicinas(const char *,int *codigo_medicina,double *precio_medicina,int &n_medicinas);
void probar_Medicinas(const char *,int *codigo_medicina,double *precio_medicina,int n_medicinas);
#endif //EJERCICIOVARGAS__ARREGLOS__FUNCIONES_HPP