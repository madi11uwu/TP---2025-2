//
// Created by Madi on 24/11/2025.
//

#include "Funciones.hpp"
#include "Vendedor.hpp"
#include "Nodo.hpp"

void inicializarVendedor(struct Vendedor & vendedor) {
    vendedor.CantidadDeVentas=0;
    vendedor.codigo=0;
    vendedor.nombre=nullptr;
    vendedor.porcentajeVentas=0.0;
    vendedor.cuotaMinima=0.0;
}

struct Nodo * BuscarNodo(struct Nodo * lista,int codigo) {
    struct Nodo *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (recorrido->vendedor.codigo==codigo) {
            return recorrido;
        }
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void completarLista(const char *str, struct Nodo *&lista) {
    ifstream read;
    apertura_lectura(str, read);
    char *codigoProducto;
    int codigo,cantidad;
    while (true) {
        codigoProducto=leer_cadena(MAX_CARACTERES,' ',read);
        if (read.eof())break;
        read>>codigo>>cantidad;
        struct Nodo *posicion=BuscarNodo(lista,codigo);
        if (posicion!=nullptr) {
            posicion->vendedor.CantidadDeVentas+=cantidad;
        }
    }
}

void imprimirReporte(const char *str, struct Nodo *lista) {
    ofstream write;
    apertura_escritura(str, write);
    imprimirEncabezado(write);
    struct Nodo *recorrido;
    recorrido=lista;
    int nroVendedor=1;
    while (recorrido) {
        write<<setw(2)<<setfill('0')<<nroVendedor<<")";
        write<<setfill(' ');
        write<<setw(4)<<""<<recorrido->vendedor.codigo;
        write<<setw(2)<<""<<recorrido->vendedor.nombre;
        write<<setw(2)<<""<<recorrido->vendedor.porcentajeVentas;
        write<<setw(2)<<""<<recorrido->vendedor.cuotaMinima;
        write<<setw(2)<<""<<recorrido->vendedor.CantidadDeVentas<<endl;
        write<<fixed<<setprecision(2);
        recorrido=recorrido->siguiente;
        nroVendedor++;
    }
    imprimirLinea(ANCHO_REPORTE,'=',write);
}

void imprimirEncabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"TIENDA POR DEPARTAMENTOS TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"DETALLE DE PAGOS A LOS VENDEDORES"<<endl;
    imprimirLinea(ANCHO_REPORTE,'=',write);
    write<<"No."<<setw(4)<<""<<"VENDEDOR";
    write<<setw(15)<<""<<"% POR VENTAS";
    write<<setw(5)<<""<<"CUOTA MINIMA";
    write<<setw(5)<<""<<"CANTIDAD DE VENTAS"<<endl;
    imprimirLinea(ANCHO_REPORTE,'-',write);
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void EliminarInformacion(struct Nodo *&lista) {
    struct Nodo *recorrido;
    struct Nodo *anterior;
    anterior=nullptr;
    recorrido=lista;
    while (true) {
        if (recorrido==nullptr) break;
        if (recorrido->vendedor.porcentajeVentas>10.0) {
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

void insertar_ordenado(struct Nodo *&lista, const struct Vendedor & vendedor) {
    struct Nodo*nuevo_nodo;
    struct Nodo*recorrido;
    struct Nodo*anterior;
    recorrido=lista;
    anterior=nullptr;
    nuevo_nodo=new struct Nodo;
    nuevo_nodo->vendedor=vendedor;
    nuevo_nodo->siguiente=nullptr;
    while (recorrido) {
        if (recorrido->vendedor.codigo>vendedor.codigo)break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr)lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void crear_lista_ordenada(const char *str, struct Nodo *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    int codigo;
    char *nombre;
    lista=nullptr;
    while (true) {
        read>>codigo;
        if (read.eof())break;
        struct Vendedor vendedor;
        inicializarVendedor(vendedor);
        read.get();
        vendedor.codigo=codigo;
        nombre=leer_cadena(MAX_CARACTERES,',',read);
        nombre=modificarCadena(nombre);
        vendedor.nombre=asignarCadena(nombre);
        vendedor.porcentajeVentas=leer_double(read);
        vendedor.cuotaMinima=leer_double(read);
        insertar_ordenado(lista,vendedor);
    }
}

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
    read>>ws;
    read.getline(cadena, n,c);
    if (read.eof())return nullptr;
    str=new char[strlen(cadena)+1];
    strcpy(str,cadena);
    return str;
}

char * modificarCadena(char *name) {
    char *str;
    str=new char[strlen(name)+1];
    strcpy(str,name);
    bool inicioPalabra=true;
    for (int i=0;str[i];i++) {
        if (inicioPalabra) {
            inicioPalabra=false;
        }
        else {
            if (str[i]>='A' and str[i]<='Z')str[i]+=32;
            if (str[i]=='/' or str[i]=='-') {
                str[i]=' ';
                inicioPalabra=true;
            }
        }
    }
    return str;
}

char * asignarCadena(const char *name) {
    char *str;
    str=new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

double leer_double(ifstream &read) {
    double n;
    read>>n;
    read.get();
    return n;
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}
