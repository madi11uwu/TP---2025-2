//
// Created by Madi on 8/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte() {
    imprimir_encabezado();
    imprimir_info();
}

void imprimir_encabezado() {
    cout<<setw(30)<<""<<"EMPRESA DE TELEFONIA"<<endl;
    imprimir_linea(120,'=');
}

void imprimir_info() {
    int DNI,dd,mm,yyyy,pais,ciudad,telefono,h,m,s;
    int ciudad214567=0,servicio,fecha,fechaComparar=20040701,fechaHoy=20250908,clientesFecha=0;
    int ciudad60=0,tarifa60=0,DNIM,DNIm,MenorPago=100000,clientes=0,añoComparar=2025;
    double pago,horas,porcentaje,tarifaProm,tarifa,MayorPago=0;
    char c,car,c1;
    while (true) {
        cin>>DNI;
        if (DNI==0) {
            break;
        }
        while (true) {
            cin>>dd>>car>>mm>>car>>yyyy;
            cin>>pais;
            cin>>ciudad;
            cin>>telefono;
            cin>>h>>car>>m>>car>>s;
            cin>>tarifa;
            imprimir_orden(DNI,dd,mm,yyyy,pais,ciudad,telefono,h,m,s,tarifa);
            fecha=convertir_fecha(ciudad,mm,yyyy);
            horas=convertir_hora(h,m,s);
            pago=horas*tarifa;
            if (ciudad==21 or ciudad==45 or ciudad==67 and pais==3) {
                ciudad214567++;
            }
            if ((añoComparar-yyyy)<5 and pago>50.0) {
                clientesFecha++;
            }
            if (ciudad==60 and fechaComparar>fecha) {
                ciudad60++;
                tarifa60=tarifa60+tarifa;
            }
            if (pago>MayorPago) {
                MayorPago=pago;
                DNIM=DNI;
            }
            if (pago<MenorPago) {
                MenorPago=pago;
                DNIm=DNI;
            }
            clientes++;
            cin.get(c);
            if (c=='\n') {
                break;
            }
        }
    }
    porcentaje=(clientesFecha/clientes)*100;
    tarifaProm=tarifa60/ciudad60;
    imprimir_estadisticas(ciudad214567,porcentaje,tarifaProm,DNIM,DNIm);
}

void imprimir_linea(int n,char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}

void imprimir_orden(int DNI,int dd,int mm,int yyyy,int pais,int ciudad,int telefono,int h,int m,int s,double tarifa) {
    cout<<DNI;
    cout<<setw(4)<<""<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
    cout<<setfill(' ');
    cout<<setw(4)<<""<<pais;
    cout<<setw(4)<<""<<ciudad;
    cout<<setw(4)<<""<<telefono;
    cout<<setw(4)<<""<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m<<":"<<setw(2)<<setfill('0')<<s;
    cout<<setfill(' ');
    cout<<setw(4)<<""<<tarifa<<endl;
}

double convertir_hora(int h,int m,int s) {
    double minutos;
    minutos=h*60+m+s/60;
    return minutos;
}

int convertir_fecha(int dd,int mm,int yyyy) {
    int fecha;
    fecha=yyyy*10000+dd*100+mm;
    return fecha;
}

void imprimir_estadisticas(int ciudad214567,double porcentaje,double tarifaProm,int DNIM,int DNIm) {
    cout<<"Resultados:"<<endl;
    cout<<"El numero de clientes que reside en las ciudades 21, 45 y 67 del pais 3: "<<ciudad214567<<endl;
    cout<<"El porcentaje de clientes que tiene menos de 5 anhos de servicio y que pagan en promedio mas de 50.00 diarios: "<<porcentaje<<endl;
    cout<<"La tarifa promedio de los clientes que viven en la ciudad 60 y que ingresaron al servicio antes de 1/7/2004: "<<tarifaProm<<endl;
    cout<<"El cliente que mas pago y el que menos pago por su consumo promedio: "<<endl;
    cout<<"Mas: "<<DNIM<<endl;
    cout<<"Menos: "<<DNIm<<endl;
}





