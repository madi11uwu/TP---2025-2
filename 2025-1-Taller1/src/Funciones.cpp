//
// Created by Madi on 1/12/2025.
//

#include "Funciones.hpp"

#include <list>

void insertarNodo(struct NodoCurso *&lista, struct Curso curso) {
    struct NodoCurso *nuevo_nodo;
    nuevo_nodo=new NodoCurso{};
    nuevo_nodo->dato=curso;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr)lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void insertarNodoEscala(struct NodoEscala *&lista, struct Escala escala) {
    struct NodoEscala *nuevo_nodo;
    nuevo_nodo=new NodoEscala{};
    nuevo_nodo->dato=escala;
    nuevo_nodo->siguiente=nullptr;
    if (lista==nullptr)lista=nuevo_nodo;
    else {
        nuevo_nodo->siguiente=lista;
        lista=nuevo_nodo;
    }
}

void insertarNodoAlumno(struct NodoAlumno *&lista,struct Alumno alumno) {
    struct NodoAlumno *nuevo_nodo;
    nuevo_nodo=new NodoAlumno{};
    nuevo_nodo->dato=alumno;
    nuevo_nodo->siguiente=nullptr;
    struct NodoAlumno *recorrido=lista;
    struct NodoAlumno *anterior=nullptr;
    while (recorrido) {
        if (recorrido->dato.escAlumno.escala>alumno.escAlumno.escala
            or recorrido->dato.escAlumno.escala==alumno.escAlumno.escala
             and strcmp(recorrido->dato.nombre,alumno.nombre)>0)break;
        anterior=recorrido;
        recorrido=recorrido->siguiente;
    }
    nuevo_nodo->siguiente=recorrido;
    if (anterior==nullptr)lista=nuevo_nodo;
    else anterior->siguiente=nuevo_nodo;
}

void imprimirLinea(int n, char c, ofstream &write) {
    for (int i=0;i<n;i++) {
        write.put(c);
    }
    write<<endl;
}

void imprimirReporte(const char *str, struct NodoAlumno *lista,
                     const char *titulo1, const char *titulo2,
                     char titulo3, int anio, int ciclo) {
    ofstream write;
    apertura_escritura(str,write);
    struct NodoAlumno *recorrido=lista;
    write<<setw((120-strlen(titulo1))/2)<<""<<titulo1<<endl;
    write<<setw((120-strlen(titulo2))/2)<<""<<titulo2<<endl;
    if (titulo3=='S') {
        write<<setw((120-strlen("CICLO: 2023-1"))/2)<<""<<"CICLO: "<<anio<<"-"<<ciclo<<endl;
    }
    imprimirLinea(120,'=',write);
    while (recorrido) {
        write<<"ALUMNO: "<<recorrido->dato.codAlumno<<" - ";
        write<<recorrido->dato.nombre;
        write<<setw(10)<<""<<"ESCALA: "<<recorrido->dato.escAlumno.escala;
        write<<setw(8)<<""<<"Valor credito: "<<recorrido->dato.escAlumno.valorCred<<endl;
        imprimirLinea(120,'-',write);
        write<<setw(5)<<""<<"CURSO MATRICULADO"<<setw(8)<<""<<"CREDITOS";
        write<<setw(5)<<""<<"MONTO PAGADO"<<endl;
        int curso=1;
        for (int i=0;i<recorrido->dato.cantidadCursos;i++) {
            write<<setw(2)<<setfill('0')<<curso<<setfill(' ')<<")";
            write<<setw(2)<<""<<recorrido->dato.cursos[i].codCurso<<" - ";
            write<<recorrido->dato.cursos[i].nombre<<setw(8)<<"";
            write<<recorrido->dato.cursos[i].creditos<<setw(8)<<"";
            write<<recorrido->dato.cursos[i].creditos*recorrido->dato.escAlumno.valorCred<<endl;
        }
        imprimirLinea(120,'-',write);
        write<<"TOTAL CREDITOS: "<<recorrido->dato.totalCreditos;
        write<<setw(3)<<""<<"TOTAL MONTO PAGADO: "<<recorrido->dato.totalPago<<endl;
        imprimirLinea(120,'=',write);
        recorrido=recorrido->siguiente;
    }
}

struct NodoAlumno * BuscarNodoAlumno(struct NodoAlumno *lista, int cod_alumno) {
    struct NodoAlumno *recorrido=lista;
    while (recorrido) {
        if (cod_alumno==recorrido->dato.codAlumno) return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

struct NodoEscala * BuscarNodoEscala(struct NodoEscala * nodo_escala, char escala, int ciclo, int anio) {
    struct NodoEscala *recorrido=nodo_escala;
    while (recorrido) {
        if (escala==recorrido->dato.escala and anio==recorrido->dato.anho and
            ciclo==recorrido->dato.ciclo)return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

struct NodoCurso * BuscarNodoCurso(struct NodoCurso * nodo_curso, int cod_curso) {
    struct NodoCurso *recorrido=nodo_curso;
    while (recorrido) {
        if (cod_curso==recorrido->dato.codCurso)return recorrido;
        recorrido=recorrido->siguiente;
    }
    return nullptr;
}

void CompletarAlumnos(const char *str, struct NodoAlumno *listaAlumno,
                      struct NodoCurso *listaCurso,
                      struct NodoEscala *listaEscala,
                      int anio, int ciclo) {
    ifstream read;
    apertura_lectura(str,read);
    int anioLeido,cicloLeido,codAlumno,codCurso;
    char c;
    while (true) {
        read>>anioLeido;
        if (read.eof())break;
        read>>c>>cicloLeido;
        if (ciclo==cicloLeido and anio==anioLeido) {
            read>>codAlumno;
            struct NodoAlumno *posicion=BuscarNodoAlumno(listaAlumno,codAlumno);
            if (posicion!=nullptr) {
                struct NodoEscala *posiEscala = BuscarNodoEscala(listaEscala, posicion->dato.escAlumno.escala,
                                                                 ciclo, anio);
                if (posiEscala!=nullptr) posicion->dato.escAlumno=posiEscala->dato;
                while (true) {
                    read>>codCurso;
                    struct NodoCurso *posiCurso=BuscarNodoCurso(listaCurso,codCurso);
                    if (posiCurso!=nullptr) {
                        int n=posicion->dato.cantidadCursos;
                        posicion->dato.cursos[n]=posiCurso->dato;
                        posicion->dato.totalCreditos+=posiCurso->dato.creditos;
                        posicion->dato.totalPago+=posiCurso->dato.creditos*posicion->dato.escAlumno.valorCred;
                        posicion->dato.cantidadCursos++;
                    }
                    c=read.get();
                    if (c=='\n')break;
                }
            }
            else {
                read.ignore(200,'\n');
                continue;
            }
        }
        else {
            read.ignore(200,'\n');
            continue;
        }
    }
}

void EliminarNodos(struct NodoAlumno *lista, int ciclo, int anio) {
    struct NodoAlumno *recorrido=lista;
    struct NodoAlumno *anterior=nullptr;
    while (true) {
        if (recorrido==nullptr) break;
        if (recorrido->dato.escAlumno.anho!=anio or
            recorrido->dato.escAlumno.ciclo!=ciclo) {
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
            recorrido=anterior->siguiente;
        }
    }
}

void cargarAlumnos(const char *str, struct NodoAlumno *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    int codAlumno;
    while (true) {
        codAlumno=leer_int(read);
        if (read.eof())break;
        struct Alumno alumno{};
        alumno.cursos=new struct Curso[8]{};
        alumno.codAlumno=codAlumno;
        alumno.nombre=leer_cadena(100,',',read);
        alumno.escAlumno.escala=leer_char(read);
        insertarNodoAlumno(lista,alumno);
    }
}

void cargarEscala(const char *str, struct NodoEscala *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    int anio,ciclo;
    char c;
    while (true) {
        read>>anio;
        if (read.eof())break;
        struct Escala escala{};
        read>>c>>ciclo>>c;
        escala.anho=anio;
        escala.ciclo=ciclo;
        escala.escala=leer_char(read);
        escala.valorCred=leer_double(read);
        insertarNodoEscala(lista,escala);
    }
}

char leer_char(ifstream &read) {
    char c;
    read>>c;
    read.get();
    return c;
}

void cargarCursos(const char *str, struct NodoCurso *&lista) {
    ifstream read;
    apertura_lectura(str,read);
    lista=nullptr;
    int codCurso;
    while (true) {
        codCurso=leer_int(read);
        if (read.eof())break;
        struct Curso c{};
        c.codCurso=codCurso;
        c.nombre=leer_cadena(80,',',read);
        c.creditos=leer_double(read);
        insertarNodo(lista,c);
    }
}

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

int leer_int(ifstream &read) {
    int d;
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

double leer_double(ifstream &read) {
    double d;
    read>>d;
    read.get();
    return d;
}
