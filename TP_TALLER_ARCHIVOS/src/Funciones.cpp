//
// Created by Madi on 10/10/2025.
//

#include "Funciones.hpp"

void apertura_lectura(const char *file,ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file,ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void generarReporte(int fechaInicial, int fechaFinal,const char *clientes,
                    const char*libros,const char *ventas,const char*reporte) {
    ifstream leer_clientes;
    ifstream leer_libros;
    ifstream leer_ventas;
    apertura_lectura(clientes,leer_clientes);
    apertura_lectura(libros,leer_libros);
    apertura_lectura(ventas,leer_ventas);
    ofstream write;
    apertura_escritura(reporte,write);
    imprimir_EncabezadoPrincipal(fechaInicial,fechaFinal,write);
    imprimir_reporte(fechaInicial,fechaFinal,leer_clientes,leer_libros,
                        leer_ventas,write);
    leer_ventas.close();
    leer_clientes.close();
    leer_libros.close();
    write.close();
}

void imprimir_EncabezadoPrincipal(int fechaInicial,int fechaFinal,ofstream &write) {
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"REPORTE DE VENTAS POR LIBROS"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"DESDE: ";
    imprimir_fecha(fechaInicial,write);
    write<<"     HASTA: ";
    imprimir_fecha(fechaFinal,write);
    write<<endl;
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
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<fecha/10000;
    write<<setfill(' ');
}

void leer_nombres(ifstream &leer,char c,char c1,ofstream &write) {
    char car;
    leer>>ws;
    if (c=='L' or c=='A') {
        car=leer.get();
        while (true) {
            car=leer.get();
            if (car==c1)break;
            if (car>='a' and car<='z') car=car-32;
            write.put(car);
        }
    }
    else if (c=='N') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            write.put(car);
        }
    }
}

void imprimir_reporte(int fechaInicial, int fechaFinal,ifstream &leer_clientes,
                      ifstream &leer_libros,ifstream &leer_ventas,ofstream &write) {
    int codigo_libro;
    double precio;
    while (true) {
        leer_libros>>codigo_libro;
        if (leer_libros.eof()) break;
        imprimir_parteEstatica(leer_libros,write,precio);
        imprimir_parteDinamica(leer_clientes,leer_ventas,write,codigo_libro,
                                fechaInicial,fechaFinal);
        imprimir_linea(ANCHO_REPORTE,'-',write);
    }
}

void imprimir_encabezadoSecundario(ofstream &write) {
    write<<"LIBRERIA";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"CLIENTE";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"TIPO";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"FECHA VENTA";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"CALIFICACION"<<endl;
}

void imprimir_parteEstatica(ifstream &leer_libros,ofstream &write,double precio) {
    write<<"LIBRO: ";
    leer_nombres(leer_libros,'L',']',write);
    write<<setw(15)<<""<<"AUTOR: ";
    leer_nombres(leer_libros,'A','*',write);
    leer_libros>>precio;
    write<<setw(10)<<""<<"PRECIO: S/.   "<<fixed<<setprecision(2)<<precio<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void imprimir_parteDinamica(ifstream &leer_clientes,ifstream &leer_ventas,ofstream &write,int codigo,
                            int fechaInicial,int fechaFinal) {
    imprimir_encabezadoSecundario(write);
    int codigo_libreria,fecha,codigo_libro,DNI,calificacion,nroVentas;
    leer_ventas.clear();
    leer_ventas.seekg(0,ios::beg);
    while (true) {
        leer_ventas>>codigo_libreria;
        if (leer_ventas.eof())break;
        fecha=AlmacenarFecha(leer_ventas);
        if (!ValidarFecha(fechaInicial,fechaFinal,fecha)) {
            leer_ventas.ignore(1000,'\n');
            continue;
        }
        imprimir_datosDinamicos(leer_clientes,leer_ventas,write,codigo_libreria,
                                fecha,codigo,nroVentas);
    }
}

void imprimir_datosDinamicos(ifstream &leer_clientes,ifstream &leer_ventas,ofstream &write,
                            int codigo_libreria,int fecha,int codigo,int &nroVentas) {
    int codigo_libro,DNI,calificacion;
    nroVentas=0;
    char c;
    while (true) {
        leer_ventas>>codigo_libro>>DNI>>calificacion;
        if (codigo_libro==codigo) {
            write<<setw(2)<<""<<codigo_libreria;
            BuscarCliente(leer_clientes,DNI,write);
            write<<setw(10)<<"";
            imprimir_fecha(fecha,write);
            write<<setw(10)<<""<<calificacion<<endl;
            nroVentas++;
        }
        c=leer_ventas.get();
        if (c=='\n')break;
    }
}

void BuscarCliente(ifstream &leer_clientes,int DNI,ofstream &write) {
    leer_clientes.clear();
    leer_clientes.seekg(0,ios::beg);
    int DNILeido;
    char TipoCliente;
    while (true) {
        leer_clientes>>DNILeido;
        if (leer_clientes.eof())break;
        if (DNILeido==DNI) {
            leer_clientes>>ws>>TipoCliente;
            write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<DNILeido;
            write<<" - ";
            leer_nombres(leer_clientes,'N','\n',write);
            write<<setw(10)<<TipoCliente;
        }
        else {
            leer_clientes.ignore(200,'\n');
            continue;
        }
    }
}
bool ValidarFecha(int fechaInicial,int fechaFinal,int fecha) {
    if (fecha>=fechaInicial and fecha<=fechaFinal) return true;
    else return false;
}