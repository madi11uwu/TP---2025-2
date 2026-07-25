//
// Created by Madi on 16/11/2025.
//

#ifndef INC_2025_1_LAB9_FUNCIONES_HPP
#define INC_2025_1_LAB9_FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
char *leer_str(ifstream &,int,char);
char *asignar_str(const char*);
int leer_int(ifstream &write);
double leer_double(ifstream &write);
int almacenarFecha(ifstream &);
void imprimirFecha(int fecha,ofstream &);
char *modificarTexto(char *cadena);
void llenarTabla(const char * str, struct TablaDeInfracciones *&tabla_de_infracciones, int &n_tabla);
void cargarEmpresas(const char * str, struct EmpresasRegistradas *&empresas_registradas, int &n_empresas_registradas);
void CompletarEmpresas(const char * str, struct EmpresasRegistradas * empresas_registradas, int n_empresas_registradas);
int BuscarEmpresa(int dni,struct EmpresasRegistradas *empresa,int n_empresas);
void completarEmpresas(const char * str, struct EmpresasRegistradas * empresas_registradas, struct TablaDeInfracciones * tabla_de_infracciones, int n_empresas_registradas, int n_tabla);
int almacenarFecha(int dd,int mm,int aa);
int BuscarEmpresa2(char * placa, struct EmpresasRegistradas * empresas_registradas, int n_empresas_registradas);
void llenarArreglos(int pos, int posInfraccion, struct EmpresasRegistradas *empresas_registradas,
                    struct TablaDeInfracciones *tabla_de_infracciones,
                    bool pago, char *placa, char *infraccion, int fechaPago, int fecha);
void ordenarEmpresas(struct EmpresasRegistradas *empresas,int n);
void swapStructEmpresas(struct EmpresasRegistradas &a,struct EmpresasRegistradas &b);
void swapStructInfraccion(struct InfraccionCometida &a,struct InfraccionCometida &b);
void imprimir_reporte(const char *file,struct EmpresasRegistradas * empresas_registradas, struct TablaDeInfracciones * tabla_de_infracciones, int n_empresas_registradas, int n_tabla);
void imprimir_encabezado(ofstream &write);
void imprimir_linea(int,char,ofstream &);
void imprimirPrimeraParte(ofstream &write, int dni, char *nombre,
                          char *distrito, char **placas,int i);
void imprimirSegundoEncabezado(ofstream &write,char c);
void imprimirTotales(double total,ofstream &write,char c);
void imprimirSegundaParte(ofstream &write, struct InfraccionCometida *infraccion,int cantidadDeInfracciones,int &n);
#endif //INC_2025_1_LAB9_FUNCIONES_HPP