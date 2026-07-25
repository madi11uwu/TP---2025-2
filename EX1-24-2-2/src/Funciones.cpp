//
// Created by Madi on 12/10/2025.
//

#include "Funciones.hpp"

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

void cargarClientes(const char *cliente, int *DNICliente, int *codigo_distrito, char *tipo_vehiculo,
    double *descuento, int &n_clientes) {
    ifstream leer_clientes;
    apertura_lectura(cliente,leer_clientes);
    int DNI;
    char c;
    while (true) {
        leer_clientes>>DNI;
        if (leer_clientes.eof()) break;
        ignorar(leer_clientes,']');
        leer_clientes>>codigo_distrito[n_clientes];
        DNICliente[n_clientes]=DNI;
        ignorar(leer_clientes,' ');
        leer_clientes>>ws>>tipo_vehiculo[n_clientes];
        leer_clientes>>ws>>c;
        if (c=='S') {
            leer_clientes>>descuento[n_clientes]>>c;
        }
        else {
            descuento[n_clientes]=0.0;
        }
        n_clientes++;
    }
}

void probarClientes(const char *reporte_clientes,int *DNICliente, int *codigo_distrito, char *tipo_vehiculo,
    double *descuento, int n_clientes) {
    ofstream write;
    apertura_escritura(reporte_clientes, write);
    int i=0;
    write<<"CLIENTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"DNI DEL CLIENTE";
    write<<setw(10)<<""<<"CODIGO DEL DISTRITO";
    write<<setw(10)<<""<<"TIPO DE VEHICULO";
    write<<setw(10)<<""<<"VALOR DEL DESCUENTO"<<endl;
    while (i<n_clientes) {
        write<<DNICliente[i];
        write<<setw(10)<<""<<codigo_distrito[i];
        write<<setw(10)<<""<<tipo_vehiculo[i];
        write<<setw(10)<<""<<descuento[i]<<endl;
        i++;
    }
}

void cargarPlatos(const char *platos, int *codigo_plato, double *precioPlato, int *cantidadHecha, double *descuentoPlato,
    int &n_platos) {
    ifstream leer_platos;
    apertura_lectura(platos,leer_platos);
    int codigo;
    char c;
    while (true) {
        leer_platos>>codigo;
        if (leer_platos.eof())break;
        ignorar(leer_platos,'}');
        leer_platos>>precioPlato[n_platos];
        leer_platos>>cantidadHecha[n_platos];
        c=leer_platos.get();
        if (c=='\n')descuentoPlato[n_platos]=0.0;
        else {
            leer_platos>>descuentoPlato[n_platos]>>c;
        }
        codigo_plato[n_platos]=codigo;
        n_platos++;
    }
}

void probarPlatos(const char *reporte_platos, int *codigo_plato, double *precioPlato, int *cantidadHecha, double *descuentoPlato,
    int &n_platos) {
    ofstream write;
    apertura_escritura(reporte_platos, write);
    int i=0;
    write<<"PLATOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"CODIGO DEL PLATO";
    write<<setw(10)<<""<<"PRECIO";
    write<<setw(10)<<""<<"CANTIDAD HECHA";
    write<<setw(10)<<""<<"DESCUENTO"<<endl;
    while (i<n_platos) {
        write<<codigo_plato[i];
        write<<setw(10)<<""<<precioPlato[i];
        write<<setw(10)<<""<<cantidadHecha[i];
        write<<setw(10)<<""<<descuentoPlato[i]<<endl;
        i++;
    }
}


void ignorar(ifstream &leer, char c) {
    leer>>ws;
    char car;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}
