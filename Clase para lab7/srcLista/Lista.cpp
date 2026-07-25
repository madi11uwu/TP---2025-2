//
// Created by Madi on 15/11/2025.
//

#include "Lista.hpp"
#include "ListaTAD.hpp"

void insertar(struct Nodo *&lista, int valor) {
    //Primer paso
    struct Nodo *nuevo_nodo;
    nuevo_nodo=new struct Nodo; //Es como si fuera new struct Nodo[1];
    //Reserva de memoria
    nuevo_nodo->dato=valor;
    nuevo_nodo->siguiente=nullptr;
    if (lista == nullptr) {
        lista = nuevo_nodo; //Lista apunta al nuevo_nodo
    }
    else {
        struct Nodo *recorrido; //Es como crear un puntero gemelo de lista
        recorrido=lista;
        while (recorrido->siguiente!=nullptr) {
            recorrido=recorrido->siguiente; //Cambiar al siguiente espacio
        }
        recorrido->siguiente=nuevo_nodo; //Insertamos al final
    }
}

void insertar_inicio(struct Nodo *&lista, int valor) {
    struct Nodo *nuevo_nodo;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->dato=valor;
    nuevo_nodo->siguiente=nullptr;
    if (lista == nullptr) {
        lista = nuevo_nodo;
    }
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void creador_lista_ordenada(struct Nodo *&lista, const char *file) {
    ifstream read;

}

void insertar_ordenado(struct Nodo *&lista, int dato) {
    struct Nodo *nuevo_nodo;
    struct Nodo *recorrido=lista;
    struct Nodo *anterior=nullptr;
    //Asignación estática: no reservo memoria y solo apunto, se van a eliminar solos
    //Armar el nodo nuevo
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->dato=dato; //Cambia de acuerdo al dato que insertemos (como las cadenas)
    //Buscar la posición
    while (recorrido) {
        if (recorrido->dato>dato)break; //Aquí se pone la comparación multicriterio
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr) lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void apertura_lectura(const char * file_name,ifstream & input) {
    input.open(file_name,ios::in);
    if (!input.is_open()) {
        cout<<"El archivo: "<<file_name<<" no pudo abrirse";
        exit(1);
    }
}

void crear_lista(struct Nodo *&lista, const char *file_name) {
    ifstream input;
    apertura_lectura(file_name,input);
    int valor;
    lista = nullptr;
    while (true) {
        input>>valor;
        if (input.eof())break;
        insertar(lista,valor);
    }
}

void imprimir_lista(struct Nodo *lista,const char *file_na) {
    ofstream output;

}

void remover_elemento_lista(struct Nodo *&lista, int dato) {
    struct Nodo *recorrido=lista;
    struct Nodo *anterior=nullptr;
    while (recorrido and recorrido->dato < dato) {
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    if (anterior==nullptr or recorrido->dato!=dato) {
        cout<<"No se encontro el dato en la lista"<<endl;
    }
    else {
        if (anterior == nullptr) lista=recorrido->siguiente;
        else anterior->siguiente=recorrido->siguiente;
        delete recorrido;
    }
}

void apertura_escritura(ofstream &output,const char *file) {

}

//Dos listas y quiero eliminar de una lista los elementos que están en la otra
//Comparar listas una por una

//Lista TAD
void crear_lista_TAD(struct Lista &lista, const char *file_name) {
    ifstream read;
    apertura_lectura(file_name,read);

}

void insertar_nodo_tad(struct Lista &lista,int dato) {
    struct Nodo *nuevo_nodo;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->dato=dato;
    nuevo_nodo->siguiente=lista.inicio;
    lista.inicio=nuevo_nodo;
}

