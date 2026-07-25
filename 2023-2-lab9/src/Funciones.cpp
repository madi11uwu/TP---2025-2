//
// Created by Madi on 17/11/2025.
//

#include "Funciones.hpp"
#include "Alumno.hpp"
#include "Curso.hpp"
#include "Escala.hpp"
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

void imprimir_encabezado(char *semestre, ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"INSTITUCION EDUCATIVA_TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"DETALLE DE PAGOS REALIZADO POR CICLO"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"CICLO: "<<semestre<<endl;

}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

char * leer_str(ifstream &read, char c, int n) {
    char *str;
    char buffer[n];
    read.getline(buffer,n,c);
    if (read.eof())return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

char * asignar_str(const char *name) {
    char *str;
    str = new char[strlen(name)+1];
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

void cargarEscalas(const char *str, struct Escala *&escala, int &n_escala) {
    ifstream read;
    apertura_lectura(str,read);
    escala=new struct Escala[30]();
    char *semestre;
    while (true) {
        semestre=leer_str(read,',',MAX_CARACTERES);
        if (read.eof()) break;
        escala[n_escala].semestre=semestre;
        escala[n_escala].escala=leer_char(read);
        read>>escala[n_escala].costoPorCredito;
        n_escala++;
    }
}

char leer_char(ifstream &read) {
    char c;
    read>>c;
    read.get();
    return c;
}

void cargarCursos(const char *file, struct Curso *&curso, int &n) {
    ifstream read;
    apertura_lectura(file,read);
    curso=new struct Curso[100]();
    int codigoCurso;
    while (true) {
        read>>codigoCurso;
        if (read.eof())break;
        read.get();
        curso[n].codigoCurso=codigoCurso;
        curso[n].nombreCurso=leer_str(read,',',MAX_CARACTERES);
        read>>curso[n].numCreditos;
        curso[n].alumnos=new struct Alumno[50]();
        n++;
    }
}

int buscarCurso(int codigo_curso, struct Curso * curso, int n_curso) {
    for (int i = 0; i < n_curso; i++) {
        if (curso[i].codigoCurso==codigo_curso) return i;
    }
    return -1;
}

void LeerMatricula(const char *str, struct Curso *curso, struct Escala *escala,
                   int n_escala, int n_curso, char *semestre) {
    ifstream read;
    apertura_lectura(str, read);
    char *semestreLeido;
    int codigoAlumno;
    int codigoCurso,pos;
    char c;
    while (true) {
        semestreLeido=leer_str(read,',',MAX_CARACTERES);
        if (read.eof())break;
        if (strcmp(semestre,semestreLeido)==0) {
            codigoAlumno=leer_int(read);
            while (true) {
                read>>codigoCurso;
                c=read.get();
                pos=buscarCurso(codigoCurso,curso,n_curso);
                if (pos!=-1) {
                    curso[pos].alumnos[curso[pos].cantidadAlumnos].codigo=codigoAlumno;
                    curso[pos].cantidadAlumnos++;
                }
                if (c=='\n')break;
            }
        }
        else {
            read.ignore(500,'\n');
            continue;
        }
    }
}
