//
// Created by Madi on 28/11/2025.
//

#include "Funciones.hpp"
#include "UsuarioConElLibro.hpp"
#include "LibroEnSuPoder.hpp"
#include "Libro.hpp"
#include "Usuario.hpp"

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

void cargarLibros(const char *str, struct Libro *&libro, int &n_libros) {
    ifstream read;
    apertura_lectura(str, read);
    char *codigoLibro;
    libro=new Libro[40]{};
    int n;
    while (true) {
        codigoLibro=leer_cadena(10,',',read);
        if (read.eof())break;
        libro[n_libros].codigo=codigoLibro;
        libro[n_libros].titulo=leer_cadena(150,',',read);
        libro[n_libros].autor=leer_cadena(90,',',read);
        libro[n_libros].cantidad=leer_int(read);
        n=libro[n_libros].cantidad;
        libro[n_libros].precio=leer_double(read);
        libro[n_libros].usuario=new UsuarioConElLibro[n]{};
        n_libros++;
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

char * asignarCadena(char *name) {
    char *str;
    str=new char[strlen(name)+1];
    strcpy(str,name);
    return str;
}

char leer_char(ifstream &read) {
    char c;
    read>>c;
    read.get();
    return c;
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

void probarLibros(const char *str, struct Libro *libro, int n_libros) {
    ofstream write;
    apertura_escritura(str, write);
    write<<setw((ANCHO_REPORTE-strlen("LIBROS"))/2)<<""<<"LIBROS"<<endl;
    imprimirLinea(ANCHO_REPORTE,'-',write);
    write<<"CODIGO"<<setw(5)<<""<<"TITULO";
    write<<setw(10)<<""<<"CANTIDAD";
    write<<setw(10)<<""<<"PRECIO"<<endl;
    for (int i = 0; i < n_libros; i++) {
        write<<libro[i].codigo;
        write<<setw(5)<<""<<libro[i].titulo;
        imprimirEspacios(30,strlen(libro[i].titulo),write);
        write<<setw(10)<<""<<libro[i].cantidad;
        write<<setw(10)<<""<<libro[i].precio<<endl;
        write<<"USUARIOS: "<<endl;
        for (int j = 0; j < libro[i].cantUsuarios; j++) {
            write<<libro[i].usuario[j].dni<<setw(5)<<""<<libro[i].usuario[j].fechaDevolucion<<endl;
        }
        imprimirLinea(ANCHO_REPORTE,'-',write);
    }
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void cargarUsuarios(const char *str, struct Usuario *&usuario, int &n_usuarios) {
    ifstream read;
    apertura_lectura(str, read);
    int dni;
    usuario=new Usuario[60]{};
    while (true) {
        read>>dni;
        if (read.eof()) break;
        read.get();
        usuario[n_usuarios].dni=dni;
        usuario[n_usuarios].nombre=leer_cadena(100,',',read);
        usuario[n_usuarios].categoria=leer_char(read);
        usuario[n_usuarios].calificacion=leer_double(read);
        usuario[n_usuarios].libros=new LibroEnSuPoder[6]{};
        n_usuarios++;
    }
}

void probarUsuarios(const char *str, struct Usuario *usuario, int n_usuarios) {
    ofstream write;
    apertura_escritura(str, write);
    write<<setw((ANCHO_REPORTE-strlen("USUARIOS"))/2)<<""<<"USUARIOS"<<endl;
    imprimirLinea(ANCHO_REPORTE,'-',write);
    write<<"DNI"<<setw(10)<<""<<"NOMBRE";
    write<<setw(10)<<""<<"CATEGORIA";
    write<<setw(10)<<""<<"CALIFICACION"<<endl;
    for (int i = 0; i < n_usuarios; i++) {
        write<<usuario[i].dni;
        write<<setw(5)<<""<<usuario[i].nombre;
        imprimirEspacios(35,strlen(usuario[i].nombre),write);
        write<<setw(10)<<""<<usuario[i].categoria;
        write<<setw(10)<<""<<usuario[i].calificacion<<endl;
        write<<"LIBROS: "<<endl;
        for (int j=0;j<usuario[i].cantLibros;j++) {
            write<<usuario[i].libros[j].codLibro<<setw(5)<<""<<usuario[i].libros[j].fechaDevolucion<<endl;
        }
        imprimirLinea(ANCHO_REPORTE,'-',write);
    }
}

void imprimirEspacios(int ancho, int size, ofstream &write) {
    for (int i = 0; i < ancho-size; i++) {
        write.put(' ');
    }
}

int buscarLibro(char * codigo, struct Libro * libro,int n) {
    for (int i=0;i<n;i++) {
        if (strcmp(libro[i].codigo,codigo)==0) return i;
    }
    return -1;
}

int BuscarUsuario(struct Usuario * usuario, int n_usuario, int dni) {
    for (int i=0;i<n_usuario;i++) {
        if (usuario[i].dni==dni) return i;
    }
    return -1;
}

void CompletarPrestamos(const char *str, struct Usuario *usuario, struct Libro *libro,
                        int n_usuario, int n_libro) {
    ifstream read;
    apertura_lectura(str, read);
    char *codigo, c;
    int dni, fecha, posLibro, posUsuario;
    while (true) {
        codigo = leer_cadena(10, ' ', read);
        if (read.eof())break;
        posLibro = buscarLibro(codigo, libro,n_libro);
        if (posLibro!=-1) {
            while (true) {
                read >> dni;
                fecha = almacenarFecha(read);
                posUsuario=BuscarUsuario(usuario,n_usuario,dni);
                if (posUsuario!=-1) {
                    int n=usuario[posUsuario].cantLibros;
                    int nLibro=libro[posLibro].cantUsuarios;
                    libro[posLibro].usuario[nLibro].dni=dni;
                    libro[posLibro].usuario[nLibro].fechaDevolucion=fecha;
                    usuario[posUsuario].libros[n].codLibro=asignarCadena(codigo);
                    usuario[posUsuario].libros[n].fechaDevolucion=fecha;
                    libro[posLibro].cantUsuarios++;
                    usuario[posUsuario].cantLibros++;
                }
                c = read.get();
                if (c == '\n')break;
            }
        }
        else {
            read.ignore(500,'\n');
            continue;
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

void ordenarLibro(struct Libro *libro, int n_libros) {
    for (int i=0;i<n_libros-1;i++) {
        for (int k=i+1;k<n_libros;k++) {
            if (strcmp(libro[i].codigo,libro[k].codigo)>0) {
                swapStruct(libro[i],libro[k]);
            }
        }
    }
    for (int i=0;i<n_libros;i++) {
        for (int k=0;k<libro[i].cantUsuarios-1;k++) {
            for (int j=k+1;j<libro[i].cantUsuarios;j++) {
                if (libro[i].usuario[k].fechaDevolucion<libro[i].usuario[j].fechaDevolucion
                    or (libro[i].usuario[k].fechaDevolucion==libro[i].usuario[j].fechaDevolucion
                        and libro[i].usuario[k].dni>libro[i].usuario[j].dni)) {
                        swapUsuario(libro[i].usuario[k],libro[i].usuario[j]);
                }
            }
        }
    }
}

void swapStruct(struct Libro &a, struct Libro &b) {
    struct Libro aux;
    aux=a;
    a=b;
    b=aux;
}

void swapUsuario(struct UsuarioConElLibro &a, struct UsuarioConElLibro &b) {
    struct UsuarioConElLibro aux;
    aux=a;
    a=b;
    b=aux;
}

