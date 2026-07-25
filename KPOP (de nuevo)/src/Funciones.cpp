//
// Created by Madi on 27/09/2025.
//

#include "Funciones.hpp"

void cargar_artistas(int *fecha_artista, int *codigo_int_artista,double *rating_artistas,int &n_artistas,const char*artistas) {
    ifstream leer_artista;
    apertura_lectura(artistas,leer_artista);
    int fecha,int_artista;
    char c_artista;
    double rating;
    while (true) {
        fecha=AlmacenarFecha(leer_artista);
        if (leer_artista.eof())break;
        leer_artista>>ws>>c_artista>>int_artista;
        ignorar(leer_artista,' ');
        leer_artista>>rating;
        ignorar(leer_artista,'\n');
        fecha_artista[n_artistas]=fecha;
        codigo_int_artista[n_artistas]=int_artista;
        rating_artistas[n_artistas]=rating;
        n_artistas++;
    }
}

void ignorar(ifstream &leer,char car) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==car)break;
    }
}
void probar_artistas(int *fecha_artista,int *codigo_int_artista,double *rating_artista,int n_artistas,const char*salida) {
    ofstream write;
    apertura_escritura(salida,write);
    int i=0;
    write<<"ARTISTAS: "<<endl;
    write<<setw(ANCHO_REPORTE/3 -6)<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/3 +5)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/3 +5)<<""<<"RATING"<<endl;
    while (i<n_artistas) {
        write<<setw(ANCHO_REPORTE/3 -6)<<"";
        imprimir_fecha(write,fecha_artista[i]);
        write<<setw(ANCHO_REPORTE/3 )<<""<<"A"<<codigo_int_artista[i];
        write<<setw(ANCHO_REPORTE/3 +6)<<""<<rating_artista[i]<<endl;
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

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

void cargar_canciones(int *codigo_cancion, int *duracion_cancion, int &n_canciones, const char *canciones) {
    ifstream leer_canciones;
    apertura_lectura(canciones,leer_canciones);
    int c_cancion,duracion;
    while (true) {
        leer_canciones>>c_cancion;
        if (leer_canciones.eof())break;
        ignorar(leer_canciones,' ');
        duracion=Almacenar_duracion(leer_canciones);
        codigo_cancion[n_canciones]=c_cancion;
        duracion_cancion[n_canciones]=duracion;
        n_canciones++;
    }
}
int Almacenar_duracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}

void imprimir_duracion(int duracion,ofstream &write,char c) {
    if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    else if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60<<":"<<setw(2)<<setfill('0')<<(duracion%60);
    }
    else if (c=='D') {
        write<<setw(2)<<setfill('0')<<duracion/(3600*24)<<":"<<setw(2)<<setfill('0')<<(duracion%(3600*24))/3600<<":";
        write<<setw(2)<<setfill('0')<<((duracion%(3600*24))%3600)/60<<setw(2)<<setfill('0')<<":"<<((duracion%(3600*24))%3600)%60;
    }
    write<<setfill(' ');
}

void ordenarInformacion(int *fecha_registro, int *reproducciones, int *reproduccionesTotalesTiempo,
    double *gananciasRepro, int *codigo_cancion, int *codigo_int_artista, int n_canciones, int n_artistas, int *) {

}

void BuscarFechaYRepro(int *fecha_registro,int *reproducciones,int *codigo_cancion,const char *fileRepro,
    int n_canciones) {
    ifstream leer_repro;
    apertura_lectura(fileRepro,leer_repro);
    int i,j=0,fechaRegistro;
    char c_artista;
    int int_artista,c_cancion;
    while (j<n_canciones) {
        fechaRegistro=AlmacenarFecha(leer_repro);
        leer_repro>>ws>>c_artista>>int_artista>>c_cancion;
        i=0;
        while (i<n_canciones) {
            if (c_cancion==codigo_cancion[i]) {
                leer_repro>>reproducciones[i];
                fecha_registro[i]=fechaRegistro;
            }
            i++;
        }
        j++;
    }
}
void probar_canciones(int *codigo_cancion, int *duracion_cancion, int n_canciones, const char *salida_canciones) {
    ofstream write;
    apertura_escritura(salida_canciones,write);
    int i=0;
    write<<"CANCIONES: "<<endl;
    write<<setw(ANCHO_REPORTE/2 -10)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/2 -10)<<""<<"DURACION"<<endl;
    while (i<n_canciones) {
        write<<setw(ANCHO_REPORTE/2 -10)<<""<<codigo_cancion[i];
        write<<setw(ANCHO_REPORTE/2 -10)<<"";
        imprimir_duracion(duracion_cancion[i],write,'M');
        write<<endl;
        i++;
    }
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
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
