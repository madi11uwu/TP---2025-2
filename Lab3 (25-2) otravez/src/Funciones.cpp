//
// Created by Madi on 29/09/2025.
//

#include "Funciones.hpp"

#include <set>

void cargarCanales(const char *canales, int *fechaCreacion, char *c_canal, int *int_canal, double *rating_canal,
                   int &n_canales) {
    ifstream leer_canales;
    apertura_lectura(canales,leer_canales);
    int fecha;
    while (true) {
        fecha=AlmacenarFecha(leer_canales);
        if (leer_canales.eof()) break;
        leer_canales>>ws>>c_canal[n_canales]>>int_canal[n_canales];
        ignorar(leer_canales,' ');
        leer_canales>>rating_canal[n_canales];
        fechaCreacion[n_canales]=fecha;
        ignorar(leer_canales,'\n');
        n_canales++;
    }
}

void ignorar (ifstream &leer,char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void probarCanales(const char *salida_canal,int *fechaCreacion, char *c_canal, int *int_canal, double *rating_canal,
                    int n_canales) {
    ofstream write;
    apertura_escritura(salida_canal,write);
    int i=0;
    write<<"CANALES:"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/3)<<""<<"FECHA DE CREACION";
    write<<setw(ANCHO_REPORTE/3 -10)<<""<<"CODIGO DEL CANAL";
    write<<setw(ANCHO_REPORTE/3 -10)<<""<<"RATING"<<endl;
    while (i<n_canales) {
        write<<setw(ANCHO_REPORTE/3)<<"";
        imprimir_fecha(write,fechaCreacion[i]);
        write<<setw(ANCHO_REPORTE/3)<<""<<c_canal[i]<<int_canal[i];
        write<<setw(ANCHO_REPORTE/3)<<""<<fixed<<setprecision(2)<<rating_canal[i]<<endl;
        i++;
    }
    write.close();
}

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

void cargarEtiquetas(const char *file_etiquetas, int *etiquetas, int *duracion, int &n_etiquetas) {
    ifstream leer_etiquetas;
    apertura_lectura(file_etiquetas,leer_etiquetas);
    int etiqueta,durac;
    while (true) {
        leer_etiquetas>>etiqueta;
        if (leer_etiquetas.eof())break;
        ignorar(leer_etiquetas,' ');
        durac=AlmacenarDuracion(leer_etiquetas);
        etiquetas[n_etiquetas]=etiqueta;
        duracion[n_etiquetas]=durac;
        n_etiquetas++;
    }
}

void probarEtiquetas(const char *salida_etiquetas, int *etiquetas, int *duracion, int n_etiquetas) {
    ofstream write;
    apertura_escritura(salida_etiquetas,write);
    int i=0;
    write<<"ETIQUETAS: "<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/3)<<""<<"ETIQUETA";
    write<<setw(ANCHO_REPORTE/3)<<""<<"DURACION"<<endl;
    while (i<n_etiquetas) {
        write<<setw(ANCHO_REPORTE/3)<<""<<etiquetas[i];
        write<<setw(ANCHO_REPORTE/3)<<"";
        imprimir_duracion(write,duracion[i],'M');
        write<<endl;
        i++;
    }
    write.close();
}

int AlmacenarDuracion(ifstream &leer) {
    int mm,ss;
    char c;
    leer>>mm>>c>>ss;
    return (mm*60+ss);
}
void imprimir_duracion(ofstream &write,int duracion,char c) {
    if (c=='H') {
        write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60;
        write<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    }
    else if (c=='M') {
        write<<setw(2)<<setfill('0')<<duracion/60<<":"<<setw(2)<<setfill('0')<<(duracion%60);
    }
    write<<setfill(' ');
}
int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file, ios::in);
    if (!leer.is_open()) {
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

void imprimir_encabezadoPrincipal(ofstream &write, double tarifa) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"TARIFA POR DURACION DE LAS ETIQUETAS: "<<tarifa<<" POR CADA MINUTO Y FRACCION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void ArmarArreglos(const char*repro,int *etiquetas, int *duracionTotalEtiqueta, int n_etiquetas,
                   char *c_canal, int *int_canal,int *duracion,int n_canales,
                   int *reproTotalPorEtiqueta,int *reproTotalCanal,double tarifa,
                   double *ingresosDuracionEtiquetas) {
    ifstream leer_reproducciones;
    apertura_lectura(repro,leer_reproducciones);
    int pos_etiqueta,pos_canal,fecha,codigo_int_canal,etiquetaLeida,reproducciones;
    char codigo_c_canal;
    while (true) {
        fecha=AlmacenarFecha(leer_reproducciones);
        if (leer_reproducciones.eof())break;
        leer_reproducciones>>ws>>codigo_c_canal>>codigo_int_canal>>etiquetaLeida>>reproducciones;
        pos_canal=buscar_canal(codigo_c_canal,codigo_int_canal,c_canal,int_canal,n_canales);
        pos_etiqueta=buscar_etiqueta(etiquetas,etiquetaLeida,n_etiquetas);
        if (pos_canal!=-1) {
            reproTotalCanal[pos_canal]+=reproducciones;
        }
        if (pos_etiqueta!=-1) {
            reproTotalPorEtiqueta[pos_etiqueta]+=reproducciones;
            duracionTotalEtiqueta[pos_etiqueta]+=reproducciones*duracion[pos_etiqueta];
            ingresosDuracionEtiquetas[pos_etiqueta]+=(duracionTotalEtiqueta[pos_etiqueta]/60.0)*tarifa;
        }
    }
}

int buscar_canal(char codigo_c_canal,int codigo_int_canal,char *c_canal,int *int_canal,int n_canales) {
    int i=0;
    while (i<n_canales) {
        if (codigo_c_canal==c_canal[i] and codigo_int_canal==int_canal[i]) {
            return i;
        }
        i++;
    }
    return -1;
}

int buscar_etiqueta(int *etiquetas,int etiquetaLeida,int n_etiquetas) {
    int i=0;
    while (i<n_etiquetas) {
        if (etiquetaLeida==etiquetas[i]) {
            return i;
        }
        i++;
    }
    return -1;
}

void imprimir_reporte(const char *reporte,int *etiquetas, int *duracionTotalEtiqueta, int n_etiquetas,
                    char *c_canal, int *int_canal,int *duracion,int n_canales,double *rating_canal,
                    int *reproTotalPorEtiqueta,int *reproTotalCanal,int *fechaCreacion,double tarifa,double *ingresosDuracionEtiquetas) {
    ofstream write;
    apertura_escritura(reporte,write);
    int i=0,canal=1,j=0;
    imprimir_encabezadoPrincipal(write,tarifa);
    while (i<n_canales) {
        imprimir_encabezadoCanales(write,canal);
        write<<setw(ANCHO_REPORTE/4)<<""<<c_canal[i]<<int_canal[i];
        write<<setw(ANCHO_REPORTE/4)<<"";
        imprimir_fecha(write,fechaCreacion[i]);
        write<<setw(ANCHO_REPORTE/4)<<""<<rating_canal[i];
        write<<setw(ANCHO_REPORTE/4)<<""<<reproTotalCanal[i]<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        canal++;
        i++;
    }
    imprimir_linea(ANCHO_REPORTE,'=',write);
    imprimir_encabezadoEtiquetas(write);
    while (j<n_etiquetas) {
        write<<etiquetas[j];
        write<<setw(ANCHO_REPORTE/5)<<"";
        imprimir_duracion(write,duracion[j],'M');
        write<<setw(ANCHO_REPORTE/5)<<""<<reproTotalPorEtiqueta[j];
        write<<setw(ANCHO_REPORTE/5)<<"";
        imprimir_duracion(write,duracionTotalEtiqueta[j],'H');
        write<<setw(ANCHO_REPORTE/5)<<""<<ingresosDuracionEtiquetas[j]<<endl;
        j++;
    }
    write.close();
}

void imprimir_encabezadoEtiquetas(ofstream &write) {
    write<<"ETIQUETA";
    write<<setw(ANCHO_REPORTE/6)<<""<<"DURACION";
    write<<setw(ANCHO_REPORTE/7)<<""<<"REPRODUCCIONES TOTALES";
    write<<setw(ANCHO_REPORTE/10)<<""<<"DURACION TOTAL";
    write<<setw(ANCHO_REPORTE/10)<<""<<"INGRESOS POR DURACION"<<endl;
}

void imprimir_encabezadoCanales(ofstream &write,int canal) {
    write<<"CANAL No. "<<canal<<endl;
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/4)<<""<<"CREADO EL";
    write<<setw(ANCHO_REPORTE/4)<<""<<"RATING DE CALIDAD";
    write<<setw(ANCHO_REPORTE/4)<<""<<"REPRODUCCIONES POR CANAL"<<endl;
}