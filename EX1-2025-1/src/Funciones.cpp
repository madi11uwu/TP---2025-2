//
// Created by Madi on 11/10/2025.
//

#include "Funciones.hpp"

void GenerarReporte(const char *empresas, const char *infracciones, const char *placas,
                    const char *tabla, const char *reporte) {
    ifstream leer_empresas;
    ifstream leer_infracciones;
    ifstream leer_placas;
    ifstream leer_tablaDeInfracciones;
    ofstream write;
    apertura_lectura(empresas,leer_empresas);
    apertura_lectura(infracciones,leer_infracciones);
    apertura_lectura(placas,leer_placas);
    apertura_lectura(tabla,leer_tablaDeInfracciones);
    apertura_escritura(reporte,write);
    imprimir_reporte(write,leer_empresas,leer_infracciones,leer_placas,
                    leer_tablaDeInfracciones);
    leer_empresas.close();
    leer_infracciones.close();
    leer_placas.close();
    leer_tablaDeInfracciones.close();
    write.close();
}

void apertura_lectura(const char *file,ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file,ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_linea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTE"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE ESTADO DE MULTAS POR COMPANIA"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimirDatosEstaticos(ofstream &write,ifstream &leer_empresas,int nroCompania,int DNI) {
    write<<"COMPANIA No. "<<nroCompania<<endl;
    write<<"REPRESENTANTE LEGAL: ";
    leer_nombres(leer_empresas,write,'N',' ');
    write<<setw(8)<<""<<"DNI: "<<DNI;
    write<<setw(5)<<""<<"DISTRITO: ";
    leer_nombres(leer_empresas,write,'D','\n');
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void leer_nombres(ifstream &leer,ofstream &write,char c,char c1) {
    leer>>ws;
    char car;
    if (c=='D') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            if (car=='_')car=' ';
            write.put(car);
        }
    }
    else if (c=='N') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            if (car>='a' and car<='z') car=car-32;
            if (car=='/' or car=='-')car=' ';
            write.put(car);
        }
    }
}

void imprimir_reporte(ofstream &write,ifstream &leer_empresas,
                        ifstream &leer_infracciones,ifstream &leer_placas,
                        ifstream &leer_tablaDeInfracciones) {
    imprimirEncabezado(write);
    int DNI,nroCompania=1;
    while (true) {
        leer_empresas>>DNI;
        if (leer_empresas.eof())break;
        imprimirDatosEstaticos(write,leer_empresas,nroCompania,DNI);
        nroCompania++;
    }
}

void imprimirDatosDinamicos(ofstream &write,ifstream &leer_placas,ifstream &leer_infracciones,
                            ifstream &leer_tabla,int DNI) {

}