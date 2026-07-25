//
// Created by Madi on 1/12/2025.
//

#include "Funciones.hpp"

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

void insertarNodo(struct NodoUsuario *&lista, const struct Usuario usuario) {
    struct NodoUsuario *nuevo_nodo;
    nuevo_nodo=new NodoUsuario;
    nuevo_nodo->usuario=usuario;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void cargarUsuarios(const char *str, struct NodoUsuario *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    int dni;
    while (true) {
        dni=leer_int(read);
        if (read.eof()) break;
        struct Usuario u{};
        u.libros=new LibroEnSuPoder[6]{};
        u.cantLibros=0;
        u.dni=dni;
        u.nombre=leer_cadena(',',80,read);
        u.categoria=leer_char(read);
        u.calificacion=leer_double(read);
        insertarNodo(lista,u);
    }
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}

char * leer_cadena(char c, int n, ifstream &read) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof()) return nullptr;
    str=new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
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

void probarUsuarios(const char *str, struct NodoUsuario *lista,const char *titulo) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoUsuario *recorrido=lista;
    write<<setw((120-strlen(titulo))/2)<<""<<titulo<<endl;
    imprimirLinea(120,'-',write);
    int cant=0;
    while (recorrido) {
        if (cant%5==0) {
            write<<"DNI"<<setw(10)<<""<<"NOMBRE";
            write<<setw(10)<<""<<"CATEGORIA";
            write<<setw(10)<<""<<"CALIFICACION"<<endl;
            imprimirLinea(120,'-',write);
        }
        cant++;
        write<<recorrido->usuario.dni;
        write<<setw(5)<<""<<recorrido->usuario.nombre;
        imprimirEspacios(40,strlen(recorrido->usuario.nombre),write);
        write<<setw(10)<<""<<recorrido->usuario.categoria;
        write<<setw(10)<<""<<recorrido->usuario.calificacion<<endl;
        write<<"LIBROS: "<<endl;
        for (int i=0;i<recorrido->usuario.cantLibros;i++) {
            write<<recorrido->usuario.libros[i].codLibro<<setw(5)<<"";
            imprimirFecha(recorrido->usuario.libros[i].fechaDevolucion,write);
            write<<endl;
        }
        imprimirLinea(120,'-',write);
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

struct NodoUsuario * BuscarUsuario(int dni, struct NodoUsuario * lista) {
    struct NodoUsuario *recorrido=lista;
    while (recorrido) {
        if (dni==recorrido->usuario.dni) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void ActualizarUsuarios(const char *str, struct NodoUsuario *lista) {
    ifstream read;
    apertura_lectura(str,read);
    char *codLibro,c;
    int dni,fecha;
    while (true) {
        codLibro=leer_cadena(' ',10,read);
        if (read.eof())break;
        while (true) {
            read>>dni;
            fecha=almacenarFecha(read);
            struct NodoUsuario *posicion=BuscarUsuario(dni,lista);
            if (posicion!=nullptr) {
                int n=posicion->usuario.cantLibros;
                posicion->usuario.libros[n].codLibro=codLibro;
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

void insertarNodoMoroso(int dni, struct NodoUsuarioMoroso *&lista_moroso) {
    struct NodoUsuarioMoroso *nuevo_nodo;
    nuevo_nodo=new NodoUsuarioMoroso;
    nuevo_nodo->dni=dni;
    nuevo_nodo->siguiente=nullptr;
    if (lista_moroso==nullptr) lista_moroso=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista_moroso;
        lista_moroso=nuevo_nodo;
    }
}

void cargarMorosos(const char *str, struct NodoUsuarioMoroso *&lista_moroso) {
    ifstream read;
    apertura_lectura(str,read);
    lista_moroso=nullptr;
    int dni;
    while (true) {
        read>>dni;
        if (read.eof())break;
        insertarNodoMoroso(dni,lista_moroso);
    }
}

void probarMorosos(const char *str, struct NodoUsuarioMoroso *lista_moroso) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoUsuarioMoroso *recorrido=lista_moroso;
    write<<"MOROSOS"<<endl;
    imprimirLinea(120,'-',write);
    write<<"DNI"<<endl;
    imprimirLinea(120,'-',write);
    while (recorrido) {
        write<<recorrido->dni<<endl;
        recorrido=recorrido->siguiente;
    }
}


bool esMoroso(int dni, struct NodoUsuarioMoroso * lista_moroso) {
    struct NodoUsuarioMoroso *recorrido=lista_moroso;
    while (recorrido) {
        if (recorrido->dni==dni) return true;
        recorrido=recorrido->siguiente;
    }
    return false;
}

void insertarOrdenado(struct Usuario usuario, struct NodoUsuario *&listaUsuario) {
    struct NodoUsuario *nuevo_nodo;
    nuevo_nodo=new NodoUsuario;
    nuevo_nodo->usuario=usuario;
    nuevo_nodo->siguiente=nullptr;
    struct NodoUsuario *recorrido=listaUsuario;
    struct NodoUsuario *anterior=nullptr;
    while (recorrido) {
        if (recorrido->usuario.dni>usuario.dni) break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr) listaUsuario=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void eliminarNodos(struct NodoUsuario *listaUsuario, struct NodoUsuarioMoroso *lista_moroso,
                   struct NodoUsuario *&lista_ordenada) {
    lista_ordenada=nullptr;
    struct NodoUsuario *recorrido=listaUsuario;
    struct NodoUsuario *anterior=nullptr;
    struct Usuario u{};
    while (true) {
        if (recorrido==nullptr) break;
        if (esMoroso(recorrido->usuario.dni,lista_moroso)) {
            u=recorrido->usuario;
            u.moroso=true;
            if (u.categoria=='A')u.calificacion*=0.9;
            else if (u.categoria=='D') u.calificacion*=0.85;
            else if (u.categoria=='V') u.calificacion*=0.75;
            insertarOrdenado(u,lista_ordenada);
            if (anterior==nullptr) {
                listaUsuario=recorrido->siguiente;
                delete recorrido;
                recorrido=listaUsuario;
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
