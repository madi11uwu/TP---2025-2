//
// Created by Madi on 29/08/2025.
//

#include "Functions.hpp"
#include <cmath>

void imprimir_reporte() {
    imprimir_Encabezado();
    while (cin.eof()) {
        imprimir_Linea('=');
        cin.ignore(100,'\n');
        imprimir_datosRepartidor();
        imprimir_Linea('-');
        cin.ignore(100,'\n');
        imprimir_datosRuta();
    }
}

void imprimir_Encabezado() {
    int dd,mm,aaaa;
    char car;
    cout<<setw(50)<<"EMPRESA DE REPARTO A DOMICILIO TP S.A."<<endl;
    cout<<setw(40)<<"FECHA DE LOS REPARTOS: ";
    cin>>dd>>car>>mm>>car>>aaaa;
    cout<<"0"<<dd<<car<<"0"<<mm<<car<<aaaa<<endl;
}

void imprimir_Linea(char c) {
    cout<<setfill(c)<<setw(80)<<""<<endl;
    cout << setfill(' ');
}

void imprimir_datosRepartidor() {
    cout<<"Repartidor:"<<endl;
    cout<<"Nombre ";
    char c;
    int DNI;
    cin>>DNI;
    cin.ignore();
    while (true) {
        cin.get(c);
        if (c==' ') {
            break;
        }
        cout<<c;
    }
    cout<<setw(40)<<"DNI: "<<DNI<<endl;
}

void imprimir_datosRuta() {
    int horaI,minutoI,segundoI,horaF,minutoF,segundoF,grado,minuto,segundo;
    char caracter;
    double Vpromedio,distancia,tiempofinal,tiempoinicial,grados,Xi=0,Yi=0,Xf,Yf,distanciaAcumulada,pago,distanciaA=0,pagoTotal=0;
    cin>>ws;
    cout<<"DATOS DE LA RUTA: "<<endl;
    cout<<right<<setw(10)<<""<<"HORA INI"<<right<<setw(10)<<""<<"HORA FIN"<<right<<setw(10)<<""<<"VELOCIDAD";
    cout<<right<<setw(10)<<""<<"DISTANCIA"<<right<<setw(10)<<""<<"PUNTO DE PARTIDA (X,Y)"<<right<<setw(20)<<""<<"PUNTO DE LLEGADA (X,Y)";
    cout<<right<<setw(20)<<""<<"DISTANCIA ACUMULADA"<<right<<setw(20)<<""<<"PAGO POR ENVIO"<<endl;
    int i=1;
    while (i<=3) {
        cout<<"Tramo "<<i<<":";
        cin>>horaI>>caracter>>minutoI>>caracter>>segundoI;
        cout<<horaI<<caracter<<minutoI<<caracter<<segundoI;
        cin>>ws;
        cin>>Vpromedio;
        cin>>ws;
        cin>>horaF>>caracter>>minutoF>>caracter>>segundoF;
        cout<<left<<setw(10)<<horaF<<caracter<<minutoF<<caracter<<segundoF;
        cout<<left<<setw(10)<<Vpromedio;
        tiempoinicial=calcularSegundos(horaI,minutoI,segundoI);
        tiempofinal=calcularSegundos(horaF,minutoF,segundoF);
        distancia=calcularDistancia(Vpromedio,tiempoinicial,tiempofinal);
        cout<<distancia;
        cout<<left<<setw(10)<<Xi<<" - "<<Yi;
        cin>>ws;
        cin>>grado>>caracter>>minuto>>caracter>>segundo>>caracter;
        grados=calcularGrados(grado,minuto,segundo);
        Xf=calcularX(Xi,grados,distancia);
        Yf=calcularY(Yi,grados,distancia);
        cout<<left<<setw(10)<<Xf<<" - "<<Yf;
        distanciaAcumulada=distanciaA+distancia;
        cout<<left<<setw(10)<<distanciaAcumulada;
        pago=calcularPago(distanciaAcumulada);
        cout<<left<<setw(10)<<pago;
        pagoTotal=pago+pagoTotal;
        distanciaA=distancia;
        Xi=Xf;
        Yi=Yf;
        cout<<endl;
        i++;
    }
    imprimir_Linea('-');
    cout<<"PAGO TOTAL AL REPARTIDOR: "<<pagoTotal;
}

double calcularPago(double distancia) {
    double pago;
    if (distancia<10.5) {
        pago=8.5;
    }
    else {
        if (distancia>=10.5 && distancia<20.5) {
            pago=17.75;
        }
        else {
            if (distancia>=20.5 && distancia<35.5) {
                pago=29.85;
            }
            else {
                pago=45.69;
            }
        }
    }
    return pago;
}

double calcularGrados(int grado, int minutos, int segundos) {
    double grados;
    grados=grado+(double)minutos/60+(double)segundos/3600;
    return grados;
}

double calcularDistancia(double Vpromedio,double inicio,double fin) {
    double velocidad,tiempo;
    velocidad = Transformar_Kmh_a_ms(Vpromedio);
    tiempo=fin-inicio;
    return ((velocidad*tiempo)/1000);
}

double Transformar_Kmh_a_ms(double Vpromedio) {
    return (Vpromedio*(5.0/18.0));
}

double calcularSegundos(int hora,int minuto,int segundo) {
    return (hora*3600+minuto*60+segundo);
}

double calcularX(double X, double grados,double distancia) {
    X=distancia*cos(grados*PI/180);
    return X;
}

double calcularY(double Y, double grados,double distancia) {
    Y=distancia*sin(grados*PI/180);
    return Y;
}





