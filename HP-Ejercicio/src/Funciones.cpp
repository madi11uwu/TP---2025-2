//
// Created by Madi on 30/11/2025.
//

#include "Funciones.hpp"

#include "NodoPersonaje.hpp"

void apertura_lectura(const char *file, ifstream &read) {
    read.open(file, ios::in);
    if (!read.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof())return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

struct NodoPersonaje * buscarPosicion(char * nombre, struct NodoPersonaje *&lista) {
    struct NodoPersonaje *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (strcmp(recorrido->dato.nombre,nombre)==0) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void insertarOrdenado(struct NodoPersonaje *&lista, const struct Personaje personaje) {
    struct NodoPersonaje *nuevo_nodo;
    nuevo_nodo=new struct NodoPersonaje;
    nuevo_nodo->dato=personaje;
    nuevo_nodo->siguiente=nullptr;
    struct NodoPersonaje *recorrido;
    struct NodoPersonaje *anterior;
    recorrido=lista;
    anterior=nullptr;
    while (recorrido) {
        if (strcmp(recorrido->dato.nombre,personaje.nombre)>0)break;
            anterior=recorrido;
            recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr) lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void cargarPersonajes(const char *file, struct NodoPersonaje *&lista) {
    ifstream read;
    apertura_lectura(file,read);
    lista=nullptr;
    char *nombre;
    while (true) {
        nombre=leer_cadena(20,',',read);
        if (read.eof())break;
        struct Personaje p{};
        struct NodoPersonaje *posicion=buscarPosicion(nombre,lista);
        if (posicion==nullptr) {
            int d=p.cantidadOraciones;
            p.oraciones=new struct Oracion[40]{};
            p.oraciones[d].oracion=leer_cadena(200,',',read);
            cout<<p.oraciones[d].oracion<<endl;
            p.oraciones[d].temporada=leer_int(read);
            p.nombre=nombre;
            p.cantidadOraciones++;
            insertarOrdenado(lista,p);
        }
        else {
            int n=posicion->dato.cantidadOraciones;
            posicion->dato.oraciones[n].oracion=leer_cadena(120,',',read);
            cout<<posicion->dato.oraciones[n].oracion<<endl;
            posicion->dato.oraciones[n].temporada=leer_int(read);
            posicion->dato.cantidadOraciones++;
        }
    }
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}
