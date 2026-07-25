//
// Created by Madi on 13/10/2025.
//

#include "Funciones.hpp"

void apertura_lectura(const char *file,ifstream &leer) {
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

void imprimir_fecha(int fecha, ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(2)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

void cargarVideos(const char *videos,int *codigo_video, int *duracion,
                    int *codigo_idioma, int &n_videos) {
    ifstream leer_videos;
    apertura_lectura(videos,leer_videos);
    int codigo,hora;
    while (true) {
        leer_videos>>codigo;
        if (leer_videos.eof())break;
        codigo_video[n_videos]=codigo;
        hora=AlmacenarDuracion(leer_videos);
        duracion[n_videos]=hora;
        leer_videos>>codigo_idioma[n_videos];
        ignorar(leer_videos,'\n');
        n_videos++;
    }
}

void probarVideos(const char *reporte_videos, int *codigo_video,
                int *duracion, int *codigo_idioma, int n_videos) {
    ofstream write;
    apertura_escritura(reporte_videos,write);
    int i=0;
    write<<"VIDEOS:"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/5)<<""<<"CODIGO DEL VIDEO";
    write<<setw(ANCHO_REPORTE/5)<<""<<"DURACION";
    write<<setw(ANCHO_REPORTE/5)<<""<<"CODIGO DEL IDIOMA"<<endl;
    while (i<n_videos) {
        write<<setw(ANCHO_REPORTE/5)<<""<<codigo_video[i];
        write<<setw(ANCHO_REPORTE/5)<<"";
        imprimirDuracion(duracion[i],write);
        write<<setw(ANCHO_REPORTE/5)<<""<<codigo_idioma[i]<<endl;
        i++;
    }
}

int AlmacenarDuracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

void imprimirDuracion(int duracion, ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

void ignorar(ifstream &leer,char c) {
    leer>>ws;
    char car;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void GenerarArreglos(const char *canales, int *codigo_video,
                    int n_videos,int *UltimaFecha,
                    int *FechaAntigua,int *veces,double *sumaRating,
                    double *sumatasas) {
    ifstream leer_canales;
    apertura_lectura(canales,leer_canales);
    int fechaCreacion,fechaPublicacion,CodVideo,HoraPublicacion,posVideo;
    double rating,tasa;
    char c;
    while (true) {
        fechaCreacion=AlmacenarFecha(leer_canales);
        if (leer_canales.eof()) break;
        ignorar(leer_canales,' ');
        while (true) {
            leer_canales>>CodVideo;
            fechaPublicacion=AlmacenarFecha(leer_canales);
            HoraPublicacion=AlmacenarDuracion(leer_canales);
            leer_canales>>rating>>tasa;
            posVideo=BuscarVideo(codigo_video,n_videos,CodVideo);
            if (posVideo!=-1) {
                if (UltimaFecha[posVideo]==0 or fechaPublicacion>UltimaFecha[posVideo]) {
                    UltimaFecha[posVideo]=fechaPublicacion;
                }
                if (FechaAntigua[posVideo]==0 or fechaPublicacion<FechaAntigua[posVideo]) {
                    FechaAntigua[posVideo]=fechaPublicacion;
                }
                veces[posVideo]++;
                sumaRating[posVideo]+=rating;
                sumatasas[posVideo]+=tasa;
            }
            c=leer_canales.get();
            if (c=='\n')break;
        }
    }
}

void ordenarArreglos(int *codigo_video, int *duracion,
                    int *codigo_idioma, int n_videos,int *UltimaFecha,
                    int *FechaAntigua,int *veces,double *sumaRating,
                    double *sumatasas) {
    for (int i=0;i<n_videos;i++) {
        for (int k=i+1;k<n_videos;k++) {
            if (duracion[i]>duracion[k] or duracion[i]==duracion[k]
                and codigo_video[i]>codigo_video[k]) {
                swapInt(duracion[i],duracion[k]);
                swapInt(codigo_video[i],codigo_video[k]);
                swapInt(veces[i],veces[k]);
                swapDouble(sumaRating[i],sumaRating[k]);
                swapDouble(sumatasas[i],sumatasas[k]);
                swapInt(codigo_idioma[i],codigo_idioma[k]);
                swapInt(FechaAntigua[i],FechaAntigua[k]);
                swapInt(UltimaFecha[i],UltimaFecha[k]);
            }
        }
    }
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"YOUTUBE"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"ALL VIDEOS REPORT"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimirSegundoEncabezado(ofstream &write) {
    write<<"VIDEO";
    write<<setw(8)<<""<<"IDIOMA";
    write<<setw(8)<<""<<"FECHA ANTIGUA";
    write<<setw(8)<<""<<"FECHA RECIENTE";
    write<<setw(8)<<""<<"PROMEDIO RATING";
    write<<setw(8)<<""<<"TASA PROMEDIO";
    write<<setw(8)<<""<<"DURACION"<<endl;
}

void imprimirReporte(const char*reporte,int *codigo_video, int *duracion,
                     int *codigo_idioma, int n_videos,int *UltimaFecha,
                     int *FechaAntigua,int *veces,double *sumaRating,
                     double *sumatasas) {
    ofstream write;
    apertura_escritura(reporte,write);
    int i=0;
    imprimirEncabezado(write);
    imprimirSegundoEncabezado(write);
    while (i<n_videos) {
        write<<codigo_video[i];
        write<<setw(8)<<""<<codigo_idioma[i];
        if (veces[i]) {
            write<<setw(8)<<"";
            imprimir_fecha(FechaAntigua[i],write);
            write<<setw(8)<<"";
            imprimir_fecha(UltimaFecha[i],write);
            write<<setw(8)<<""<<sumaRating[i]/veces[i];
            write<<setw(8)<<""<<sumatasas[i]/veces[i];
            write<<setw(8)<<"";
            imprimirDuracion(duracion[i],write);
            write<<endl;
        }
        else {
            write<<setw(8)<<""<<"No se encontro el video"<<endl;
        }
        i++;
    }
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

int BuscarVideo(int *codigo_video,int n_videos,int codigo) {
    int i=0;
    while (i<n_videos) {
        if (codigo_video[i]==codigo) {
            return i;
        }
        i++;
    }
    return -1;
}