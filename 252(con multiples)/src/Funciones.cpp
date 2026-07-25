//
// Created by Madi on 21/09/2025.
//

#include "Funciones.hpp"

void imprimir_ProcesarDatos(const char *canales, const char *streams, const char *categorias, const char *salida) {
    int fecha1=20220910,fecha2=20230101;
    double Trepro=2.47,Tduracion=0.78;
    ifstream leer_canales;
    ifstream leer_streams;
    ifstream leer_categorias;
    apertura_entrada(canales,leer_canales);
    apertura_entrada(streams,leer_streams);
    apertura_entrada(categorias,leer_categorias);
    ofstream write;
    apertura_salida(salida,write);
    imprimir_encabezadoPrincipal(write,fecha1,fecha2,Trepro,Tduracion);
    imprimir_reporte(write,leer_canales,leer_streams,leer_categorias,fecha1,fecha2,Trepro,Tduracion);
    write.close();
    leer_categorias.close();
    leer_streams.close();
    leer_canales.close();
}

void apertura_entrada(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_salida(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void imprimir_encabezadoPrincipal(ofstream &write, int fecha1, int fecha2, double Trepro, double Tduracion) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"REGISTRO DE LOS CANALES AFILIADOS"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"FECHAS DE CREACION ENTRE EL ";
    imprimir_fecha(fecha1,write);
    write<<" Y EL ";
    imprimir_fecha(fecha2,write);
    write<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO4)/2)<<""<<"TARIFA POR NUMERO DE REPRODUCCIONES: "<<Trepro<<" POR CADA 1,000 REPRODUCCIONES Y FRACCION"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO5)/2)<<""<<"TARIFA POR DURACION DEL STREAM: "<<Tduracion<<" POR CADA MINUTO Y FRACCION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

int AlmacenarDuracion(ifstream &leer) {
    int h,m,s;
    char c;
    leer>>h>>c>>m>>c>>s;
    return (h*3600+m*60+s);
}

void imprimir_fecha(int fecha, ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

void imprimir_duracion(int duracion, ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

bool ValidarFecha(int fecha,int fecha1,int fecha2) {
    if (fecha>=fecha1 and fecha<=fecha2) return true;
    else return false;
}

void imprimir_encabezadoEstatico(int canal1,ofstream &write) {
    write<<"CANAL No. "<<canal1<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"CREADO EL";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+8))<<""<<"SEGUIDORES NUEVOS POR MES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+8))<<""<<"VISITAS NUEVAS POR MES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+8))<<""<<"MAXIMO DE ESPECTADORES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+8))<<""<<"CATEGORIA"<<endl;
}

void imprimir_reporte(ofstream &write,ifstream &leer_canales,ifstream &leer_streams,ifstream &leer_categorias,int fecha1,int fecha2,
    double Trepro,double Tduracion) {
    int canal=1,fecha,int_canal,DuracionTotal,TotalReproCanal,TotalReproGlobal=0;
    char c_canal,c;
    double ingresoDuracionCanal,ingresoReproCanal,ingresoDuracionGlobal=0.0,ingresoReproGlobal=0.0;
    while (true) {
        fecha=AlmacenarFecha(leer_canales);
        if (leer_canales.eof())break;
        if (!ValidarFecha(fecha,fecha1,fecha2)) {
            leer_canales.ignore(400,'\n');
            continue;
        }
        imprimir_encabezadoEstatico(canal,write);
        imprimir_datosEstaticos(write,leer_canales,c_canal,int_canal,fecha,leer_categorias);
        imprimir_EncabezadoDinamico(write);
        imprimir_datosDinamicos(write,leer_streams,c_canal,int_canal,Trepro,Tduracion,DuracionTotal,TotalReproCanal,
            ingresoDuracionCanal,ingresoReproCanal);
        ingresoDuracionGlobal+=ingresoDuracionCanal;
        ingresoReproGlobal+=ingresoReproCanal;
        TotalReproGlobal+=TotalReproCanal;
        c=leer_canales.get();
        canal++;
    }
}
//P6114 16/07/2025 00:02:46 19400
void imprimir_datosDinamicos(ofstream &write,ifstream &leer_streams,char c_canal,int int_canal,double Trepro,double Tduracion,
    int &DuracionTotal,int &TotalReproCanal,double &ingresoDuracionCanal,double &ingresoReproCanal) {
    char c_canalLeido;
    int int_canalLeido,fecha,duracion,reproducciones;
    DuracionTotal=0,TotalReproCanal=0;
    double ingresoDuracion;
    ingresoDuracionCanal=0.0,ingresoReproCanal;
    leer_streams.clear();
    leer_streams.seekg(0,ios::beg);
    while (true) {
        leer_streams>>c_canalLeido>>int_canalLeido;
        if (leer_streams.eof()) break;
        if (c_canalLeido==c_canal and int_canalLeido==int_canal) {
            fecha=AlmacenarFecha(leer_streams),duracion=AlmacenarDuracion(leer_streams);
            leer_streams>>reproducciones;
            ingresoDuracion=(duracion/60.0)*Tduracion;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<"";
            imprimir_fecha(fecha,write);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+2))<<"";
            imprimir_duracion(duracion,write);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+1))<<""<<ingresoDuracion;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+1))<<""<<reproducciones<<endl;
            ingresoDuracionCanal+=ingresoDuracion,TotalReproCanal+=reproducciones,DuracionTotal+=duracion;
        }
        else {
            leer_streams.ignore(400,'\n');
            continue;
        }
    }
    ingresoReproCanal=(reproducciones/1000.0)*Trepro;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}
//01/04/2021 F3765 Fextralife 1734810 93036735 222720
void imprimir_datosEstaticos(ofstream &write,ifstream &leer_canales,char &c_canal,int &int_canal,int fecha,ifstream &leer_categoria) {
    long long seguidores,visitas,espectadores;
    leer_canales>>ws>>c_canal>>int_canal;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<"";
    imprimir_nombre(leer_canales,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<""<<c_canal<<int_canal;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<"";
    imprimir_fecha(fecha,write);
    leer_canales>>seguidores>>visitas>>espectadores;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<""<<seguidores;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<""<<visitas;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<""<<espectadores;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+4))<<""<<"";
    buscar_imprimirCategoria(int_canal,c_canal,write,leer_categoria);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}
//F3765 RPG
void buscar_imprimirCategoria(int int_canal,char c_canal,ofstream &write,ifstream &leer_categoria) {
    int int_canalLeido;
    char c_canalLeido;
    leer_categoria.clear();
    leer_categoria.seekg(0,ios::beg);
    while (true) {
        leer_categoria>>c_canalLeido>>int_canalLeido;
        if (leer_categoria.eof())break;
        if (c_canalLeido==c_canal and int_canalLeido==int_canal) {
            imprimir_categoria(write,leer_categoria);
            break;
        }
        else {
            leer_categoria.ignore(400,'\n');
            continue;
        }
    }
}

void imprimir_categoria(ofstream &write,ifstream &leer_categoria) {
    char c;
    leer_categoria>>ws;
    while (true) {
        c=leer_categoria.get();
        if (c==' ')break;
        write.put(c);
    }
}
void imprimir_EncabezadoDinamico(ofstream &write) {
    write<<setw(3)<<""<<"ULTIMAS REPRODUCCIONES"<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"FECHA DE PUBLICACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"TIEMPO DE DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"INGRESOS POR DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"NUMERO DE REPRODUCCIONES"<<endl;
}
void imprimir_nombre(ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (c>='a' and c<='z')c=(char)(c-'a'+'A');
        write.put(c);
    }
}