//
// Created by Madi on 12/09/2025.
//

#include "Funciones.hpp"

#include <fstream>

void imprimir_calcular_reporte(const char *entrada,const char *salida) {
    ifstream leer;
    apertura_archivo_lectura(leer,entrada);
    ofstream escr;
    apertura_archivo_escritura(escr,salida);
    imprimir_encabezado(escr);
    leer.close();
    escr.close();
}

void apertura_archivo_lectura(ifstream &input,const char *file) {
    input.open(file,ios::in);
    if (!input.is_open()) {
        cout<< "El archivo: "<<file<<"No se pudo abrir";
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &output,const char *file) {
    output.open(file,ios::out);
    if (!output.is_open()) {
        cout<< "El archivo: "<<file<<"No se pudo abrir";
        exit(1);
    }
}
//69323674  M  ROSARIO_MENDOZA_EGUSQUIZA   B   31/03/2013    556     13:54:27   16:12:37
void leer_datos_imprimir_datos(ifstream &leer,ofstream &escr,int DNI,char sexo,int &i,int &duracion,int &fecha,char &compañia) {
    int duracionTotal;
    escr<<DNI<<setw(3)<<"";
    leer_nombre_imprimir(leer,escr);
    leer>>compañia;
    fecha=calcularFecha(leer);
    imprimir_sexo(sexo,escr);
    imprimir_categoria(fecha,escr);
    imprimir_compañia(compañia,escr);
    leer_canal_horas(leer,escr,duracionTotal);
    i++;
}

void acumular_datos(int duracion,char fecha,char sexo,char compañia,int &duracionTotal,int &cantAdultosYMenores,int &cantMujeres,int &cantMujeresTVPUCP) {
    if (fecha/10000>2009 or fecha/10000<=1988) {
        cantAdultosYMenores++;
        duracionTotal+=duracion;
    }
    if (sexo=='F') {
        cantMujeres++;
        if (compañia=='A') cantMujeresTVPUCP++;
    }
}
void imprimir_todo(ifstream &leer,ofstream &escr) {
    int DNI,televidentes=0,duracionTotal=0,cantAdultosYMenores=0,cantMujeres=0,cantMujeresTVPUCP=0,duracion,fecha;
    char sexo,compañia;
    while (true) {
        leer>>DNI>>ws>>sexo>>ws;
        if (leer.eof())break;
        leer_datos_imprimir_datos(leer,escr,DNI,sexo,televidentes,duracion,fecha,compañia);
        acumular_datos(televidentes,duracion,fecha,sexo,compañia,duracionTotal,cantAdultosYMenores,cantMujeres,cantMujeresTVPUCP);
    }

}

void imprimir_estadisticas(int televidentes,int tiempoProm,double porcentaje) {

}
void leer_canal_horas(ifstream &leer,ofstream &escr,int &duracionTotal) {
    int canal,duracion;
    duracionTotal=0;
    char c;
    while (true) {
        leer>>canal;
        escr<<canal;
        imprimir_hora(escr,leer,duracion);
        duracionTotal=duracionTotal+duracion;
        c=leer.get();
        if (c=='\n') break;
    }
    escr<<setw(60)<<""<<"TIEMPO TOTAL: "<<duracionTotal;
}

void imprimir_hora(ofstream &escr,ifstream &leer,int &duracion) {
    int hh1,mm1,ss1,hh2,mm2,ss2,s1,s2;
    char c;
    leer>>hh1>>c>>mm1>>c>>ss1;
    escr<<setw(2)<<setfill('0')<<hh1<<'/'<<setw(2)<<setfill('0')<<mm1<<'/'<<setw(2)<<setfill('0')<<ss1;
    escr<<setfill(' ');
    leer>>hh2>>c>>mm2>>c>>ss2;
    escr<<'-'<<setw(2)<<setfill('0')<<hh1<<'/'<<setw(2)<<setfill('0')<<mm1<<'/'<<setw(2)<<setfill('0')<<ss1;
    escr<<setfill(' ');
    s1=hh1*3600+mm1*60+ss1;
    s2=hh2*3600+mm2*60+ss2;
    duracion=s1+s2;
}
int calcularFecha(ifstream &leer) {
    char c;
    int dd,mm,yyyy;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}

void imprimir_compañia(char compañia,ofstream &escr) {
    if (compañia=='A') {
        escr<<"TVPUCP";
    }
    else if (compañia=='B') {
        escr<<"CableMas";
    }
    else if (compañia=='C') {
        escr<<"TPVision";
    }
}

void imprimir_categoria(int fecha,ofstream &escr) {
    int yyyy=fecha/10000;
    if (yyyy>2009) escr<<"Menor";
    else if (yyyy<=2009 and yyyy>1988) escr<<"Joven";
    else if (yyyy<=1988) escr<<"Adulto";
}
void imprimir_sexo (char sexo,ofstream &escr) {
    if (sexo=='F') {
        escr<<"Femenino";
    }
    else if (sexo=='M') {
        escr<<"Masculino";
    }
}

void leer_nombre_imprimir(ifstream &leer,ofstream &escr) {
    char c;
    c=leer.get();
    escr.put(c);
    while (true) {
        c=leer.get();
        if (c=='-') {
            c=' ';
            escr.put(c);
            leer.get(c);
            escr.put(c);
        }
        if (c==' ') break;
        convertirMayus(escr,c);
    }
}

void convertirMayus(ofstream &escr,char &c) {
    if (c>='A' and c<='Z') {
        c=(char)(c+'a'-'A');
    }
    escr.put(c);
}
void imprimir_encabezado(ofstream &escr) {
    escr<<setw(50)<<""<<"EMPRESA DE OPINION DE MERCADO S.A."<<endl;
    imprimir_linea(120,'=',escr);
    escr<<setw(10)<<""<<"REGISTRO DE PREFERENCIAS DE LOS TELEVIDENTES"<<endl;
    imprimir_linea(120,'=',escr);
    escr<<"DNI No."<<setw(5)<<""<<"NOMBRE"<<setw(15)<<""<<"SEXO"<<setw(5)<<""<<"CATEGORIA";
    escr<<setw(5)<<""<<"COMPANIA"<<setw(5)<<""<<"CANAL"<<setw(8)<<""<<"RANGO"<<setw(8)<<""<<"DURACION"<<endl;
    imprimir_linea(120,'-',escr);
}

void imprimir_linea(int n,char c,ofstream &escr) {
    int i=0;
    while (i<n) {
        escr.put(c);
        i++;
    }
    escr<<endl;
}

