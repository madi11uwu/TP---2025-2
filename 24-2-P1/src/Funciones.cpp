//
// Created by Madi on 13/10/2025.
//

#include "Funciones.hpp"

void generarReporteRepartos(const char *repartos, const char *platos, const char *clientes,
                            const char *repartidores, const char *reporte) {
    ifstream leer_repartos;
    ifstream leer_platos;
    ifstream leer_clientes;
    ifstream leer_repartidores;
    ofstream write;
    apertura_lectura(repartos, leer_repartos);
    apertura_lectura(platos, leer_platos);
    apertura_lectura(clientes, leer_clientes);
    apertura_lectura(repartidores,leer_repartidores);
    apertura_escritura(reporte, write);
    imprimir_reporte(leer_repartos,leer_platos,leer_clientes,leer_repartidores,write);
    leer_repartos.close();
    leer_platos.close();
    leer_clientes.close();
    leer_repartidores.close();
    write.close();
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

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITLULO2)/2)<<""<<"CLIENTES POR ATENDER"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_reporte(ifstream &leer_repartos,ifstream &leer_platos,
                      ifstream &leer_clientes,ifstream &leer_repartidores,
                      ofstream &write) {
    int DNI,codigo_distrito;
    double descuento_cliente;
    imprimirEncabezado(write);
    while (true) {
        int nroPedido=1;
        leer_clientes>>DNI;
        if (leer_clientes.eof())break;
        imprimirParteEstatica(leer_clientes,write,DNI,descuento_cliente,codigo_distrito);
        imprimir_linea(ANCHO_REPORTE,'-',write);
        write<<"REPARTOS:"<<endl;
        imprimir_linea(ANCHO_REPORTE,'-',write);
        imprimirParteDinamica(leer_platos,leer_repartos,leer_repartidores,nroPedido,write,DNI);
        imprimir_linea(ANCHO_REPORTE,'-',write);
    }
}

void imprimirParteDinamica(ifstream &leer_platos,ifstream &leer_repartos,ifstream &leer_repartidores,
                            int nroPedido,ofstream &write,int DNI) {
    int codigo_pedido,DNILeido,nroPlato,cantidad,codigo_plato;
    double precio,descuento_plato,subtotal,descuentoDelPlato;
    char c;
    leer_repartos.clear();
    leer_repartos.seekg(0,ios::beg);
    while (true) {
        leer_repartos>>codigo_pedido;
        if (leer_repartos.eof()) break;
        leer_repartos>>DNILeido;
        if (DNI==DNILeido) {
            write<<setw(2)<<setfill('0')<<nroPedido<<")"<<setfill(' ');
            write<<" PEDIDO: "<<codigo_pedido<<endl;
            imprimirEncabezadoPlatos(write);
            nroPlato=1;
            while (true) {
                write<<setw(5)<<""<<nroPlato<<")";
                leer_repartos>>cantidad>>codigo_plato;
                imprimirDatosDinamicos(write,leer_repartos,cantidad,
                    codigo_plato,leer_platos,precio,descuento_plato,subtotal,
                    descuentoDelPlato);
                c=leer_repartos.get();
                if (c=='\n')break;
                nroPlato++;
            }
            nroPedido++;
        }
        else {
            leer_repartos.ignore(1000,'\n');
            continue;
        }
    }
}

void imprimirDatosDinamicos(ofstream &write,ifstream &leer_repartos,
                            int cantidad,int codigo_plato,ifstream &leer_platos,
                            double &precio,double &descuento_plato,double &subtotal,
                            double &descuentoDelPlato) {
    write<<codigo_plato<<" - ";
    buscarDescripcionPrecioyDescuentoPlato(leer_platos,precio,descuento_plato,codigo_plato,write);
    write<<setw(10)<<""<<cantidad<<setw(10)<<""<<precio;
    subtotal=precio*cantidad;
    write<<setw(10)<<""<<subtotal;
    write<<setw(10)<<""<<fixed<<setprecision(2)<<descuento_plato;
    descuentoDelPlato=subtotal*descuento_plato/100.0;
    write<<" - "<<descuentoDelPlato<<endl;
}

void buscarDescripcionPrecioyDescuentoPlato(ifstream &leer,double &precio,double &descuento_plato,
                                            int codigo_plato,ofstream &write) {
    leer.clear();
    leer.seekg(0,ios::beg);
    int codigo,cantidadHecha;
    char c;
    while (true) {
        leer>>codigo;
        if (leer.eof())break;
        if (codigo==codigo_plato) {
            leer_nombre(leer,write,'N','}');
            leer>>precio>>cantidadHecha;
            c=leer.get();
            if (c=='\n')descuento_plato=0;
            else leer>>descuento_plato>>c;
        }
        else {
            leer.ignore(200,'\n');
            continue;
        }
    }
}
void imprimirEncabezadoPlatos(ofstream &write) {
    write<<setw(10)<<""<<"PLATO";
    write<<setw(20)<<""<<"CANTIDAD";
    write<<setw(10)<<""<<"PRECIO";
    write<<setw(10)<<""<<"SUBTOTAL";
    write<<setw(10)<<""<<"DESCUENTO"<<endl;
}
void imprimirParteEstatica(ifstream &leer_clientes,ofstream &write,int DNI,
                            double &descuento_cliente,int &codigo_distrito) {
    char c;
    write<<"CLIENTE:"<<DNI<<" - ";
    leer_nombre(leer_clientes,write,'N',']');
    write<<"    DISTRITO: ";
    leer_clientes>>codigo_distrito;
    leer_nombre(leer_clientes,write,'D',' ');
    write<<"    TIPO DE VEHICULO: ";
    leer_clientes>>ws>>c;
    DevolverVehiculo(write,c);
    write<<"    DESCUENTO: ";
    leer_clientes>>ws>>c;
    if (c=='S')leer_clientes>>descuento_cliente>>c;
    else if (c=='N')descuento_cliente=0.0;
    write<<descuento_cliente<<"%"<<endl;
}

void DevolverVehiculo(ofstream &write,char c) {
    if (c=='M') {
        write<<"Motocicleta";
    }
    else if (c=='B')write<<"Bicicleta";
}
void leer_nombre(ifstream &leer,ofstream &write,char c,char c1) {
    leer>>ws;
    char car;
    if (c=='N') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            write.put(car);
        }
    }
    else if (c=='D') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            if (car=='_')car=' ';
            write.put(car);
        }
    }
}