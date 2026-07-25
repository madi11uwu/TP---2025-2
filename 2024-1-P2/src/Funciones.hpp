//
// Created by Madi on 12/10/2025.
//

#ifndef INC_2024_1_P2_FUNCIONES_HPP
#define INC_2024_1_P2_FUNCIONES_HPP
#include "Utils.hpp"
void cargarPacientes(const char*,int *DNIPacientes,int *codigo_distrito,
                    int *anioNacimiento,double *descuento,int &n_pacientes);
void probarPacientes(const char*,int *DNIPacientes,int *codigo_distrito,
                    int *anioNacimiento,double *descuento,int n_pacientes);
void cargarMedicinas(const char*,int *codigo_medicina,double *precio_medicina,int &n_medicina);
void probarMedicinas(const char*,int *codigo_medicina,double *precio_medicina,int n_medicina);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezado(ofstream &);
void imprimirEncabezado1(ofstream &write);
void ignorar(ifstream &,char);
void GenerarArreglos(const char *citas, int *DNIPacientes, int *codigo_distrito,
                    int *anioNacimiento, double *descuento,
                    int n_pacientes, int *codigo_medicina,
                    double *precio_medicina, int n_medicina,
                    int *cantCitas,int *cantMedicinas,double *pagoMedicinas);
int AlmacenarFecha(ifstream &leer);
int AlmacenarDuracion(ifstream &leer);
int BuscarPaciente(int *DNIPacientes,int n_pacientes,int DNILeido) ;
void swapInt (int &a,int &b);
void swapDouble (double &a,double &b);
void ordenarArreglos(int *DNIPacientes, int *codigo_distrito, int *anioNacimiento,
                    double *descuento,int n_pacientes,int *cantCitas,int *cantMedicinas,
                    double *pagoMedicinas);
char DevolverClasificacion(int anio);
void imprimir_reporte(const char*reporte,int *DNIPacientes, int *codigo_distrito, int *anioNacimiento,
                    double *descuento,int n_pacientes,int *cantCitas,int *cantMedicinas,
                    double *pagoMedicinas);

#endif //INC_2024_1_P2_FUNCIONES_HPP