//
// Created by Madi on 21/09/2025.
//

#include "Funciones.hpp"

void ProcesarDatos(const char *cartelera, const char *clientes, const char *salida) {
    ifstream leer_cartelera;
    ifstream leer_clientes;
    apertura_lectura(cartelera,leer_cartelera);
    apertura_lectura(clientes,leer_clientes);
    ofstream write;
    apertura_escritura(salida,write);
    leer_clientes.close();
    leer_cartelera.close();
    write.close();
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
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

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/2)<<""<<"LISTADO DE PELICULAS A LAS QUE PODRIAN ASISTIR LOS SOLICITANTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_nombre(ifstream &leer, ofstream &write) {
    leer>>ws;
    char c;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (c=='_') c=' ';
        write.put(c);
    }
}

int almacenarDuracion(ifstream &leer) {
    int h,m,s;
    char c;
    leer>>h>>c>>m>>c>>s;
    return (h*3600+m*60+s);
}

void imprimir_duracion(ofstream &write,int duracion) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

void imprimir_reporte(ofstream &write,ifstream &leer_cartelera,ifstream &leer_clientes) {
    int distrito1,distrito2,hora,duracion,DNI,i;
    char alimentos;
    while (true) {
        leer_clientes>>distrito1;
        if (leer_clientes.eof())break;
        leer_clientes>>distrito2;
        hora=almacenarDuracion(leer_cartelera);
        duracion=almacenarDuracion(leer_clientes);
        leer_cartelera>>ws>>alimentos>>DNI;
        write<<i<<")"<<setw(5)<<""<<DNI<<setw(5)<<"";
        imprimir_nombre(leer_cartelera,write);
        write<<setw(7)<<""<<"DISTRITO: "<<distrito1<<" - ";
        i++;
    }
}

void BuscarImprimirDistrito(ifstream &leer_cartelera,ofstream &write,int distrito) {

}