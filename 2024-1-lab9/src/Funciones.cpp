//
// Created by Madi on 16/11/2025.
//

#include "Funciones.hpp"
#include "Cliente.hpp"
#include "Fecha.hpp"
#include "Venta.hpp"
#include "Libro.hpp"

void apertura_lectura(const char *file, ifstream &read) {
    read.open(file, ios::in);
    if (!read.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"LIBRERIA PUCP-TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"RESULTADO DE LAS VENTAS REALIZADAS"<<endl;
    imprimir_linea(ANCHO_REPORTE, '=', write);
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void cargarCliente(const char *file, struct Cliente *&cliente, int &n_clientes) {
    ifstream read;
    apertura_lectura(file, read);
    cliente=new struct Cliente[MAX_CLIENTES];
    char *nombre;
    int dni;
    while (true) {
        read>>dni;
        if (read.eof())break;
        read.get();
        cliente[n_clientes].dni=dni;
        nombre=leer_cadena(read,MAX_CARACTERES,'\n');
        nombre=modificar_cadena(nombre);
        cliente[n_clientes].nombre=nombre;
        n_clientes++;
    }
}

char * leer_cadena(ifstream &read, int n, char c) {
    char *str;
    char buffer[n];
    read.getline(buffer, n,c);
    if (read.eof())return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

char * asignar_cadena(const char *name) {
    char *str;
    str = new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

char * modificar_cadena(char *cadena) {
    char *str;
    str = new char[strlen(cadena)+1];
    strcpy(str,cadena);
    for (int i=0;str[i];i++) {
        if (str[i]>='a' and str[i]<='z')str[i]-=32;
    }
    return str;
}

void cargarLibros(const char *file, struct Libro *&libro, int &n_libros) {
    ifstream read;
    apertura_lectura(file, read);
    libro=new struct Libro[MAX_LIBROS]();
    char *codigo;
    while (true) {
        codigo=leer_cadena(read,MAX_CARACTERES, ',');
        if (read.eof()) break;
        libro[n_libros].codigo=asignar_cadena(codigo);
        libro[n_libros].titulo=leer_cadena(read,MAX_CARACTERES, ',');
        libro[n_libros].autor=leer_cadena(read,MAX_CARACTERES, ',');
        read>>libro[n_libros].precio;
        n_libros++;
    }
    for (int i=0;i<n_libros;i++) {
        libro[i].ventas=new struct Venta[10]();
    }
}

int leer_int(ifstream &read) {
    int d;
    read>>d;
    read.get();
    return d;
}

double leer_double(ifstream &read) {
    double n;
    read>>n;
    read.get();
    return n;
}

void completarLibros(const char *str, struct Libro *libro, int n_libros) {
    ifstream read;
    apertura_lectura(str, read);
    char *codigo;
    char c;
    int dni,dd,mm,aa,calificacion,pos,fecha;
    while (true) {
        codigo=leer_cadena(read,MAX_CARACTERES, ',');
        if (read.eof())break;
        dni=leer_int(read);
        read>>dd>>c>>mm>>c>>aa;
        fecha=almacenarFecha(dd,mm,aa);
        read.get();
        read>>calificacion;
        pos=BuscarLibro(codigo,libro,n_libros);
        if (pos!=-1) {
            libro[pos].ventas[libro[pos].librosVendidos].dni=dni;
            libro[pos].ventas[libro[pos].librosVendidos].calificacion=calificacion;
            libro[pos].ventas[libro[pos].librosVendidos].fecha.aa=aa;
            libro[pos].ventas[libro[pos].librosVendidos].fecha.dd=dd;
            libro[pos].ventas[libro[pos].librosVendidos].fecha.mm=mm;
            libro[pos].ventas[libro[pos].librosVendidos].fecha.fecha=fecha;
            libro[pos].librosVendidos++;
            libro[pos].sumaDeCalificaciones+=calificacion;
        }
    }
}

int almacenarFecha(int dd, int mm, int aa) {
    return (aa*10000+mm*100+dd);
}

int BuscarLibro(char *codigo, struct Libro *libro, int n_libros) {
    for (int i=0;i<n_libros;i++) {
        if (strcmp(codigo,libro[i].codigo)==0) {
            return i;
        }
    }
    return -1;
}

void calcularRanking(struct Libro *libro, int n_libros) {
    for (int i=0;i<n_libros;i++) {
        if (libro[i].librosVendidos==0)libro[i].ranking=0;
        else if (libro[i].sumaDeCalificaciones/libro[i].librosVendidos<25) {
            libro[i].ranking=1;
        }
        else if (libro[i].sumaDeCalificaciones/libro[i].librosVendidos>=25
            and libro[i].sumaDeCalificaciones/libro[i].librosVendidos<50) {
            libro[i].ranking=2;
        }
        else if (libro[i].sumaDeCalificaciones/libro[i].librosVendidos>=50
            and libro[i].sumaDeCalificaciones/libro[i].librosVendidos<75) {
            libro[i].ranking=3;
        }
        else
            libro[i].ranking=5;
    }
}

void ordenarLibros(struct Libro *libro, int n_libros) {
    for (int i=0;i<n_libros-1;i++) {
        for (int k=i+1;k<n_libros;k++) {
            if (libro[i].ranking<libro[k].ranking or
                (libro[i].ranking==libro[k].ranking and
                    strcmp(libro[i].titulo,libro[k].titulo)<0)) {
                swapStruct(libro[i],libro[k]);
            }
        }
    }
}

void swapStruct(struct Libro &a, struct Libro &b) {
    Libro aux;
    aux=a;
    a=b;
    b=aux;
}

void imprimir_segundaParte(int nro_ventas, int dni, char * nombre, int calificacion,ofstream &write) {
    write<<setw(8)<<""<<setw(2)<<setfill('0')<<nro_ventas;
    write<<setfill(' ');
    write<<setw(5)<<""<<dni;
    write<<setw(8)<<""<<nombre;
    write<<setw(20)<<""<<calificacion<<endl;
}

void imprimir_reporte(const char *file,struct Libro *libro, int n_libros,
                      struct Cliente *cliente, int n_clientes){
    ofstream write;
    apertura_escritura(file,write);
    imprimir_encabezado(write);
    int nro_libro=1;
    for (int i=0;i<n_libros;i++) {
        imprimir_primeraParte(nro_libro,libro[i].codigo,libro[i].titulo,
            libro[i].autor,libro[i].precio,libro[i].librosVendidos,
            libro[i].ranking,write);
        int nro_ventas=0;
        write<<setw(8)<<""<<"VENTAS REALIZADAS: "<<endl;
        if (libro[i].librosVendidos!=0) {
            imprimir_encabezadoSecundario(write);
            for (int k=0;k<n_clientes;k++) {
                for (int j=0;libro[i].ventas[j].dni;j++) {
                    if (libro[i].ventas[j].dni==cliente[k].dni) {
                        imprimir_segundaParte(nro_ventas, cliente[k].dni,
                                              cliente[k].nombre,
                                              libro[i].ventas[j].calificacion,write);
                    nro_ventas++;
                    }
                }
            }
        }
        else write<<setw(8)<<""<<"NO SE VENDIO ESTE LIBRO"<<endl;
        imprimir_linea(ANCHO_REPORTE,'=',write);
        nro_libro++;
    }
}

void imprimir_encabezadoSecundario(ofstream &write) {
    write<<setw(8)<<""<<"No.";
    write<<setw(5)<<""<<"DNI";
    write<<setw(8)<<""<<"NOMBRE";
    write<<setw(20)<<""<<"CALIFICACION"<<endl;
}

void imprimir_primeraParte(int n, char *codigo, char *titulo,
                           char *autor, double precio, int libros,
                           int ranking,ofstream &write) {
    write<<"LIBRO NO. "<<setw(3)<<setfill('0')<<n<<endl;
    write<<setfill(' ');
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"CODIGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"TITULO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"AUTOR";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"PRECIO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"LIBROS VENDIDOS";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<"RANKINGS"<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<codigo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<titulo;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<autor;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<precio;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<libros;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+5))<<""<<ranking<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

int BuscarCliente(int dni, struct Cliente *cliente, int n_clientes) {
    for (int i=0;i<n_clientes;i++) {
        if (dni==cliente[i].dni) {
            return i;
        }
    }
    return -1;
}
