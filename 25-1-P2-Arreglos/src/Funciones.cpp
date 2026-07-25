//
// Created by Madi on 13/10/2025.
//

#include "Funciones.hpp"

void cargarInfracciones(const char *infracciones, char *c_infraccion,
                        int *int_infraccion,double *multa, int &n_infraccion) {
    ifstream leer_infracciones;
    apertura_lectura(infracciones,leer_infracciones);
    char c;
    while (true) {
        leer_infracciones >> c;
        if (leer_infracciones.eof()) break;
        c_infraccion[n_infraccion] = c;
        leer_infracciones>>int_infraccion[n_infraccion];
        leer_infracciones>>multa[n_infraccion];
        ignorar(leer_infracciones,'\n');
        n_infraccion++;
    }
}

void probarInfracciones(const char *reporte_infracciones, char *c_infraccion, int *int_infraccion, double *multa, int n_infraccion) {
    ofstream write;
    apertura_escritura(reporte_infracciones,write);
    int i=0;
    write<<"TABLA DE INFRACCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(10)<<""<<"CODIGO DE INFRACCION";
    write<<setw(20)<<""<<"MULTA"<<endl;
    while (i<n_infraccion) {
        write<<setw(10)<<""<<c_infraccion[i]<<int_infraccion[i];
        write<<setw(20)<<""<<multa[i]<<endl;
        i++;
    }
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTES"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE INFRACCIONES TOTALIZADAS POR PLACA"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimirEncabezadoSecundario(ofstream &write) {
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"MULTAS PAGADAS";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"MULTAS PENDIENTES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"MULTAS TOTALES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void ignorar(ifstream &leer, char c) {
    leer>>ws;
    char car;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

