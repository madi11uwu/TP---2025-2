//
// Created by Madi on 22/09/2025.
//

#include "Funciones.hpp"

void ProcesarDatosKpop(const char *artista, const char *reproducciones, const char *canciones, const char *salida) {
    double tarifa=0.85;
    ifstream leer_artista;
    ifstream leer_reproducciones;
    ifstream leer_canciones;
    apertura_lectura(artista,leer_artista);
    apertura_lectura(reproducciones,leer_reproducciones);
    apertura_lectura(canciones,leer_canciones);
    ofstream write;
    apertura_escritura(salida,write);
    imprimir_encabezadoPrincipal(write,tarifa);
    imprimir_reporte(write,leer_canciones,leer_reproducciones,leer_artista);
    leer_artista.close();
    leer_reproducciones.close();
    leer_canciones.close();
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"Error al abrir el archivo: "<<file<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"Error al abrir el archivo: "<<file<<endl;
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

void imprimir_encabezadoPrincipal(ofstream &write,double tarifa) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"KPOP_MUSIC PLATFORM"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"REPLAY FEE PER MINUTE: "<<tarifa<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_reporte(ofstream &write,ifstream &leer_canciones,ifstream &leer_reproducciones,
    ifstream &leer_artistas) {
    int fecha,int_cancion,contador=1,int_artista,cancion;
    char c_artista,c;
    while (true) {
        fecha=AlmacenarFecha(leer_artistas);
        if (leer_artistas.eof())break;
        imprimir_datosEstaticos(write,contador,fecha,leer_artistas,c_artista,int_artista);
        cancion=1;
        imprimir_encabezadoDinamico(write);
        while (true) {
            leer_artistas>>int_cancion;
            imprimir_datosDinamicos(write,leer_canciones,cancion,leer_reproducciones,int_artista,c_artista,int_cancion);
            c=leer_artistas.get();
            if (c=='\n')break;
            c=leer_artistas.get();
            cancion++;
        }
        imprimir_linea(ANCHO_REPORTE,'-',write);
        contador++;
    }
}

void imprimir_datosDinamicos(ofstream &write,ifstream &leer_canciones,int cancion,ifstream &leer_reproducciones,int int_artista,
    char c_artista,int int_cancion) {
    int fechaLeida,duracion;
    long long reproducciones;
    write<<setw(2)<<setfill('0')<<cancion<<")";
    write<<setfill(' ');
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<"";
    RecuperarFechayReproducciones(leer_reproducciones,int_artista,c_artista,int_cancion,fechaLeida,reproducciones);
    imprimir_fecha(write,fechaLeida);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<int_cancion;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<"";
    imprimir_nombreCancionyDuracion(write,leer_canciones,int_cancion,duracion);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<reproducciones;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<"";
    imprimir_duracionTotal(reproducciones*duracion,write);
    write<<endl;
}

void imprimir_duracionTotal(int duracionTotal,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracionTotal/(3600*24)<<":"<<setw(2)<<setfill('0')<<(duracionTotal%(3600*24))/3600<<":";
    write<<setw(2)<<setfill('0')<<((duracionTotal%(3600*24))%3600)/60<<":"<<setw(2)<<setfill('0')<<((duracionTotal%(3600*24))%3600)%60;
    write<<setfill(' ');
}

void imprimir_nombreCancionyDuracion(ofstream &write,ifstream &leer_canciones,int in_cancion,int &duracion) {
    leer_canciones.clear();
    leer_canciones.seekg(0,ios::beg);
    int int_cancionLeida;
    while (true) {
        leer_canciones>>int_cancionLeida;
        if (leer_canciones.eof())break;
        if (int_cancionLeida==in_cancion) {
            imprimir_nombre(leer_canciones,write);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<"";
            duracion=AlmacenarDuracion(leer_canciones);
            imprimir_duracion(duracion,write);
            break;
        }
        else {
            leer_canciones.ignore(300,'\n');
            continue;
        }
    }
}

void RecuperarFechayReproducciones(ifstream &leer,int int_artista,char c_artista,int int_cancion,int &fechaLeida,long long &reproducciones) {
    leer.clear();
    leer.seekg(0,ios::beg);
    int int_artistaLeida,int_cancionLeida;
    char c_artistaLeida;
    while (true) {
        fechaLeida=AlmacenarFecha(leer);
        if (leer.eof())break;
        leer>>ws>>c_artistaLeida>>int_artistaLeida>>int_cancionLeida;
        if (c_artistaLeida==c_artista and int_artistaLeida==int_cancion and int_artistaLeida==int_artista) {
            leer>>reproducciones;
            break;
        }
        else {
            leer.ignore(200,'\n');
            continue;
        }
    }
}

void imprimir_encabezadoEstatico(ofstream &write,int contador) {
    write<<"ARTIST No: "<<contador<<endl;
    write<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"DIA DEBUT";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"RATING"<<endl;
}

void imprimir_encabezadoDinamico(ofstream &write) {
    write<<"PLAYED SONGS"<<endl;
    write<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"TITULO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"REPRODUCCIONES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2))<<""<<"TOTAL"<<endl;
}

void imprimir_datosEstaticos(ofstream &write,int contador,int fecha,ifstream &leer_artistas,char &c_artista,int &int_artista) {
    double rating;
    imprimir_encabezadoEstatico(write,contador);
    leer_artistas>>ws>>c_artista>>int_artista;
    imprimir_nombre(leer_artistas,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<c_artista<<int_artista;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<"";
    imprimir_fecha(write,fecha);
    leer_artistas>>rating;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<rating<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

int AlmacenarFecha (ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(ofstream &write, int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

int AlmacenarDuracion (ifstream &leer) {
    int m,s;
    char c;
    leer>>m>>c>>s;
    return (m*60+s);
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

void imprimir_nombre(ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (c>='a' and c<='z') c=(char)(c-'a'+'A');
        if (c=='_' or c=='-')c=' ';
        write.put(c);
    }
}