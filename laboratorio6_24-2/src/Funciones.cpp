//
// Created by Madi on 2/11/2025.
//

#include "Funciones.hpp"

void cargar_ordenado_repartos(const char *str, int *arr, int *arr_num_platos_vendidos, int n_platos) {

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
}

void imprimir_encabezado(ofstream &) {

}

void insertar_ordenado(int *arrCodigoPlatos, int codigoplato, int &n_datos,
                       int *arrNumPlatosVendidos,int ) {
    int i = n_datos - 1;
    while (i >= 0 and arrCodigoPlatos[i] < codigoplato) {
        arrCodigoPlatos[i+1]=arrCodigoPlatos[i];
        arrNumPlatosVendidos[i+1]=arrNumPlatosVendidos[i];
        i--;
    }
    arrCodigoPlatos[i+1]=codigoplato;

}
