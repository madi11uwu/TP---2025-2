//
// Created by Madi on 4/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte(int fechaI,int fechaF) {
    imprimir_linea('*',119);
    imprimir_encabezado(fechaI,fechaF);
    imprimir_linea('=',119);
    leerLosDatos(fechaI,fechaF);


}

void imprimir_encabezado(int fechaI,int fechaF) {
    cout<<right<<setw(50)<<""<<"SPOTIFY PLATFORM"<<endl;
    cout<<right<<setw(33)<<""<<"REPORT FOR DATES BETWEEN: ";
    imprimir_fecha(fechaI);
    cout<<" AND ";
    imprimir_fecha(fechaF);
    cout<<endl;
}

void leer_username() {
    char c;
    cin>>ws;
    cout<<setw(19)<<"";
    while (true) {
        cin.get(c);
        if (c==' ') {
            break;
        }
        imprimirMayus(c);
    }
}

void leer_codigo() {
    char letra;
    int numero;
    cin>>ws;
    cin>>letra>>numero;
    cout<<letra<<setfill('0')<<setw(4)<<numero;
    cout<<setfill(' ');
}

void leer_reproducciones() {
    int repro;
    cin>>repro;
    cout<<setw(18)<<""<<repro;
}

void leer_fechacreada() {
    int dd,mm,yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    cout<<setw(20)<<""<<dd<<'/'<<mm<<'/'<<yyyy;
}

void imprimirMayus(char &c) {
    if (c>='a' and c<='z') {
        c= (c-('a'-'A'));
        cout.put(c);
    }
    else {
        cout.put(c);
    }
}

void imprimir_encabezado2() {
    cout<<"CODE"<<setw(20)<<""<<"USERNAME"<<setw(20)<<""<<"#FOLLOWERS"<<setw(20)<<""<<"CREATED"<<endl;
}


void imprimir_linea(char car,int n) {
    int i=0;
    while(i<n) {
        cout<<car;
        i++;
    }
    cout<<endl;
}

void imprimir_fecha(int fecha) {
    int yyyy,mm,dd;
    yyyy=fecha/1000;
    mm=(fecha%1000)/100;
    dd=fecha%100;
    cout<<setfill('0')<<setw(2)<<dd<<'/'<<setfill('0')<<setw(2)<<mm<<'/'<<yyyy;
    cout<<setfill(' ');
}

void leerLosDatos(int fechaInicio,int fechaFinal) {
    int dd,mm,yyyy,f,n;
    char c,c1;
    while (true) {
        if (cin.eof()) {
            break;
        }
        cin>>dd>>c>>mm>>c>>yyyy;
        f=calcularFecha(dd,mm,yyyy);
        if (f<fechaInicio or f>fechaFinal) {
            cin.ignore(180,'\n');
            continue;
        }
        imprimir_encabezado2();
        imprimir_datosolicitados();
        cout<<endl;
        imprimir_linea('-',119);
        imprimir_encabezado3();
    }
}

int calcularFecha(int dd,int mm,int yyyy) {
    return yyyy*10000+mm*100+dd;
}

void imprimir_encabezado3() {
    cout<<"LAST PLAYBACKS: "<<endl;
    cout<<setw(10)<<""<<"DATE"<<setw(10)<<""<<"TIME DURATION"<<setw(10)<<""<<"#REPRODUCTIONS"<<endl;
    cout<<setfill(' ');
}

void imprimir_datosolicitados() {
    leer_codigo();
    leer_username();
    leer_reproducciones();
    leer_fechacreada();
}



