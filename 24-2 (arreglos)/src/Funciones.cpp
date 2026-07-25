//
// Created by Madi on 28/09/2025.
//

#include "Funciones.hpp"

void cargarPlatosOfrecidos(const char *platos, int *codigo_platos, double *precio_platos, int &n_platos) {
    ifstream leer_platos;
    apertura_lectura(platos,leer_platos);
    int c_plato;
    while (true) {
        leer_platos >> c_plato;
        if (leer_platos.eof())break;
        ignorar(leer_platos,' ');
        leer_platos >> precio_platos[n_platos];
        codigo_platos[n_platos] = c_plato;
        ignorar(leer_platos,'\n');
        n_platos++;
    }
}

void probarPlatosOfrecidos(const char *salida_platos, int *codigo_platos, double *precio_platos, int n_platos) {
    ofstream write;
    apertura_escritura(salida_platos,write);
    int i=0;
    write<<"PLATOS OFRECIDOS"<<endl;
    write<<setw(ANCHO_REPORTE/2)<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/2)<<""<<"PRECIO"<<endl;
    while (i<n_platos) {
        write<<setw(ANCHO_REPORTE/2)<<""<<codigo_platos[i];
        write<<setw(ANCHO_REPORTE/2)<<""<<precio_platos[i]<<endl;
        i++;
    }
    write.close();
}

void ignorar(ifstream &leer,char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void cargarRepartidores(const char *repartidores, int *DNI_repartidores, int *codigo_distrito, int &n_repartidores) {
    ifstream leer_repartidores;
    apertura_lectura(repartidores,leer_repartidores);
    int DNI;
    while (true) {
        leer_repartidores>>DNI;
        if (leer_repartidores.eof()) break;
        ignorar(leer_repartidores,' ');
        ignorar(leer_repartidores,' ');
        leer_repartidores>>codigo_distrito[n_repartidores];
        DNI_repartidores[n_repartidores]=DNI;
        ignorar(leer_repartidores,'\n');
        n_repartidores++;
    }
}

void probarRepartidores(const char *salida_repartidores, int *DNI_repartidores, int *codigo_distrito, int n_repartidores) {
    ofstream write;
    apertura_escritura(salida_repartidores,write);
    int i=0;
    write<<"REPARTIDORES"<<endl;
    write<<setw(ANCHO_REPORTE/2)<<""<<"DNI";
    write<<setw(ANCHO_REPORTE/2)<<""<<"CODIGO DISTRITO"<<endl;
    while (i<n_repartidores) {
        write<<setw(ANCHO_REPORTE/2)<<""<<DNI_repartidores[i];
        write<<setw(ANCHO_REPORTE/2)<<""<<codigo_distrito[i]<<endl;
        i++;
    }
    write.close();
}

int buscar(int *arreglo,int n,int busqueda) {
    int i=0;
    while (i<n) {
        if (arreglo[i]==busqueda) {
            return i;
        }
        i++;
    }
    return -1;
}

void procesarArreglos(int *codigo_distrito,int n_repartidores,char *tipo_vehiculos) {
    ifstream leer_repartos;
    apertura_lectura("Datos/RepartosARealizar.txt",leer_repartos);
    int c_distrito,pos;
    char tipo;
    while (true) {
        leer_repartos>>c_distrito;
        if (leer_repartos.eof()) break;
        leer_repartos>>ws>>tipo;
        ignorar(leer_repartos,' ');
        ignorar(leer_repartos,'\n');
        pos=buscar(codigo_distrito,n_repartidores,c_distrito);
        if (pos!=-1) {
            tipo_vehiculos[pos]=tipo;
        }
    }
}

void imprimir_reporte(const char*salida,int *DNI_repartidores, int *codigo_distrito, int n_repartidores,
                        int *codigo_platos, double *precio_platos, int n_platos,char *tipo_vehiculos) {
    ofstream write;
    apertura_escritura(salida,write);
    for (int i=0;i<n_platos;i++) {

    }
}


void imprimir_tipo(ofstream &write,char c) {
    if (c=='M') write<<"MOTOCICLETA";
    else if (c=='B') write<<"BICICLETA";
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
