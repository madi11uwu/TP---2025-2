//
// Created by Madi on 10/10/2025.
//

#include "Funciones.hpp"

void cargarLibros(const char *libros, int *codigo_libro, double *precio_libro, int &n_libros) {
    ifstream leer_libros;
    apertura_lectura(libros,leer_libros);
    int codigo;
    while (true) {
        leer_libros>>codigo;
        if (leer_libros.eof()) break;
        codigo_libro[n_libros] = codigo;
        ignorar(leer_libros,']');
        ignorar(leer_libros,'*');
        leer_libros>>precio_libro[n_libros];
        n_libros++;
    }
}

void probarLibros(const char *reporte_libros, int *codigo_libro, double *precio_libro, int n_libros) {
    ofstream write;
    apertura_escritura(reporte_libros, write);
    int i=0;
    write<<"LIBROS"<<endl;
    imprimirLinea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/5)<<""<<"CODIGO DE LIBROS";
    write<<setw(ANCHO_REPORTE/8)<<""<<"PRECIO"<<endl;
    while (i<n_libros) {
        write<<setw(ANCHO_REPORTE/5)<<""<<codigo_libro[i];
        write<<setw(ANCHO_REPORTE/5)<<""<<precio_libro[i]<<endl;
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

void imprimirLinea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void ignorar(ifstream &leer,char c) {
    char car;
    leer>>ws>>car;
    while (true) {
        car=leer.get();
        if (car==c) break;
    }
}

void imprimirEncabezado(ofstream &write) {
    imprimirLinea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/2)<<""<<"REPORTE DE VENTAS POR LIBRO"<<endl;
    imprimirLinea(ANCHO_REPORTE,'-',write);
    imprimirEncabezadoSecundario(write);
    imprimirLinea(ANCHO_REPORTE,'-',write);
}

void imprimirEncabezadoSecundario(ofstream &write) {
    write<<"#";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"LIBRO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"PRECIO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"UNIDADES.VENDIDAS";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"PROM.CALIFICACION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"TOT.VENTAS";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"PRIMERA.VENTA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<"ULTIMA.VENTA"<<endl;
}

void generarArreglos(const char *ventas, double *promCalificacion, int *unidadesVendidos, double *TotalVentas,
    int *FechaPrimeraVenta, int *DNIPrimeraVenta, int *FechaUltimaVenta, int *DNIUltimaVenta,int n_libros,
    int *codigo_libro,double *precio_libro) {
    ifstream leer_ventas;
    apertura_lectura(ventas,leer_ventas);
    int i=0,codigo;
    while (i<n_libros) {
        codigo=codigo_libro[i];
        llenar_arreglos(leer_ventas,promCalificacion,unidadesVendidos,
                        TotalVentas,FechaPrimeraVenta,DNIPrimeraVenta,FechaUltimaVenta,
                        DNIUltimaVenta,n_libros,codigo,precio_libro,i);
        i++;
    }
}

void ordenarArreglos(int *codigo_libro,double *precio_libro,int n_libros) {
    for (int i=0;i<n_libros-1;i++) {
        for (int k=i+1;k<n_libros;k++) {
            if (precio_libro[i]>precio_libro[k]) {
                swapDouble(precio_libro[i],precio_libro[k]);
                swapInt(codigo_libro[i],codigo_libro[k]);
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

void swapDouble(double &a,double &b) {
    double aux;
    aux=a;
    a=b;
    b=aux;
}

void llenar_arreglos(ifstream &leer, double *promCalificacion, int *unidadesVendidos, double *TotalVentas,
    int *FechaPrimeraVenta, int *DNIPrimeraVenta, int *FechaUltimaVenta, int *DNIUltimaVenta, int n_libros, int codigo,
    double *precio_libro,int i) {
    int codigo_libreria,fecha,codigoBook,DNI,puntuacion;
    char c;
    leer.clear();
    leer.seekg(0,ios::beg);
    FechaPrimeraVenta[i]=99999999;
    while (true) {
        leer>>codigo_libreria;
        if (leer.eof())break;
        fecha=AlmacenarFecha(leer);
        while (true) {
            leer>>codigoBook>>DNI>>puntuacion;
            if (codigoBook==codigo) {
                promCalificacion[i]+=puntuacion;
                unidadesVendidos[i]++;
                TotalVentas[i]+=precio_libro[i];
                if (FechaPrimeraVenta[i]>fecha) {
                    FechaPrimeraVenta[i]=fecha;
                    DNIPrimeraVenta[i]=DNI;
                }
                if (FechaUltimaVenta[i]<fecha) {
                    FechaUltimaVenta[i]=fecha;
                    DNIUltimaVenta[i]=DNI;
                }
            }
            c=leer.get();
            if (c=='\n')break;
        }
    }
    if (unidadesVendidos[i]>0) promCalificacion[i]=promCalificacion[i]/(double)unidadesVendidos[i];
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

void imprimir_reporte(const char*reporte,int *codigo_libro,double *precio_libro,int n_libros,
                      double *promCalificacion,int *unidadesVendidos,
                      double *TotalVentas,int *FechaPrimeraVenta,int *DNIPrimeraVenta,
                      int *FechaUltimaVenta,int *DNIUltimaVenta) {
    ofstream write;
    apertura_escritura(reporte,write);
    imprimirEncabezado(write);
    int i=0,nro_libro=1,UnidadesTotales=0;
    double VentasTotales=0.0;
    while (i<n_libros) {
        write<<setw(3)<<setfill('0')<<nro_libro<<")"<<setfill(' ');
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<codigo_libro[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<fixed<<setprecision(2)<<precio_libro[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<unidadesVendidos[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<promCalificacion[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<""<<TotalVentas[i];
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1))<<"";
        imprimir_fecha(FechaPrimeraVenta[i],write);
        write<<setw(3)<<""<<DNIPrimeraVenta[i]<<setw(5)<<"";
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1));
        imprimir_fecha(FechaUltimaVenta[i],write);
        write<<setw(3)<<""<<DNIUltimaVenta[i]<<endl;
        UnidadesTotales+=unidadesVendidos[i];
        VentasTotales+=TotalVentas[i];
        nro_libro++;
        i++;
    }
    imprimirLinea(ANCHO_REPORTE,'-',write);
    write<<"TOTALES: "<<UnidadesTotales<<setw(10)<<""<<VentasTotales<<endl;
    imprimirLinea(ANCHO_REPORTE,'=',write);
}
