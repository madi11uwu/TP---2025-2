//
// Created by Madi on 24/11/2025.
//

#include "Funciones.hpp"
#include "Nodo.hpp"
#include "Cuenta.hpp"
void apertura_lectura(const char *file,ifstream &read) {
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

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"BANCO DE LOS CLIENTES TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE LAS CUENTAS DE AHORROS DE NUESTROS CLIENTES"<<endl;
    imprimirLinea(ANCHO_REPORTE,'=',write);
    write<<"No."<<setw(4)<<""<<"CUENTA";
    write<<setw(5)<<""<<"CLIENTE";
    write<<setw(15)<<""<<"SALDO";
    write<<setw(5)<<""<<"SOBREGIRADA";
    write<<setw(5)<<""<<"FECHA DEL ULTIMO SOBREGIRO"<<endl;
}

char * leer_cadena(int n, char c, ifstream &read) {
    char *str;
    char cadena[n];
    read.getline(cadena,n,c);
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

double leer_double(ifstream &read) {
    double n;
    read>>n;
    read.get();
    return n;
}

int almacenarFecha(ifstream &read) {
    int dd,mm,yyyy;
    char c;
    read>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}

void insertar_ordenado(struct Nodo *&lista, const struct Cuenta & cuenta) {
    struct Nodo *recorrido;
    struct Nodo *anterior;
    recorrido=lista;
    anterior=nullptr;
    struct Nodo *nuevo_nodo;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->cuenta=cuenta;
    nuevo_nodo->siguiente=nullptr;
    while (recorrido) {
        if (recorrido->cuenta.codigo<cuenta.codigo)break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr)lista=nuevo_nodo;
    else {
        anterior->siguiente=nuevo_nodo;
    }
}

void inicializarCuenta(struct Cuenta & cuenta) {
    cuenta.codigo=0;
    cuenta.nombre=nullptr;
    cuenta.saldo=0.0;
    cuenta.fechaSobregiro=0;
    cuenta.sobregiro=false;
}

struct Nodo * BuscarNodo(int codigo, struct Nodo * lista) {
    struct Nodo *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (recorrido->cuenta.codigo==codigo)
            return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void CompletarLista(const char *str, struct Nodo *lista) {
    ifstream read;
    apertura_lectura(str,read);
    int fecha,codigo;
    double monto;
    char c;
    while (true) {
        fecha=almacenarFecha(read);
        if (read.eof())break;
        read.get();
        while (true) {
            codigo=leer_int(read);
            read>>monto;
            struct Nodo *posicion=BuscarNodo(codigo,lista);
            if (posicion!=nullptr) {
                posicion->cuenta.saldo+=monto;
                if (posicion->cuenta.saldo<0) {
                    posicion->cuenta.sobregiro=true;
                    if (posicion->cuenta.fechaSobregiro==0 or
                        posicion->cuenta.fechaSobregiro<fecha) {
                        posicion->cuenta.fechaSobregiro=fecha;
                    }
                }
            }
            c=read.get();
            if (c=='\n')break;
        }
    }
}

void imprimir_reporte(const char *str, struct Nodo *lista) {
    ofstream write;
    apertura_escritura(str,write);
    struct Nodo *recorrido;
    recorrido=lista;
    imprimirEncabezado(write);
    int cliente=1;
    while (recorrido) {
        write<<setw(2)<<setfill('0')<<cliente<<")";
        write<<setfill(' ');
        write<<setw(4)<<""<<recorrido->cuenta.codigo;
        write<<setw(4)<<""<<recorrido->cuenta.nombre;
        write<<setw(4)<<""<<recorrido->cuenta.saldo;
        if (recorrido->cuenta.sobregiro) {
            write<<setw(8)<<""<<"SI";
            write<<setw(10)<<"";
            imprimirFecha(recorrido->cuenta.fechaSobregiro,write);
        }
        else {
            write<<setw(8)<<""<<"NO";
            write<<setw(10)<<""<<"--/--/----";
        }
        write<<endl;
        cliente++;
        recorrido=recorrido->siguiente;
    }
}

void EliminarCuentasPositivas(struct Nodo *&lista) {
    struct Nodo *recorrido;
    struct Nodo *anterior;
    recorrido=lista;
    anterior=nullptr;
    while (true) {
        if (recorrido==nullptr)break;
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

void crear_lista(const char *file, struct Nodo *&lista) {
    ifstream read;
    apertura_lectura(file,read);
    lista=nullptr;
    int codigo;
    while (true) {
        codigo=leer_int(read);
        if (read.eof())break;
        struct Cuenta cuenta;
        inicializarCuenta(cuenta);
        cuenta.codigo=codigo;
        cuenta.nombre=leer_cadena(MAX_CARACTERES,',',read);
        cuenta.saldo=leer_double(read);
        insertar_ordenado(lista,cuenta);
    }
}

void imprimirFecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(4)<<setfill('0')<<fecha/10000;
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void eliminarUnElemento(struct Nodo *&lista,int codigo) {
    struct Nodo *recorrido;
    struct Nodo *anterior;
    anterior=nullptr;
    recorrido=lista;
    while(recorrido) {
        if (lista->cuenta.codigo==codigo) break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    if (recorrido==nullptr or recorrido->cuenta.codigo!=codigo) {
        cout<<"No se hallo";
    }
    else {
        if (anterior==nullptr) lista=recorrido->siguiente;
        else anterior->siguiente=recorrido->siguiente;
        delete recorrido;
    }
}