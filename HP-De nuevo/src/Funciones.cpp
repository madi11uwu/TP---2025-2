//
// Created by Madi on 1/12/2025.
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
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}

struct NodoPersonaje * buscarNodo(struct NodoPersonaje * lista, char * nombre) {
    struct NodoPersonaje *recorrido;
    recorrido = lista;
    while (recorrido) {
        if (strcmp(recorrido->dato.nombre,nombre)==0) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void insertarNodo(struct Personaje personaje, struct NodoPersonaje *&lista) {
    struct NodoPersonaje *nuevo_nodo;
    nuevo_nodo = new NodoPersonaje{};
    nuevo_nodo->dato = personaje;
    nuevo_nodo->siguiente = lista;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente = lista;
        lista=nuevo_nodo;
    }
}

void cargarPersonaje(const char *str, struct NodoPersonaje *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    char *nombre;
    while (true) {
        nombre=leer_cadena(80,',',read);
        if (read.eof())break;
        struct NodoPersonaje *posicion=buscarNodo(lista,nombre);
        struct Personaje p{};
        p.oraciones=new struct Oracion[200]{};
        if (posicion==nullptr) {
            int n=p.cantOraciones;
            p.oraciones[n].oracion=leer_cadena(150,'\n',read);
            p.nombre=nombre;
            // p.oraciones[n].pelicula=leer_int(read);
            p.cantOraciones++;
            insertarNodo(p,lista);
        }
        else {
            int d=posicion->dato.cantOraciones;
            posicion->dato.oraciones[d].oracion=leer_cadena(150,'\n',read);
            cout<<posicion->dato.oraciones[d].oracion<<endl;
            // posicion->dato.oraciones[d].pelicula=leer_int(read);
            posicion->dato.cantOraciones++;
        }
    }
}
