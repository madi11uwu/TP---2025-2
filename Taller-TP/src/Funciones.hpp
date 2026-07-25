//
// Created by Madi on 10/10/2025.
//

#ifndef TALLER_TP_FUNCIONES_HPP
#define TALLER_TP_FUNCIONES_HPP
#include "Utils.hpp"
void cargarLibros(const char*,int *codigo_libro,double *precio_libro,int &n_libros);
void probarLibros(const char*,int *codigo_libro,double *precio_libro,int n_libros);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimirEncabezado(ofstream &);
void imprimirLinea(int,char,ofstream &);
void ignorar(ifstream &,char);
void imprimirEncabezado(ofstream &);
void imprimirEncabezadoSecundario(ofstream &write);
void generarArreglos(const char*,double *promCalificacion,int *unidadesVendidos,
                    double *TotalVentas,int *FechaPrimeraVenta,int *DNIPrimeraVenta,
                    int *FechaUltimaVenta,int *DNIUltimaVenta,int n_libros,
                    int *codigo_libro,double *precio_libro);
void ordenarArreglos(int *codigo_libro,double *precio_libro,int n_libros);
void swapInt(int &a,int &b);
void swapDouble(double &a,double &b);
void llenar_arreglos(ifstream &,double *promCalificacion,int *unidadesVendidos,
                        double *TotalVentas,int *FechaPrimeraVenta,int *DNIPrimeraVenta,int *FechaUltimaVenta,
                        int *DNIUltimaVenta,int n_libros,int codigo,double *precio_libro,int);
int AlmacenarFecha(ifstream &);
void imprimir_fecha(int,ofstream &);
void imprimir_reporte(const char*reporte,int *codigo_libro,double *precio_libro,int n_libros,
                      double *promCalificacion,int *unidadesVendidos,
                      double *TotalVentas,int *FechaPrimeraVenta,int *DNIPrimeraVenta,
                      int *FechaUltimaVenta,int *DNIUltimaVenta);
#endif //TALLER_TP_FUNCIONES_HPP