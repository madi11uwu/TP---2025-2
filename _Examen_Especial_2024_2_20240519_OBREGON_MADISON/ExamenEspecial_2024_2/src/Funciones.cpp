//
// Created by Madi on 30/11/2025.
//

#include "Funciones.hpp"

#include <list>

#include "Palabra.hpp"
#include "NodoLexicon.hpp"
#include "Comentario.hpp"
#include "Plato.hpp"
#include "Atencion.hpp"
#include "NodoPlato.hpp"
#include "NodoAtencion.hpp"
void insertarNodo(struct NodoLexicon *&lista,struct Palabra palabra) {
    struct NodoLexicon *nuevo_nodo;
    nuevo_nodo=new struct NodoLexicon;
    nuevo_nodo->dato=palabra;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void cargarLexicon(const char *str, struct NodoLexicon *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    char *palabra;
    while (true) {
        palabra=leer_cadena(20,',',read);
        if (read.eof())break;
        struct Palabra p{};
        p.texto=palabra;
        p.polaridad=leer_int(read);
        insertarNodo(lista,p);
    }
}

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

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
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

double leer_double(ifstream &read) {
    double d;
    read>>d;
    read.get();
    return d;
}

char * asignar_cadena(const char *name) {
    char *str;
    str=new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

int almacenarHora(ifstream &read) {
    int hh,mm;
    char c;
    read>>hh>>c>>mm;
    return (hh*60+mm);
}

void imprimirHora(int hora, ofstream &write) {
    write<<setw(2)<<setfill('0')<<hora/60<<":";
    write<<setw(2)<<setfill('0')<<hora%60;
    write<<setfill(' ');
}

void probarLexicon(const char *str, struct NodoLexicon *lista, const char *text) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoLexicon *recorrido;
    recorrido=lista;
    write<<setw((ANCHO_REPORTE-strlen(text))/2)<<""<<text<<endl;
    imprimirLinea(ANCHO_REPORTE,'-',write);
    write<<"PALABRA"<<setw(20)<<""<<"POLARIDAD"<<endl;
    while (recorrido) {
        write<<recorrido->dato.texto;
        imprimirEspacios(20,strlen(recorrido->dato.texto),write);
        write<<setw(10)<<""<<recorrido->dato.polaridad<<endl;
        recorrido=recorrido->siguiente;
    }
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i=0;i<n;i++) {
        write.put(c);
    }
    write<<endl;
}

void imprimirEspacios(int ancho, int size, ofstream &write) {
    for (int i=0;i<ancho-size;i++) {
        write.put(' ');
    }
}

void insertarNodoPlato(struct Plato plato, struct NodoPlato *&lista) {
    struct NodoPlato *nuevo_nodo;
    nuevo_nodo=new NodoPlato;
    nuevo_nodo->dato=plato;
    nuevo_nodo->siguiente=lista;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void cargarPlatos(const char *str, struct NodoPlato *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    char *codigo;
    lista=nullptr;
    while (true) {
        codigo=leer_cadena(10,',',read);
        if (read.eof())break;
        struct Plato p{};
        p.codigo=codigo;
        p.nombre=leer_cadena(35,',',read);
        p.precio=leer_double(read);
        insertarNodoPlato(p,lista);
    }
}

void probarPlatos(const char *str, struct NodoPlato *lista, const char *text) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoPlato *recorrido;
    recorrido=lista;
    write<<setw((ANCHO_REPORTE-strlen(text))/2)<<""<<text<<endl;
    write<<"CODIGO"<<setw(10)<<""<<"NOMBRE";
    write<<setw(35)<<""<<"PRECIO";
    write<<setw(10)<<""<<"CANTIDAD"<<endl;
    while (recorrido) {
        write<<recorrido->dato.codigo;
        write<<setw(10)<<""<<recorrido->dato.nombre;
        imprimirEspacios(30,strlen(recorrido->dato.nombre),write);
        write<<setw(10)<<""<<recorrido->dato.precio;
        write<<setw(10)<<""<<recorrido->dato.cantidad<<endl;
        recorrido=recorrido->siguiente;
    }
}

struct NodoPlato * BuscarNodoPlato(char * str, struct NodoPlato * lista) {
    struct NodoPlato *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (strcmp(str,recorrido->dato.codigo)==0) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void insertarNodoAtencion(const struct Atencion atencion, struct NodoAtencion *&lista) {
    struct NodoAtencion *nuevo_nodo;
    struct NodoAtencion *recorrido;
    struct NodoAtencion *anterior;
    anterior=nullptr;
    recorrido=lista;
    nuevo_nodo=new NodoAtencion;
    nuevo_nodo->dato=atencion;
    nuevo_nodo->siguiente=nullptr;
    while (recorrido) {
        if (recorrido->dato.codigo>atencion.codigo) break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr) lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void cargarAtencion(const char *str, struct NodoAtencion *&lista, struct NodoPlato *listaPlato) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    int numAtencion;
    char c;
    char buffer[7];
    int cantidad;
    while (true) {
        read>>numAtencion;
        if (read.eof())break;
        struct Atencion a{};
        a.platos_atendidos=new struct Plato[20]{};
        a.codigo=numAtencion;
        a.hora=almacenarHora(read);
        int platoPedido=0;
        while (true) {
            read>>buffer;
            read>>cantidad;
            struct NodoPlato *posicion=BuscarNodoPlato(buffer,listaPlato);
            if (posicion!=nullptr) {
                a.platos_atendidos[platoPedido].codigo=asignar_cadena(posicion->dato.codigo);
                a.platos_atendidos[platoPedido].nombre=asignar_cadena(posicion->dato.nombre);
                a.platos_atendidos[platoPedido].cantidad=cantidad;
                a.platos_atendidos[platoPedido].precio=posicion->dato.precio;
                a.total_venta+=cantidad*posicion->dato.precio;
            }
            a.cantidad_platos+=cantidad;
            platoPedido++;
            c=read.get();
            if (c=='\n')break;
        }
        insertarNodoAtencion(a,lista);
    }
}

struct NodoAtencion * BuscarNodoAtencion(int num_atencion, struct NodoAtencion * lista) {
    struct NodoAtencion *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (recorrido->dato.codigo==num_atencion) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

char * modificarCadena(char * comentario) {
    char *str;
    str=new char[strlen(comentario)+1];
    strcpy(str,comentario);
    for (int i=0; str[i]; i++) {
        if (str[i]>='A' and str[i]<='Z') str[i]+=32;
        if (!noEsMayusniMinus(str[i]) and str[i]!=' ') {
            for (int j = i; str[j]; j++) {
                str[j] = str[j+1];
            }
            i--;
        }
    }
    return str;
}

bool noEsMayusniMinus(char c) {
    if (c>='A' and c<='Z' or c>='a' and c<='z') return true;
    else return false;
}

int cantPalabras(char * comentario_procesado) {
    int i=0,numPalabras=0;
    while (true) {
        if (comentario_procesado[i]==' ' or comentario_procesado[i]=='\0') {
            numPalabras++;
        }
        if (comentario_procesado[i]=='\0') break;
        i++;
    }
    return numPalabras;
}

struct NodoLexicon * BuscarNodoLexicon(char * nueva, struct NodoLexicon * nodo_lexicon) {
    struct NodoLexicon *recorrido;
    recorrido=nodo_lexicon;
    while (recorrido) {
        if (strcmp(recorrido->dato.texto, nueva)==0) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void SepararPalabras(char * oracion,struct NodoAtencion *nodo,struct NodoLexicon *listaLexicon,int n) {
    int i=0,j=0,cantPalabras=0;
    char *str=new char[strlen(oracion)+1];
    strcpy(str,oracion);
    char palabra[20];
    while (true) {
        if (str[i]!=' ' and str[i]!='\0') {
            palabra[j]=str[i];
        }
        else {
            palabra[j]='\0';
            char *nueva=new char[strlen(palabra)+1];
            strcpy(nueva,palabra);
            struct NodoLexicon *posicion=BuscarNodoLexicon(nueva,listaLexicon);
            if (posicion!=nullptr) {
                nodo->dato.comentarios[n].palabras[cantPalabras].texto=nueva;
                nodo->dato.comentarios[n].palabras[cantPalabras].polaridad=posicion->dato.polaridad;
                nodo->dato.comentarios[n].polaridad_total+=posicion->dato.polaridad;
            }
            else {
                nodo->dato.comentarios[n].palabras[cantPalabras].polaridad=0;
            }
            cantPalabras++;
            i++;
            j=0;
            if (str[i]=='\0')break;
            continue;
        }
        j++;
        i++;
    }
}

void llenarPalabras(struct NodoAtencion * posicion, struct NodoLexicon * listaLexicon,char *oracion,int n) {
    struct NodoLexicon *recorrido;
    recorrido=listaLexicon;
    SepararPalabras(oracion,posicion,listaLexicon,n);
}

void imprimirReporte(const char *str, struct NodoAtencion *lista) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoAtencion *recorrido;
    write<<setw((ANCHO_REPORTE-strlen("EMPRESA DE REPARTOS A DOMICILIO TP S.A."))/2)<<"";
    write<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    write<<setw((ANCHO_REPORTE-strlen("RELACION DE ATENCIONES"))/2)<<"";
    write<<"RELACION DE ATENCIONES"<<endl;
    imprimirLinea(ANCHO_REPORTE,'=',write);
    recorrido=lista;
    while (recorrido) {
        int n=1;
        write<<"No. ATENCION "<<recorrido->dato.codigo<<setw(10)<<"";
        write<<"Atendido a las: ";
        imprimirHora(recorrido->dato.hora,write);
        write<<endl;
        imprimirLinea(ANCHO_REPORTE,'-',write);
        for (int i=0;recorrido->dato.platos_atendidos[i].codigo;i++) {
            write<<n<<")"<<recorrido->dato.platos_atendidos[i].codigo<<")";
            write<<setw(2)<<""<<recorrido->dato.platos_atendidos[i].nombre;
            imprimirEspacios(25,strlen(recorrido->dato.platos_atendidos[i].nombre),write);
            write<<setw(8)<<""<<recorrido->dato.platos_atendidos[i].precio;
            write<<setw(5)<<""<<recorrido->dato.platos_atendidos[i].cantidad;
            write<<setw(5)<<"";
            write<<recorrido->dato.platos_atendidos[i].precio*recorrido->dato.platos_atendidos[i].cantidad;
            write<<endl;
        }
        write<<"Total de ventas "<<recorrido->dato.total_venta<<endl;
        imprimirLinea(ANCHO_REPORTE,'-',write);
        write<<"Comentarios: "<<endl;
        int polaridadTotal=0;
        for (int i=0;i<recorrido->dato.cantidad_comentarios;i++) {
            write<<recorrido->dato.comentarios[i].texto<<endl;
            polaridadTotal=recorrido->dato.comentarios[i].polaridad_total;
        }
        write<<"Polaridad total de los comentarios: "<<polaridadTotal<<endl;
        imprimirLinea(ANCHO_REPORTE,'=',write);
        recorrido=recorrido->siguiente;
    }
}

void CompletarAtencion(const char *str, struct NodoAtencion *listaAtencion, struct NodoLexicon *listaLexicon) {
    ifstream read;
    apertura_lectura(str,read);
    int numAtencion,numeroPalabras;
    char *comentario;
    char *comentarioProcesado;
    while (true) {
        numAtencion=leer_int(read);
        if (read.eof())break;
        struct NodoAtencion *posicion=BuscarNodoAtencion(numAtencion,listaAtencion);
        if (posicion!=nullptr) {
            int n=posicion->dato.cantidad_comentarios;
            comentario=leer_cadena(120,'\n',read);
            posicion->dato.comentarios[n].texto=comentario;
            comentarioProcesado=modificarCadena(comentario);
            posicion->dato.comentarios[n].pre_procesado=comentarioProcesado;
            numeroPalabras=cantPalabras(comentarioProcesado);
            posicion->dato.comentarios[n].cantidad_palabras=numeroPalabras;
            llenarPalabras(posicion,listaLexicon,comentarioProcesado,n);
            posicion->dato.cantidad_comentarios++;
        }
        else {
            read.ignore(300,'\n');
            continue;
        }
    }
}
