//
// Created by Madi on 20/09/2025.
//

#include "Funciones.hpp"

void CalcularReporte(const char *artista, const char *canciones, const char *reproducciones, const char *reporte) {

}

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