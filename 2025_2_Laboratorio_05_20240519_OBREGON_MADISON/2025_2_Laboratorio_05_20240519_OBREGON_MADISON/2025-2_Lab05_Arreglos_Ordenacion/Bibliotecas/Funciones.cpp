//
// Created by Madi on 6/10/2025.
//

#include "Funciones.hpp"

void cargarCanales(const char *canales, int *FechaCreacion, char *c_canal, int *int_canal, double *rating, int &n_canales) {
    ifstream leer_canales;
    apertura_lectura(canales,leer_canales);
    int fecha;
    while (true) {
        fecha=AlmacenarFecha(leer_canales);
        if (leer_canales.eof()) break;
        FechaCreacion[n_canales]=fecha;
        leer_canales>>ws>>c_canal[n_canales]>>int_canal[n_canales];
        ignorar(leer_canales,' ');
        leer_canales>>rating[n_canales];
        n_canales++;
    }
}

void probarCanales(const char *reporte_canales,int *FechaCreacion,
                    char *c_canal,int *int_canal,double *rating,int n_canales) {
    ofstream write;
    apertura_escritura(reporte_canales,write);
    int i=0;
    write<<"CANALES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/4)<<""<<"FECHA DE CREACION";
    write<<setw(ANCHO_REPORTE/5)<<""<<"CODIGO DE CANAL";
    write<<setw(ANCHO_REPORTE/6)<<""<<"RATING"<<endl;
    while (i<n_canales) {
        write<<setw(ANCHO_REPORTE/4)<<"";
        imprimir_fecha(FechaCreacion[i],write);
        write<<setw(ANCHO_REPORTE/4)<<""<<c_canal[i]<<int_canal[i];
        write<<setw(ANCHO_REPORTE/4)<<""<<rating[i]<<endl;
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

void imprimirEncabezadoPrincipal(ofstream &write,double rating) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"TARIFA POR DURACION DE LAS ETIQUETAS: ";
    write<<fixed<<setprecision(2)<<rating<<" POR CADA MINUTO Y FRACCION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_linea(int n,char c,ofstream &write) {
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

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100;
    write<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100;
    write<<"/"<<fecha/1000;
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

void cargarEtiquetas(const char *etiquetas, int *codigo_etiqueta, int *duracion, int &n_etiquetas) {
    ifstream leer_etiqueta;
    apertura_lectura(etiquetas,leer_etiqueta);
    int etiqueta,tiempo;
    while (true) {
        leer_etiqueta>>etiqueta;
        if (leer_etiqueta.eof())break;
        codigo_etiqueta[n_etiquetas]=etiqueta;
        ignorar(leer_etiqueta,' ');
        tiempo=AlmacenarDuracion(leer_etiqueta);
        duracion[n_etiquetas]=tiempo;
        n_etiquetas++;
    }
}

void probarEtiquetas(const char *reporte_etiquetas,int *codigo_etiqueta,int *duracion,int n_etiquetas) {
    ofstream write;
    apertura_escritura(reporte_etiquetas,write);
    int i=0;
    write<<"ETIQUETAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO DE LA ETIQUETA";
    write<<setw(ANCHO_REPORTE/4)<<""<<"DURACION"<<endl;
    while (i<n_etiquetas) {
        write<<setw(ANCHO_REPORTE/4)<<""<<codigo_etiqueta[i];
        write<<setw(ANCHO_REPORTE/4)<<"";
        imprimirDuracion(duracion[i],write,'M');
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

void imprimirDuracion(int duracion,ofstream &write,char c) {
    if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60<<":";
        write<<setw(2)<<setfill('0')<<duracion%60;
    }
    else if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3660<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    write<<setfill(' ');
}

void imprimir_encabezadoCanales(ofstream &write) {
    write<<setw(3)<<""<<"CANALES DONDE SE REPRODUCE:"<<endl;
    write<<setw(30)<<""<<"RATING DE";
    write<<setw(8)<<""<<"NUMERO TOTAL";
    write<<setw(10)<<""<<"TIEMPO TOTAL DE"<<endl;
    write<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+6))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+6))<<""<<"CALIDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+6))<<""<<"DE REPRODUCCIONES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+6))<<""<<"REPRODUCCIONES"<<endl;
}

void cargarEtiquetasEnCanales(const char *etiquetasCanales, char *char_canal,int *codigo_canal,
                            int *etiqueta, int &n_etiquetasEnCanales){
    ifstream leer_etiquetasCanales;
    apertura_lectura(etiquetasCanales,leer_etiquetasCanales);
    char c;
    while (true) {
        leer_etiquetasCanales>>c;
        if (leer_etiquetasCanales.eof())break;
        leer_etiquetasCanales>>codigo_canal[n_etiquetasEnCanales]>>etiqueta[n_etiquetasEnCanales];
        char_canal[n_etiquetasEnCanales]=c;
        n_etiquetasEnCanales++;
    }
}

void probarEtiquetasEnCanales(const char *reporte_etiquetaCanales, char *char_canal,
                                int *codigo_canal,int *etiqueta, int n_etiquetasEnCanales) {
    ofstream write;
    apertura_escritura(reporte_etiquetaCanales,write);
    int i=0;
    write<<"ETIQUETAS EN CANALES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO DE CANAL";
    write<<setw(ANCHO_REPORTE/5)<<""<<"CODIGO DE ETIQUETA"<<endl;
    while (i<n_etiquetasEnCanales) {
        write<<setw(ANCHO_REPORTE/4)<<""<<char_canal[i]<<codigo_canal[i];
        write<<setw(ANCHO_REPORTE/4)<<""<<etiqueta[i]<<endl;
        i++;
    }
}

void GenerarArreglos(const char*reproducciones,int *codigo_etiqueta,int *duracion,
                    int n_etiquetas,char *char_canal,int*codigo_canal,
                    int *etiqueta,int n_etiquetasEnCanales,
                    int *NumeroTotalRepros,int *DuracionTotalRepros) {
    ifstream leer_reproducciones;
    apertura_lectura(reproducciones,leer_reproducciones);
    int fecha,canal,cod_etiqueta,repros,pos,posEtiqueta;
    char c;
    while (true) {
        fecha=AlmacenarFecha(leer_reproducciones);
        if (leer_reproducciones.eof()) break;
        leer_reproducciones>>c>>canal>>cod_etiqueta>>repros;
        pos=BuscarCanalYEtiqueta(char_canal,codigo_canal,etiqueta,
                                n_etiquetasEnCanales,c,canal,cod_etiqueta);
        if (pos!=-1) {
            NumeroTotalRepros[pos]+=repros;
            posEtiqueta=BuscarEtiqueta(codigo_etiqueta,n_etiquetas,cod_etiqueta);
            if (posEtiqueta!=-1) {
                DuracionTotalRepros[pos]+=NumeroTotalRepros[pos]*duracion[posEtiqueta];
            }
        }
    }
}

void imprimir_reporte(const char *reporte,char *c_canal,
                        int *int_canal,double *rating,
                        int n_canales,int *codigo_etiqueta,
                        int *duracion,int n_etiquetas,double tarifa,
                        int *NumeroTotalRepros,int *DuracionTotalRepros,
                        char *char_canal,int*codigo_canal,
                        int *etiqueta,int n_etiquetasEnCanales) {
    ofstream write;
    apertura_escritura(reporte,write);
    imprimirEncabezadoPrincipal(write,tarifa);
    int nro_etiqueta=1,etiquetaBuscar,i=0;
    while (i<n_etiquetas) {
        write<<"ETIQUETA No. "<<nro_etiqueta<<endl;
        write<<setw(3)<<""<<"CODIGO: "<<codigo_etiqueta[i]<<endl;
        write<<setw(3)<<""<<"DURACION: ";
        imprimirDuracion(duracion[i],write,'M');
        write<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        etiquetaBuscar=codigo_etiqueta[i];
        imprimir_CanalesEtiquetayEstadisticas(etiquetaBuscar,c_canal,
                                        int_canal,rating,
                                        n_canales,codigo_etiqueta,
                                        duracion,n_etiquetas,tarifa,
                                        NumeroTotalRepros,DuracionTotalRepros,
                                        char_canal,codigo_canal,
                                        etiqueta,n_etiquetasEnCanales,write);
        nro_etiqueta++;
        i++;
    }
}

void imprimir_CanalesEtiquetayEstadisticas(int etiquetaBuscar,char *c_canal,
                                        int *int_canal,double *rating,
                                        int n_canales,int *codigo_etiqueta,
                                        int *duracion,int n_etiquetas,double tarifa,
                                        int *NumeroTotalRepros,int *DuracionTotalRepros,
                                        char *char_canal,int*codigo_canal,
                                        int *etiqueta,int n_etiquetasEnCanales,ofstream &write) {
    int i=0,nro_canal=1,pos_canal;
    int TotalReproEtiqueta=0,TotalDuracionEtiqueta=0,sumaRating=0;
    double promedioRating;
    imprimir_encabezadoCanales(write);
    while (i<n_etiquetasEnCanales) {
        if (etiquetaBuscar==etiqueta[i]) {
            write<<nro_canal<<")";
            write<<setw(10)<<""<<char_canal[i]<<codigo_canal[i];
            pos_canal=BuscarCanal(c_canal,int_canal,n_canales,
                                char_canal[i],codigo_canal[i]);
            if (pos_canal!=-1) {
                write<<setw(15)<<""<<rating[pos_canal];
                write<<setw(15)<<""<<NumeroTotalRepros[i];
                write<<setw(20)<<"";
                imprimirDuracion(DuracionTotalRepros[i],write,'H');
                write<<endl;
                TotalReproEtiqueta+=NumeroTotalRepros[i];
                TotalDuracionEtiqueta+=DuracionTotalRepros[i];
                sumaRating+=rating[pos_canal];
                nro_canal++;
            }
            else {
                write<<setw(15)<<""<<"No se halló el canal"<<endl;
            }
        }
        i++;
    }
    if (nro_canal-1==0) {
        write<<"No se encontró la etiqueta "<<etiquetaBuscar<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
    }
    else {
        imprimir_linea(ANCHO_REPORTE,'-',write);
        promedioRating=static_cast<double>(sumaRating)/(nro_canal-1);
        imprimir_resumenEtiqueta(TotalReproEtiqueta,TotalDuracionEtiqueta,
                                promedioRating,tarifa,write);
    }
}

void imprimir_resumenEtiqueta(int TotalReproEtiqueta,int TotalDuracionEtiqueta,
                                double promedioRating,double tarifa,ofstream &write) {
    write<<"RESUMEN DE LA ETIQUETA:"<<endl;
    write<<setw(2)<<""<<"TOTAL DE REPRODUCCIONES: "<<TotalReproEtiqueta<<endl;
    write<<setw(2)<<""<<"TIEMPO TOTAL REPRODUCIDO: ";
    imprimirDuracion(TotalDuracionEtiqueta,write,'H');
    write<<endl;
    write<<setw(2)<<""<<"PORCENTAJE PROMEDIO POR RATING: "<<DevolverPorcentaje(promedioRating)<<"%"<<endl;
    write<<setw(2)<<""<<"INGRESOS POR REPRODUCCIONES: "<<"S/.";
    write<<(TotalDuracionEtiqueta/60.0)*((100+DevolverPorcentaje(promedioRating))/100.0)*tarifa<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

int DevolverPorcentaje(double promedioRating) {
    if (promedioRating<5 and promedioRating>=4) {
        return 30;
    }
    else if (promedioRating<4 and promedioRating>=3) {
        return 20;
    }
    else if (promedioRating<3 and promedioRating>=2) {
        return 0;
    }
    else if (promedioRating<2 and promedioRating>=1) {
        return -25;
    }
}
int BuscarCanalYEtiqueta(char *char_canal,int*codigo_canal,
                    int *etiqueta,int n_etiquetasEnCanales,
                    char c,int canal,int cod_etiqueta) {
    int i=0;
    while (i<n_etiquetasEnCanales) {
        if (char_canal[i]==c and etiqueta[i]==cod_etiqueta and codigo_canal[i]==canal) {
            return i;
        }
        i++;
    }
    return -1;
}
int BuscarEtiqueta(int *codigo_etiqueta,int n,int cod_etiqueta) {
    int i=0;
    while (i<n) {
        if (codigo_etiqueta[i]==cod_etiqueta) {
            return i;
        }
        i++;
    }
    return -1;
}

int BuscarCanal(char *c_canal,int *int_canal,int n,char c,int canal) {
    int i=0;
    while (i<n) {
        if (c_canal[i]==c and int_canal[i]==canal) {
            return i;
        }
        i++;
    }
    return -1;
}

void ordenarEtiquetas(int *codigo_etiqueta, int *duracion, int n_etiquetas) {
    for (int i=0;i<n_etiquetas-1;i++) {
        for (int k=i+1;k<n_etiquetas;k++) {
            if (duracion[i]<duracion[k]) {
                swapInt(duracion[i],duracion[k]);
                swapInt(codigo_etiqueta[i],codigo_etiqueta[k]);
            }
        }
    }
}

void swapInt(int &a,int &b) {
    int aux;
    aux=a;
    a=b;
    b=aux;
}