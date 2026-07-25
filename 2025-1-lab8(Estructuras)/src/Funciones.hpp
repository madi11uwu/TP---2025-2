//
// Created by Madi on 9/11/2025.
//

#ifndef INC_2025_1_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#define INC_2025_1_LAB8_ESTRUCTURAS__FUNCIONES_HPP
#include "Utils.hpp"
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void cargar_tablaDeInfracciones(const char*,struct TablaDeInfracciones * &tabla_de_infracciones, int &n_tabla_de_infracciones);
void cargar_empresasRegistradas(const char*,struct EmpresasRegistradas * &empresas_registradas, int &n_empresas_registradas);
char *leer_cadena(ifstream &,int,char);
char *asignar_cadena(const char *);
int leer_int(ifstream &);
double leer_double(ifstream &);
char *modificarCadena(char *cadena);
void LlenarPlacasDeEmpresas(const char * file, struct EmpresasRegistradas * empresas_registradas, int n_empresas_registradas);
int BuscarEmpresa(int n,EmpresasRegistradas *empresas_registradas,int DNI);
void CompletarEmpresasRegistradas(const char * str, struct EmpresasRegistradas * empresas_registradas,struct TablaDeInfracciones *, int n_empresas_registradas,int);
int almacenarFecha(int,int,int);
int BuscarInfraccion(char *codInfraccion,struct TablaDeInfracciones *tabla,int n);
int BuscarPlacaEnEmpresa(char * placa, struct EmpresasRegistradas * empresas_registradas, int n_empresas_registradas);
void ordenarEmpresas(struct EmpresasRegistradas *empresas,int n_empresas);
void swapStructEmpresa(struct EmpresasRegistradas &a,struct EmpresasRegistradas &b);
void swaprStructTabla(struct TablaDeInfracciones &a,struct TablaDeInfracciones &b);
void ordenarTabla(struct TablaDeInfracciones *tabla,int n_infracciones);
void imprimirReportePorFin(const char *, TablaDeInfracciones *tabla, int n_infracciones,
                           EmpresasRegistradas *empresas_registradas, int n_empresas);
void imprimir_fecha(ofstream &,int);
char *leer_cadena_exacta(ifstream &);
#endif //INC_2025_1_LAB8_ESTRUCTURAS__FUNCIONES_HPP