//
// Created by Madi on 7/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte() {
    imprimir_encabezado();
    imprimirtodo();
}

void imprimir_encabezado() {
    cout<<setw(40)<<""<<"Lista de Profesores"<<endl;
    imprimir_linea(120,'=');
    cout<<endl;
}

void imprimir_estatico() {
    cout<<"Codigo de Profesor";
    cout<<setw(5)<<""<<"Hora";
    cout<<setw(5)<<""<<"Edad";
    cout<<setw(5)<<""<<"Sueldo";
    cout<<setw(5)<<""<<"#Cursos";
    cout<<endl;
}

void leer_datos(int &edadmayor,double &sueldo) {
    int hh,mm,ss,edad,num,cursos=0;
    char c,car;
    edadmayor=0;
    cin>>hh;
    cin.get(c);
    if (c==' ') {
        mm=0;
        ss=0;
    }
    else if (c==':') {
        cin>>mm;
        cin.get(c);
        if (c==' ') ss=0;
        else if (c==':') cin>>ss;
    }
    cout<<setw(5)<<""<<setw(2)<<setfill('0')<<hh<<":"<<setw(2)<<setfill('0')<<mm<<":"<<setw(2)<<setfill('0')<<ss;
    cout<<setfill(' ');
    cin>>edad;
    if (edad>=50) edadmayor=edad;
    cout<<setw(5)<<""<<edad;
    cin>>sueldo;
    cout<<setw(5)<<""<<sueldo;
    while (true) {
        cin>>ws;
        cin>>c>>c>>c>>num;
        cin.get(car);
        cursos++;
        if (car=='\n')break;
    }
    cout<<setw(5)<<""<<cursos<<endl;
}

void imprimirtodo() {
    int edadmayor,cantbonos=0,cantprofes=0,codigo;
    double sueldo,aumento=0;
    imprimir_estatico();
    while (true) {
        cin>>codigo;
        if (cin.eof()) {
            break;
        }
        cout<<codigo;
        leer_datos(edadmayor,sueldo);
        if (edadmayor>0) {
            aumento=aumento+sueldo*(0.25/100.0);
            cantbonos++;
        }
        cantprofes++;
    }
    imprimir_estadisticas(cantbonos,cantprofes,aumento);
}

void imprimir_estadisticas(int cantbonos,int cantprofes,double aumento) {
    double porcentaje;
    imprimir_linea(120,'=');
    cout<<endl;
    cout<<"Resumen:"<<endl;
    porcentaje=((double)cantbonos/cantprofes)*100;
    cout<<"Porcentaje profesores con bonos: "<<porcentaje<<"%"<<endl;
    cout<<"Aumento total: "<<aumento<<endl;
}
void imprimir_linea(int n,char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
}
