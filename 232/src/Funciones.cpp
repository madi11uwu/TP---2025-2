//
// Created by Madi on 7/09/2025.
//

#include "Funciones.hpp"
void imprimir_reporte() {
    imprimir_encabezado();
    imprimir();
}

void imprimir_encabezado() {
    cout<<setw(30)<<""<<"EMPRESA DE OPINION DE MERCADO S. A."<<endl;
    imprimir_linea(120,'=');
    cout<<setw(10)<<""<<"REGISTRO DE PREFERENCIAS DE LOS TELEVIDENTES"<<endl;
    imprimir_linea(120,'=');
}

void imprimir_linea(int n, char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}

void imprimir_estático() {
    cout<<"DNI No.";
    cout<<setw(3)<<""<<"Sexo";
    cout<<setw(3)<<""<<"Categoria";
    cout<<setw(3)<<""<<"Hora(P)";
    cout<<setw(3)<<""<<"Hora(A)";
    cout<<setw(3)<<""<<"Duracion(H:M:S)";
    cout<<setw(3)<<""<<"Duracion(H)";
    cout<<setw(3)<<""<<"Canales";
    cout<<setw(3)<<""<<"Compania"<<endl;
    imprimir_linea(120,'-');
}

void imprimir() {
    int DNI,televidentes=0,cantMenores14y19=0,cantFAdultasNoVen=0,cantMJas3=0,cantPersonasCan=0,cantMenores=0;
    int cantAdultos=0,tiempoMenoresyAdultos=0,MujeresTVPUCP=0,HJovenesTP=0,PromCanales=0,cantMujeres=0,cantJovenes=0;
    int canal1,canal2,canal3,cantCanales;
    int año,tiempoI,tiempoF;
    double durac,promedioMenoresYAdultos,porcentajeTVPUCP,porcentajeTPVision,porcentajeAdultos,promedio;
    char c,S,car;
    imprimir_estático();
    while (true) {
        cin>>DNI;
        if (cin.eof()) {
            break;
        }
        cout<<DNI;
        while (true) {
            cin>>ws;
            leer_sexo(S);
            if (S=='F') {
                cantMujeres++;
            }
            leer_fechaDeNacimiento(año);
            if (año>1988 and año<=2009) {
                cantJovenes++;
            }
            if (año<2009) {
                cantMenores++;
            }
            if (año>=1988) {
                cantAdultos++;
            }
            leer_hora(tiempoI);
            leer_hora(tiempoF);
            if (año<2009 and tiempoI>=14*3600 and tiempoF<=19*3600) {
                cantMenores14y19++;
            }
            if (S=='F' and año<=1988 and (tiempoI<(9*3600+30*60) and tiempoF<(9*3600+30*60)) or (tiempoI>(12*3600+45*60) and tiempoF>(12*3600+45*60))) {
                cantFAdultasNoVen++;
            }
            durac=duracion(tiempoF,tiempoI);
            if (año<2009 or año>=1988) {
                tiempoMenoresyAdultos=tiempoMenoresyAdultos+durac;
            }
            if (S=='M' and año>1988 and año<=2009 and durac>3.5) {
                cantMJas3++;
            }
            duracionEnHMS(durac);
            cout<<setw(3)<<""<<durac;
            leerCanales(canal1,canal2,canal3,cantCanales);
            if (canal1==770 or canal2==770 or canal3==770 or canal1==312 or canal2==312 or canal3==312
            or canal1==577 or canal2==577 or canal3==577 and (canal1!=314 and canal2!=314 and canal3!=314
            and canal1!=555 and canal2!=555 and canal3!=555)) {
                cantPersonasCan++;
            }
            leer_compania(car);
            cout<<endl;
            if (S=='F' and car=='A') {
                MujeresTVPUCP++;
            }
            if (S=='M' and año>1988 and año<=2009 and car=='C') {
                HJovenesTP++;
            }
            PromCanales=PromCanales+cantCanales;
            cin.get(c);
            televidentes++;
            if (c=='\n') {
                break;
            }
        }
    }
    imprimir_linea(120,'=');
    promedioMenoresYAdultos=static_cast<double>(tiempoMenoresyAdultos)/(cantAdultos+cantMenores);
    porcentajeTVPUCP=(static_cast<double>(MujeresTVPUCP)/cantMujeres)*100;
    porcentajeTPVision=(static_cast<double>(HJovenesTP)/cantJovenes)*100;
    porcentajeAdultos=(static_cast<double>(cantAdultos)/televidentes)*100;
    promedio=(static_cast<double>(PromCanales)/televidentes);
    cout<<setw(3)<<""<<"ESTADISTICAS OBTENIDAS:"<<endl;
    cout<<setw(3)<<""<<"Cantidad de televidentes registrados"<<setw(10)<<""<<televidentes<<endl;
    cout<<setw(3)<<""<<"Cantidad de menores que ven entre las 14:00:00 y las 19:00:00"<<setw(5)<<""<<cantMenores14y19<<endl;
    cout<<setw(3)<<""<<"Cantidad de mujeres adultas que NO ven televisión entre las 9:30:00 y las 12:45"<<setw(2)<<""<<cantFAdultasNoVen<<endl;
    cout<<setw(3)<<""<<"Cantidad de hombres jovenes que ve mas de 3 horas y media"<<setw(8)<<""<<cantMJas3<<endl;
    cout<<setw(3)<<""<<"Cantidad de personas que ven los canales 770,312 o 577 pero no 314 ni 555"<<setw(4)<<""<<cantPersonasCan<<endl;
    cout<<setw(3)<<""<<"Tiempo promedio que ven los menores y adultos"<<setw(5)<<"";
    duracionEnHMS(promedioMenoresYAdultos);
    cout<<endl;
    cout<<setw(3)<<""<<"Porcentaje de mujeres que ve TVPUCP"<<setw(10)<<""<<porcentajeTVPUCP<<endl;
    cout<<setw(3)<<""<<"Porcentaje de hombres jovenes que ve TPVision"<<setw(10)<<""<<porcentajeTPVision<<endl;
    cout<<setw(3)<<""<<"Porcentaje de adultos registrados"<<setw(15)<<""<<porcentajeAdultos<<endl;
    cout<<setw(3)<<""<<"Promedio de canales que ven los televidentes"<<setw(15)<<""<<promedio<<endl;
}

void leer_sexo(char &S) {
    char sexo;
    cin>>sexo;
    if (sexo=='M') {
        cout<<setw(3)<<""<<"Masculino";
        S='M';
    }
    else if (sexo=='F') {
        cout<<setw(3)<<""<<"Feminino";
        S='F';
    }
}

void leer_fechaDeNacimiento(int &año) {
    int dd,mm,yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    cout<<setw(3)<<""<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<setfill('0')<<mm<<'/'<<yyyy;
    cout<<setfill(' ');
    año=yyyy;
}

int calcular_hora(int h,int m,int s) {
    return (h*3600+m*60+s);
}

void leer_hora(int &tiempo) {
    int h,m,s;
    char c;
    cin>>h>>c>>m>>c>>s;
    cout<<setw(3)<<""<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<':'<<setw(2)<<setfill('0')<<s;
    cout<<setfill(' ');
    tiempo=calcular_hora(h,m,s);
}

double duracion(int tiempoF,int tiempoI) {
    double duracion;
    duracion=(tiempoF-tiempoI)/3600.0;
    return duracion;
}

void duracionEnHMS(double duracion) {
    int duracionH,duracionM,duracionS;
    double duracionM1,duracionS1;
    duracionH=duracion;
    duracionM1=(duracion-duracionH)*60.0;
    duracionM=duracionM1;
    duracionS1=(duracionM1-duracionM)*60.0;
    duracionS=duracionS1;
    cout<<setw(3)<<""<<setw(2)<<setfill('0')<<duracionH<<':'<<setw(2)<<setfill('0')<<duracionM<<':'<<setw(2)<<setfill('0')<<duracionS;
    cout<<setfill(' ');
}

void leerCanales(int &canal1,int &canal2,int &canal3,int &cantCanales) {
    cin>>canal1>>canal2>>canal3;
    if (canal1!=0 and canal2!=0 and canal3!=0) {
        cout<<setw(3)<<""<<canal1<<'/'<<canal2<<'/'<<canal3;
        cantCanales=3;
    }
    else {
        if (canal1!=0 and canal2==0 and canal3==0) {
            cout<<setw(3)<<""<<canal1;
            cantCanales=1;
        }
        else {
            if (canal1!=0 and canal2!=0 and canal3==0) {
                cout<<setw(3)<<""<<canal1<<'/'<<canal2;
                cantCanales=2;
            }
        }
    }
}

void leer_compania(char &compania) {
    cin>>ws;
    cin>>compania;
    if (compania=='A') {
        cout<<setw(3)<<""<<"TVPUCP";
    }
    else if (compania=='B') {
        cout<<setw(3)<<""<<"CableMas";
    }
    else if (compania=='C') {
        cout<<setw(3)<<""<<"TPVision";
    }
}