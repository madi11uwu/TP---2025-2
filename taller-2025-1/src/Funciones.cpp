//
// Created by Madi on 30/11/2025.
//

#include "Funciones.hpp"

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

void insertarNodo(struct NodoCurso *&lista,struct Curso curso) {
    struct NodoCurso *nuevo_nodo;
    nuevo_nodo=new NodoCurso;
    nuevo_nodo->dato=curso;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void cargarCursos(const char *str, struct NodoCurso *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    int codigo;
    while (true) {
        read>>codigo;
        if (read.eof())break;
        read.get();
        struct Curso c{};
        c.codCurso=codigo;
        c.nombre=leer_cadena(65,',',read);
        c.creditos=leer_double(read);
        insertarNodo(lista,c);
    }
}

void insertarNodoEscala(struct NodoEscala *&lista, const struct Escala escala) {
    struct NodoEscala *nuevo_nodo;
    nuevo_nodo=new NodoEscala;
    nuevo_nodo->dato=escala;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr) lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void cargarEscalas(const char *str, struct NodoEscala *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    int anio;
    while (true) {
        read>>anio;
        if (read.eof())break;
        read.get();
        struct Escala e{};
        e.anho=anio;
        e.ciclo=leer_int(read);
        e.escala=leer_char(read);
        e.valorCred=leer_double(read);
        insertarNodoEscala(lista,e);
    }
}

char leer_char(ifstream &read) {
    char c;
    read>>c;
    read.get();
    return c;
}

void insertarNodoAlumno(struct NodoAlumno *&lista, const struct Alumno alumno) {
    struct NodoAlumno *nuevo_nodo;
    struct NodoAlumno *recorrido=lista;
    struct NodoAlumno *anterior=nullptr;
    nuevo_nodo=new NodoAlumno;
    nuevo_nodo->dato=alumno;
    nuevo_nodo->siguiente=nullptr;
    while (recorrido) {
        if (recorrido->dato.escAlumno.escala>alumno.escAlumno.escala or
            (recorrido->dato.escAlumno.escala==alumno.escAlumno.escala
                and strcmp(recorrido->dato.nombre,alumno.nombre)>0))break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr) lista=nuevo_nodo;
    else {
        anterior->siguiente=nuevo_nodo;
    }

}

struct NodoEscala * BuscarNodo(char ca, struct NodoEscala * lista) {
    struct NodoEscala *recorrido;
    recorrido=lista;
    while (recorrido) {
        if (recorrido->dato.escala==ca) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void cargarAlumnos(const char *str, struct NodoAlumno *&lista,
                   struct NodoEscala *listaEscala) {
    ifstream read;
    apertura_lectura(str, read);
    lista = nullptr;
    char ca;
    int codigo;
    while (true) {
        read >> codigo;
        if (read.eof())break;
        read.get();
        struct Alumno c{};
        c.codAlumno = codigo;
        c.nombre = leer_cadena(50, ',', read);
        c.escAlumno.escala = leer_char(read);
        ca=c.escAlumno.escala;
        struct NodoEscala *posicion=BuscarNodo(ca,listaEscala);
        if (posicion!=nullptr) {
            c.escAlumno.valorCred=posicion->dato.valorCred;
            c.escAlumno.anho=posicion->dato.anho;
            c.escAlumno.ciclo=posicion->dato.ciclo;
        }
        c.cursos = new Curso[8]{};
        insertarNodoAlumno(lista, c);
    }
}

void ImprimirReporte(const char *str, struct NodoAlumno *lista,int anio,int ciclo) {
    ofstream write;
    apertura_escritura(str, write);
    struct NodoAlumno *recorrido;
    recorrido=lista;
    imprimirEncabezado(write,anio,ciclo);
    while (recorrido) {
        write<<"ALUMNO: "<<recorrido->dato.codAlumno<<" - "<<recorrido->dato.nombre;
        write<<setw(10)<<""<<"ESCALA: "<<recorrido->dato.escAlumno.escala;
        write<<setw(5)<<""<<"Valor Credito: "<<recorrido->dato.escAlumno.valorCred<<endl;
        imprimirLinea(120,'-',write);
        write<<setw(8)<<""<<"CURSO MATRICULADO"<<setw(10)<<"";
        write<<"CREDITOS"<<setw(5)<<""<<"MONTO PAGADO"<<endl;
        int nroCurso=1;
        for (int i=0;i<recorrido->dato.cantidadCursos;i++) {
            write<<setw(2)<<setfill('0')<<") ";
            write<<recorrido->dato.cursos[i].codCurso<<" - ";
            write<<recorrido->dato.cursos[i].nombre;
            write<<setw(8)<<""<<recorrido->dato.cursos[i].creditos;
            write<<setw(5)<<""<<recorrido->dato.cursos[i].creditos*recorrido->dato.escAlumno.valorCred<<endl;
        }
        write<<"TOTAL CREDITOS: "<<recorrido->dato.totalCreditos<<setw(3)<<"";
        write<<"TOTAL MONTO PAGADO: "<<recorrido->dato.totalPago<<endl;
        imprimirLinea(120,'=',write);
        recorrido=recorrido->siguiente;
    }
}

void imprimirEncabezado(ofstream &write, int anio, int ciclo) {
    write<<setw((120-strlen("INSTITUCION EDUCATIVA TP"))/2)<<"";
    write<<"INSTITUCION EDUCATIVA TP"<<endl;
    write<<setw((120-strlen("DETALLE DE PAGOS REALIZADOS POR CICLO"))/2)<<"";
    write<<"DETALLE DE PAGOS REALIZADOS POR CICLO"<<endl;
    write<<setw((120-strlen("CICLO: 2023-1"))/2)<<"";
    write<<"CICLO: "<<anio<<"-"<<ciclo<<endl;
    imprimirLinea(120,'=',write);
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i=0;i<n;i++) {
        write.put(c);
    }
    write<<endl;
}

struct NodoAlumno * BuscarNodoAlumno(int codigo_alumno, struct NodoAlumno * nodo_alumno) {
    struct NodoAlumno *recorrido=nodo_alumno;
    while (recorrido) {
        if (recorrido->dato.codAlumno==codigo_alumno) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

struct NodoCurso * BuscarNodoCurso(int codigo_curso, struct NodoCurso * nodo_curso) {
    struct NodoCurso *recorrido=nodo_curso;
    while (recorrido) {
        if (recorrido->dato.codCurso==codigo_curso) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void llenarAlumnos(const char *str, struct NodoEscala *nodo_escala, struct NodoAlumno *nodo_alumno,
                   struct NodoCurso *nodo_curso,
                   int anio, int ciclo) {
    ifstream read;
    apertura_lectura(str, read);
    int anioLeido,cicloLeido,codigoAlumno,codigoCurso;
    char c;
    while (true) {
        read>>anioLeido;
        if (read.eof())break;
        read>>c>>cicloLeido;
        if (anio==anioLeido and ciclo==cicloLeido) {
            read>>codigoAlumno;
            struct NodoAlumno *posicion=BuscarNodoAlumno(codigoAlumno,nodo_alumno);
            if (posicion!=nullptr) {
                while (true) {
                    read>>codigoCurso;
                    struct NodoCurso *posi=BuscarNodoCurso(codigoCurso,nodo_curso);
                    if (posi!=nullptr) {
                        int n=posicion->dato.cantidadCursos;
                        posicion->dato.cursos[n]=posi->dato;
                        posicion->dato.cantidadCursos++;
                    }
                    c=read.get();
                    if (c=='\n')break;
                }
            }
            else {
                read.ignore(100,'\n');
                continue;
            }
        }
        else {
            read.ignore(200,'\n');
            continue;
        }
    }
}



