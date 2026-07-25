//
// Created by Madi on 12/10/2025.
//

#ifndef INC_2024_1_P1_FUNCIONES_HPP
#define INC_2024_1_P1_FUNCIONES_HPP
#include "Utils.hpp"
void GenerarReporteMedicina(const char*,const char*,const char*,const char*,const char*);
void apertura_lectura(const char*,ifstream &);
void aperuta_escritura(const char*,ofstream &);
void imprimir_encabezado(ofstream &);
void imprimir_linea(int,char,ofstream &);
void imprimir_reporte(ifstream &leer_citas,ifstream &leer_medicos,
                        ifstream &leer_medicinas,ifstream &leer_pacientes,
                        ofstream &write);
void leerNombres(ifstream &leer,ofstream &write,char c,char c1);
void imprimirDatosEstaticos(ifstream &leer_pacientes,ofstream &write,int DNI,double &descuento);
int AlmacenarDuracion(ifstream &leer);
void imprimir_duracion(int duracion,ofstream &write);
void imprimirPrimerEncabezadoDinamico(ofstream &write);
void imprimirSegundoEncabezadoDinamico(ofstream &write);
int AlmacenarFecha(ifstream &leer);
void imprimirFecha(int fecha,ofstream &write);
void BuscartarifaEImprimirNombreYEspecialidad(ifstream &leer_medicos,int codigo_medico,double &tarifa,ofstream &write);
void imprimirPrimeraParteDinamica(int fecha,int duracion,int codigo_medico,ifstream &leer_medicos,
                                ofstream &write,double &tarifa,double);
void BuscarDescripcionYPrecio(ifstream &leer_medicina,ofstream &write,int codigo_medicina,
                            double &precio);
void imprimirSegundaParteDinamica(ofstream &write,int codigo_medicina,
                                    int cantidad,int nro_medicina,double &pago,
                                    ifstream &leer_medicina,double descuento);
void imprimirParteDinamica(ifstream &leer_citas,ifstream &leer_medicinas,
                            ifstream &leer_medicos,ofstream &write,int DNI,
                            double descuento,double &pagoTotal);
#endif //INC_2024_1_P1_FUNCIONES_HPP