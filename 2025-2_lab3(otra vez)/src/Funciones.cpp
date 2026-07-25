//
// Created by Madi on 27/09/2025.
//

#include "Funciones.hpp"

void ProcesarDatos(const char *canales, const char *etiquetas, const char *reproducciones, const char *salida) {
    double tarifa=0.78;
    ifstream leer_canales;
    ifstream leer_etiquetas;
    ifstream leer_reproducciones;
    apertura_lectura(canales,leer_canales);
    apertura_lectura(etiquetas,leer_etiquetas);
    apertura_lectura(reproducciones,leer_reproducciones);
    ofstream write;
    apertura_escritura(salida,write);
    imprimir_reporte(write,leer_canales,leer_reproducciones,leer_etiquetas,tarifa);
    leer_canales.close();
    leer_etiquetas.close();
    leer_reproducciones.close();
    write.close();
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
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

void imprimir_encabezadoPrincipal(ofstream &write, double tarifa) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"TARIFA POR DURACION DE LAS ETIQUETAS: ";
    write<<tarifa<<" POR CADA MINUTO Y FRACCION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
//19/06/2022    X5514      xQcOW      2.5
void imprimir_reporte(ofstream &write,ifstream &leer_canales,ifstream &leer_reproducciones,ifstream &leer_etiquetas,double tarifa) {
    int canal=1,fechaCreacion,int_canal,etiqueta,nro_etiqueta,reproTotalEtiqueta,TiempoTotalCanal;
    char c_canal,c;
    double rating;
    imprimir_encabezadoPrincipal(write,tarifa);
    while (true) {
        fechaCreacion=AlmacenarFecha(leer_canales);
        if (leer_canales.eof())break;
        imprimir_datosEstaticos(write,leer_canales,canal,fechaCreacion,c_canal,int_canal,rating);
        nro_etiqueta=1;
        TiempoTotalCanal=0;
        imprimir_encabezadoDinamico(write);
        while (true) {
            leer_canales>>etiqueta;
            imprimir_datosDinamicos(write,leer_reproducciones,leer_etiquetas,etiqueta,nro_etiqueta,c_canal,int_canal,reproTotalEtiqueta);
            TiempoTotalCanal+=reproTotalEtiqueta;
            c=leer_canales.get();
            if (c=='\n')break;
            nro_etiqueta++;
        }
        imprimir_Estadisticas(TiempoTotalCanal,rating,tarifa,write);
        canal++;
    }
}

void imprimir_Estadisticas(int TiempoTotalCanal,double rating,double tarifa,ofstream &write) {
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"TIEMPO TOTAL DE REPRODUCCIONES DE ETIQUETAS: ";
    imprimir_duracion(write,TiempoTotalCanal,'H');
    write<<endl;
    write<<"PORCENTAJE POR RATING DE CALIDAD: ";
    imprimir_porcentaje(rating,write);
    write<<endl;
    double porcentaje;
    if (rating>1 and rating<2) porcentaje=75;
    else if (rating>2 and rating<3) porcentaje=100;
    else if (rating>3 and rating<4) porcentaje=120;
    else porcentaje=130;
    double IngresoRepro;
    IngresoRepro=(TiempoTotalCanal/60.0)*tarifa*porcentaje;
    write<<"INGRESOS POR REPRODUCCION DE ETIQUETAS: "<<fixed<<setprecision(2)<<IngresoRepro<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_porcentaje(double rating,ofstream &write) {
    if (rating>1 and rating<2) write<<"-25%";
    else if (rating>2 and rating<3) write<<"0%";
    else if (rating>3 and rating<4) write<<"+20%";
    else write<<"+30%";
}

void imprimir_datosDinamicos(ofstream &write,ifstream &leer_reproducciones,ifstream &leer_etiquetas,int etiqueta,int nro_etiqueta,char c_canal,int int_canal,int &reproTotalEtiqueta) {
    int fecha,repro,duracion;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<setw(2)<<setfill('0')<<nro_etiqueta<<setfill(' ');
    RecogerFechayCantidadRepro(fecha,repro,leer_reproducciones,int_canal,c_canal,etiqueta);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<"";
    imprimir_fecha(write,fecha);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<etiqueta;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<"";
    imprimir_descripcionYDuracion(etiqueta,write,leer_etiquetas,duracion);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<repro;
    reproTotalEtiqueta=repro*duracion;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<"";
    imprimir_duracion(write,reproTotalEtiqueta,'H');
    write<<endl;
}
void imprimir_descripcionYDuracion(int etiqueta,ofstream &write,ifstream &leer_etiquetas,int &duracion) {
    leer_etiquetas.clear();
    leer_etiquetas.seekg(0,ios::beg);
    int etiquetaLeida;
    while (true) {
        leer_etiquetas>>etiquetaLeida;
        if (leer_etiquetas.eof()) break;
        if (etiquetaLeida==etiqueta) {
            imprimir_texto(leer_etiquetas,write);
            duracion=AlmacenarDuracion(leer_etiquetas);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<"";
            imprimir_duracion(write,duracion,'M');
            break;
        }
        else {
            leer_etiquetas.ignore(100,'\n');
            continue;
        }
    }
}

void imprimir_texto(ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        write.put(c);
    }
}
void RecogerFechayCantidadRepro(int &fecha,int &repro,ifstream &leer_reproducciones,int int_canal,char c_canal,int etiqueta) {
    leer_reproducciones.clear();
    leer_reproducciones.seekg(0,ios::beg);
    char c_canalLeido;
    int int_canalLeido,etiquetaLeida;
    while (true) {
        fecha=AlmacenarFecha(leer_reproducciones);
        if (leer_reproducciones.eof()) break;
        leer_reproducciones>>ws>>c_canalLeido>>int_canalLeido>>etiquetaLeida;
        if (c_canalLeido==c_canalLeido and int_canalLeido==int_canal and etiquetaLeida==etiqueta) {
            leer_reproducciones>>repro;
            break;
        }
        else {
            leer_reproducciones.ignore(100,'\n');
            continue;
        }
    }
}
void imprimir_encabezadoDinamico(ofstream &write) {
    write<<"ETIQUETAS REPRODUCIDAS: "<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<"No. ";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<"ETIQUETA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<"DESCRIPCION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<"DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<"CANTIDAD DE REPRODUCCIONES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+6))<<""<<"TIEMPO TOTAL REPRODUCIDO"<<endl;
}

//19/06/2022    X5514      xQcOW      2.5
void imprimir_datosEstaticos(ofstream &write,ifstream &leer_canales,int canal,int fecha,char &c_canal,int &int_canal,double &rating) {
    imprimir_encabezadoEstatico(canal,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<"";
    leer_canales>>ws>>c_canal>>int_canal;
    imprimir_nombre(leer_canales,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<""<<c_canal<<int_canal;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<"";
    imprimir_fecha(write,fecha);
    leer_canales>>rating;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<""<<rating<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}
int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}
void imprimir_fecha (ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}
void imprimir_encabezadoEstatico(int canal,ofstream &write) {
    write<<"CANAL No. "<<canal<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<""<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<""<<"CREADO EL";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+3))<<""<<"RATING DE CALIDAD"<<endl;
}
void imprimir_nombre(ifstream &leer,ofstream &write) {
    int tamaño=0,i=0;
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (c>='a' and c<='z') c=(char)(c-'a'+'A');
        write.put(c);
        tamaño++;
    }
    int ancho=ANCHO_REPORTE/NRO_COLUMNAS1;
    while (i<ancho-tamaño-3) {
        write.put(' ');
        i++;
    }
}

int AlmacenarDuracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}

void imprimir_duracion(ofstream &write,int duracion,char c) {
    if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60;
        write<<setw(2)<<setfill('0')<<":"<<(duracion%3600)%60;
    }
    else {
        write<<setw(2)<<setfill('0')<<duracion/60<<":"<<setw(2)<<setfill('0')<<duracion%60;
    }
    write<<setfill(' ');
}