//
// Created by Madi on 4/09/2025.
//

#include "Funciones.hpp"

void imprimir_informe() {
    imprimir_encabezado();

}

void imprimir_encabezado() {
    cout<<left<<setw(40)<<"INFORME DE PRECIPITACIONES"<<endl;
}

void imprimir_datos() {
    int i=1;
    char car;
    while (cin.eof()) {
        cout<<"ESTACION No. "<<i<<endl;
        cout<<endl;
        cout<<"NOMBRE: ";
        imprimir_mayusculas(',');
        cout<<"CIUDAD: ";
        imprimir_mayusculas(',');
        cout<<"REGION: ";
        imprimir_mayusculas(':');
        cout<<endl;

        i++;
    }
}

char convertir_mayusculas(char car) {
    return car-("a"-"A");
}

void imprimir_mayusculas(char carac) {
    while (true) {
        char car;
        cin>>car;
        cout<<convertir_mayusculas(car);
        if (car==carac) {
            break;
        }
    }
}






