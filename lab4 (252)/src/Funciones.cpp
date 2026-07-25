//
// Created by Madi on 1/10/2025.
//

#include "Funciones.hpp"

void cargarCanales(const char *canales, int *fechaCreacion, char *cCanal, int *int_canal, double *rating, int &n_canal) {
    ifstream leer_canales;
    apertura_lectura(canales,leer_canales);
    int fecha;
    while (true) {
        fecha=AlmacenarFecha(leer_canales);
        if (leer_canales.eof())break;
        leer_canales>>ws>>cCanal[n_canal]>>int_canal[n_canal];
        ignorar(leer_canales,' ');
        leer_canales>>rating[n_canal];
        fechaCreacion[n_canal]=fecha;
        ignorar(leer_canales,'\n');
        n_canal++;
    }
}

void probarCanales(const char *reporteCanal, int *fechaCreacion, char *cCanal, int *int_canal, double *rating, int n_canal) {
    ofstream write;
    apertura_escritura(reporteCanal,write);
    int i=0;
    write<<"CANALES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/3)<<""<<"FECHA DE CREACION";
    write<<setw(ANCHO_REPORTE/3)<<""<<"CODIGO DE CANAL";
    write<<setw(ANCHO_REPORTE/3)<<""<<"RATING"<<endl;
    while (i<n_canal) {
        write<<setw(ANCHO_REPORTE/3)<<"";
        imprimir_fecha(write,fechaCreacion[i]);
        write<<setw(ANCHO_REPORTE/3)<<""<<cCanal[i]<<int_canal[i];
        write<<setw(ANCHO_REPORTE/3)<<""<<rating[i]<<endl;
        i++;
    }
}

void ignorar(ifstream &leer,char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void cargarEtiquetas(const char *etiquetas, int *codigoEtiqueta, int *duracionEtiqueta, int &n_etiquetas) {
    ifstream leer_etiquetas;
    apertura_lectura(etiquetas,leer_etiquetas);
    int codigo,duracion;
    while (true) {
        leer_etiquetas>>codigo;
        if (leer_etiquetas.eof())break;
        ignorar(leer_etiquetas,' ');
        duracion=AlmacenarDuracion(leer_etiquetas);
        codigoEtiqueta[n_etiquetas]=codigo;
        duracionEtiqueta[n_etiquetas]=duracion;
        n_etiquetas++;
    }
}

void probarEtiquetas(const char *ReporteEtiquetas, int *codigoEtiqueta, int *duracionEtiqueta, int n_etiquetas) {
    ofstream write;
    apertura_escritura(ReporteEtiquetas,write);
    int i=0;
    write<<"ETIQUETAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/3)<<""<<"CODIGO DE ETIQUETAS";
    write<<setw(ANCHO_REPORTE/3 -15)<<""<<"DURACION"<<endl;
    while (i<n_etiquetas) {
        write<<setw(ANCHO_REPORTE/3)<<""<<codigoEtiqueta[i];
        write<<setw(ANCHO_REPORTE/3)<<"";
        imprimir_duracion(write,duracionEtiqueta[i],'M');
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

void imprimir_duracion(ofstream &write,int duracion,char c) {
    if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
        write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    else if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60;
        write<<setw(2)<<setfill('0')<<(duracion%60);
    }
    write<<setfill(' ');
}
int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}
void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
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

void ArmarEtiquetas(const char *repro,int *codigoEtiqueta, int *duracionEtiqueta, int n_etiquetas,
                    char *cCanal, int *int_canal, int n_canal,
                    int *TotalReproEtiqueta,int *TotalTiempoReproEtiqueta,int *TotalReproCanal,
                    int *TotalTiempoReproCanal) {
    ifstream leer_repro;
    apertura_lectura(repro,leer_repro);
    int fecha,entero_canal,c_etiqueta,reproducciones,pos_etiqueta,pos_canal;
    char c_canal;
    while (true) {
        fecha=AlmacenarFecha(leer_repro);
        if (leer_repro.eof())break;
        leer_repro>>c_canal>>entero_canal>>c_etiqueta>>reproducciones;
        pos_canal=buscar_canal(cCanal,int_canal,n_canal,c_canal,entero_canal);
        pos_etiqueta=buscar_etiqueta(codigoEtiqueta,n_etiquetas,c_etiqueta);
        if (pos_etiqueta!=1) {
            TotalReproEtiqueta[pos_etiqueta]+=reproducciones;
            TotalTiempoReproEtiqueta[pos_etiqueta]+=reproducciones*duracionEtiqueta[pos_etiqueta];
        }
        if (pos_canal!=1) {
            TotalReproCanal[pos_canal]+=reproducciones;
            TotalTiempoReproCanal[pos_canal]+=reproducciones*duracionEtiqueta[pos_etiqueta];
        }
    }
}

int DevolverPorcentajeCalidad(double rating) {
    if (rating>4 and rating<5) return 30;
    else if (rating>3 and rating<4) return 20;
    else if (rating>2 and rating<3) return 0;
    else if (rating>1 and rating<2) return -25;
}

int buscar_canal(char *cCanal,int *int_canal,int n,char c_canal, int entero_canal) {
    int i=0;
    while (i<n) {
        if (cCanal[i]==c_canal and int_canal[i]==entero_canal) {
            return i;
        }
        i++;
    }
    return -1;
}

int buscar_etiqueta(int *codigoEtiqueta,int n,int c_etiqueta) {
    int i=0;
    while (i<n) {
        if (codigoEtiqueta[i]==c_etiqueta) {
            return i;
        }
        i++;
    }
    return -1;
}

void imprimirEncabezadoCanales(ofstream &write) {
    write<<"CANALES ADSCRITOS A LA PLATAFORMA"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"FECHA DE CREACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"RATING DE CALIDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"NUMERO TOTAL DE REPRODUCCIONES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"TIEMPO TOTAL DE REPRODUCCIONES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"PORCENTAJE POR RATING DE CALIDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"INGRESOS POR REPRODUCCION DE ETIQUETAS"<<endl;
}

void imprimirEncabezadoEtiquetas(ofstream &write) {
    write<<"ETIQUETAS DE LA PLATAFORMA"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"ETIQUETA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"DURACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"CANTIDAD TOTAL DE REPRODUCCIONES";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"TIEMPO TOTAL DE REPRODUCIDO"<<endl;
}

void imprimir_reporte(const char*reporte,int *codigoEtiqueta, int *duracionEtiqueta, int n_etiquetas,
                        int *fechaCreacion, char *cCanal, int *int_canal, double *rating, int n_canal,
                        int *TotalReproEtiqueta,int *TotalTiempoReproEtiqueta,int *TotalReproCanal,
                    int *TotalTiempoReproCanal,double tarifa) {
    ofstream write;
    apertura_escritura(reporte,write);
    int i=0,j=0,nro_etiqueta=1,nro_canal=1;
    imprimirEncabezado(write,tarifa);
    imprimirEncabezadoCanales(write);
    while (i<n_canal) {
        write<<nro_canal;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<cCanal[i]<<int_canal[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<"";
        imprimir_fecha(write,fechaCreacion[i]);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<rating[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<TotalReproCanal[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<"";
        imprimir_duracion(write,TotalTiempoReproCanal[i],'H');
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<DevolverPorcentajeCalidad(rating[i])<<"%";
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<(TotalTiempoReproCanal[i]/60.0)*((100+DevolverPorcentajeCalidad(rating[i]))/100.0)*tarifa;
        write<<endl;
        nro_canal++;
        i++;
    }
    imprimirEncabezadoEtiquetas(write);
    while (j<n_etiquetas) {
        write<<nro_etiqueta;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<codigoEtiqueta[j];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<"";
        imprimir_duracion(write,duracionEtiqueta[j],'M');
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<TotalReproEtiqueta[j];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<"";
        imprimir_duracion(write,TotalTiempoReproEtiqueta[j],'H');
        write<<endl;
        nro_etiqueta++;
        j++;
    }
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimirEncabezado(ofstream &write,double tarifa) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"TARIFA POR DURACION DE LAS ETIQUETAS: "<<tarifa<<" POR CADA MINUTO Y FRACCION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
