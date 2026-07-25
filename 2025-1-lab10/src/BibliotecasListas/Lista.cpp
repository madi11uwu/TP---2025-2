//
// Created by Madi on 23/11/2025.
//

#include "Lista.hpp"
#include "Cuenta.hpp"
#include "Nodo.hpp"
void insertar_ordenado(struct Nodo *&lista,struct Cuenta &cuenta) {
    struct Nodo *nuevo_nodo;
    struct Nodo *anterior=nullptr;
    struct Nodo *recorrido=lista;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->cuenta=cuenta;
    while (recorrido) {
        if (recorrido->cuenta.codigo>cuenta.codigo)break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr)lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void CompletarDatos(const char *str, struct Nodo *lista) {
    ifstream read;
    apertura_lectura(str,read);
    int fecha,codigoCuenta;
    double monto;
    char c;
    while (true) {
        fecha=devolverFecha(read);
        if (read.eof())break;
        read.get();
        while (true) {
            codigoCuenta=leer_int(read);
            read>>monto;
            struct Nodo *n=buscarNumeroDeCuenta(codigoCuenta,lista);
            if (n) {
                n->cuenta.saldo+=monto;
                if (n->cuenta.saldo<0) {
                    if (n->cuenta.fechaSobregiro==0 or n->cuenta.fechaSobregiro<fecha)n->cuenta.fechaSobregiro=fecha;
                    n->cuenta.sobregiro=true;
                }
            }
            c=read.get();
            if (c=='\n')break;
        }
    }
}

void imprimirReporte(const char *str, struct Nodo *lista) {
    ofstream write;
    apertura_escritura(str,write);
    struct Nodo*recorrido=lista;
    imprimirEncabezado(write);
    int n=1;
    while (recorrido) {
        write<<setw(2)<<setfill('0')<<n<<")";
        write<<setfill(' ');
        write<<setw(4)<<""<<recorrido->cuenta.codigo;
        write<<setw(4)<<""<<recorrido->cuenta.nombre;
        imprimirEspacios(36,strlen(recorrido->cuenta.nombre),write);
        write<<setw(4)<<""<<recorrido->cuenta.saldo;
        if (recorrido->cuenta.sobregiro)write<<setw(4)<<""<<"SI";
        else write<<setw(4)<<""<<"NO";
        if (recorrido->cuenta.fechaSobregiro!=0) {
            write<<setw(6)<<"";
            imprimirFecha(recorrido->cuenta.fechaSobregiro,write);
        }
        else write<<setw(6)<<""<<"--/--/----";
        write<<endl;
        recorrido=recorrido->siguiente;
        n++;
    }
}

void insertar_inicio(const struct Cuenta &cuenta, struct Nodo *&lista) {
    struct Nodo*nuevo_nodo;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->cuenta=cuenta;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr) {
        lista=nuevo_nodo;
    }
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void llenarInicio(const char *str, struct Nodo *&listaInicio) {
    ifstream read;
    apertura_lectura(str,read);
    struct Cuenta cuenta;
    inicializarCuenta(cuenta);
    int codigoCuenta;
    listaInicio=nullptr;
    while (true) {
        codigoCuenta=leer_int(read);
        if (read.eof())break;
        cuenta.codigo=codigoCuenta;
        cuenta.nombre=leer_cadena(MAX_CARACTERES,',',read);
        cuenta.saldo=leer_double(read);
        insertar_inicio(cuenta,listaInicio);
    }
}

void insertarFinal(const struct Cuenta & cuenta, struct Nodo *&listaFinal) {
    struct Nodo *nuevo_nodo;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->cuenta=cuenta;
    nuevo_nodo->siguiente=nullptr;
    if (listaFinal==nullptr) listaFinal=nuevo_nodo;
    else {
        struct Nodo*recorrido=listaFinal;
        while (recorrido->siguiente!=nullptr) {
            recorrido=recorrido->siguiente;
        }
        recorrido->siguiente=nuevo_nodo;
    }
}

void llenarFinal(const char *str, struct Nodo *&listaFinal) {
    ifstream read;
    apertura_lectura(str,read);
    struct Cuenta c;
    inicializarCuenta(c);
    int cuentaBancaria;
    listaFinal=nullptr;
    while (true) {
        cuentaBancaria=leer_int(read);
        if (read.eof())break;
        c.codigo=cuentaBancaria;
        c.nombre=leer_cadena(MAX_CARACTERES,',',read);
        c.saldo=leer_double(read);
        insertarFinal(c,listaFinal);
    }
}

void inicializarCuenta(struct Cuenta & cuenta) {
    cuenta.codigo=0;
    cuenta.fechaSobregiro=0;
    cuenta.nombre=nullptr;
    cuenta.saldo=0.0;
    cuenta.sobregiro=false;
}

void llenarOrdenado(const char *str, struct Nodo *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    int codigo;
    struct Cuenta c;
    inicializarCuenta(c);
    lista=nullptr;
    while (true) {
        read>>codigo;
        if (read.eof())break;
        read.get();
        c.codigo=codigo;
        c.nombre=leer_cadena(MAX_CARACTERES,',',read);
        c.saldo=leer_double(read);
        insertar_ordenado(lista,c);
    }
}

struct Nodo *buscarNumeroDeCuenta(int num_cuenta,struct Nodo *lista) {
    struct Nodo *recorrido = lista;
    while (recorrido) {
        if (num_cuenta == recorrido->cuenta.codigo) {
            return recorrido;
        }
        recorrido = recorrido->siguiente;
    }
    return nullptr;
}

void EliminarElementos(struct Nodo *&lista) {
    struct Nodo*recorrido=lista;
    struct Nodo*anterior=nullptr;
    while (true) {
        if (recorrido==nullptr) break;
        if (recorrido->cuenta.saldo>0) {
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