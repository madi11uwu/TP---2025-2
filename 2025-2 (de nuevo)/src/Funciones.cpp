//
// Created by Madi on 21/09/2025.
//

#include "Funciones.hpp"

void Calcular_ProcesarDatos(const char *entrada, const char *salida) {
    int fecha1=20220910,fecha2=20230101;
    double Trepro=2.57,Tduracion=0.78;
    ifstream leer;
    apertura_lectura(leer,entrada);
    ofstream write;
    apertura_salida(write,salida);
    imprimir_encabezado(write,fecha1,fecha2,Trepro,Tduracion);
    imprimir_reporte(leer,write,Tduracion,Trepro,fecha1,fecha2);
    leer.close();
    write.close();
}

void apertura_lectura(ifstream &leer,const char *file) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_salida(ofstream &write,const char *file) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimir_encabezado(ofstream &write,int fecha1,int fecha2,double Trepro,double Tduracion) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"REGISTRO DE LOS CANALES AFILIADOS"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"FECHAS DE CREACION ENTRE EL";
    imprimir_fecha(fecha1,write);
    write<<" Y EL ";
    imprimir_fecha(fecha2,write);
    write<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO4)/2)<<""<<"TARIFA POR NUMERO DE REPRODUCCIONES: "<<Trepro<<" POR CADA 1,000 REPRODUCCIONES Y FRACCION"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO5)/2)<<""<<"TARIFA POR DURACION DEL STREAM: "<<Tduracion<<" POR CADA MINUTO Y FRACCION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}
//01/04/2021    F3765    Fextralife       1734810    93036735    222720
void imprimir_datosEstaticos(ofstream &write,ifstream &leer,int fecha,long long seguidores,long long visitas,
    long long espectadores) {
    int int_codigo;
    char c_codigo;
    leer>>ws>>c_codigo>>int_codigo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<"";
    imprimir_nombre(leer,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<c_codigo<<int_codigo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<"";
    imprimir_fecha(fecha,write);
    leer>>seguidores>>visitas>>espectadores;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<seguidores;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<visitas;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<espectadores<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}
//16/07/2025   00:25:55   1396
void imprimir_datosDinamicos(ofstream &write,ifstream &leer,double Tduracion,double Trepro,int &TotalReproducciones,
    int &TotalDuracion,double &IngresototalDuracion,double &ingresoPublicidad,int &streams) {
    int fecha,duracion,reproducciones;
    double ingresoDuracion;
    IngresototalDuracion=0.0,TotalReproducciones=0,TotalDuracion=0;
    char c;
    imprimir_encabezadoDinamico(write);
    while (true) {
        fecha=AlmacenarFecha(leer);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<"";
        imprimir_fecha(fecha,write);
        duracion=AlmacenarDuracion(leer);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<"";
        imprimir_duracion(duracion,write);
        ingresoDuracion=Tduracion*duracion/60.0;
        IngresototalDuracion+=ingresoDuracion;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<ingresoDuracion;
        leer>>reproducciones;
        TotalReproducciones+=reproducciones;
        TotalDuracion+=duracion;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<reproducciones<<endl;
        c=leer.get();
        if (c=='\n') break;
        streams++;
    }
    ingresoPublicidad=(TotalReproducciones/1000.0)*Trepro;
}

void imprimir_reporte(ifstream &leer,ofstream &write,double Tduracion,double Trepro,int fecha1,int fecha2) {
    int canal=1,fecha,TotalReproducciones,TotalDuracion,streams=0,DuracionGlobal=0;
    double ingresoPublicidad,IngresototalDuracion,ingresoGlobalDuracion=0.0,ingresoGlobalRepro=0.0;
    long long seguidores,visitas,espectadores;
    while (true) {
        fecha=AlmacenarFecha(leer);
        if (leer.eof())break;
        if (!ValidarFecha(fecha,fecha1,fecha2)) {
            leer.ignore(500,'\n');
            continue;
        }
        imprimir_encabezadoEstatico(write,canal);
        imprimir_datosEstaticos(write,leer,fecha,seguidores,visitas,espectadores);
        imprimir_datosDinamicos(write,leer,Tduracion,Trepro,TotalReproducciones,TotalDuracion,IngresototalDuracion,ingresoPublicidad,streams);
        imprimir_linea(ANCHO_REPORTE,'-',write);
        imprimir_estadisticasCanal(write,TotalReproducciones,IngresototalDuracion,TotalDuracion,ingresoPublicidad,seguidores,visitas,espectadores);
        ingresoGlobalDuracion+=IngresototalDuracion;
        ingresoGlobalRepro+=ingresoPublicidad;
        DuracionGlobal+=TotalDuracion;
        canal++;
    }
    imprimir_estadisticaGlobal(write,ingresoGlobalRepro,DuracionGlobal,ingresoGlobalDuracion,streams);
}

bool ValidarFecha(int fecha,int fecha1,int fecha2) {
    if (fecha>=fecha1 and fecha<=fecha2) return true;
    else return false;
}
void imprimir_estadisticaGlobal(ofstream &write,double ingresoGlobalRepro,int DuracionGlobal,double ingresoGlobalDuracion,int streams) {
    write<<"RESUMEN FINAL: "<<endl;
    write<<"CANTIDAD TOTAL DE STREAMS COLOCADOS POR LOS CANALES: "<<streams<<endl;
    write<<"DURACION TOTAL DE LOS STREAMS PUBLICADOS: ";
    imprimir_duracion(DuracionGlobal,write);
    write<<endl;
    write<<"INGRESOS TOTALES POR DURACION: "<<ingresoGlobalDuracion<<endl;
    write<<"INGRESOS TOTALES POR PUBLICIDAD: "<<ingresoGlobalRepro<<endl;
}
void imprimir_estadisticasCanal(ofstream &write,int TotalReproducciones,double IngresototalDuracion,int TotalDuracion,double ingresoPublicidad,
    long long seguidores,long long visitas,long long espectadores) {
    write<<setw(5)<<""<<"RESUMEN DEL CANAL: "<<endl;
    write<<setw(5)<<""<<"DURACION TOTAL DE LAS REPRODUCCIONES: ";
    imprimir_duracion(TotalDuracion,write);
    write<<endl;
    write<<setw(5)<<""<<"INGRESOS POR DURACION: "<<IngresototalDuracion<<endl;
    write<<setw(5)<<""<<"TOTAL DE REPRODUCCIONES: "<<TotalReproducciones<<endl;
    write<<setw(5)<<""<<"INGRESOS POR PUBLICIDAD: "<<ingresoPublicidad<<endl;
    double engagement=(seguidores+visitas/1000.0)/espectadores;
    write<<setw(5)<<""<<"ENGAGEMENT INDEX: "<<engagement<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
int AlmacenarDuracion(ifstream &leer) {
    int h,m,s;
    char c;
    leer>>h>>c>>m>>c>>s;
    return (h*3600+m*60+s);
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}
void imprimir_encabezadoDinamico(ofstream &write) {
    write<<setw(5)<<""<<"ULTIMAS REPRODUCCIONES"<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"FECHA DE PUBLICACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"TIEMPO DE DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"INGRESOS POR DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"NUMERO DE REPRODUCCIONES"<<endl;
}

void imprimir_nombre (ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (c>='a' and c<='z') c=(char)(c-'a'+'A');
        write.put(c);
    }
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}
void imprimir_encabezadoEstatico(ofstream &write,int canal) {
    write<<"CANAL No. "<<canal<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"CREADO EL";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"SEGUIDORES NUEVOS POR MES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"VISITAS NUEVAS POR MES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"MAXIMO DE ESPECTADORES"<<endl;
}

