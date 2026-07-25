//
// Created by User on 7/10/2025.
//
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Funciones.hpp"
#define NO_ENCONTRADO -1
#define MAX 80

void llenarArrCanales(const char *nombArch,
                      char *arrCarCodCanal, int *arrNumCodCanal, double *arrRatingCanal,
                      int &cant) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "ERROR";
        exit(1);
    }

    int num;
    char carCod, car;
    double rating;

    while (true) {
        arch >> num;
        if (arch.eof())break;
        while (arch.get() != ' ');
        arch >> carCod >> num;
        arch >> ws;
        while (arch.get() != ' ');
        arch >> rating;

        arrCarCodCanal[cant] = carCod;
        arrNumCodCanal[cant] = num;
        arrRatingCanal[cant] = rating;
        cant++;
    }
}

void llenarArrEtiquetas(const char *nombArch,
                        int *arrCodEtiquetas, int *arrDuracionEtiquetas,
                        int &cant) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "ERROR";
        exit(1);
    }

    int cod, min, seg;
    char car;
    while (true) {
        arch >> cod;
        if (arch.eof())break;
        arch >> ws;
        while (arch.get() != ' ');
        arch >> min >> car >> seg;
        int duracion = min * 60 + seg;
        arrCodEtiquetas[cant] = cod;
        arrDuracionEtiquetas[cant] = duracion;
        cant++;
    }
}

void llenarArrEtiquetasXCanal(const char *nombArch,
                              char *arrCarCodEtiquetaxCanal,
                              int *arrNumCodEtiquetaxCanal, int *arrCodEtiquetaxCanal,
                              int &cant) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "ERROR";
        exit(1);
    }

    int codCanal, codEtiqueta;
    char car;
    while (true) {
        arch >> car;
        if (arch.eof())break;

        arch >> codCanal >> codEtiqueta;

        arrCarCodEtiquetaxCanal[cant] = car;
        arrNumCodEtiquetaxCanal[cant] = codCanal;
        arrCodEtiquetaxCanal[cant] = codEtiqueta;
        cant++;
    }
}


void llenarArrAuxiliareas(const char *nombArch,
                          char *arrCarCodEtiquetaxCanal,
                          int *arrNumCodEtiquetaxCanal,
                          int *arrCodEtiquetaxCanal,
                          int cantEtiquetasXCanal,
                          int *arrNumeroTotalReproducciones,
                          int *arrTotalDuracion,
                          int *arrCodEtiquetas, int *arrDuracionEtiquetas,
                          int cantEtiquetas) {
    ifstream arch(nombArch, ios::in);
    if (!arch.is_open()) {
        cout << "ERROR";
        exit(1);
    }

    int codCanal, codEtiqueta, cantReproducciones;
    char carCanal;

    while (true) {
        arch >> codCanal;
        if (arch.eof())break;
        while (arch.get() != ' ');
        arch >> carCanal >> codCanal; //CODIGO CANAL
        arch >> codEtiqueta;
        //EN ESTE PUNTO TENEMOS AMBOS CODIGOS
        int pos = buscarRelacion(carCanal, codCanal, codEtiqueta,
                                 arrCarCodEtiquetaxCanal,
                                 arrNumCodEtiquetaxCanal,
                                 arrCodEtiquetaxCanal,
                                 cantEtiquetasXCanal); //BUSCAMOS EL POS EN EL RASCACIECLOS/RELACION
        if (pos != NO_ENCONTRADO) {
            arch >> cantReproducciones;
            //PROCEDEMOS A ACTUALIZAR, TENEMOS EL POS, EL PISO DEL RASCACIELOS
            arrNumeroTotalReproducciones[pos] += cantReproducciones;
            int posEtiqueta = buscarEtiqueta(codEtiqueta, arrCodEtiquetas, cantEtiquetas);
            if (posEtiqueta != NO_ENCONTRADO) {
                arrTotalDuracion[pos] += arrDuracionEtiquetas[posEtiqueta];
            }
        } else {
            while (arch.get() != '\n');
        }
    }
}

int buscarEtiqueta(int codEtiqueta, int *arrCodEtiquetas, int cantEtiquetas) {
    for (int i = 0; i < cantEtiquetas; i++) {
        if (arrCodEtiquetas[i] == codEtiqueta)return i;
    }
    return NO_ENCONTRADO;
}

int buscarRelacion(char carCanal, int codCanal, int codEtiqueta,
                   char *arrCarCodEtiquetaxCanal,
                   int *arrNumCodEtiquetaxCanal,
                   int *arrCodEtiquetaxCanal, int cantEtiquetasXCanal) {
    for (int i = 0; i < cantEtiquetasXCanal; i++) {
        if (carCanal == arrCarCodEtiquetaxCanal[i] and
            codCanal == arrNumCodEtiquetaxCanal[i] and
            codEtiqueta == arrCodEtiquetaxCanal[i])
            return i;
    }
    return NO_ENCONTRADO;
}

int buscarCanal(char carCodEtiquetaxCanal, int numCodEtiquetaxCanal,
                char *arrCarCodCanal, int *arrNumCodCanal, int cantCanales) {
    for (int i = 0; i < cantCanales; i++) {
        if (carCodEtiquetaxCanal == arrCarCodCanal[i] and
            numCodEtiquetaxCanal == arrNumCodCanal[i])
            return i;
    }
    return NO_ENCONTRADO;
}

void elaborarReporte(const char *nomb,
                     char *arrCarCodCanal, int *arrNumCodCanal, double *arrRatingCanal,
                     int cantCanales,
                     int *arrCodEtiquetas, int *arrDuracionEtiquetas,
                     int cantEtiquetas,
                     char *arrCarCodEtiquetaxCanal,
                     int *arrNumCodEtiquetaxCanal, int *arrCodEtiquetaxCanal,
                     int cantEtiquetasXCanal,

                     int *arrNumeroTotalReproducciones,
                     int *arrTotalDuracion) {
    ofstream arch(nomb, ios::out);
    if (!arch.is_open()) {
        cout << "ERROR";
        exit(1);
    }

    arch << setw(30) << "PLATAFORMA TP_Twitch" << endl;
    imprimirLinea(arch, '=');

    for (int i = 0; i < cantEtiquetas; i++) {
        //RECORREMOS UNA POR UNA LAS ETIQUETAS
        arch << "ETIQUETA No. " << i + 1 << endl;
        arch << setw(5) << " " << "CODIGO: " << arrCodEtiquetas[i] << endl;
        arch << setw(5) << " " << "DURACION: " << arrDuracionEtiquetas[i] << endl;
        imprimirLinea(arch, '-');
        int codigoEtiqueta = arrCodEtiquetas[i];
        imprimirCanalesDondeSeReproduce(arrCarCodCanal, arrNumCodCanal, arrRatingCanal, cantCanales,

                                        arrCarCodEtiquetaxCanal,
                                        arrNumCodEtiquetaxCanal, arrCodEtiquetaxCanal,
                                        cantEtiquetasXCanal,

                                        arrNumeroTotalReproducciones, arrTotalDuracion,
                                        codigoEtiqueta, arch);
    }
}

void imprimirCanalesDondeSeReproduce(char *arrCarCodCanal, int *arrNumCodCanal,
                                     double *arrRatingCanal, int cantCanales,

                                     char *arrCarCodEtiquetaxCanal,
                                     int *arrNumCodEtiquetaxCanal, int *arrCodEtiquetaxCanal,
                                     int cantEtiquetasXCanal,

                                     int *arrNumeroTotalReproducciones, int *arrTotalDuracion,
                                     int codigoEtiqueta, ofstream &arch) {
    int totalRepro = 0,totalDuracion=0;
    imprimirSubtitulos(arch);
    int contador = 1;
    for (int i = 0; i < cantEtiquetasXCanal; i++) {
        //RECORREMOS EL RASACACIELOS BUSCANDO LOS CANALES
        //EN i TENGO EL PISO
        int codEtiquetaXCanal = arrCodEtiquetaxCanal[i];
        if (codEtiquetaXCanal == codigoEtiqueta) {
            //SIGNIFICA QUE ENCONTRE EL PISO DONDE ME INTERESA EL CANAL
            char carCodEtiquetaxCanal = arrCarCodEtiquetaxCanal[i];
            int numCodEtiquetaxCanal = arrNumCodEtiquetaxCanal[i];
            arch << contador << ")" << setw(3) << " "
                    << carCodEtiquetaxCanal << numCodEtiquetaxCanal;
            contador++;
            int posCanal = buscarCanal(carCodEtiquetaxCanal, numCodEtiquetaxCanal,
                                       arrCarCodCanal, arrNumCodCanal, cantCanales);
            if (posCanal != NO_ENCONTRADO) {
                double rating = arrRatingCanal[posCanal];
                arch << setw(3) << " " << rating
                        << setw(8) << " " << arrNumeroTotalReproducciones[i]
                        << setw(8) << " " << arrTotalDuracion[i] << endl;
                totalRepro+=arrNumeroTotalReproducciones[i];
                totalDuracion+=arrTotalDuracion[i];
            }
        }
    }
    imprimirLinea(arch, '-');
    arch<<setw(3)<<" "<<"RESUMEN DE LA ETIQUETA: "<<endl;
    arch<<setw(3)<<" "<<"TOTAL DE REPRODUCCIONES: "<<totalRepro<<endl;
    arch<<setw(3)<<" "<<"TIEMPO TOTAL REPRODUCIDO: "<<totalDuracion<<endl;
    imprimirLinea(arch, '=');

}

void imprimirSubtitulos(ofstream &arch) {
    arch << setw(5) << " " << "CANALES DONDE SE REPRODUCE: " << endl;
    arch << setw(10) << " " << "RATING DE " << setw(5) << " " << "NUMERO TOTAL"
            << setw(5) << " " << "TOTAL DE " << endl;
    arch << "No" << setw(3) << " " << "CODIGO"
            << setw(3) << " " << "CALIDAD"
            << setw(3) << " " << "DE REPRODUCCIONES"
            << setw(3) << " " << "REPRODUCCIONES" << endl;
}

void imprimirLinea(ofstream &arch, char car) {
    for (int i = 0; i < MAX; i++) {
        arch << car;
    }
    arch << endl;
}