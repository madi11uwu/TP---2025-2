//
// Created by Madi on 17/11/2025.
//
#include "cmake-build-debug/Persona.hpp"
#include "Funciones.hpp"
void apertura_lectura(const char *file,ifstream &read) {
    read.open(file,ios::in);
    if (!read.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void cargarPersona(const char *str, struct Persona &persona, int &n_personas) {
    ifstream read;
    apertura_lectura(str,read);
    char *nombre;
    while (true) {
        nombre=read_str(20,',',read);
        if (read.eof())break;

    }
}

char *read_str(int n,char c,ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof())return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}
