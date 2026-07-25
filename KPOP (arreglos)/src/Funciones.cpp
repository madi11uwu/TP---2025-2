//
// Created by Madi on 27/09/2025.
//

#include "Funciones.hpp"
//12/03/2019   A1023   BTS        4.85   55001->90311->92110
void cargar_artistas(const char *data, int *fecha, char *charcod, int *intcod,
    double *rating, int &n) {
    int fechaLeida,int_codigo;
    char c_codigo;
    double ratingLeido;
    ifstream leer;
    apertura_lectura(data,leer);
    while (true) {
        fechaLeida = Almacenar_fecha(leer);
        if (leer.eof()) break;
        leer>>ws>>c_codigo>>int_codigo;
        charcod[n] = c_codigo; //Espacios en blanco y A
        intcod[n] = int_codigo;
        ignorar(leer,' ');
        leer>>ratingLeido;
        rating[n] = ratingLeido;
        ignorar(leer,'\n');
        fecha[n] = fechaLeida;
        n++;
    }
}
//A1023   BTS
void ignorar(ifstream &leer,char car) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==car)break;
    }
}

void leer_Nombre_Artistas (ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (c>='a' and c<='z') c=(char)(c-'a'+'A');
        write.put(c);
    }
}
int Almacenar_fecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void probar_artistas(const char *reporte, int *fecha, char *charcod, int *intcod,
    double *rating, int n) {
    //Que es lo que tiene que tener su funcion de prueba?
    ofstream write;
    apertura_escritura(reporte,write);
    //Header
    write<<setw((ANCHO_REPORTE)/2)<<"PRUEBA DE CARGA DE ARTISTAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE)/3)<<"FECHA";
    write<<setw((ANCHO_REPORTE)/3)<<"CODIGO";
    write<<setw((ANCHO_REPORTE)/3)<<"RATING"<<endl;
    //Contenido de los arreglos
    for (int i=0;i<n;i++) {
        write<<setw((ANCHO_REPORTE)/4 +4)<<"";
        imprimir_fecha(write,fecha[i]);
        write<<setw((ANCHO_REPORTE)/3 -8)<<charcod[i]<<intcod[i];
        write<<setw((ANCHO_REPORTE)/3 -1)<<fixed;
        write<<setprecision(2)<<rating[i]<<endl;
    }
    write.close();
}

void imprimir_fecha (ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}
//55001   Dynamite          3:45
void cargar_canciones(const char *canciones, int *codigos_canciones, int *duracion_canciones, int &n_canciones) {
    int duracionLeida,c_cancion;
    double ratingLeido;
    ifstream leer;
    apertura_lectura(canciones,leer);
    while (true) {
        leer>>c_cancion;
        if (leer.eof()) break;
        ignorar(leer,' ');
        duracionLeida=AlmacenarDuracion(leer);
        codigos_canciones[n_canciones]=c_cancion;
        duracion_canciones[n_canciones]=duracionLeida;
        n_canciones++;
    }
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/60<<":"<<setw(2)<<setfill('0')<<duracion%60;
    write<<setfill(' ');
}
int AlmacenarDuracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}
//A4411   77002
void generar_arreglos( ifstream &leer, int * reproducciones_tiempo_total, double * revenue,
    int * total_reproducciones, int n_artistas, int n_canciones, int *codigo_int_artistas) {
    leer.clear();
    leer.seekg(0,ios::beg);
    int fecha,codigo_intLeido,codigoCancionLeido,CantReproduccionesLeido,pos;
    char codigo_cLeido;
    while (true) {
        fecha=Almacenar_fecha(leer);
        if (leer.eof())break;
        leer>>codigo_cLeido>>codigo_intLeido>>codigoCancionLeido>>CantReproduccionesLeido;
        pos = buscar(codigo_int_artistas,codigo_intLeido,n_artistas);
        if (pos != -1)
            reproducciones_tiempo_total[pos] +=CantReproduccionesLeido;
        else
            cout<<"No se pudo encontrar el codigo del artista"<<endl;
    }
}

int buscar(int *codigo_int_artistas,int codigo_intLeido,int n_artistas) {
    for (int i=0;i<n_artistas;i++) {
        if (codigo_int_artistas[i] == codigo_intLeido) {
            return i;
        }
    }
    return -1;
}

void generar_reporte(const char *reproducciones, int *fecha_artistas, char *codigo_char_artistas, int *codigo_int_artistas,
                     double *rating, int *codigos_canciones, int *duracion_canciones, int *reproducciones_tiempo_total, double *Revenue,
                     int *TotalReproducciones,int n_artistas,int n_canciones) {
    ifstream leer;
    apertura_lectura(reproducciones,leer);
    ofstream write;
    apertura_escritura("Reporte/reporte.txt",write);
    //Calcular y guardar en los arreglos auxiliares para imprimir
    generar_arreglos(leer,reproducciones_tiempo_total,Revenue,TotalReproducciones,n_artistas,n_canciones,codigo_int_artistas);
    write<<"ARTISTAS"<<endl;
    for (int i=0; i<n_artistas; i++) {
        imprimir_fecha(write,fecha_artistas[i]);
        write<<setw(ANCHO_REPORTE/3 -6)<<"";
        write<<codigo_char_artistas[i]<<codigo_int_artistas[i];
        write<<setw(ANCHO_REPORTE/3 -6)<<""<<rating[i];
        write<<setw(ANCHO_REPORTE/3)<<reproducciones_tiempo_total[i];
    }
}

void probar_canciones(const char *reporte, int *codigos_canciones, int *duracion_canciones, int n_canciones) {
    ofstream write;
    apertura_escritura(reporte,write);
    //Header
    write<<setw((ANCHO_REPORTE)/2)<<"PRUEBA DE CARGA DE CANCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE)/3)<<"CODIGO";
    write<<setw((ANCHO_REPORTE)/3)<<"DURACION"<<endl;
    //Contenido de los arreglos
    for (int i=0;i<n_canciones;i++) {
        write<<setw((ANCHO_REPORTE)/4 +6)<<""<<codigos_canciones[i];
        write<<setw((ANCHO_REPORTE)/3 -6)<<"";
        imprimir_duracion(duracion_canciones[i],write);
        write<<endl;
    }
    write.close();
}

void imprimir_linea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}
void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file, ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}
