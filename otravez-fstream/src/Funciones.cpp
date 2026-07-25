//
// Created by Madi on 14/09/2025.
//

#include "Funciones.hpp"

void imprimir_procesar_datos(const char *entrada, const char *salida) {
    int Inicio=20220909,Salida=20230101;
    ifstream leer;
    procesar_datos_entrada(leer,entrada);
    ofstream write;
    procesar_datos_salida(write,salida);
    imprimirEncabezado(Inicio,Salida,write);
    imprimir_todo(write,leer,Inicio,Salida);
    leer.close();
    write.close();
}

void procesar_datos_entrada(ifstream &leer,const char *entrada) {
    leer.open(entrada,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<entrada<<" no se puede abrir"<<endl;
        exit(1);
    }
}

void procesar_datos_salida(ofstream &write,const char *salida) {
    write.open(salida,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<salida<<" no se puede abrir"<<endl;
        exit(1);
    }
}

void imprimirEncabezado(int Inicio, int Salida, ofstream &write) {
    write<<setw((ANCHO-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO-ANCHO_TITULO2)/2)<<""<<"REGISTRO DE LOS CANALES AFILIADOS"<<endl;
    write<<setw((ANCHO-ANCHO_TITULO3)/2)<<""<<"FECHAS DE CREACION ENTRE EL ";
    imprimirFecha(Inicio,write);
    write<<" Y EL ";
    imprimirFecha(Salida,write);
    write<<endl;
    imprimir_linea(ANCHO,'=',write);
}

void imprimir_encabezado_Estatico(int canal,ofstream &write) {
    write<<"CANAL No. "<<canal<<endl;
    write<<setw(ANCHO/(NRO_COLUMNAS1+5))<<""<<"NOMBRE";
    write<<setw(ANCHO/(NRO_COLUMNAS1+2))<<""<<"CODIGO";
    write<<setw(ANCHO/(NRO_COLUMNAS1+2))<<""<<"CREADO EL";
    write<<setw(ANCHO/(NRO_COLUMNAS1+2))<<""<<"NUMERO DE SEGUIDORES"<<endl;
}
//15/10/2022    F3765    Fextralife        508816
void imprimir_leer_datos_estaticos(int &codigo,int fecha,char &letra,ifstream &leer,ofstream &write,int canal) {
    int seguidores;
    imprimir_encabezado_Estatico(canal,write);
    write<<setw(ANCHO/(NRO_COLUMNAS1+5))<<"";
    leer>>ws>>letra>>codigo;
    leer_imprimir_nombre(write,leer,' ');
    write<<setw(ANCHO/(NRO_COLUMNAS1+2))<<""<<letra<<codigo;
    write<<setw(ANCHO/(NRO_COLUMNAS1+2))<<"";
    imprimirFecha(fecha,write);
    leer>>seguidores;
    write<<setw(ANCHO/(NRO_COLUMNAS1+2))<<""<<seguidores<<endl;
    imprimir_linea(ANCHO,'-',write);
}

void imprimir_encabezadoDinamico(ofstream &write) {
    write<<setw(ANCHO/(NRO_COLUMNAS2+8))<<""<<"ULTIMAS REPRODUCCIONES"<<endl;
    write<<setw(ANCHO/(NRO_COLUMNAS2+5))<<""<<"FECHA DE PUBLICACION";
    write<<setw(ANCHO/(NRO_COLUMNAS2+5))<<""<<"TIEMPO DE DURACION";
    write<<setw(ANCHO/(NRO_COLUMNAS2+5))<<""<<"NUMERO DE SEGUIDORES"<<endl;
}
//16/07/2025   00:25:55   1396
void imprimir_leer_datosDinamicos(ofstream &write,ifstream &leer,int &duracionCanal,int &fechaFinal,int &reproCanal,double &ingresos,int &streams) {
    int fecha,duracion,reproducciones;
    char c;
    fechaFinal=0,duracionCanal=0,reproCanal=0;
    imprimir_encabezadoDinamico(write);
    while (true) {
        fecha=leer_convertirFecha(leer);
        if (fecha>fechaFinal) fechaFinal=fecha;
        write<<setw(ANCHO/(NRO_COLUMNAS2+3))<<"";
        imprimirFecha(fecha,write);
        write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<"";
        imprimir_leer_duracion(leer,duracion,write);
        leer>>reproducciones;
        write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<reproducciones<<endl;
        duracionCanal+=duracion;
        reproCanal+=reproducciones;
        streams++;
        c=leer.get();
        if (c=='\n')break;
    }
    ingresos=(3.25/1000)*reproCanal;
}

void imprimir_leer_duracion(ifstream &leer,int &duracion,ofstream &write) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    write<<setw(2)<<setfill('0')<<hh<<":"<<setw(2)<<setfill('0')<<mm<<":"<<setw(2)<<setfill('0')<<ss;
    write<<setfill(' ');
    duracion=hh*3600+mm*60+ss;
}
void leer_imprimir_nombre(ofstream &write,ifstream &leer,char car) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c>='a' and c<='z') {
            c=(char)(c-'a'+'A');
        }
        if (c==car)break;
        write.put(c);
    }
}
void imprimir_linea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimirFecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<(fecha%100)<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}
void imprimir_todo(ofstream &write,ifstream &leer,int Inicio,int Salida) {
    int fecha,canal=1,codigo,fechaFinal,reproCanal,duracionCanal,duracionGlobal=0,mayorCodigo=0,streams=0;
    double ingresos,MayorIngreso=0.0,ingresoGlobal=0.0;
    char letra,MayorLetra=' ';
    while (true) {
        fecha=leer_convertirFecha(leer);
        if (leer.eof())break;
        if (!Validar_fecha(fecha,Inicio,Salida)) {
            leer.ignore(1000,'\n');
            continue;
        }
        imprimir_leer_datos_estaticos(codigo,fecha,letra,leer,write,canal);
        imprimir_leer_datosDinamicos(write,leer,duracionCanal,fechaFinal,reproCanal,ingresos,streams);
        imprimir_estadisticasCanal(duracionCanal,fechaFinal,reproCanal,ingresos,leer,write);
        if (ingresos>MayorIngreso) {
            MayorIngreso=ingresos;
            MayorLetra=letra;
            mayorCodigo=codigo;
        }
        ingresoGlobal+=ingresos;
        duracionGlobal+=duracionCanal;
        canal++;
    }
    imprimir_estadisticasGlobal(duracionGlobal,ingresoGlobal,streams,mayorCodigo,MayorLetra,MayorIngreso,leer,write);
}
void imprimir_estadisticasGlobal(int duracionGlobal,double ingresoGlobal,int streams,int mayorCodigo,char MayorLetra,double MayorIngreso,
        ifstream &leer,ofstream &write) {
    write<<"RESUMEN FINAL: "<<endl;
    write<<"CANTIDAD TOTAL DE STREAMS COLOCADOS POR LOS CANALES: "<<streams<<endl;
    write<<"DURACION TOTAL DE LOS STREAMS PUBLICADOS: ";
    imprimir_duracion(duracionGlobal,write);
    write<<endl;
    write<<"INGRESOS TOTALES POR PUBLICIDAD: "<<ingresoGlobal<<endl;
    write<<"CANAL CON MAYORES INGRESOS POR PUBLICIDAD: "<<MayorLetra<<mayorCodigo<<" CON "<<"S/. "<<MayorIngreso;
}

void imprimir_estadisticasCanal(int duracionCanal,int fechaFinal,int reproCanal,double ingresos, ifstream &leer,ofstream &write) {
    imprimir_linea(ANCHO,'-',write);
    write<<"RESUMEN DEL CANAL"<<endl;
    write<<"DURACION TOTAL DE LAS REPRODUCCIONES: ";
    imprimir_duracion(duracionCanal,write);
    write<<endl;
    write<<"ULTIMA PUBLICACION: ";
    imprimirFecha(fechaFinal,write);
    write<<endl;
    write<<"TOTAL DE REPRODUCCIONES: "<<reproCanal<<endl;
    write<<"INGRESOS POR PUBLICIDAD: "<<"S/. "<<ingresos<<endl;
    imprimir_linea(ANCHO,'=',write);
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}
bool Validar_fecha(int fecha,int Inicio,int Salida) {
    if (fecha>=Inicio and fecha<=Salida) return true;
    else return false;
}
int leer_convertirFecha(ifstream &leer) {
    int dd,mm,yyyy,fecha;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    fecha=yyyy*10000+mm*100+dd;
    return fecha;
}