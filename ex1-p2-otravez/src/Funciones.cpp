//
// Created by Madi on 27/10/2025.
//

#include "Funciones.hpp"

void cargar_ordenado_streams(const char *streams, int *codigo_stream, int *duracion_stream,
                             int *codigo_idioma, char *c_categoria,
                             int *int_categoria, int &n_streams) {
    ifstream leer_streams;
    apertura_lectura(streams, leer_streams);
    int codigo,duracion,idioma,categoriaInt;
    char char_categoria;
    while (true) {
        leer_streams>>codigo;
        if (leer_streams.eof()) break;
        duracion=almacenar_duracion(leer_streams);
        leer_streams>>idioma>>char_categoria>>categoriaInt;
        insertar_ordenado(codigo_stream, duracion_stream, codigo_idioma,
                          c_categoria, int_categoria, n_streams, codigo,
                          duracion, idioma, char_categoria, categoriaInt);
    }
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file, ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
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

void imprimir_encabezado(ofstream &write) {
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA DE STREAMING TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"DETALLE COMPLETO DE REPRODUCCION DE STREAMS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"STREAM"<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"IDIOMA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"CATEGORIA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"REP.ANTIGUA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"REP.RECIENTE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"PROM.RAT.CAL.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"PROM.TASA.DROP-OFF";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"DURAC.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"#REPR.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"TOT.REPR."<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

int almacenar_duracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

int almacenar_fecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha/10000);
    write<<setfill(' ');
}

void insertar_ordenado(int *codigo_stream, int *duracion_stream, int *codigo_idioma,
                       char *c_categoria, int *int_categoria, int &n_streams,
                       int codigo, int duracion, int idioma, char char_categoria,
                       int categoria_int) {
    int i=n_streams-1;
    while (i>=0 and codigo_stream[i]>codigo) {
        codigo_stream[i+1]=codigo_stream[i];
        codigo_idioma[i+1]=codigo_idioma[i];
        duracion_stream[i+1]=duracion_stream[i];
        c_categoria[i+1]=c_categoria[i];
        int_categoria[i+1]=int_categoria[i];
        i--;
    }
    codigo_stream[i+1]=codigo;
    codigo_idioma[i+1]=idioma;
    duracion_stream[i+1]=duracion;
    c_categoria[i+1]=char_categoria;
    int_categoria[i+1]=categoria_int;
    n_streams++;
}

void probar_ordenado_streams (const char *reporteStreams, int *codigo_stream, int *duracion_stream,
                             int *codigo_idioma, char *c_categoria,
                             int *int_categoria, int n_streams) {
    ofstream write;
    apertura_escritura(reporteStreams,write);
    write<<"STREAMS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"CODIGO STREAM"<<setw(10)<<""<<"DURACION";
    write<<setw(10)<<""<<"IDIOMA"<<setw(10)<<""<<"CATEGORIA"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    int i=0;
    while (i<n_streams) {
        write<<codigo_stream[i]<<setw(10)<<"";
        imprimir_duracion(duracion_stream[i],write);
        write<<setw(10)<<""<<codigo_idioma[i]<<setw(10)<<""<<c_categoria[i]<<int_categoria[i]<<endl;
        i++;
    }
}

