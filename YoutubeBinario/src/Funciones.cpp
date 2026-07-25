//
// Created by Madi on 27/10/2025.
//

#include "Funciones.hpp"

void insertar_ordenado(int *codigo_video, int *duracion_video, int *codigo_idioma,
                       char *char_categoria, int *int_categoria,
                       int &n_videos, int codigo, int duracion, int idioma,
                       char c_categoria, int categoria_int) {
    int i=n_videos-1;
    while (i >= 0 and (codigo_video[i] > codigo or
           codigo_video[i] == codigo and duracion_video[i] > duracion)) {
        codigo_video[i+1] = codigo_video[i];
        duracion_video[i+1] = duracion_video[i];
        codigo_idioma[i+1] = codigo_idioma[i];
        int_categoria[i+1] = int_categoria[i];
        char_categoria[i+1] = char_categoria[i];
        i--;
    }
    codigo_idioma[i+1]=idioma;
    int_categoria[i+1]=categoria_int;
    char_categoria[i+1]=c_categoria;
    codigo_video[i+1]=codigo;
    duracion_video[i+1]=duracion;
    n_videos++;
}

void cargar_ordenado_videos(const char *videos, int *codigo_video, int *duracion_video, int *codigo_idioma,
                            char *char_categoria, int *int_categoria,
                            int &n_videos) {
    ifstream leer_videos;
    apertura_lectura(videos, leer_videos);
    int codigo,duracion,idioma,categoria_int;
    char c_categoria;
    while (true) {
        leer_videos >> codigo;
        if (leer_videos.eof())break;
        duracion=almacenar_duracion(leer_videos);
        leer_videos>>idioma>>c_categoria>>categoria_int;
        insertar_ordenado(codigo_video, duracion_video, codigo_idioma,
                          char_categoria, int_categoria, n_videos, codigo, duracion, idioma,
                          c_categoria, categoria_int);
    }
}

void probar_videos(const char *reporte_videos, int *codigo_video, int *duracion_video,
                   int *codigo_idioma,
                   char *char_categoria, int *int_categoria,
                   int n_videos) {
    ofstream write;
    apertura_escritura(reporte_videos, write);
    write<<"VIDEOS"<<endl;
    write<<"CODIGO VIDEO"<<setw(5)<<""<<"DURACION"<<setw(5)<<""<<"IDIOMA";
    write<<setw(5)<<""<<"CATEGORIA"<<endl;
    int i=0;
    while (i<n_videos) {
        write<<codigo_video[i]<<setw(5)<<"";
        imprimir_duracion(duracion_video[i], write);
        write<<setw(5)<<""<<codigo_idioma[i];
        write<<setw(5)<<""<<char_categoria[i]<<int_categoria[i]<<endl;
        i++;
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
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"YOUTUBE"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"ALL VIDEOS REPORT"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"VIDEO"<<setw(5)<<""<<"IDIOMA";
    write<<setw(5)<<""<<"REPRODUCCION ANTIGUA"<<setw(5);
    write<<setw(5)<<""<<"REPRODUCCION RECIENTE"<<setw(5);
    write<<setw(5)<<""<<"PROMEDIO RATING"<<setw(5);
    write<<setw(5)<<""<<"PROMEDIO TASA"<<setw(5)<<"DURACION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

int almacenar_duracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

int almacenar_fecha(ifstream &leer) {
    int yyyy,mm,dd;
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
    write<<setw(2)<<setfill('0')<<(fecha%1000)/100<<"/";
    write<<setw(2)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

void llenarArreglos(const char *canales, int *codigo_video,
                    int n_videos,int *ReproAntigua,int *ReproReciente,int *cantVideo,
                    double *sumaRating,double *sumaTasa) {
    ifstream leer_canales;
    apertura_lectura(canales, leer_canales);
    int fecha,codigo,fechaRepro,horaI,pos;
    double rating,tasa;
    char c;
    while (true) {
        fecha=almacenar_fecha(leer_canales);
        if (leer_canales.eof()) break;
        ignorar(leer_canales,' ');
        while (true) {
            leer_canales>>codigo;
            fechaRepro=almacenar_fecha(leer_canales);
            horaI=almacenar_duracion(leer_canales);
            leer_canales>>rating>>tasa;
            pos = BusquedaBinaria(codigo_video, n_videos, codigo);
            if (pos!=-1) {
                if (ReproAntigua[pos]==0 or ReproAntigua[pos]>fechaRepro) ReproAntigua[pos]=fechaRepro;
                if (ReproReciente[pos]==0 or ReproReciente[pos]<fechaRepro) ReproReciente[pos]=fechaRepro;
                cantVideo[pos]++;
                sumaRating[pos]+=rating;
                sumaTasa[pos]+=tasa;
            }
            c=leer_canales.get();
            if (c=='\n')break;
        }
    }
}

int BusquedaBinaria(int *codigo_video,
                    int n_videos,int codigo) {
    int limite_inferior=0, limite_superior=n_videos-1;
    int medio;
    while (true) {
        if (limite_inferior>limite_superior) return -1;
        medio=(limite_superior+limite_inferior)/2;
        if (codigo==codigo_video[medio]) return medio;
        else if (codigo<codigo_video[medio]) limite_superior=medio-1;
        else limite_inferior=medio+1;
    }
}

void ignorar(ifstream &leer, char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void imprimir_reporte(const char *reporte, int *codigo_video, int *duracion_video,
                      int *codigo_idioma,char *char_categoria, int *int_categoria,
                      int n_videos, int *repro_antigua, int *repro_reciente,
                      int *cant_video, double *suma_rating, double *suma_tasa) {
    ofstream write;
    apertura_escritura(reporte,write);
    imprimir_encabezado(write);
    int mayorVideo,menorVideo,mayorDuracion=0,menorDuracion=9999999;
    int i=0;
    while (i<n_videos) {
        write<<codigo_video[i]<<setw(5)<<""<<codigo_idioma[i];
        write<<setw(5)<<"";
        if (cant_video[i]!=0) {
            imprimir_fecha(repro_antigua[i],write);
            write<<setw(5)<<"";
            imprimir_fecha(repro_reciente[i],write);
            write<<setw(5)<<""<<suma_rating[i]/cant_video[i];
            write<<setw(5)<<""<<suma_tasa[i]/cant_video[i];
        }
        else {
            write<<setw(5)<<" - "<<setw(10)<<" - ";
            write<<setw(10)<<" - "<<setw(10)<<" - ";
        }
        write<<setw(5)<<"";
        imprimir_duracion(duracion_video[i],write);
        if (mayorDuracion<duracion_video[i]) {
            mayorDuracion=duracion_video[i],mayorVideo=codigo_video[i];
        }
        if (menorDuracion>duracion_video[i]) {
            menorDuracion=duracion_video[i],menorVideo=codigo_video[i];
        }
        write<<endl;
        i++;
    }
    imprimirEstadisticas(mayorDuracion,menorDuracion,mayorVideo,menorVideo,write);
}

void imprimirEstadisticas(int mayorDuracion, int menorDuracion,
                          int mayorVideo, int menorVideo,ofstream &write) {
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"RESUMEN"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"VIDEO MAS LARGO: "<<mayorVideo<<setw(3)<<"";
    imprimir_duracion(mayorDuracion,write);
    write<<endl;
    write<<"VIDEO MAS CORTO: "<<menorVideo<<setw(3)<<"";
    imprimir_duracion(menorDuracion,write);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
