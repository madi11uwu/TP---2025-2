//
// Created by Madi on 27/11/2025.
//

#include "Funciones.hpp"
#include "Comentario.hpp"
#include "Personaje.hpp"
#include "Nodo.hpp"

void apertura_lectura(const char *file, ifstream &read) {
    read.open(file, ios::in);
    if (!read.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

char * leer_cadena(char c, int n, ifstream &read) {
    char buffer[n];
    char *str;
    read.getline(buffer, n,c);
    if (read.eof())return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}

void insertarInicio(struct Nodo *&lista, const struct Personaje & personaje) {
    struct Nodo *nuevo_nodo;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->personaje=personaje;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void cargarPersonajes(const char *file, struct Nodo *&lista) {
    ifstream read;
    apertura_lectura(file,read);
    char *nombre;
    int estado;
    lista=nullptr;
    while (true) {
        nombre=leer_cadena(',',50,read);
        if (read.eof())break;
        struct Personaje p;
        inicializarPersonaje(p);
        p.nombre=nombre;
        estado=leer_int(read);
        p.Estado=retornarEstado(estado);
        insertarInicio(lista,p);
    }
}

void inicializarPersonaje(struct Personaje &p) {
    p.Estado=true;
    p.nombre=nullptr;
    p.palabrasMayuscula=new char*[500]{};
    p.palabrasMinuscula=new char*[500]{};
    p.CantidadComentarios=0;
    p.comentario=new struct Comentario[3]{};
}

bool retornarEstado(int i) {
    if (i==1)return true;
    else return false;
}

void completarLista(const char *str, struct Nodo *lista) {
    ifstream read;
    apertura_lectura(str,read);
    char *nombre;
    char *comentario;
    int temporada;
    while (true) {
        nombre=leer_cadena(',',50,read);
        if (read.eof())break;
        comentario=leer_cadena('.',120,read);
        read.get();
        temporada=leer_int(read);
        struct Nodo *posicion=BuscarNodo(lista,nombre);
        if (posicion!=nullptr) {
            int n=posicion->personaje.CantidadComentarios;
            posicion->personaje.comentario[n].comentarios=comentario;
            posicion->personaje.comentario[n].temporada=temporada;
            procesarComentarios(comentario,posicion);
            posicion->personaje.CantidadComentarios++;
        }
    }
}

void procesarComentarios(char *comentario, struct Nodo *posicion) {
    char *mayusculas;
    char *minusculas;
    char *copia;
    int j=0,nro_palabras=0;
    mayusculas=new char[30]{};
    minusculas=new char[30]{};
    copia=new char[strlen(comentario)+1];
    strcpy(copia,comentario);
    int i=0;
    while (true){
        if (copia[i]==' ' or copia[i]=='\0' or copia[i]=='\n') {
            mayusculas[j]='\0';
            minusculas[j]='\0';
            posicion->personaje.palabrasMayuscula[nro_palabras]=mayusculas;
            posicion->personaje.palabrasMinuscula[nro_palabras]=minusculas;
            nro_palabras++;
            if (copia[i]=='\0')break;
            mayusculas=new char[30]{};
            minusculas=new char[30]{};
            i++;
            j=0;
            continue;
        }
        if (copia[i]>='a' and copia[i]<='z') {
            minusculas[j]=copia[i];
            copia[i]-=32;
            mayusculas[j]=copia[i];
        }
        else if (copia[i]>='A' and copia[i]<='Z') {
            mayusculas[j]=copia[i];
            copia[i]+=32;
            minusculas[j]=copia[i];
        }
        else {
            mayusculas[j]=copia[i];
            minusculas[j]=copia[i];
        }
        i++;
        j++;
    }
}

void imprimirReporte(const char *str, struct Nodo *lista) {
    ofstream write;
    apertura_escritura(str,write);
    struct Nodo *recorrido=lista;
    write<<setw((120-strlen("TWD-PERSONAJES"))/2)<<""<<"TWD-PERSONAJES"<<endl;
    imprimir_linea(120,'=',write);
    while (recorrido) {
        write<<"PERSONAJE"<<setw(20)<<"ESTADO"<<endl;
        write<<recorrido->personaje.nombre;
        if (recorrido->personaje.Estado) write<<setw(10)<<""<<"VIVO"<<endl;
        else write<<setw(10)<<""<<"MUERTO:("<<endl;
        write<<"COMENTARIOS:"<<endl;
        imprimir_linea(120,'-',write);
        for (int i=0;i<recorrido->personaje.CantidadComentarios;i++)write<<recorrido->personaje.comentario[i].comentarios<<endl;
        imprimir_linea(120,'-',write);
        recorrido=recorrido->siguiente;
    }
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i=0;i<n;i++) {
        write.put(c);
    }
    write<<endl;
}

void procesarPalabras(const char *str, char **arr, int &nro_comentarios) {
    ifstream read;
    apertura_lectura(str,read);
    char palabra[80];
    int num;
    char *nombre;
    char c;
    while (true) {
        nombre=leer_cadena(',',80,read);
        if (read.eof()) break;
        while (true) {
            read>>palabra;
            c=read.get();
            if (c=='\n')break;
        }
        nro_comentarios++;
    }
}


struct Nodo * BuscarNodo(struct Nodo *lista,char *nombre) {
    struct Nodo *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (strcmp(recorrido->personaje.nombre,nombre)==0) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}
