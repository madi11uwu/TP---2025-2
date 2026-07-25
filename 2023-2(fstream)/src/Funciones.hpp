//
// Created by Madi on 15/09/2025.
//

#ifndef INC_2023_2_FSTREAM__FUNCIONES_HPP
#define INC_2023_2_FSTREAM__FUNCIONES_HPP
#include "Utils.hpp"
void ProcesarDatosTelevidentes(const char *entrada,const char *salida);
void apertura_entrada(ifstream &leer,const char *entrada);
void apertura_salida(ofstream &write,const char *salida);
void imprimir_linea(int,char,ofstream&);
void imprimir_encabezado(ofstream&);
void imprimir_encabezadoEstatico(ofstream&);
int calcular_fecha(ifstream &leer);
void CamelizacionNombre(ifstream &leer,ofstream &write);
void imprimirCategoria_compañiaYSexo(char sexo,int fecha,char compañia,ofstream &write);
int leer_calcularDuracion(ifstream &leer);
void imprimir_duracion(int duracion,ofstream &write);
void almacenarDatosEstadisticas(int &cantMenoresYAdultos,int duracionT,char sexo,char compañia,int fecha,int &DuracionTotalMyA,int &cantMujeres,int &cantComA);
void leer_imprimir_Dinamicos(ifstream &leer,ofstream &write,int &DuracionCanal);
void imprimir_estadisticas(int cantMujeres,int cantMenoresYAdultos,int DuracionTotalMyA,int canal,ofstream &write,int cantMujeresA) ;
void imprimir_reporte(ofstream &write,ifstream &leer);
#endif //INC_2023_2_FSTREAM__FUNCIONES_HPP