//
// Created by Madi on 29/09/2025.
//

#include "Funciones.hpp"

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

void imprimir_linea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimir_encabezado(ofstream &write,double tarifa) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"KPOP_MUSIC PLATFORM"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"REPLAY FEE PER MINUTE: "<<fixed<<setprecision(2)<<tarifa<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void cargarArtistas(const char *artistas, int *fechaDebut, int *int_codigo, double *rating, int &n_artistas) {
    ifstream leer_artistas;
    apertura_lectura(artistas,leer_artistas);
    int fecha;
    char c_artista;
    while (true) {
        fecha=AlmacenarFecha(leer_artistas);
        if (leer_artistas.eof()) break;
        leer_artistas>>ws>>c_artista>>int_codigo[n_artistas];
        ignorar(leer_artistas,' ');
        leer_artistas>>rating[n_artistas];
        ignorar(leer_artistas,'\n');
        fechaDebut[n_artistas]=fecha;
        n_artistas++;
    }
}

void probarArtistas(const char *salida_artistas, int *fechaDebut, int *int_codigo, double *rating, int n_artistas) {
    ofstream write;
    apertura_escritura(salida_artistas,write);
    int i=0;
    write<<"ARTISTAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(5)<<""<<"FECHA DEBUT";
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO ARTISTA";
    write<<setw(ANCHO_REPORTE/4)<<""<<"RATING"<<endl;
    while (i<n_artistas) {
        write<<setw(5)<<"";
        imprimir_fecha(write,fechaDebut[i]);
        write<<setw(ANCHO_REPORTE/4)<<""<<"A"<<int_codigo[i];
        write<<setw(ANCHO_REPORTE/4)<<""<<rating[i]<<endl;
        i++;
    }
    write.close();
}

void ignorar(ifstream &leer,char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}
int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100;
    write<<"/"<<fecha/10000;
    write<<setfill(' ');
}

void cargarCanciones(const char *canciones, int *c_cancion, int *duracion, int &n_canciones) {
    ifstream leer_canciones;
    apertura_lectura(canciones,leer_canciones);
    int codigo_canciones,duracionCancion;
    while (true) {
        leer_canciones>>codigo_canciones;
        if (leer_canciones.eof())break;
        ignorar(leer_canciones,' ');
        duracionCancion=AlmacenarDuracion(leer_canciones);
        c_cancion[n_canciones]=codigo_canciones;
        duracion[n_canciones]=duracionCancion;
        n_canciones++;
    }
}

void probarCanciones(const char *salida_canciones, int *c_cancion, int *duracion, int n_canciones) {
    ofstream write;
    apertura_escritura(salida_canciones,write);
    int i=0;
    write<<"CANCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(5)<<""<<"CODIGO DE CANCION";
    write<<setw(ANCHO_REPORTE/4)<<""<<"DURACION DE CANCION"<<endl;
    while (i<n_canciones) {
        write<<setw(5)<<""<<c_cancion[i];
        write<<setw(ANCHO_REPORTE/3)<<"";
        imprimir_duracion(write,duracion[i],'M');
        write<<endl;
        i++;
    }
    write.close();
}

int AlmacenarDuracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}

void imprimir_duracion(ofstream &write,int duracion,char c) {
    if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60<<":"<<setw(2)<<setfill('0')<<duracion%60;
    }
    else if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    write<<setfill(' ');
}

void armarArreglos(const char*reproducciones,int *c_cancion, int *duracion, int n_canciones,
                    int *fechaDebut, int *int_codigo, double *rating, int n_artistas,double tarifa,
                    int *FechaCanciones,int *ReproduccionesCancion,int *ReproduccionesArtista,
                    double *GananciaArtista,int *DuracionTotal){
    ifstream leer_reproducciones;
    apertura_lectura(reproducciones,leer_reproducciones);
    int fechaRegistro,int_artista,codigo_cancion,repros,pos_cancion,pos_artista;
    char c_artista;
    while (true){
        fechaRegistro=AlmacenarFecha(leer_reproducciones);
        if (leer_reproducciones.eof())break;
        leer_reproducciones>>ws>>c_artista>>int_artista>>codigo_cancion>>repros;
        pos_cancion=buscar(c_cancion,n_canciones,codigo_cancion);
        pos_artista=buscar(int_codigo,n_artistas,int_artista);
        if (pos_cancion!=-1) {
            FechaCanciones[pos_cancion]=fechaRegistro;
            ReproduccionesCancion[pos_cancion]+=repros;
            DuracionTotal[pos_cancion]+=repros*duracion[pos_cancion];
        }
        if (pos_artista!=-1) {
            ReproduccionesArtista[pos_artista]+=repros;
            GananciaArtista[pos_artista]+=repros*tarifa;
        }
    }
}

void imprimir_reporte(const char*reporte,int *c_cancion, int *duracion, int n_canciones,
                    int *fechaDebut, int *int_codigo, double *rating, int n_artistas,double tarifa,
                    int *FechaCanciones,int *ReproduccionesCancion,int *ReproduccionesArtista,
                    double *GananciaArtista,int *DuracionTotal) {
    ofstream write;
    apertura_escritura(reporte,write);
    imprimir_encabezado(write,tarifa);
    int i=0,j=0,nro_cancion=1,nro_artista=1;
    imprimir_encabezadoArtista(write);
    while (j<n_artistas) {
        write<<setw(2)<<setfill('0')<<nro_artista<<")"<<setfill(' ');
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<"";
        imprimir_fecha(write,fechaDebut[j]);
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"A"<<int_codigo[j];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<rating[j];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<ReproduccionesArtista[j];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<GananciaArtista[j]<<endl;
        nro_artista++;
        j++;
    }
    imprimir_linea(ANCHO_REPORTE,'-',write);
    imprimir_encabezadoCanciones(write);
    while (i<n_canciones) {
        write<<setw(2)<<setfill('0')<<nro_cancion<<")"<<setfill(' ');
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<"";
        imprimir_fecha(write,FechaCanciones[i]);
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<c_cancion[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<"";
        imprimir_duracion(write,duracion[i],'M');
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<ReproduccionesCancion[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<"";
        imprimir_duracion(write,DuracionTotal[i],'H');
        write<<endl;
        nro_cancion++;
        i++;
    }
}

void imprimir_encabezadoArtista(ofstream &write) {
    write<<"ARTISTAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"No.";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"DATE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"CODE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"RATING";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"REPLAYS";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"REVENUE"<<endl;
}

void imprimir_encabezadoCanciones(ofstream &write) {
    write<<"CANCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"No.";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"DATE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"CODE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"DURATION";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"N PLAYS";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"TOTAL"<<endl;
}

int buscar(int *arreglos,int n,int busqueda){
    int i=0;
    while (i<n){
        if (arreglos[i]==busqueda){
            return i;
        }
        i++;
    }
    return -1;
}
