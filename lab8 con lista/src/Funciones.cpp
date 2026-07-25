//
// Created by Madi on 23/11/2025.
//

#include "Funciones.hpp"

#include <list>

#include "Canal.hpp"
#include "Categoria.hpp"
#include "Nodo.hpp"

void apertura_lectura(const char *file, ifstream &read) {
    read.open(file,ios::in);
    if (!read.is_open()) {
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

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char cadena[n];
    read.getline(cadena, n,c);
    if (read.eof())return nullptr;
    str=new char[strlen(cadena)+1];
    strcpy(str,cadena);
    return str;
}

char * asignar_cadena(const char *name) {
    char *str;
    str=new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

int leer_int(ifstream &read) {
    int n;
    read>>n;
    read.get();
    return n;
}

int almacenarDuracion(ifstream &read) {
    int hh,mm,ss;
    char c;
    read>>hh>>c>>mm>>c>>ss;
    return (hh*3600+mm*60+ss);
}

void imprimir_duracion(int duracion, ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":";
    write<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

void inicializarCategoria(struct Categoria & categoria) {
    categoria.codigo=nullptr;
    categoria.descripcion=nullptr;
    categoria.nombre=nullptr;
    categoria.canal=new struct Canal[300]();
    categoria.cantidadCanales=0;
}

void imprimirReporte(const char *str, struct Nodo *lista) {
    ofstream write;
    apertura_escritura(str,write);
    struct Nodo *recorrido;
    recorrido=lista;
    imprimirEncabezado(write);
    while (recorrido) {
        write<<"Codigo: "<<recorrido->categoria.codigo<<endl;
        write<<"Nombre: "<<recorrido->categoria.nombre<<endl;
        write<<"Descripcion: "<<recorrido->categoria.descripcion<<endl;
        imprimirLinea(ANCHO_REPORTE,'-',write);
        write<<"REPRODUCCIONES: "<<endl;
        for (int i=0;i<recorrido->categoria.cantidadCanales;i++) {
            write<<"CANAL: "<<recorrido->categoria.canal[i].nombre;
            write<<setw(5)<<""<<"RATING: "<<recorrido->categoria.canal[i].rating;
            write<<setw(5)<<"";
            imprimir_duracion(recorrido->categoria.canal[i].duracion,write);
            write<<endl;
        }
        imprimirLinea(ANCHO_REPORTE,'=',write);
        recorrido=recorrido->siguiente;
    }
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"REPORTE POR CATEGORIAS"<<endl;
    imprimirLinea(ANCHO_REPORTE,'=',write);
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i=0;i<n;i++) {
        write.put(c);
    }
    write<<endl;
}

void insertar_ordenado(struct Nodo *&lista, const struct Categoria & categoria) {
    struct Nodo*nuevo_nodo;
    struct Nodo *recorrido;
    struct Nodo *anterior;
    anterior=nullptr;
    recorrido=lista;
    nuevo_nodo=new struct Nodo();
    nuevo_nodo->categoria=categoria;
    nuevo_nodo->siguiente=nullptr;
    while (recorrido) {
        if (strcmp(recorrido->categoria.nombre,categoria.nombre)<0)break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr)lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void insertar_inicio(struct Nodo *&lista, const struct Categoria & categoria) {
    struct Nodo*nuevo_nodo;
    nuevo_nodo=new struct Nodo();
    nuevo_nodo->categoria=categoria;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr)lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void insertar_final(struct Nodo *&lista, const struct Categoria & categoria) {
    struct Nodo *nuevo_nodo;
    nuevo_nodo=new struct Nodo();
    nuevo_nodo->categoria=categoria;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr)lista=nuevo_nodo;
    else {
        struct Nodo *recorrido;
        recorrido=lista;
        while (recorrido->siguiente!=nullptr) {
            recorrido=recorrido->siguiente;
        }
        recorrido->siguiente=nuevo_nodo;
    }
}

struct Nodo * BuscarNodo(char * codigo, struct Nodo * lista) {
    struct Nodo *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (strcmp(recorrido->categoria.codigo,codigo)==0) {
            return recorrido;
        }
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void llenarCanales(const char *str, struct Nodo *lista) {
    ifstream read;
    apertura_lectura(str,read);
    char *Canal,*codigo;
    double rating;
    int duracion;
    while (true) {
        Canal=leer_cadena(MAX_CARACTERES,',',read);
        if (read.eof())break;
        codigo=leer_cadena(MAX_CARACTERES,',',read);
        rating=leer_double(read);
        duracion=almacenarDuracion(read);
        read.get();
        struct Nodo *posicion=BuscarNodo(codigo,lista);
        if (posicion!=nullptr) {
            posicion->categoria.canal[posicion->categoria.cantidadCanales].nombre=asignar_cadena(Canal);
            posicion->categoria.canal[posicion->categoria.cantidadCanales].rating=rating;
            posicion->categoria.canal[posicion->categoria.cantidadCanales].duracion=duracion;
            posicion->categoria.cantidadCanales++;
        }
    }
}

double leer_double(ifstream &read) {
    double n;
    read>>n;
    read.get();
    return n;
}

void EliminarPorDescripcion(struct Nodo *&lista) {
    struct Nodo *recorrido;
    struct Nodo *anterior;
    recorrido=lista;
    anterior=nullptr;
    while (true) {
        if (recorrido==nullptr) break;
        if (strlen(recorrido->categoria.descripcion)>50) {
            if (anterior==nullptr) {
                lista=recorrido->siguiente;
                delete recorrido;
                recorrido=lista;
            }
            else {
                anterior->siguiente=recorrido->siguiente;
                delete recorrido;
                recorrido=anterior->siguiente;
            }
        }
        else {
            anterior=recorrido;
            recorrido=recorrido->siguiente;
        }
    }
}

void llenarLista(const char *str, struct Nodo *&lista,char c) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    char *nombre;
    while (true) {
        nombre=leer_cadena(MAX_CARACTERES,',',read);
        if (read.eof())break;
        struct Categoria categoria;
        inicializarCategoria(categoria);
        categoria.codigo=asignar_cadena(nombre);
        categoria.nombre=leer_cadena(MAX_CARACTERES,',',read);
        categoria.descripcion=leer_cadena(MAX_CARACTERES,'\n',read);
        if (c=='O')insertar_ordenado(lista,categoria);
        else if (c=='I') insertar_inicio(lista,categoria);
        else if (c=='F') insertar_final(lista,categoria);
    }
}
