//
// Created by Madi on 6/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte() {
    imprimir_encabezado();
    imprimir_encabezado1();
    imprimir_datosSolicitados();
    imprimir_linea(120,'=');

}

void imprimir_encabezado() {
    cout<<setw(50)<<""<<"EMPRESA DE SALUD S.A."<<endl;
    imprimir_linea(120,'=');
    cout<<setw(40)<<""<<"REGISTRO DE CITAS DE LAS CONSULTAS MEDICAS"<<endl;
    imprimir_linea(120,'=');

}

void imprimir_linea(int n,char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}

void imprimir_encabezado1() {
    cout<<"Fecha";
    cout<<setw(5)<<""<<"Paciente";
    cout<<setw(5)<<""<<"Inicio";
    cout<<setw(5)<<""<<"Fin";
    cout<<setw(5)<<""<<"Duracion (H:M:S)";
    cout<<setw(5)<<""<<"Duracion (H)";
    cout<<setw(5)<<""<<"Especialidad";
    cout<<setw(5)<<""<<"Pago (cita+medicinas)";
    cout<<endl;
    cout<<setfill(' ');
    imprimir_linea(120,'-');
}

void leer_fecha(int &luego) {
    int dd,mm,yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    cout<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
    cout<<setfill(' ');
    luego=yyyy*10000+mm*100+dd;
}

void leer_paciente() {
    int d;
    cin>>d;
    cout<<setw(5)<<""<<d;
}

void leer_inicioYFin(double &duracionH) {
    int hI,mI,sI,hF,mF,sF,totalsI,totalsF,duracion,duracionH1,duracionM1,duracionS1;
    double duracionM,duracionS;
    char c;
    cin>>hI>>c>>mI>>c>>sI;
    cout<<setw(5)<<""<<setw(2)<<setfill('0')<<hI<<":"<<setw(2)<<setfill('0')<<mI<<":"<<setw(2)<<setfill('0')<<sI;
    cout<<setfill(' ');
    cin>>hF>>c>>mF>>c>>sF;
    cout<<setw(5)<<""<<setw(2)<<setfill('0')<<hF<<":"<<setw(2)<<setfill('0')<<mF<<":"<<setw(2)<<setfill('0')<<sF;
    cout<<setfill(' ');
    totalsI=hI*3600+mI*60+sI;
    totalsF=hF*3600+mF*60+sF;
    duracion=totalsF-totalsI;
    duracionH=(double)duracion/3600;
    duracionH1=duracionH;
    duracionM=(duracionH-duracionH1)*60;
    duracionM1=duracionM;
    duracionS=(duracionM-duracionM1)*60;
    duracionS1=duracionS;
    cout<<setw(5)<<""<<setfill(' ')<<setw(2)<<setfill('0')<<duracionH1<<setw(2)<<setfill('0')<<duracionM1<<setw(2)<<setfill('0')<<duracionS1;
    cout<<setfill(' ');
    cout<<fixed;
    cout<<setprecision(4);
    cout<<setw(10)<<""<<duracionH;
}


double leer_precio() {
    double precio;
    cin>>precio;
    return precio;
}

void leer_especialidad(int &E) {
    char c;
    cin>>ws;
    cin.get(c);
    if (c=='C') {
        cout<<setw(5)<<""<<"Cardiologia";
        E=1;
    }
    else {
        if (c=='D') {
            cout<<setw(5)<<""<<"Dermatologia";
            E=2;
        }
        else {
            cout<<setw(5)<<""<<"Pediatria";
            E=3;
        }
    }
}

void leer_entrega(double &monto) {
    char c;
    cin>>ws;
    cin.get(c);
    if (c=='S') {
        cin>>monto;
    }
    else {
        monto=0;
    }
}

void imprimir_datosSolicitados() {
    while (true) {
        if (cin.eof()) {
            break;
        }
    imprimir();
    }
}

void imprimir(int &E,int &fecha,double &horas,double &precio) {
    double totalmonto=0,montohoras,monto1;
    int totalreceta=0,totalnoreceta=0,cantpacientes=0,cardio=0,derma=0,pediatra=0,cardioyfecha=0;
    char c;
    double monto;
    while (true) {
        leer_fecha(fecha);
        leer_paciente();
        leer_inicioYFin(horas);
        precio=leer_precio();
        leer_especialidad(E);
        if (fecha>20240115 and E==1) {
            cardioyfecha++;
        }
        if (E==1) {
            cardio++;
        }
        else if (E==2) {
            derma++;
        }
        else if (E==3) {
            pediatra++;
        }
        leer_entrega(monto);
        montohoras=precio*horas;
        if (monto!=0) {
            totalreceta++;
        }
        else {
            totalnoreceta++;
        }
        monto1=montohoras+monto;
        cout<<fixed;
        cout<<setprecision(2);
        cout<<setw(5)<<""<<monto1;
        totalmonto=totalmonto+monto1;
        cout<<endl;
        cin.get(c);
        cantpacientes++;
        if (c=='\n') {
            break;
        }
    }
}





