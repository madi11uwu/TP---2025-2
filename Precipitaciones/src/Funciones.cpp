//
// Created by Madi on 8/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte() {
    imprimir_encabezado();
    imprimir_info();
}

void imprimir_encabezado() {
    cout<<setw(30)<<""<<"INFORME DE PRECIPITACIONES"<<endl;
}

void imprimir_info() {
    int numero,dia,fecha,horaI,horaF,fechaI,totalTiempo,fechaMayor;
    double cantidadLluvia,totalLluvia,mayorPrecipitacion;
    char c;
    while (true) {
        cin>>numero;
        if (cin.eof()) break;
        cout<<"ESTACION No."<<numero<<endl;
        imprimir_parteestatica();
        totalLluvia=0,mayorPrecipitacion=0,totalTiempo=0,dia=1;
        while (true) {
            convertir_fecha(fecha);
            leer_hora(horaI);
            leer_hora(horaF);
            totalTiempo=totalTiempo+horaF-horaI;
            imprimir_hora(horaF-horaI);
            cin>>cantidadLluvia;
            cout<<setw(10)<<""<<cantidadLluvia<<" mm"<<endl;
            if (dia==1) fechaI=fecha;
            if (cantidadLluvia>mayorPrecipitacion) {
                mayorPrecipitacion=cantidadLluvia;
                fechaMayor=fecha;
            }
            totalLluvia=totalLluvia+cantidadLluvia;
            cin.get(c);
            if (c=='\n') break;
            dia++;
        }
        imprimir_estadisticas(fechaI,fecha,dia,totalTiempo,totalLluvia,fechaMayor,mayorPrecipitacion);
    }
}



void imprimir_parteestatica() {
    cout<<"NOMBRE: ";
    convertir_mayus(',');
    cout<<"CIUDAD: ";
    convertir_mayus(',');
    cout<<"REGION: ";
    convertir_mayus(':');
    cout<<setw(10)<<""<<"Fecha";
    cout<<setw(10)<<""<<"Tiempo llovido";
    cout<<setw(10)<<""<<"Cantidad llovida";
    cout<<endl;
}

void convertir_mayus(char car) {
    char c;
    cin>>ws;
    while (true) {
        cin.get(c);
        if (c>='a' and c<='z') {
            c=(char)(c-'a'+'A');
        }
        if (c==car) break;
        cout.put(c);
    }
    cout<<endl;
}

void convertir_fecha(int &fecha) {
    int dd,mm,yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    cout<<setw(10)<<""<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<setfill('0')<<mm<<'/'<<yyyy;
    cout<<setfill(' ');
    fecha=calcular_fecha(dd,mm,yyyy);
}

void leer_hora(int &hora) {
    int h, m, s;
    char c;
    cin>>h>>c>>m>>c>>s;
    hora=calcular_hora(h,m,s);
}

int calcular_fecha(int dd,int mm,int yyyy) {
    int fecha;
    fecha=yyyy*10000+mm*100+dd;
    return fecha;
}

int calcular_hora(int h,int m,int s) {
    int hora;
    hora=h*3600+m*60+s;
    return hora;
}

void imprimir_fecha(int fecha) {
    int dd,mm,yyyy;
    dd=fecha%100;
    yyyy=fecha/10000;
    mm=(fecha%10000)/100;
    cout<<setw(2)<<setfill('0')<<dd<<'/'<<setw(2)<<setfill('0')<<mm<<'/'<<yyyy;
    cout<<setfill(' ');
}

void imprimir_hora(int hora) {
    double h,m,s;
    int h1,m1,s1;
    h=hora/3600;
    h1=h;
    m=(h-h1)*60;
    m1=m;
    s=(m-m1)*60;
    s1=s;
    cout<<setw(10)<<"";
    cout<<setw(2)<<setfill('0')<<h1<<":"<<setw(2)<<setw(2)<<setfill('0')<<m1<<":"<<setw(2)<<setfill('0')<<s1;
    cout<<setfill(' ');
}

void imprimir_estadisticas(int fechaI,int fechaF,int dias,int tiempoLlovido,double totalLlovido,int fechaMayor,double mayorPrecipitacion) {
    cout<<setw(2)<<""<<"RESUMEN:"<<endl;
    cout<<setw(5)<<""<<"Fecha inicial: ";
    imprimir_fecha(fechaI);
    cout<<endl;
    cout<<setw(5)<<""<<"Fecha final: ";
    imprimir_fecha(fechaF);
    cout<<endl;
    cout<<setw(5)<<""<<"Cantidad de dias registrados: "<<dias<<endl;
    cout<<setw(5)<<""<<"Tiempo total de lluvia: ";
    imprimir_hora(tiempoLlovido);
    cout<<endl;
    cout<<setw(5)<<""<<"Total llovido en el periodo: "<<totalLlovido<<endl;
    cout<<setw(5)<<""<<"En la fecha ";
    imprimir_fecha(fechaMayor);
    cout<<" se obtuvo la mayor precipitacion, con "<<mayorPrecipitacion<<" mm"<<endl;
}


