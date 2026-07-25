//
// Created by Madi on 5/10/2025.
//

#include "Funciones.hpp"

void apertura_lectura(const char *file,ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse";
        exit(1);
    }
}

void apertura_escritura(const char *file,ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse";
        exit(1);
    }
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void ignorar(ifstream &leer, char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void cargar_Empresas(const char *empresas,int *DNI,int &n_empresas) {
    ifstream leer_empresas;
    apertura_lectura(empresas,leer_empresas);
    int DNIrepre;
    while (true) {
        leer_empresas>>DNIrepre;
        if (leer_empresas.eof())break;
        ignorar(leer_empresas,' ');
        ignorar(leer_empresas,'\n');
        DNI[n_empresas]=DNIrepre;
        n_empresas++;
    }
}

void probar_empresas(const char *reporteEmpresas,int *DNI,int n_empresas) {
    int i=0;
    ofstream write;
    apertura_escritura(reporteEmpresas,write);
    write<<"EMPRESAS REGISTRADAS:"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/4)<<""<<"DNI REPRESENTANTE"<<endl;
    while (i<n_empresas) {
        write<<setw(ANCHO_REPORTE/4)<<""<<DNI[i]<<endl;
        i++;
    }
}

void cargar_TablaInfracciones(const char *tabla, char *c_infraccion,
                            int *int_infraccion, double *multas,
                            int &n_tablaInfracciones) {
    ifstream leer_tablaInfracciones;
    apertura_lectura(tabla,leer_tablaInfracciones);
    char char_infraccion;
    while (true) {
        leer_tablaInfracciones>>char_infraccion;
        if (leer_tablaInfracciones.eof()) break;
        leer_tablaInfracciones>>int_infraccion[n_tablaInfracciones]>>multas[n_tablaInfracciones];
        c_infraccion[n_tablaInfracciones]=char_infraccion;
        ignorar(leer_tablaInfracciones,'\n');
        n_tablaInfracciones++;
    }
}

void probar_TablaInfracciones(const char *reporteInfracciones, char *c_infraccion,
                            int *int_infraccion, double *multas,
                            int n_tablaInfracciones) {
    ofstream write;
    apertura_escritura(reporteInfracciones,write);
    int i=0;
    write<<"TABLA DE INFRACCIONES:"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO DE INFRACCION";
    write<<setw(ANCHO_REPORTE/4)<<""<<"MULTA"<<endl;
    while (i<n_tablaInfracciones) {
        write<<setw(ANCHO_REPORTE/4)<<""<<c_infraccion[i]<<int_infraccion[i];
        write<<setw(ANCHO_REPORTE/3)<<""<<multas[i]<<endl;
        i++;
    }
}
