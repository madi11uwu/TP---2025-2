//
// Created by Madi on 29/11/2025.
//

#include "Funciones.hpp"
#include "LibroEnSuPoder.hpp"
#include "Usuario.hpp"
#include "NodoUsuario.hpp"
#include "NodoUsuarioMoroso.hpp"

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

void insertarNodo(const struct Usuario & usuario, struct NodoUsuario *&lista) {
    struct NodoUsuario *nuevo_nodo;
    nuevo_nodo=new struct NodoUsuario;
    nuevo_nodo->usuario=usuario;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void cargarUsuarios(const char *str, struct NodoUsuario *&listaUsuario) {
    ifstream read;
    apertura_lectura(str,read);
    listaUsuario = nullptr;
    int dni;
    while (true) {
        dni=leer_int(read);
        if (read.eof())break;
        struct Usuario usuario{};
        usuario.dni = dni;
        usuario.nombre=leer_cadena(80,',',read);
        usuario.categoria=leer_char(read);
        read>>usuario.calificacion;
        usuario.libros=new LibroEnSuPoder[6]{};
        insertarNodo(usuario,listaUsuario);
    }
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}

char leer_char(ifstream &read) {
    char c;
    read>>c;
    read.get();
    return c;
}

double leer_double(ifstream &read) {
    double d;
    read>>d;
    read.get();
    return d;
}

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof()) return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

char * asignar_cadena(char *name) {
    char *str;
    str=new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

void probarUsuarios(const char *str, struct NodoUsuario *lista,const char *titulo) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoUsuario *recorrido;
    recorrido=lista;
    write<<setw((ANCHO_REPORTE-strlen(titulo))/2)<<"";
    write<<titulo<<endl;
    imprimirLinea(ANCHO_REPORTE,'=',write);
    write<<"DNI"<<setw(10)<<""<<"NOMBRE";
    write<<setw(35)<<""<<"CATEGORIA";
    write<<setw(10)<<fixed<<setprecision(2)<<""<<"CALIFICACION"<<endl;
    imprimirLinea(ANCHO_REPORTE,'-',write);
    while (recorrido) {
        write<<recorrido->usuario.dni;
        write<<setw(5)<<""<<recorrido->usuario.nombre;
        imprimirEspacios(30,strlen(recorrido->usuario.nombre),write);
        write<<setw(15)<<""<<recorrido->usuario.categoria;
        write<<setw(15)<<""<<recorrido->usuario.calificacion<<endl;
        for (int i=0;i<recorrido->usuario.cantLibros;i++) {
            write<<recorrido->usuario.libros[i].codLibro<<setw(6)<<"";
            imprimirFecha(recorrido->usuario.libros[i].fechaDevolucion,write);
            write<<endl;
        }
        imprimirLinea(ANCHO_REPORTE,'-',write);
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

struct NodoUsuario * BuscarNodo(struct NodoUsuario * lista,int dni) {
    struct NodoUsuario *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (recorrido->usuario.dni==dni) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void ActualizarLista(const char *str, struct NodoUsuario *lista) {
    ifstream read;
    apertura_lectura(str,read);
    char *codigo,c;
    int dni,fecha;
    while (true) {
        codigo=leer_cadena(10,' ',read);
        if (read.eof())break;
        while (true) {
            read>>dni;
            fecha=almacenarFecha(read);
            struct NodoUsuario *posicion=BuscarNodo(lista,dni);
            if (posicion!=nullptr) {
                int n=posicion->usuario.cantLibros;
                posicion->usuario.libros[n].codLibro=asignar_cadena(codigo);
                posicion->usuario.libros[n].fechaDevolucion=fecha;
                posicion->usuario.cantLibros++;
            }
            c=read.get();
            if (c=='\n')break;
        }
    }
}

int almacenarFecha(ifstream &read) {
    int dd,mm,aa;
    char c;
    read>>dd>>c>>mm>>c>>aa;
    return (aa*10000+mm*100+dd);
}

void imprimirFecha(int fecha, ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(2)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

void insertarNodoMoroso(struct NodoUsuarioMoroso *&lista, int dni){
    struct NodoUsuarioMoroso *nuevo_nodo;
    nuevo_nodo=new struct NodoUsuarioMoroso;
    nuevo_nodo->dni=dni;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr)lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

bool esMoroso(struct NodoUsuario * recorrido, struct NodoUsuarioMoroso * lista_moroso) {
    struct NodoUsuarioMoroso *camino;
    camino=lista_moroso;
    while (camino) {
        if (recorrido->usuario.dni==camino->dni) return true;
        camino=camino->siguiente;
    }
    return false;
}

void insertarOrdenado(const struct Usuario & usuario, struct NodoUsuario *&lista) {
    struct NodoUsuario *nuevo_nodo;
    struct NodoUsuario *recorrido;
    struct NodoUsuario *anterior;
    recorrido=lista;
    anterior=nullptr;
    nuevo_nodo=new struct NodoUsuario;
    nuevo_nodo->usuario=usuario;
    nuevo_nodo->siguiente=nullptr;
    while (recorrido) {
        if (recorrido->usuario.dni>usuario.dni) break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr) lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void EliminarMorosos(struct NodoUsuario *&lista, struct NodoUsuarioMoroso *listaMoroso,
                     struct NodoUsuario *&lista_morosoDNI) {
    lista_morosoDNI=nullptr;
    struct Usuario usuario{};
    struct NodoUsuario *recorrido;
    struct NodoUsuario *anterior;
    recorrido=lista;
    anterior=nullptr;
    while (true) {
        if (recorrido==nullptr) break;
        if (esMoroso(recorrido,listaMoroso)) {
            usuario=recorrido->usuario;
            usuario.moroso=true;
            if (usuario.categoria=='A')usuario.calificacion*=0.9;
            else if (usuario.categoria=='D')usuario.calificacion*=0.85;
            else if (usuario.categoria=='V')usuario.calificacion*=0.75;
            insertarOrdenado(usuario,lista_morosoDNI);
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

void cargarMorosos(const char *str, struct NodoUsuarioMoroso *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    int dni;
    lista=nullptr;
    while (true) {
        read>>dni;
        if (read.eof())break;
        insertarNodoMoroso(lista,dni);
    }
}

void probarMorosos(const char *str, struct NodoUsuarioMoroso *lista) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoUsuarioMoroso *recorrido;
    recorrido=lista;
    write<<setw((ANCHO_REPORTE-strlen("USUARIOS MOROSOS"))/2)<<"";
    write<<"USUARIOS MOROSOS"<<endl;
    imprimirLinea(ANCHO_REPORTE,'-',write);
    write<<"DNI"<<endl;
    while (recorrido) {
        write<<recorrido->dni<<endl;
        recorrido=recorrido->siguiente;
    }
}
