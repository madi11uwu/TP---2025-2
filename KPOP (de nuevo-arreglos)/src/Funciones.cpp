//
// Created by Madi on 28/09/2025.
//

#include "Funciones.hpp"

#include <set>

void cargar_artistas(const char *artistas, int *int_artista, double *rating, int &n_artistas) {
    ifstream leer_artistas;
    apertura_lectura(leer_artistas,artistas);
    int fecha;
    char c_artista;
    while (true) {
        fecha=AlmacenarFecha(leer_artistas);
        if (leer_artistas.eof()) break;
        leer_artistas>>ws>>c_artista>>int_artista[n_artistas];
        ignorar(leer_artistas,' ');
        leer_artistas>>rating[n_artistas];
        ignorar(leer_artistas,'\n');
        n_artistas++;
    }
}

void probar_artistas(const char *salida_artista, int *int_artista, double *rating, int n_artistas) {
    ofstream write;
    apertura_escritura(write,salida_artista);
    int i=0;
    write<<"ARTISTAS: "<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/2)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/2)<<""<<"RATING"<<endl;
    while (i<n_artistas) {
        write<<setw(ANCHO_REPORTE/2)<<""<<"A"<<int_artista[i];
        write<<setw(ANCHO_REPORTE/2)<<" "<<rating[i]<<endl;
        i++;
    }
    write.close();
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_linea (int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}
void ignorar(ifstream &leer,char car) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==car)break;
    }
}

void cargar_canciones(const char *canciones, int *codigo_canciones, int *duracion, int &n_canciones) {
    ifstream leer_canciones;
    apertura_lectura(leer_canciones,canciones);
    int int_cancion,duracion_cancion;
    while (true) {
        leer_canciones>>int_cancion;
        if (leer_canciones.eof())break;
        ignorar(leer_canciones,' ');
        duracion_cancion=AlmacenarDuracion(leer_canciones);
        duracion[n_canciones]=duracion_cancion;
        codigo_canciones[n_canciones]=int_cancion;
        n_canciones++;
    }
}

void probar_canciones(const char *salida_canciones, int *codigo_canciones, int *duracion, int n_canciones) {
    ofstream write;
    apertura_escritura(write,salida_canciones);
    int i=0;
    write<<"CANCIONES: "<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/2)<<""<<"CODIGO CANCION";
    write<<setw(ANCHO_REPORTE/2)<<""<<"DURACION"<<endl;
    while (i<n_canciones) {
        write<<setw(ANCHO_REPORTE/2)<<""<<codigo_canciones[i];
        write<<setw(ANCHO_REPORTE/2)<<"";
        imprimir_duracion(write,duracion[i],'M');
        write<<endl;
        i++;
    }
    write.close();
}

void procesarDatosReproducciones(const char *repro, int *int_artista, int *codigo_canciones, int *reproduccionesArtista,
                                int *reproduccionesCanciones, int *fecha_registroCanciones, int *duracion,
                                int *tiempoTotalReproduccionCancion, double *GananciaPorArtista,
                                int n_artistas, int n_canciones, double tarifa) {
    ifstream leer_reproducciones;
    apertura_lectura(leer_reproducciones,repro);
    int fecha,int_codigo_artista,codigo_cancion,pos_artista,pos_cancion,reproducciones;
    char c_artista;
    while (true) {
        fecha=AlmacenarFecha(leer_reproducciones);
        if (leer_reproducciones.eof()) break;
        leer_reproducciones>>ws>>c_artista>>int_codigo_artista>>codigo_cancion>>reproducciones;
        pos_artista=BuscarInfo(int_artista,n_artistas,int_codigo_artista);
        pos_cancion=BuscarInfo(codigo_canciones,n_canciones,codigo_cancion);
        if (pos_artista!=-1) {
            reproduccionesArtista[pos_artista]+=reproducciones;
            GananciaPorArtista[pos_cancion]+=reproducciones*tarifa;
        }
        if (pos_cancion!=-1) {
            reproduccionesCanciones[pos_cancion]=reproducciones;
            fecha_registroCanciones[pos_cancion]=fecha;
            tiempoTotalReproduccionCancion[pos_cancion]+=reproducciones*duracion[pos_cancion];
        }
    }
}

void imprimir_reporte(const char *reporte, int *int_artista, double *rating, int *codigo_canciones, int *duracion,
    int *reproduccionesArtista, int *reproduccionesCanciones, int *fecha_registroCanciones,
    int *tiempoTotalReproduccionCancion, double *GananciaPorArtista, int n_canciones, int n_artistas, double tarifa) {
    ofstream write;
    apertura_escritura(write,reporte);
    imprimir_encabezado(write,tarifa);
    imprimir_encabezadoArtista(write);
    int i=0,nroCanciones=1,nroArtista=1;
    while (i<n_artistas) {
        write<<setw(2)<<setfill('0')<<nroArtista<<")"<<setfill(' ');
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<int_artista[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<fixed<<setprecision(2)<<rating[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<reproduccionesArtista[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<GananciaPorArtista[i]<<endl;
        nroArtista++;
        i++;
    }
    imprimir_linea(ANCHO_REPORTE,'-',write);
    i=0;
    imprimir_encabezadoCanciones(write);
    while (i<n_canciones) {
        write<<setw(2)<<setfill('0')<<nroCanciones<<")"<<setfill(' ');
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<"";
        imprimir_fecha(write,fecha_registroCanciones[i]);
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<codigo_canciones[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<"";
        imprimir_duracion(write,duracion[i],'M');
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<reproduccionesCanciones[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<"";
        imprimir_duracion(write,tiempoTotalReproduccionCancion[i],'H');
        write<<endl;
        nroCanciones++;
        i++;
    }
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}
void imprimir_encabezadoCanciones(ofstream &write) {
    write<<"CANCIONES"<<endl;
    write<<"No.";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"DATE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"CODE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"DURATION";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"N PLAYS";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS2)<<""<<"TOTAL"<<endl;
}
void imprimir_encabezadoArtista(ofstream &write) {
    write<<"ARTISTA"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"No.";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"CODE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"RATING";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"REPLAYS";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"REVANUE"<<endl;
}
void imprimir_encabezado(ofstream &write,double tarifa) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"KPOP_MUSIC PLATFORM"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"REPLAY FEE PER MINUTE: "<<tarifa<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

int BuscarInfo(int *arreglo,int n,int busqueda) {
    int i=0;
    while (i<n) {
        if (arreglo[i]==busqueda) {
            return i;
        }
        i++;
    }
    return -1;
}

void imprimir_duracion (ofstream &write,int duracion,char c) {
    if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60<<":"<<setw(2)<<setfill('0')<<duracion%60;
    }
    else if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60;
        write<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    write<<setfill(' ');
}
int AlmacenarDuracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}

void apertura_lectura(ifstream &leer, const char *file) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_escritura(ofstream &write, const char *file) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}
