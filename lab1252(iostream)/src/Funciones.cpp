//
// Created by Madi on 14/09/2025.
//

#include "Funciones.hpp"

void leer_procesar_canalesTwitch(const char *entrada, const char *salida) {
    int fechaInicial=20220909,fechaFinal=20230101;
    ifstream leer;
    apertura_archivo_lectura(leer,entrada);
    ofstream write;
    apertura_archivo_escritura(write,salida);
    imprimir_encabezado(write,fechaInicial,fechaFinal);
    imprimir_datos(write,leer,fechaInicial,fechaFinal);
    leer.close();
    write.close();
}

void apertura_archivo_lectura(ifstream &leer, const char *entrada) {
    leer.open(entrada, ios::in);
    if (!leer.is_open()) {
        cout << "El archivo: "<<entrada<<" no se pudo abrir." << endl;
        exit(1);
    }
}

void apertura_archivo_escritura(ofstream &write, const char *salida) {
    write.open(salida, ios::out);
    if (!write.is_open()) {
        cout << "El archivo: "<<salida<<" no se pudo abrir." << endl;
        exit(1);
    }
}
void imprimir_encabezadoEstatico(ofstream &write,int canal) {
    write<<"CANAL No. "<<canal<<endl;
    write<<"    NOMBRE";
    write<<setw((ANCHO/(NUM_COLUMNAS1+2)))<<""<<"CODIGO";
    write<<setw((ANCHO/(NUM_COLUMNAS1+2)))<<""<<"CREADO EL";
    write<<setw((ANCHO/(NUM_COLUMNAS1+2)))<<""<<"NUMERO DE SEGUIDORES"<<endl;
}
// NOMBRE   CODIGO  FECHA DE CREACION   NUMERO DE SEGUIDORES
//15/10/2022    F3765    Fextralife        508816      16/07/2025   00:25:55
void imprimir_datos(ofstream &write,ifstream &leer,int fechaInicio,int fechaFinal) {
    int canal=1,fecha,codigo,duracionCanal,reproduccionesCanal,mayorCod=0,mayorFecha,streams=0,duracionGlobal=0;
    double ingresos,mayorIngreso=0.0,ingresoGlobal=0.0;
    char letraCod,mayorLetra=' ';
    while (true) {
        fecha=calcularFecha(leer);
        if (leer.eof())break;
        if (!validar_fecha(fechaInicio,fechaFinal,fecha)) {
            leer.ignore(1000,'\n');
            continue;
        }
        imprimir_datos_estaticos(leer,write,canal,fecha,letraCod,codigo);
        leer_datos_dinamicos_y_escribir(leer,write,duracionCanal,reproduccionesCanal,ingresos,mayorFecha,streams);
        if (ingresos>mayorIngreso) {
            mayorIngreso=ingresos;
            mayorLetra=letraCod;
            mayorCod=codigo;
        }
        duracionGlobal+=duracionCanal;
        ingresoGlobal+=ingresos;
        imprimir_estadisticas_canal(write,duracionCanal,mayorFecha,reproduccionesCanal,ingresos);
        canal++;
    }
    imprimir_estadisticasGlobales(write,streams,mayorIngreso,mayorLetra,mayorCod,ingresoGlobal,duracionGlobal);
}

void imprimir_estadisticasGlobales(ofstream &write,int streams,double mayorIngreso,char mayorLetra,int mayorCod,double ingresoGlobal,int duracionGlobal) {
    write<<"RESUMEN FINAL: "<<endl;
    write<<"CANTIDAD TOTAL DE STREAMS COLOCADOS POR LOS CANALES: "<<streams<<endl;
    write<<"DURACION TOTAL DE LOS STREAMS PUBLICADOS: ";
    imprimir_duracion(write,duracionGlobal);
    write<<endl;
    write<<"INGRESOS TOTALES POR PUBLICIDAD: "<<ingresoGlobal<<endl;
    write<<"CANAL CON MAYORES INGRESOS POR PUBLICIDAD: "<<mayorLetra<<mayorCod<<" CON "<<"S/. "<<mayorIngreso<<endl;
}
void imprimir_estadisticas_canal(ofstream &write,int duracionCanal,int mayorFecha,int reproduccionesCanal,double ingresos) {
    imprimir_linea(120,'-',write);
    write<<"RESUMEN DEL CANAL: "<<endl;
    write<<"DURACION TOTAL DE LAS REPRODUCCIONES: ";
    imprimir_duracion(write,duracionCanal);
    write<<endl;
    write<<"ULTIMA PUBLICACION: ";
    imprimir_fecha(write,mayorFecha);
    write<<endl;
    write<<"TOTAL DE REPRODUCCIONES: "<<reproduccionesCanal<<endl;
    write<<"INGRESOS POR PUBLICIDAD: "<<ingresos<<endl;
    imprimir_linea(120,'=',write);
}
// NOMBRE   CODIGO  FECHA DE CREACION   NUMERO DE SEGUIDORES
void imprimir_datos_estaticos(ifstream &leer,ofstream &write,int canal,int fecha,char &letraCod,int &codigo) {
    int seguidores;
    imprimir_encabezadoEstatico(write,canal);
    leer>>letraCod>>codigo;
    write<<"    ";
    leer_Nombre(leer,write);
    leer>>seguidores;
    write<<setw((ANCHO/(NUM_COLUMNAS1+10)))<<""<<letraCod<<codigo;
    write<<setw((ANCHO/(NUM_COLUMNAS1+2)))<<"";
    imprimir_fecha(write,fecha);
    write<<setw((ANCHO/(NUM_COLUMNAS1+1)))<<""<<seguidores<<endl;
    imprimir_linea(120,'-',write);
}

//ULTIMAS REPRODUCCIONES
//  FECHA DE PUBLICACION    TIEMPO DE DURACION     NUMERO DE REPRODUCCIONES

void imprimir_encabezado_dinamico(ofstream &write) {
    write<<"ULTIMAS REPRODUCCIONES"<<endl;
    write<<"    FECHA DE PUBLICACION";
    write<<setw((ANCHO/(NUM_COLUMNAS2+2)))<<""<<"TIEMPO DE DURACION";
    write<<setw((ANCHO/(NUM_COLUMNAS2+2)))<<""<<"NUMERO DE REPRODUCCIONES"<<endl;
}
//16/07/2025   00:25:55   1396
void leer_datos_dinamicos_y_escribir(ifstream &leer,ofstream &write,int &duracionCanal,int &reproduccionesCanal,double &ingresos,int &mayorFecha,int &streams) {
    int fecha,duracion,reproducciones;
    mayorFecha=0;
    duracionCanal=0;
    reproduccionesCanal=0;
    char c;
    imprimir_encabezado_dinamico(write);
    while (true) {
        fecha=calcularFecha(leer);
        write<<"    ";
        imprimir_fecha(write,fecha);
        write<<setw((ANCHO/(NUM_COLUMNAS2)))<<"";
        leer_imprimir_duracion(leer,write,duracion);
        leer>>reproducciones;
        write<<setw((ANCHO/(NUM_COLUMNAS2)))<<""<<reproducciones<<endl;
        duracionCanal+=duracion;
        reproduccionesCanal+=reproducciones;
        if (fecha>mayorFecha) mayorFecha=fecha;
        streams++;
        c=leer.get();
        if (c=='\n')break;
    }
    ingresos=(3.25/1000)*reproduccionesCanal;
}

bool validar_fecha (int fechaInicio,int fechaFinal,int fecha) {
    if (fecha>=fechaInicio and fecha<=fechaFinal) return true;
    else return false;
}

void leer_imprimir_duracion(ifstream &leer,ofstream &write,int &duracion) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    write<<setw(2)<<setfill('0')<<hh<<":"<<setw(2)<<setfill('0')<<mm<<":"<<setw(2)<<setfill('0')<<ss;
    write<<setfill(' ');
    duracion=hh*3600+mm*60+ss;
}

void imprimir_duracion(ofstream &write,int duracion) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}
void leer_Nombre(ifstream &leer,ofstream &write) {
    int tamaño=0,i=0;
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c<='z' and c>='a') {
            c=(char)(c-'a'+'A');
        }
        if (c==' ')break;
        write.put(c);
        tamaño++;
    }
    int ancho=ANCHO/(NUM_COLUMNAS1+2);
    while (i<(ancho-tamaño)) {
        write.put(' ');
        i++;
    }
}

int calcularFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return yyyy*10000+mm*100+dd;
}

void imprimir_encabezado(ofstream &write,int fechaInicial,int fechaFinal) {
    write<<setw((ANCHO-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch "<<endl;
    write<<setw((ANCHO-ANCHO_TITULO2)/2)<<""<<"REGISTRO DE LOS CANALES AFILIADOS"<<endl;
    write<<setw((ANCHO-ANCHO_TITULO3)/2)<<""<<"FECHAS DE CREACION ENTRE EL ";
    imprimir_fecha(write,fechaInicial);
    write<<" Y EL ";
    imprimir_fecha(write,fechaFinal);
    write<<endl;
    imprimir_linea(120,'=',write);
}

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<setw(2)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

void imprimir_linea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

