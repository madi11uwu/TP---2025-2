//
// Created by Madi on 15/09/2025.
//

#include "Funciones.hpp"

void procesarDatosTwitch(const char *entrada, const char *salida) {
    int fecha1=20220909,fecha2=20230101;
    ifstream read;
    apertura_lectura(read,entrada);
    ofstream write;
    apertura_salida(write,salida);
    imprimir_reporte(fecha1,fecha2,read,write);
    read.close();
    write.close();
}

void apertura_lectura(ifstream &read,const char *entrada) {
    read.open(entrada,ios::in);
    if (!read.is_open()) {
        cout<<"El archivo: "<<entrada<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_salida(ofstream &write,const char *salida) {
    write.open(salida,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<salida<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_linea(int n,char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimir_encabezado(ofstream &write,int fecha1,int fecha2) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"REGISTRO DE LOS CANALES AFILIADOS"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"FECHAS DE CREACION ENTRE EL ";
    imprimir_fecha(fecha1,write);
    write<<" Y EL ";
    imprimir_fecha(fecha2,write);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

//03/06/2021      I5881      ibai        1894953
void imprimir_datosEstaticos(ofstream &write,ifstream &read,int fecha,int &codigo,char &letraCod) {
    int seguidores;
    read>>ws>>letraCod>>codigo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<"";
    leer_imprimir_nombre(write,read);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+20))<<""<<letraCod<<codigo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<"";
    imprimir_fecha(fecha,write);
    read>>seguidores;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<""<<seguidores<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void imprimir_encabezado2(ofstream &write,int i) {
    write<<"CANAL No. "<<i<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"CREADO EL";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"NUMERO DE SEGUIDORES"<<endl;
}
void imprimir_reporte(int fecha1,int fecha2,ifstream &read,ofstream &write) {
    int i=1,fecha,reproCanal,mayorFecha,totalDuracion,DuracionGlobal=0,codigo,mayorCodigo=0,streams=0;
    double ingresos,ingresoGlobal=0.0,mayorIngreso=0.0;
    char letraCod,mayorLetra=' ';
    imprimir_encabezado(write,fecha1,fecha2);
    while (true) {
        fecha=leer_almacenarFecha(read);
        if (read.eof()) break;
        if (!ValidarFecha(fecha,fecha1,fecha2)) {
            read.ignore(500,'\n');
            continue;
        }
        imprimir_encabezado2(write,i);
        imprimir_datosEstaticos(write,read,fecha,codigo,letraCod);
        imprimir_datosDinamicos(write,read,reproCanal,mayorFecha,totalDuracion,ingresos,streams);
        imprimir_estadisticasCanal(totalDuracion,mayorFecha,reproCanal,ingresos,write);
        DuracionGlobal+=totalDuracion;
        ingresoGlobal+=ingresos;
        if (ingresos>mayorIngreso) {
            mayorIngreso=ingresos;
            mayorLetra=letraCod;
            mayorCodigo=codigo;
        }
        i++;
    }
    imprimir_estadisticasGlobales(write,streams,DuracionGlobal,ingresoGlobal,mayorCodigo,mayorLetra,mayorIngreso);
}

void imprimir_estadisticasGlobales(ofstream &write,int streams,int DuracionGlobal,double ingresoGlobal,int mayorCodigo,
    char mayorLetra,double mayorIngreso) {
    write<<"RESUMEN FINAL: "<<endl;
    write<<"CANTIDAD TOTAL DE STREAMS COLOCADOS POR LOS CANALES: "<<streams<<endl;
    write<<"DURACION TOTAL DE LOS STREAMS PUBLICADOS: ";
    imprimir_duracion(DuracionGlobal,write);
    write<<endl;
    write<<"INGRESOS TOTALES POR PUBLICIDAD: "<<ingresoGlobal<<endl;
    write<<"CANAL CON MAYORES INGRESOS POR PUBLCIDAD: "<<mayorLetra<<mayorCodigo<<" CON "<<mayorIngreso<<endl;
}
//05/08/2025   02:02:00   4562
void imprimir_datosDinamicos(ofstream &write,ifstream &read,int &reproCanal,int &mayorFecha,
    int &totalDuracion,double &ingresos,int &streams) {
    int fecha,duracion,reproducciones;
    totalDuracion=0;
    reproCanal=0;
    mayorFecha=0;
    char c;
    imprimir_encabezado1(write);
    while (true) {
        fecha=leer_almacenarFecha(read);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<"";
        imprimir_fecha(fecha,write);
        duracion=AlmacenarDuracion(read);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+1))<<"";
        imprimir_duracion(duracion,write);
        read>>reproducciones;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+1))<<""<<reproducciones<<endl;
        if (fecha>mayorFecha) mayorFecha=fecha;
        totalDuracion+=duracion;
        reproCanal+=reproducciones;
        streams++;
        c=read.get();
        if (c=='\n')break;
    }
    ingresos=(3.25/1000.0)*reproCanal;
}

void imprimir_estadisticasCanal(int totalDuracion,int mayorFecha,int reproCanal,double ingresos,ofstream &write) {
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"RESUMEN DEL CANAL:"<<endl;
    write<<"DURACION TOTAL DE LAS REPRODUCCIONES: ";
    imprimir_duracion(totalDuracion,write);
    write<<endl;
    write<<"ULTIMA PUBLICACION: ";
    imprimir_fecha(mayorFecha,write);
    write<<endl;
    write<<"TOTAL DE REPRODUCCIONES: "<<reproCanal<<endl;
    write<<"INGRESOS POR PUBLICIDAD: "<<ingresos<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

int AlmacenarDuracion(ifstream &read) {
    int h,m,s;
    char c;
    read>>h>>c>>m>>c>>s;
    return (h*3600+m*60+s);
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}
void imprimir_encabezado1(ofstream &write) {
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+10))<<""<<"ULTIMAS REPRODUCCIONES"<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"FECHA DE PUBLICACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"TIEMPO DE DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"NUMERO DE REPRODUCCIONES"<<endl;
}

int leer_almacenarFecha(ifstream &read) {
    int fecha,dd,mm,yyyy;
    char c;
    read>>dd>>c>>mm>>c>>yyyy;
    fecha=yyyy*10000+mm*100+dd;
    return fecha;
}

void leer_imprimir_nombre(ofstream &write,ifstream &read) {
    int tamaño=0,ancho,i=0;
    char c;
    read>>ws;
    while (true) {
        c=read.get();
        if (c>='a' and c<='z') {
            c=(char)(c-'a'+'A');
        }
        if (c==' ')break;
        write.put(c);
        tamaño++;
    }
    ancho=ANCHO_REPORTE/NRO_COLUMNAS1;
    while (i<ancho-tamaño-15) {
        write.put(' ');
        i++;
    }
}

bool ValidarFecha(int fecha,int fecha1,int fecha2) {
    if (fecha>=fecha1 and fecha<=fecha2)return true;
    else return false;
}