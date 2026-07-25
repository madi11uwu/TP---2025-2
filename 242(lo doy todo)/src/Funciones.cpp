//
// Created by Madi on 8/09/2025.
//

#include "Funciones.hpp"

void imprimir_y_calcularReporte() {
    imprimir_encabezado();
}

void imprimir_linea(int n, char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}

void imprimir_encabezado() {
    int fecha;
    cout<<setw(40)<<""<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    cout<<setw(50)<<""<<"FECHA DE LOS REPARTOS: ";
    CalcularFecha(fecha);
    imprimirfecha(fecha);
    imprimir_linea(120,'=');
}

void CalcularFecha(int &fecha) {
    int dd,mm,yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    fecha=yyyy*10000+mm*100+dd;
}

void imprimirfecha(int fecha) {
    int dd,mm,yyyy;
    dd=fecha%100;
    yyyy=fecha/10000;
    mm=(fecha%10000)/100;
    cout<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<setfill('0')<<mm<<'/'<<yyyy;
    cout<<setfill(' ');
    cout<<endl;
}

void imprimirInfo() {
    int DNI,i;
    double MayorDistancia=0,MenorDistancia=10000000000;
    char c;
    while (true) {
        cout<<"Repartidor"<<endl;
        cout<<"Nombre ";
        cin>>DNI;
        if (cin.eof()) break;
        leer_nombre();
        cout<<setw(6)<<""<<"DNI: "<<DNI<<endl;
        imprimir_linea(120,'-');
        imprimir_segundo_encabezado();
        i=1;
        while (true) {
            cout<<"Tramo "<<i;
            cin.get(c);
            if (c=='\n') break;
        }
    }
}

void imprimir_estadisticas(int DNIM,int DNIm,double distancia,double distanciaMayor,double distanciaMenor) {
    cout<<setw(20)<<setfill('/')<<endl;
    cout<<"REPARTIDOR CON MAYOR RECORRIDO: "<<endl;
    cout<<"DNI: "<<setw(4)<<""<<DNIM<<endl;
    cout<<"Distancia: "<<distanciaMayor<<"km."<<endl;
    cout<<"REPARTIDOR CON MENOR RECORRIDO: "<<endl;
    cout<<"DNI: "<<setw(4)<<""<<DNIm<<endl;
    cout<<"Distancia: "<<distanciaMenor<<"km."<<endl;
}

void leer_nombre() {
    char c;
    cin>>ws;
    while (true) {
        cin.get(c);
        if (c==' ') break;
        cout.put(c);
    }
}


void imprimir_segundo_encabezado() {
    cout<<"DATOS DE LA RUTA: "<<endl;
    cout<<setw(5)<<""<<"HORA INI";
    cout<<setw(5)<<""<<"HORA FIN";
    cout<<setw(5)<<""<<"VELOCIDAD";
    cout<<setw(5)<<""<<"DISTANCIA";
    cout<<setw(5)<<""<<"PUNTO DE PARTIDA (X,Y)";
    cout<<setw(5)<<""<<"PUNTO DE LLEGADA (X,Y)";
    cout<<setw(5)<<""<<"DISTANCIA ACUMULADA";
    cout<<setw(5)<<""<<"PAGO POR ENVÍO"<<endl;
}

void leer_horas (int i,int &horaI,int &horaF,double &VProm) {
    int hI,mI,sI,hF,mF,sF;
    char c;
    if (i==1) {
        cin>>hI>>c>>mI>>c>>sI>>VProm>>hF>>c>>mF>>c>>sF;
        horaI=hI*10000+mI*100+sI;
        horaF=hF*10000+mF*100+sF;
    }
    else {
        horaI=horaF;
        cin>>VProm;
        cin>>hF>>c>>mF>>c>>sF;
        horaF=hF*10000+mF*100+sF;
    }
}

void imprimirHoras(int hora) {
    int h,m,s;
    h=hora/10000;
    s=hora%100;
    m=(hora%10000)/100;
    cout<<setw(4)<<""<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<':'<<setw(2)<<setfill('0')<<s;
}

double Calcular_Distancia(double VProm,double horas) {
    return (VProm*horas);
}

double CalcularHoras(int hora) {
    double h,m,s;
    double horas;
    h=hora/10000;
    s=hora%100;
    m=(hora%10000)/100;
    horas=h+m/60+s/60;
    return horas;
}

void leer_direccion(double &grados) {
    double grado,minuto,segundo,gr;
    char c;
    cin>>grado>>c>>minuto>>c>>segundo;
    gr=grado+minuto/60+segundo/3600;
    grados=gr*(PI/180);
}

void CalcularXyY(double &Xi,double &Yi,double &Xf,double &Yf,double distancia,int i,double grados) {
    if (i==1) {
        Xi=0,Yi=0;
    }
    else {
        Xi=Xf;
        Yi=Yf;
    }
    Xf=distancia*cos(grados);
    Yf=distancia*sin(grados);
}

