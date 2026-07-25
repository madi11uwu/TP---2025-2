//
// Created by Madi on 9/10/2025.
//

#include "Funciones.hpp"

void cargarVideos(const char *videos, int *codigoVideos, int *duracion, int *codigoIdioma, int &n_videos) {
    ifstream leer_videos;
    apertura_lectura(videos,leer_videos);
    int codigo,tiempo;
    while (true) {
        leer_videos >> codigo;
        if (leer_videos.eof()) break;
        codigoVideos[n_videos] = codigo;
        tiempo = AlmacenarDuracion(leer_videos);
        duracion[n_videos] = tiempo;
        leer_videos >> codigoIdioma[n_videos];
        ignorar(leer_videos,'\n');
        n_videos++;
    }
}

void probarVideos(const char *reporte_prueba, int *codigoVideos, int *duracion, int *codigoIdioma, int n_videos) {
    ofstream write;
    apertura_escritura(reporte_prueba,write);
    int i=0;
    write<<"VIDEOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    while (i<n_videos) {
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
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

int AlmacenarDuracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

void ignorar(ifstream &leer, char c) {
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

void llenar_arreglos_archivos(ifstream &leer,int *codigoVideos,int i,int *RepAntigua,int *RepReciente,
                            double *promedioRating,double *promedioTasaAbandono,int codigo_video) {
    leer.clear();
    leer.seekg(0,ios::beg);
    int fecha,codigo,fechaPublicacion,hora,veces=0;
    double rating,tasaAbandono;
    char c;
    while (true) {
        fecha=AlmacenarFecha(leer);
        if (leer.eof())break;
        ignorar(leer,' ');
        RepAntigua[i]=99999999;
        //codigo video subido, fecha publicación, hora publicacion, rating, tasa de abandono
        while (true) {
            leer>>codigo;
            fechaPublicacion=AlmacenarFecha(leer);
            hora=AlmacenarDuracion(leer);
            leer>>rating>>tasaAbandono;
            //stream, idioma, rep antigua, rep reciente, prom. rat. cal. drop off, durac.
            if (codigo==codigo_video) {
                if (RepAntigua[i]>fechaPublicacion) {
                    RepAntigua[i]=fechaPublicacion;
                    if (RepReciente[i]<fechaPublicacion) {
                        RepReciente[i]=fechaPublicacion;
                    }
                    promedioRating[i]+=rating;
                    promedioTasaAbandono[i]+=tasaAbandono;
                    veces++;
                    if (promedioTasaAbandono[i]<tasaAbandono) {
                        promedioTasaAbandono[i]=tasaAbandono;
                    }
                }
                else {

                }
                c=leer.get();
                if (c=='\n')break;
            }
        }
        promedioRating[i]=promedioRating[i]/(double)veces;
    }
}
void GenerarArreglos(const char *canales, int *RepAntigua, int *RepReciente, double *promedioRating,
                    double *promedioTasaAbandono,int *codigoVideos,int n_videos) {
    ifstream leer_canales;
    apertura_lectura(canales,leer_canales);
    int codigo_video;
    for (int i=0;i<n_videos;i++) {
        codigo_video=codigoVideos[i];
        llenar_arreglos_archivos(leer_canales,codigoVideos,i,RepAntigua,RepReciente,promedioRating,
                                promedioTasaAbandono,codigo_video);
    }
}

// while (true) {
//
//     for (int i=0;i<n_videos;i++) {
//
//     }
// }
int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}
