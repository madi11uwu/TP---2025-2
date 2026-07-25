//
// Created by Madi on 15/09/2025.
//

#include "Funciones.hpp"

void ProcesarDatos(const char *entrada, const char *salida) {
    int fecha1=20220909,fecha2=20230101;
    ifstream leer;
    apertura_entrada(entrada,leer);
    ofstream write;
    apertura_salida(salida,write);
    imprimir_reporte(leer,write,fecha1,fecha2);
    leer.close();
    write.close();
}

void apertura_entrada(const char *entrada, ifstream &leer) {
    leer.open(entrada,ios::in);
    if(!leer.is_open()) {
        cout<<"El archivo: "<<entrada<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_salida(const char *salida, ofstream &write) {
    write.open(salida,ios::out);
    if(!write.is_open()) {
        cout<<"El archivo: "<<salida<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while(i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimir_encabezado(ofstream &write,int fecha1,int fecha2) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"REGISTRO DE LOS CANALES AFILIADOS"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"FECHA DE CREACION ENTRE EL ";
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

void imprimir_encabezadoEstatico(ifstream &leer,ofstream &write,int i) {
    write<<"CANAL No. "<<i<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"CREADO EL";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"NUMERO DE SEGUIDORES"<<endl;
}
//15/10/2022    F3765    Fextralife        508816
void imprimir_datosEstaticos(ifstream &leer,ofstream &write,int &codigo,char &letra,int fecha,int i) {
    int seguidores;
    imprimir_encabezadoEstatico(leer,write,i);
    leer>>ws>>letra>>codigo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<"";
    imprimir_nombre(leer,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<letra<<codigo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<"";
    imprimir_fecha(fecha,write);
    leer>>seguidores;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<seguidores<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void imprimir_encabezadoDinamico(ofstream &write) {
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"ULTIMAS REPRODUCCIONES"<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+3))<<""<<"FECHA DE PUBLICACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+3))<<""<<"TIEMPO DE DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+3))<<""<<"NUMERO DE REPRODUCCIONES"<<endl;
}
//16/07/2025   00:25:55   1396
void imprimir_leer_datosDinamicos(ifstream &leer,ofstream &write,int &ReproCanal,int &DuracionCanal,int &mayorFecha,int &streams,double &ingresos) {
    int fecha,duracion,reproducciones;
    ReproCanal=0,DuracionCanal=0,mayorFecha=0;
    char c;
    imprimir_encabezadoDinamico(write);
    while (true) {
        fecha=leer_fechaAlmacenar(leer);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+3))<<"";
        imprimir_fecha(fecha,write);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+3))<<"";
        duracion=CalcularDuracion(leer);
        imprimir_duracion(duracion,write);
        leer>>reproducciones;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+3))<<""<<reproducciones<<endl;
        if (mayorFecha<fecha) mayorFecha=fecha;
        DuracionCanal+=duracion;
        ReproCanal+=reproducciones;
        streams++;
        c=leer.get();
        if (c=='\n') break;
    }
    ingresos=(3.25/1000.0)*ReproCanal;
}
int CalcularDuracion (ifstream &leer) {
    int h,m,s;
    char c;
    leer>>h>>c>>m>>c>>s;
    return h*3600+m*60+s;
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}
void imprimir_nombre(ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        leer.get(c);
        if (c>='a' and c<='z') {
            c=(char)(c-'a'+'A');
        }
        if (c=='\n') break;
        write.put(c);
    }
}

void imprimir_reporte(ifstream &leer,ofstream &write,int fecha1,int fecha2) {
    int i=1,fecha,codigo,ReproCanal,DuracionCanal,mayorFecha,streams=0,DuracionGlobal=0,mayorCodigo=0;
    double ingresos,ingresoGlobal=0.0,mayorIngreso=0.0;
    char c,letra,mayorLetra=' ';
    imprimir_encabezado(write,fecha1,fecha2);
    while (true) {
        fecha=leer_fechaAlmacenar(leer);
        if (leer.eof()) break;
        if (!ValidarFecha(fecha,fecha1,fecha2)) {
            leer.ignore(500,'\n');
            continue;
        }
        imprimir_datosEstaticos(leer,write,codigo,letra,fecha,i);
        imprimir_leer_datosDinamicos(leer,write,ReproCanal,DuracionCanal,mayorFecha,streams,ingresos);
        imprimir_estadisticasCanal(write,ReproCanal,DuracionCanal,mayorFecha,ingresos);
        if (ingresos>mayorIngreso) {
            mayorIngreso=ingresos;
            mayorLetra=letra;
            mayorCodigo=codigo;
        }
        DuracionGlobal+=DuracionCanal;
        ingresoGlobal+=ingresos;
    }
    imprimir_estadisticasGlobales(write,streams,DuracionGlobal,ingresoGlobal,mayorIngreso,mayorLetra,mayorCodigo);
}

void imprimir_estadisticasGlobales(ofstream &write,int streams,int DuracionGlobal,double ingresoGlobal,double mayorIngreso,char mayorLetra,int mayorCodigo) {
    write<<"RESUMEN FINAL: "<<endl;
    write<<"CANTIDAD TOTAL DE STREAMS COLOCADOS POR LOS CANALES: "<<streams<<endl;
    write<<"DURACION TOTAL DE LOS STREAMS PUBLICADOS: ";
    imprimir_duracion(DuracionGlobal,write);
    write<<endl;
    write<<"INGRESOS TOTALES POR PUBLICIDAD: "<<ingresoGlobal<<endl;
    write<<"CANAL CON MAYORES INGRESOS POR PUBLICIDAD: "<<mayorLetra<<mayorCodigo<<" CON "<<mayorIngreso<<endl;
}
void imprimir_estadisticasCanal(ofstream &write,int ReproCanal,int DuracionCanal,int mayorFecha,double ingresos) {
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"RESUMEN DEL CANAL: "<<endl;
    write<<"DURACION TOTAL DE REPRODUCCIONES: ";
    imprimir_duracion(DuracionCanal,write);
    write<<endl;
    write<<"ULTIMA PUBLICACION: ";
    imprimir_fecha(mayorFecha,write);
    write<<endl;
    write<<"TOTAL DE REPRODUCCIONES: "<<ReproCanal<<endl;
    write<<"INGRESOS POR PUBLICIDAD: "<<ingresos<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
bool ValidarFecha(int fecha,int fecha1,int fecha2) {
    if (fecha>=fecha1 and fecha<=fecha2) return true;
    else return false;
}

int leer_fechaAlmacenar(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

