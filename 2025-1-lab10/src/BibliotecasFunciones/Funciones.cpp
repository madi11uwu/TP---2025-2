//
// Created by Madi on 23/11/2025.
//

#include "Funciones.hpp"

void apertura_escritura(const char *file, ofstream &read) {
    read.open(file,ios::out);
    if (!read.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_lectura(const char *file, ifstream &write) {
    write.open(file,ios::in);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof())return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

char * asignar_cadena(const char *nombre) {
    char *str;
    str=new char[strlen(nombre)+1];
    strcpy(str,nombre);
    return str;
}

int leer_int(ifstream &read) {
    int n;
    read>>n;
    read.get();
    return n;
}

double leer_double(ifstream &read) {
    double n;
    read>>n;
    read.get();
    return n;
}

int devolverFecha(ifstream &read) {
    int dd,mm,yyyy;
    char c;
    read>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"BANCO DE LOS CLIENTES TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE LAS CUENTAS DE AHORROS DE NUESTROS CLIENTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"No."<<setw(5)<<""<<"CUENTA"<<setw(7)<<""<<"CLIENTE";
    write<<setw(15)<<""<<"SALDO"<<setw(6)<<""<<"SOBREGIRADA";
    write<<setw(4)<<""<<"FECHA DEL ULTIMO SOBREGIRO"<<endl;
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i=0;i<n;i++) {
        write.put(c);
    }
    write<<endl;
}

void imprimirFecha(int fecha,ofstream &write){
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(4)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

void imprimirEspacios(int ancho, int size, ofstream &write) {
    for (int i=0;i<ancho-size;i++) {
        write.put(' ');
    }
}
