//
// Created by Madi on 5/10/2025.
//

#include "Funciones.hpp"

void cargar_logros(const char *logros, int *codigo_logro, int *tiempoPromedio, int &n_logros) {
    ifstream leer_logros;
    apertura_lectura(logros,leer_logros);
    int codigo,tiempo;
    while (true) {
        leer_logros>>codigo;
        if (leer_logros.eof())break;
        codigo_logro[n_logros] = codigo;
        ignorar(leer_logros,' ');
        tiempo=AlmacenarDuracion(leer_logros);
        tiempoPromedio[n_logros]=tiempo;
        n_logros++;
    }
}

void probar_logros(const char *reporte_logros, int *codigo_logro, int *tiempoPromedio, int n_logros) {
    int i=0;
    ofstream write;
    apertura_escritura(reporte_logros,write);
    write<<"LOGROS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE)/4)<<""<<"CODIGO DEL LOGRO";
    write<<setw(ANCHO_REPORTE/4)<<""<<"TIEMPO PROMEDIO REQUERIDO"<<endl;
    while (i<n_logros) {
        write<<setw((ANCHO_REPORTE)/3)<<""<<codigo_logro[i];
        write<<setw((ANCHO_REPORTE)/3)<<"";
        imprimir_duracion(tiempoPromedio[i],'M',write);
        write<<endl;
        i++;
    }
}

void apertura_lectura(const char *file,ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file,ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
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

int AlmacenarDuracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_duracion(int duracion,char c,ofstream &write) {
    if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600;
        write<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60;
        write<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    else if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60<<":";
        write<<setw(2)<<setfill('0')<<(duracion%60);
    }
    write<<setfill(' ');
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

void cargar_juegos(const char *juegos, int *FechaLanzamiento, char *c_juego, int *int_juego, double *rating, int &n_juego) {
    ifstream leer_juegos;
    apertura_lectura(juegos,leer_juegos);
    int fecha;
    while (true) {
        fecha=AlmacenarFecha(leer_juegos);
        if (leer_juegos.eof())break;
        FechaLanzamiento[n_juego]=fecha;
        leer_juegos>>ws>>c_juego[n_juego]>>int_juego[n_juego];
        ignorar(leer_juegos,' ');
        leer_juegos>>rating[n_juego];
        n_juego++;
    }
}

void probar_juegos(const char *reporte_juegos, int *FechaLanzamiento, char *c_juego, int *int_juego, double *rating,int n_juego) {
    int i=0;
    ofstream write;
    apertura_escritura(reporte_juegos,write);
    write<<"JUEGOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/5)<<""<<"FECHA DE LANZAMIENTO";
    write<<setw(ANCHO_REPORTE/9)<<""<<"CODIGO DE JUEGO";
    write<<setw(ANCHO_REPORTE/10 +2)<<""<<"RATING"<<endl;
    while (i<n_juego) {
        write<<setw(ANCHO_REPORTE/5)<<"";
        imprimir_fecha(FechaLanzamiento[i],write);
        write<<setw(ANCHO_REPORTE/5)<<""<<c_juego[i]<<setw(4)<<setfill('0')<<int_juego[i];
        write<<setfill(' ');
        write<<setw(ANCHO_REPORTE/5)<<""<<rating[i]<<endl;
        i++;
    }
}

void ordenarLogros(int *codigo_logro,int *tiempoPromedio,int n_logros) {
    for (int i=0;i<(n_logros-1);i++) {
        for (int k=i+1;k<n_logros;k++) {
            if (tiempoPromedio[k]<tiempoPromedio[i]) {
                swapInt(codigo_logro[k],codigo_logro[i]);
                swapInt(tiempoPromedio[k],tiempoPromedio[i]);
            }
        }
    }
}

void EncontrarDatos(const char *logrosJuegos,const char *PartidasRegistradas,int *codigo_logro,int n_logros,
                    int *ApareceLogroJuego,char *c_juego, int *int_juego,int n_juego) {
    char char_juego;
    int int1_juego,logro,pos_logro,pos_juego;
    ifstream leer_logros;
    apertura_lectura(logrosJuegos,leer_logros);
    while (true) {
        leer_logros>>char_juego;
        if (leer_logros.eof()) break;
        leer_logros>>int1_juego>>logro;
        pos_logro=buscarLogro(codigo_logro,n_logros,logro);
        pos_juego=buscarJuego(c_juego,int_juego,n_juego,char_juego,int1_juego);
        if (!pos_logro) {
            ApareceLogroJuego[pos_logro]++;
        }
    }
}
int buscarJuego(char *c_juego,int *int_juego,int n_juego,char char_juego,int int1_juego) {
    int i=0;
    while (i<n_juego) {
        if (c_juego[i]==char_juego and int1_juego==int_juego[i]) {
            return i;
        }
        i++;
    }
    return -1;
}
int buscarLogro(int *codigo_logro,int n_logros,int logro) {
    int i=0;
    while (i<n_logros) {
        if (codigo_logro[i]==logro) {
            return i;
        }
        i++;
    }
    return -1;
}
void imprimir_encabezadoJuegos(ofstream &write) {
    write<<"JUEGOS:"<<endl;
    write<<"No.";
    write<<setw(ANCHO_REPORTE/8)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/8)<<""<<"FECHA DE LANZAMIENTO";
    write<<setw(ANCHO_REPORTE/8)<<""<<"RATING DEL JUEGO";
    write<<setw(ANCHO_REPORTE/8)<<""<<"VECES COMPLETADO";
    write<<setw(ANCHO_REPORTE/8)<<""<<"TIEMPO TOTAL POR TODOS LOS JUGADORES"<<endl;
}
void imprimir_reporte(const char *reporte, int *codigo_logro, int *tiempoPromedio, int n_logros) {
    int i=0,logro=1;
    ofstream write;
    apertura_escritura(reporte,write);
    while (i<n_logros) {
        write<<"LOGRO N° "<<logro<<endl;
        write<<setw(2)<<""<<"CODIGO: "<<codigo_logro[i]<<endl;
        write<<setw(2)<<""<<"TIEMPO: ";
        imprimir_duracion(tiempoPromedio[i],'M',write);
        write<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        logro++;
        i++;
    }
}

void imprimir_EncabezadoPrincipal(ofstream &write) {
    write<<"PLATAFORMA DE VIDEOJUEGOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void swapInt(int &a,int &b) {
    int aux;
    aux=a;
    a=b;
    b=aux;
}

void swapDouble(double &a,double &b) {
    double aux;
    aux=a;
    a=b;
    b=aux;
}