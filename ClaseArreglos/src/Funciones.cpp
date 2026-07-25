//
// Created by Madi on 25/09/2025.
//

#include "Funciones.hpp"

void printArray(int *arr,int size) {
    for (int i=0; i<size; i++)
        cout<<"El codigo "<<i+1<<") es: "<<arr[i]<<endl;
}

void leer_codigos(int *codigos, int &n, const char *file) {
    ifstream leer;
    int codigo;
    apertura_lectura(leer,file);
    while (true) {
        leer>>codigo;
        if (leer.eof())break;
        codigos[n] = codigo;
        n++;
    }
}

void apertura_lectura(ifstream &leer, const char *file) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}


int linearSearch(int *codigos, int size, int codigo) {
    for (int i=0; i<size; i++) {
        if (codigo==codigos[i]) {
            return i;
        }
    }
    return -1;
}
