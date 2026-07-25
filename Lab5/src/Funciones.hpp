//
// Created by User on 7/10/2025.
//

#ifndef LABORATORIO_5_2025_2_FUNCIONES_H
#define LABORATORIO_5_2025_2_FUNCIONES_H
void llenarArrCanales(const char *nombArch,
                      char *arrCarCodCanal, int *arrNumCodCanal, double *arrRatingCanal,
                      int &cant);
void llenarArrEtiquetas(const char *nombArch,
            int *arrCodEtiquetas,int *arrDuracionEtiquetas,
            int &cant) ;
void llenarArrEtiquetasXCanal(const char *nombArch,
                        char *arrCarCodEtiquetaxCanal,
                        int *arrNumCodEtiquetaxCanal, int *arrCodEtiquetaxCanal,
                        int &cant) ;
int buscarRelacion(char carCanal, int codCanal, int codEtiqueta,
                   char *arrCarCodEtiquetaxCanal,
                   int *arrNumCodEtiquetaxCanal,
                   int *arrCodEtiquetaxCanal, int cantEtiquetasXCanal);
int buscarEtiqueta(int codEtiqueta,int *arrCodEtiquetas,int cantEtiquetas);
void llenarArrAuxiliareas(const char *nombArch,
                         char *arrCarCodEtiquetaxCanal,
                         int *arrNumCodEtiquetaxCanal,
                         int *arrCodEtiquetaxCanal,
                         int cantEtiquetasXCanal,
                         int *arrNumeroTotalReproducciones,
                         int *arrTotalDuracion,
                         int *arrCodEtiquetas, int *arrDuracionEtiquetas,
                         int cantEtiquetas);
void imprimirLinea(ofstream &arch,char car) ;
void imprimirSubtitulos(ofstream &arch) ;
void imprimirCanalesDondeSeReproduce(char *arrCarCodCanal, int *arrNumCodCanal,
                                     double *arrRatingCanal, int cantCanales,

                                     char *arrCarCodEtiquetaxCanal,
                                     int *arrNumCodEtiquetaxCanal, int *arrCodEtiquetaxCanal,
                                     int cantEtiquetasXCanal,

                                     int *arrNumeroTotalReproducciones, int *arrTotalDuracion,
                                     int codigoEtiqueta, ofstream &arch);
void elaborarReporte(const char *nomb,
                     char *arrCarCodCanal, int *arrNumCodCanal, double *arrRatingCanal,
                     int cantCanales,
                     int *arrCodEtiquetas, int *arrDuracionEtiquetas,
                     int cantEtiquetas,
                     char *arrCarCodEtiquetaxCanal,
                     int *arrNumCodEtiquetaxCanal, int *arrCodEtiquetaxCanal,
                     int cantEtiquetasXCanal,

                     int *arrNumeroTotalReproducciones,
                     int *arrTotalDuracion) ;
#endif //LABORATORIO_5_2025_2_FUNCIONES_H