//
// Created by Madi on 4/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte() {
    imprimir_encabezado();
    imprimir_linea('=');
}

void imprimir_encabezado() {
    cout<<right<<setw(50)<<""<<"EMPRESA DE SALUD S.A."<<endl;
    imprimir_linea('=');
    cout<<"REGISTRO DE CITAS DE LAS CONSULTAS MEDICAS"<<endl;
}


void imprimir_datos() {
    int dd,mm,yyyy,codigo,hhI,mmI,ssI,hhF,mmF,ssF;
    char car;
    cout<<"Fecha"<<setw(5)<<""<<"Paciente"<<setw(10)<<""<<"Inicio"<<setw(10)<<""<<"Fin";
    cout<<setw(10)<<""<<"Duración (H:M:S)"<<setw(10)<<""<<"Duración (H)"<<setw(10)<<""<<"Especialidad";
    cout<<setw(10)<<""<<"Pago (cita+medicinas)"<<endl;
    imprimir_linea('-');
    cin>>dd>>car>>mm>>car>>yyyy;
    cout<<dd<<'/'<<mm<<'/'<<yyyy;
    cin>>codigo>>hhI>>car>>mmI>>car>>hhF>>ssI>>car>>mmF>>car>>ssF;
    cout<<setw(2)<<setfill('0')<<hhI<<setw(2)<<setfill('0')<<mmI;
    cout<<setw(2)<<setfill('0')<<ssI;
    cout<<setw(2)<<setfill('0')<<hhF<<setw(2)<<setfill('0')<<mmF;
    cout<<setw(2)<<setfill('0')<<ssF;




}

void imprimir_linea(char car) {
    cout<<setfill(car)<<setw(119)<<endl;
    cout<<setfill(' ');
}
