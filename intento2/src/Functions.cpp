//
// Created by Madi on 1/09/2025.
//
#include "Functions.hpp"
void imprimir_reporte() {
    imprimir_encabezado();

}

void imprimir_encabezado() {
    int numero;
    char caracter;
    cout<<left<<setw(20)<<"INFORME DE PRECIPITACIONES"<<endl;
    cout<<"NOMBRE: ";
    cin>>numero;
    cin>>ws;
    imprimir_mayusculas();
    cout<<"CIUDAD: ";
    cin>>ws;

}

char convertir_mayusculas(char caracter) {
    return (caracter-("a"-"A"));
}

void imprimir_mayusculas() {
    while (true) {
        cin>>caracter;
        cout<<convertir_mayusculas(caracter);
        if (caracter==',') {
            break;
        }
    }
}

