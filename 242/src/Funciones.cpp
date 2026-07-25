//
// Created by Madi on 7/09/2025.
//

#include "Funciones.hpp"

#include <math.h>

void imprimir_reporte() {
    imprimir_encabezado();
}

void imprimir_encabezado() {
    cout<<setw(40)<<""<<"EMPRESA DE REPARTOS A DOMICILIO TP S. A."<<endl;
    cout<<setw(43)<<""<<"FECHA DE LOS REPARTOS: ";
    leer_fecha();
    cout<<endl;
    imprimir_linea(120,'=');
    cout<<"Repartidor: "<<endl;
}

void leer_fecha() {
    int dd,mm,yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    cout<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<setw(2)<<setfill('0')<<yyyy;
}

void imprimir_linea(int n,char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}

double pago(double distancia) {
    double pago;
    if (distancia<10.5) {
        pago=8.5;
    }
    else if (distancia>=10.5 and distancia<20.5) {
        pago=17.75;
    }
    else if (distancia>=20.5 and distancia<35.5) {
        pago=29.85;
    }
    else if (distancia>=35.5) {
        pago=45.69;
    }
    return pago;
}

double distancia(double velPromedio,double tiempo) {
    return (velPromedio*tiempo);
}

void partedinamica() {
    int DNI,i=1,hI,mI,sI,hF,mF,sF;
    char c;
    double velP,tiempo,direc,D;
    while (true) {
        cout<<"Nombre ";
        cin>>DNI;
        cin>>ws;
        while (true) {
            cin.get(c);
            if (c==' ') {
                break;
            }
            cout<<c;
        }
        cout<<setw(8)<<""<<"DNI: "<<DNI;
        imprimir_linea(120,'-');
        parte_estatica();
        while (i<3) {
            cout<<"Tramo "<<i<<":";
            if (i==1) {
                leer_hora(hI,mI,sI);
                cout<<setw(3)<<"";
                velP=velocidad();
                leer_hora(hF,mF,sF);
            }
            else {
                hI=hF,mI=mF,sI=sF;
                cout<<setw(4)<<""<<setw(2)<<setfill('0')<<hI<<":"<<setw(2)<<setfill('0')<<mI<<":"<<setw(2)<<setfill('0')<<sI;
                cout<<setfill(' ');
                velP=velocidad();
                leer_hora(hF,mF,sF);
            }
            direc=direccion();
            tiempo=tiempocal(hI,mI,sI,hF,mF,sF);
            D=distancia(velP,tiempo);
            cout<<setw(4)<<""<<D;

            i++;
        }
    }
}

void parte_estatica() {
    cout<<"DATOS DE LA RUTA:"<<endl;
    cout<<setw(8)<<""<<"HORA INI";
    cout<<setw(4)<<""<<"HORA FIN";
    cout<<setw(4)<<""<<"VELOCIDAD";
    cout<<setw(4)<<""<<"DISTANCIA";
    cout<<setw(4)<<""<<"PUNTO DE PARTIDA (X,Y)";
    cout<<setw(4)<<""<<"PUNTO DE LLEGADA (X,Y)";
    cout<<setw(4)<<""<<"DISTANCIA ACUMULADA";
    cout<<setw(4)<<""<<"PAGO POR ENVÍO";
    cout<<endl;
}

void leer_hora(int &hh,int &mm,int &ss) {
    char c;
    cin>>hh>>c>>mm>>c>>ss;
    cout<<setw(2)<<setfill('0')<<hh<<":"<<setw(2)<<setfill('0')<<mm<<":"<<setw(2)<<setfill('0')<<ss;
    cout<<setfill(' ');
}

double velocidad() {
    double velocidad;
    cin>>velocidad;
    return velocidad;
}

double direccion() {
    double direccion;
    char c;
    int grado,mm,ss;
    cin>>grado>>c>>mm>>c>>ss;
    direccion=grado+mm/600+ss/3600;
    direccion=direccion*(PI/180);
    return direccion;
}

void XyY(double &X, double &Y,double grados,double distancia) {
    X=distancia*cos(grados);
    Y=distancia*sin(grados);
}

double tiempocal(int hI,int mI,int sI,int hF,int mF,int sF) {
    double tiempo;
    tiempo=(hF+(double)mF/60+(double)sF/3600)-(hI+(double)mF/60+(double)sF/3600);
    return tiempo;
}






