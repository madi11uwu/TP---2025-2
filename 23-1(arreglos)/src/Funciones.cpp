//
// Created by Madi on 28/09/2025.
//

#include "Funciones.hpp"

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

void imprimir_encabezado(ofstream &write,int fecha1,int fecha2) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"LIBRERIA LOS LIBROS_TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"VENTA DE LIBROS EN EL RANGO ";
    imprimir_fecha(write,fecha1);
    write<<" AL ";
    imprimir_fecha(write,fecha2);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_fecha(ofstream &write,int fecha) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

void ignorar(ifstream &leer, char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void cargarAutores(const char *autores, int *codigo_autor, int *libros_autor, double *porcentaje_regalias, int &n_autores) {
    ifstream leer_autores;
    apertura_lectura(autores,leer_autores);
    int c_autor;
    while (true) {
        leer_autores>>c_autor;
        if (leer_autores.eof())break;
        leer_autores>>libros_autor[n_autores];
        leer_autores>>porcentaje_regalias[n_autores];
        codigo_autor[n_autores]=c_autor;
        n_autores++;
    }
}

void probarAutores(const char *salidaAutores, int *codigo_autor, int *libros_autor, double *porcentaje_regalias, int n_autores) {
    ofstream write;
    apertura_escritura(salidaAutores,write);
    int i=0;
    write<<"AUTORES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/3)<<""<<"CODIGO DE AUTOR";
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO DE LIBRO";
    write<<setw(ANCHO_REPORTE/4)<<""<<"PORCENTAJE REGALIAS"<<endl;
    while (i<n_autores) {
        write<<setw(ANCHO_REPORTE/3)<<""<<codigo_autor[i];
        write<<setw(ANCHO_REPORTE/3)<<""<<libros_autor[i];
        write<<setw(ANCHO_REPORTE/3)<<""<<fixed<<setprecision(2)<<porcentaje_regalias[i]<<endl;
        i++;
    }
    write.close();
}

void GenerarArreglos (const char*ventas,int *codigo_libro, double *precios, int n_libros,int *cantidadVentasLibros,
                        double *montoPorLibro,int fecha1,int fecha2) {
    ifstream leer_ventas;
    apertura_lectura(ventas,leer_ventas);
    int fecha,c_libro,pos_libro;
    double cantVendida;
    char c;
    while (true) {
        fecha=AlmacenarFecha(leer_ventas);
        if (leer_ventas.eof()) break;
        if (!ValidarFecha(fecha,fecha1,fecha2)) {
            leer_ventas.ignore(200,'\n');
            continue;
        }
        while (true) {
            leer_ventas>>c_libro>>cantVendida;
            pos_libro=Buscar(codigo_libro,n_libros,c_libro);
            if (pos_libro!=-1) {
                cantidadVentasLibros[pos_libro]+=cantVendida;
                montoPorLibro[pos_libro]+=cantVendida*precios[pos_libro];
            }
            c=leer_ventas.get();
            if (c=='\n')break;
        }
    }
}

void imprimir_reporte(const char*salida,int *codigo_libro, double *precios, int n_libros,int *cantidadVentasLibros,
                       double *montoPorLibro,int *codigo_autor,int *libros_autor,double *porcentaje_regalias,int n_autores,
                       int fecha1,int fecha2) {
    ofstream write;
    apertura_escritura(salida,write);
    int nro_libro=1,i=0;
    imprimir_encabezado(write,fecha1,fecha2);
    while (i<n_libros) {
        imprimir_encabezadoLibro(write,nro_libro);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+2))<<""<<codigo_libro[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1 +4)<<""<<cantidadVentasLibros[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1 +3)<<""<<fixed<<setprecision(2)<<precios[i];
        write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1 +3)<<""<<montoPorLibro[i]<<endl;
        imprimir_encabezadoAutores(write);
        imprimir_datos(write,codigo_libro[i],n_autores,codigo_autor,porcentaje_regalias,libros_autor,montoPorLibro,i);
        imprimir_linea(ANCHO_REPORTE,'=',write);
        i++;
        nro_libro++;
    }
}

void imprimir_datos(ofstream &write,int codigo_libro,int n_autores,int *codigo_autor,double *porcentaje_regalias,int *libros_autor,double *montoPorLibro,int libro) {
    int i=0;
    while (i<n_autores) {
        if (libros_autor[i]==codigo_libro) {
            write<<setw(5)<<""<<codigo_autor[i];
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+2))<<""<<porcentaje_regalias[i]<<"%";
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+2))<<""<<(porcentaje_regalias[i]/100.0)*montoPorLibro[libro]<<endl;
        }
        i++;
    }
}
void imprimir_encabezadoLibro(ofstream &write,int nro_libro) {
    write<<setw(2)<<setfill('0')<<nro_libro<<")";
    write<<setfill(' ');
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+2))<<""<<"LIBRO";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"CANTIDAD";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"PRECIO";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS1)<<""<<"MONTO RECAUDADO"<<endl;
}

void imprimir_encabezadoAutores(ofstream &write) {
    write<<setw(5)<<""<<"REGALIAS PARA LOS AUTORES"<<endl;
    write<<setw(5)<<""<<"AUTOR";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+4))<<""<<"PORCENTAJE A RECIBIR";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+4))<<""<<"MONTO A RECIBIR"<<endl;
}
int Buscar(int *arreglo,int n,int busqueda) {
    int i=0;
    while (i<n) {
        if (arreglo[i]==busqueda) {
            return i;
        }
        i++;
    }
    return -1;
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

bool ValidarFecha(int fecha,int fecha1,int fecha2) {
    if (fecha>=fecha1 and fecha<=fecha2)return true;
    else return false;
}
void cargarLibros(const char *libros, int *codigo_libro, double *precios, int &n_libros) {
    ifstream leer_libros;
    apertura_lectura(libros,leer_libros);
    int c_libro;
    while (true) {
        leer_libros>>c_libro;
        if (leer_libros.eof()) break;
        ignorar(leer_libros,' ');
        leer_libros>>precios[n_libros];
        codigo_libro[n_libros]=c_libro;
        n_libros++;
    }
}

void probarLibros(const char *salida_libros, int *codigo_libro, double *precios, int n_libros) {
    ofstream write;
    apertura_escritura(salida_libros,write);
    int i=0;
    write<<"LIBROS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<setw(ANCHO_REPORTE/4)<<""<<"CODIGO DE LIBRO";
    write<<setw(ANCHO_REPORTE/4)<<""<<"PRECIOS"<<endl;
    while (i<n_libros) {
        write<<setw(ANCHO_REPORTE/4)<<""<<codigo_libro[i];
        write<<setw(ANCHO_REPORTE/3 -2)<<""<<fixed<<setprecision(2)<<precios[i]<<endl;
        i++;
    }
    write.close();
}
