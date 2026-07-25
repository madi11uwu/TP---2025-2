//
// Created by Madi on 9/10/2025.
//

#include "Funciones.hpp"

void cargarJuegos(const char *juegos, int *FechaCreacion, char *c_juego, int *int_juego, double *rating, int &n_juego) {
    ifstream leer_juegos;
    apertura_lectura(juegos,leer_juegos);
    int fecha;
    while (true) {
        fecha=AlmacenarFecha(leer_juegos);
        if (leer_juegos.eof())break;
        FechaCreacion[n_juego]=fecha;
        leer_juegos>>ws>>c_juego[n_juego]>>int_juego[n_juego];
        ignorar(leer_juegos,' ');
        leer_juegos>>rating[n_juego];
        n_juego++;
    }
}

void probarJuegos(const char *reporte_juegos, int *FechaCreacion, char *c_juego, int *int_juego, double *rating, int n_juego) {
    ofstream write;
    apertura_escritura(reporte_juegos,write);
    int i=0;
    write<<"JUEGOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/5)<<""<<"FECHA DE LANZAMIENTO";
    write<<setw(ANCHO_REPORTE/10)<<""<<"CODIGO DE JUEGO";
    write<<setw(ANCHO_REPORTE/10)<<""<<"RATING PROMEDIO"<<endl;
    while (i<n_juego) {
        write<<setw(ANCHO_REPORTE/5)<<"";
        imprimir_fecha(FechaCreacion[i],write);
        write<<setw(ANCHO_REPORTE/5)<<""<<c_juego[i]<<setw(4)<<setfill('0')<<int_juego[i];
        write<<setfill(' ');
        write<<setw(ANCHO_REPORTE/5)<<""<<rating[i]<<endl;
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

void apertura_escritura(const char *file,ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

void ignorar(ifstream &leer,char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
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

void cargarLogros(const char *logros, int *codigo_logro, int *tiempo_promedio, int &n_logro) {
    ifstream leer_logros;
    apertura_lectura(logros,leer_logros);
    int codigo,duracion;
    while (true) {
        leer_logros>>codigo;
        if (leer_logros.eof())break;
        ignorar(leer_logros,' ');
        duracion=AlmacenarDuracion(leer_logros);
        codigo_logro[n_logro]=codigo;
        tiempo_promedio[n_logro]=duracion;
        n_logro++;
    }
}

void probarLogros(const char *reporte_logros, int *codigo_logro, int *tiempo_promedio, int n_logro) {
    ofstream write;
    apertura_escritura(reporte_logros,write);
    int i=0;
    write<<"LOGROS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO DE LOGRO";
    write<<setw(ANCHO_REPORTE/6)<<""<<"TIEMPO PROMEDIO"<<endl;
    while (i<n_logro) {
        write<<setw(ANCHO_REPORTE/4)<<""<<codigo_logro[i];
        write<<setw(ANCHO_REPORTE/4)<<"";
        imprimir_duracion(tiempo_promedio[i],write,'M');
        write<<endl;
        i++;
    }
}


int AlmacenarDuracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}

void cargarLogrosEnJuegos(const char *logrosJuegos, char *char_juego, int *num_juego, int *c_logros, int &n_logrosEnJuegos) {
    ifstream leer_logrosJuegos;
    apertura_lectura(logrosJuegos,leer_logrosJuegos);
    char c;
    while (true) {
        leer_logrosJuegos>>c;
        if (leer_logrosJuegos.eof())break;
        char_juego[n_logrosEnJuegos]=c;
        leer_logrosJuegos>>num_juego[n_logrosEnJuegos]>>c_logros[n_logrosEnJuegos];
        n_logrosEnJuegos++;
    }
}

void probarLogrosEnJuegos(const char *reporte_logrosJuegos, char *char_juego,
                            int *num_juego, int *c_logros, int n_logrosEnJuegos) {
    ofstream write;
    apertura_escritura(reporte_logrosJuegos,write);
    int i=0;
    write<<"LOGROS EN JUEGOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/5)<<""<<"CODIGO DEL JUEGO";
    write<<setw(ANCHO_REPORTE/10)<<""<<"CODIGO DEL LOGRO"<<endl;
    while (i<n_logrosEnJuegos) {
        write<<setw(ANCHO_REPORTE/5)<<""<<char_juego[i];
        write<<setw(4)<<setfill('0')<<num_juego[i];
        write<<setfill(' ');
        write<<setw(ANCHO_REPORTE/5)<<""<<c_logros[i]<<endl;
        i++;
    }
}


void imprimir_duracion(int duracion,ofstream &write,char c) {
    if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60<<":";
        write<<setw(2)<<setfill('0')<<duracion%60;
    }
    else if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    write<<setfill(' ');
}
