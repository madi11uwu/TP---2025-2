//
// Created by Madi on 9/11/2025.
//

#include "Funciones.hpp"
#include "Distrito.hpp"
#include "PlatoPedido.hpp"
#include "Cliente.hpp"
#include "Plato.hpp"

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
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

void cargar_distrito(const char *file, struct Distrito *distrito, int &n_distrito) {
    ifstream leer;
    apertura_lectura(file,leer);
    char *codDistrito;
    while (true) {
        codDistrito=leer_string(leer,',',MAX_CARACTERES);
        if (leer.eof()) break;
        distrito[n_distrito].codigo=codDistrito;
        distrito[n_distrito].nombre=leer_string(leer,',',MAX_CARACTERES);
        distrito[n_distrito].ubicacion=leer_string(leer,'\n',MAX_CARACTERES);
        n_distrito++;
    }
}

void cargar_platos(const char *file, struct Plato *plato, int &n_plato) {
    ifstream leer;
    apertura_lectura(file,leer);
    char *codigo;
    while (true) {
        codigo=leer_string(leer,',',MAX_CARACTERES);
        if (leer.eof()) break;
        plato[n_plato].codigo=codigo;
        plato[n_plato].descripcion=leer_string(leer,',',MAX_CARACTERES);
        plato[n_plato].precio=leer_double(leer);
        plato[n_plato].categoria=leer_string(leer,'\n',MAX_CARACTERES);
        plato[n_plato].cantidad++;
        n_plato++;
    }
}

void cargar_cliente(const char *file, struct Cliente *cliente, int &n_clientes) {
    ifstream leer;
    apertura_lectura(file,leer);
    int DNI;
    while (true) {
        leer>>DNI;
        if (leer.eof()) break;
        leer.get();
        cliente[n_clientes].dni=DNI;
        cliente[n_clientes].nombre=leer_string(leer,',',MAX_CARACTERES);
        cliente[n_clientes].distrito.codigo=leer_string(leer,'\n',MAX_CARACTERES);
        n_clientes++;
    }
}

int leer_int(ifstream &leer) {
    int n;
    leer>>n;
    leer.get();
    return n;
}

double leer_double(ifstream &leer) {
    double n;
    leer>>n;
    leer.get();
    return n;
}

char *leer_string(ifstream &leer,char delim,int n) {
    char *cadena,buffer[n];
    leer.getline(buffer,n,delim);
    if (leer.eof())return nullptr;
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void probar_distrito(const char *file, struct Distrito *distrito, int n_distrito) {
    ofstream write;
    apertura_escritura(file,write);
    write<<"DISTRITOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"CODIGO"<<setw(5)<<""<<"NOMBRE";
    write<<setw(5)<<""<<"UBICACION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    for (int i=0;i<n_distrito;i++) {
        write<<distrito[i].codigo;
        write<<setw(5)<<""<<distrito[i].nombre;
        write<<setw(5)<<""<<distrito[i].ubicacion<<endl;
    }
}

void probar_platos(const char *file, struct Plato *distrito, int n_distrito) {
    ofstream write;
    apertura_escritura(file,write);
    write<<"PLATOS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"CODIGO"<<setw(5)<<""<<"DESCRIPCION";
    write<<setw(5)<<""<<"PRECIO";
    write<<setw(5)<<""<<"CATEGORIA";
    write<<setw(5)<<""<<"CANTIDAD"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    for (int i=0;i<n_distrito;i++) {
        write<<distrito[i].codigo;
        write<<setw(5)<<""<<distrito[i].descripcion;
        write<<setw(5)<<""<<distrito[i].precio;
        write<<setw(5)<<""<<distrito[i].categoria;
        write<<setw(5)<<""<<distrito[i].cantidad<<endl;
    }
}

void probar_cliente(const char *file, struct Cliente *cliente, int n_distrito) {
    ofstream write;
    apertura_escritura(file,write);
    write<<"CLIENTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"DNI"<<setw(10)<<""<<"NOMBRE";
    write<<setw(10)<<""<<"CODIGO DISTRITO"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
    for (int i=0;i<n_distrito;i++) {
        write<<cliente[i].dni;
        write<<setw(5)<<""<<cliente[i].nombre;
        write<<setw(5)<<""<<cliente[i].distrito.codigo<<endl;
    }
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

int BuscarCliente(int dni, struct Cliente * cliente, int n_clientes) {
    for (int i = 0; i < n_clientes; i++) {
        if (cliente[i].dni == dni) {
            return i;
        }
    }
    return -1;
}

int BuscarPlato(char * codplato, struct Plato * plato, int n_plato) {
    for (int i = 0; i < n_plato; i++) {
        if (strcmp(codplato, plato[i].codigo) == 0) {
            return i;
        }
    }
    return -1;
}

void swapStructClientes(struct Cliente &a, struct Cliente &b) {
    struct Cliente aux;
    aux=a;
    a=b;
    b=aux;
}

void swapStructPlatos(struct PlatoPedido &a, struct PlatoPedido &b) {
    struct PlatoPedido aux;
    aux=a;
    a=b;
    b=aux;
}

void imprimir_encabezadoPrincipal(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"EMPRESA DE REPARTOS A DOMICILIO TP S.A."<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"RELACION DE PEDIDOS POR CLIENTE"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_encabezadoSecundario(ofstream &write) {
    write<<"DNI"<<setw(10)<<""<<"NOMBRE";
    write<<setw(20)<<""<<"DISTRITO";
    write<<setw(15)<<""<<"PAGO TOTAL"<<endl;
}

void ordenarPlatosPedidos(struct Cliente *cliente, int n_cliente) {
    for (int j=0;j<n_cliente;j++) {
        for (int i=0;i<MAX_PLATOSPEDIDOS-1;i++)
            for (int k=i+1;k<MAX_PLATOSPEDIDOS;k++) {
                if (cliente[j].plato_estatico[i].codigoPedido>cliente[j].plato_estatico[k].codigoPedido
                    or (cliente[j].plato_estatico[i].codigoPedido>cliente[j].plato_estatico[k].codigoPedido
                        and cliente[j].plato_estatico[i].codigoPlato<cliente[j].plato_estatico[k].codigoPlato)) {
                    swapStructPlatos(cliente[j].plato_estatico[i],cliente[j].plato_estatico[k]);
                }
            }
    }
}

void ordenarCliente(struct Cliente *cliente,int n_cliente) {
    for (int i=0;i<n_cliente-1;i++)
        for (int k=i+1;k<n_cliente;k++) {
            if (strcmp(cliente[i].nombre,cliente[k].nombre) > 0) {
                swapStructClientes(cliente[i],cliente[k]);
            }
        }
}

void llenarArregloCliente(const char *file, struct Distrito *distrito,
                          struct Plato *plato, struct Cliente *cliente,
                          int n_distrito, int n_clientes, int n_plato) {
    ifstream read;
    apertura_lectura(file,read);
    int codigoPedido,dni,cantidadVendida,posCliente,posPlato;
    char *Codplato;
    while (true) {
        read>>codigoPedido;
        if (read.eof()) break;
        read>>dni;
        Codplato = leer_cadena_exacta(read);
        read>>cantidadVendida;
        posCliente=BuscarCliente(dni,cliente,n_clientes);
        posPlato=BuscarPlato(Codplato,plato,n_plato);
        if (posCliente!=-1) {
            cliente[posCliente].cantidadDePedidos+=cantidadVendida;
            cliente[posCliente].plato_estatico[cliente[posCliente].cantPlatos].codigoPlato=asignar_cadena(Codplato);
            cliente[posCliente].plato_estatico[cliente[posCliente].cantPlatos].codigoPedido=codigoPedido;
            cliente[posCliente].plato_estatico[cliente[posCliente].cantPlatos].cantidad+=cantidadVendida;
            if (posPlato!=-1) {
                cliente[posCliente].montoTotal+=plato[posPlato].precio*cantidadVendida;
                cliente[posCliente].plato_estatico[cliente[posCliente].cantPlatos].descripcion=asignar_cadena(plato[posPlato].descripcion);
                cliente[posCliente].plato_estatico[cliente[posCliente].cantPlatos].precio=plato[posPlato].precio;
                cliente[posCliente].plato_estatico[cliente[posCliente].cantPlatos].subtotal+=plato[posPlato].precio*cantidadVendida;
                cliente[posCliente].cantPlatos++;
            }
        }
    }
}

char *leer_cadena_exacta(ifstream &read) {
    char *cadena,buffer[MAX_CARACTERES];
    read>>buffer;
    if (read.eof()) return nullptr;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

char * asignar_cadena(const char *c) {
    char *str;
    str=new char[strlen(c)+1];
    strcpy(str,c);
    return str;
}
