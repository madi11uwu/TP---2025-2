//
// Created by Madi on 12/10/2025.
//

#ifndef INC_2023_2_P1_FUNCIONES_HPP
#define INC_2023_2_P1_FUNCIONES_HPP
#include "Utils.hpp"
void GenerarReporte(const char*,const char*,
                    const char*,const char*,
                    const char*);
void apertura_lectura(const char*,ifstream &);
void apertura_escritura(const char*,ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimirEncabezado(int,int,ofstream &);
void leer_nombres(ifstream &,ofstream &,char,char);
void imprimirParteEstatica(ifstream &leer_alumnos,ofstream &write,int codigo,char &escala);
void BuscarNombreyNumeroCreditos(ifstream &leer_cursos,ofstream &write,double &numCreditos,int codigo);
void BuscarValorCredito(ifstream &leer_escalas,int año,int ciclo,char escala,double &valorCredito);
void imprimirDatosDinamicos(ifstream &leer_escalas,ifstream &leer_cursos,
                            ofstream &write,int nro_curso,int codigo,double &numCreditos,
                            int año,int ciclo,char escala,double &valorCredito,
                            double &montoPagoCurso);
void imprimirParteDinamica(ifstream &leer_cursos,ifstream &leer_escalas,ifstream &leer_matricula
                            ,ofstream &write,int codigo,char escala,double &creditosAlumno,
                            double &montoAlumno,int año,int ciclo);
void imprimir_reporte(ifstream &leer_alumnos,ifstream &leer_cursos,
                        ifstream &leer_escalas,
                        ifstream &leer_matricula,ofstream &write,int,int);
void imprimirEstadisticaAlumno(double creditoAlumno,double montoAlumno,ofstream &write);
#endif //INC_2023_2_P1_FUNCIONES_HPP