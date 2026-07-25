//
// Created by Madi on 4/10/2025.
//

#include "Funciones.hpp"

void cargar_juegos(const char *juegos, int *fechas_juegos, char *codigo_juegos_char, int *codigos_juegos_int, double *rating,
    int &n_juegos) {
    ifstream leer_juegos;
    apertura_lectura(juegos,leer_juegos);
    while (true) {

        if (leer_juegos.eof()) break;
    }
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}

void cargar_logros_juegos(const char *logros_juegos,char *codigos_char_juegos_logros,
                        int *codigos_int_juegos_logros,int *codigos_logros_juegos_logros,
                        int *cantidad_juegos_logros, int &n_logros_juegos,int n_logros,int *codigo_logros) {
    ifstream leer_juegos_logros;
    apertura_lectura(logros_juegos,leer_juegos_logros);
    char codigo_char_juego;
    int codigo_int_juego,codigo_logro,pos;
    while (true) {
        leer_juegos_logros>>codigo_char_juego;
        if (leer_juegos_logros.eof())break;
        leer_juegos_logros>>codigo_int_juego>>codigo_logro;
        codigos_char_juegos_logros[n_logros_juegos]=codigo_char_juego;
        codigos_int_juegos_logros[n_logros_juegos]=codigo_int_juego;
        codigos_logros_juegos_logros[n_logros_juegos]=codigo_logro;
        n_logros_juegos++;
        pos=buscar_codigo_logro(codigo_logros,n_logros,codigo_logro);
        if (pos!=-1)
            cantidad_juegos_logros[pos]++;
        else cout<<"No se encontraron juegos con este logro"<<endl;
    }
}

int buscar_codigo_logro(int *codigos_logros,int n_logros,int codigo_logro) {
    int i=0;
    while (i<n_logros) {
        if (codigos_logros[i]==codigo_logro) {
            return i;
        }
        i++;
    }
    return -1;
}

void ordenar_arreglos_logros(const char *logros, int *codigos_logros, int *duracionPromedio,int *cantidad_juegos_logros,int n_logros) {
    int aux;
    for (int i=0;i<n_logros-1;i++) {
        for (int k=i+1;k<n_logros;k++) {
            if (duracionPromedio[k]<duracionPromedio[i]) {
                swapInt(codigos_logros[k],codigos_logros[i]);
                swapDouble(duracionPromedio[k],duracionPromedio[i]);
                swapInt(cantidad_juegos_logros[k],cantidad_juegos_logros[i]);
            }
        }
    }
}

void swapInt(int &num1,int &num2) {
    int aux;
    aux=num1;
    num1=num2;
    num2=aux;
}

void swapDouble(int &num1,int &num2) {
    double aux;
    aux=num1;
    num1=num2;
    num2=aux;
}
void swapchar(int &num1,int &num2) {
    int aux;
    aux=num1;
    num1=num2;
    num2=aux;
}