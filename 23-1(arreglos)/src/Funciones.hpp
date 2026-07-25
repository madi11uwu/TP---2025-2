//
// Created by Madi on 28/09/2025.
//

#ifndef INC_23_1_ARREGLOS__FUNCIONES_HPP
#define INC_23_1_ARREGLOS__FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_encabezado(ofstream &);
void cargarLibros(const char *,int *codigo_libro,double *precios,int &n_libros);
void probarLibros(const char *,int *codigo_libro,double *precios,int n_libros);
void imprimir_fecha(ofstream &write,int fecha);
void ignorar(ifstream &,char);
void cargarAutores(const char *,int *codigo_autor,int *libros_autor,double *porcentaje_regalias,int &n_autores);
void probarAutores(const char *,int *codigo_autor,int *libros_autor,double *porcentaje_regalias,int n_autores);
bool ValidarFecha(int fecha,int fecha1,int fecha2);
int AlmacenarFecha(ifstream &leer);
int Buscar(int *arreglo,int n,int busqueda);
void imprimir_encabezadoLibro(ofstream &write,int nro_libro);
void GenerarArreglos (const char*ventas,int *codigo_libro, double *precios, int n_libros,int *cantidadVentasLibros,
                        double *montoPorLibro,int fecha1,int fecha2);
void imprimir_reporte(const char*salida,int *codigo_libro, double *precios, int n_libros,int *cantidadVentasLibros,
                       double *montoPorLibro,int *codigo_autor,int *libros_autor,double *porcentaje_regalias,int n_autores,
                       int fecha1,int fecha2);
void imprimir_encabezadoAutores(ofstream &write);
void imprimir_datos(ofstream &write,int codigo_libro,int n_autores,int *codigo_autor,double *porcentaje_regalias,int *libros_autor,double *montoPorLibro,int libro);
#endif //INC_23_1_ARREGLOS__FUNCIONES_HPP