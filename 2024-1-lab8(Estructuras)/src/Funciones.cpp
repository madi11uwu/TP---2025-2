//
// Created by Madi on 10/11/2025.
//

#include "Funciones.hpp"
#include "Facultad .hpp"
#include "Alumno.hpp"

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

void imprimir_encabezado(ofstream &write, char *semestre) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"INSTITUCION EDUCATIVA_TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"PROMEDIO PONDERADO DE LOS ALUMNOS MATRICULADOS"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"CICLO: "<<semestre<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO4)/2)<<""<<"TODAS LAS FACULTADES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+6))<<""<<"ALUMNO";
    write<<setw(ANCHO_REPORTE/NRO_COLUMNAS)<<""<<"No. de Cursos";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+20))<<""<<"Suma Ponderada";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+20))<<""<<"No. de Creditos";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+20))<<""<<"Prom Ponderado";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+20))<<""<<"Facultad"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void cargarAlumnos(const char *file, struct Alumno *&alumno, int &n_alumnos) {
    ifstream read;
    apertura_lectura(file,read);
    char *codigoCurso,c;
    int codigoAlumno,nota,pos;
    double numCreditos;
    alumno=new struct Alumno[MAX_ALUMNOS]();
    while (true) {
        codigoCurso = leer_cadena_csv(read,' ',MAX_CARACTERES);
        if (read.eof())break;
        read>>numCreditos;
        while (true) {
            read>>codigoAlumno>>nota;
            c=read.get();
            pos=BuscarAlumnos(codigoAlumno,alumno,n_alumnos);
            if (pos!=-1) {
                alumno[pos].sumaPonderada+=nota;
                alumno[pos].numCursos++;
            }
            else {
                alumno[n_alumnos].codigo=codigoAlumno;
                alumno[n_alumnos].numCursos++;
                alumno[n_alumnos].sumaPonderada+=nota;
                n_alumnos++;
            }
            if (c=='\n')break;
        }
    }
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void imprimirEspacios(int size, int ancho, ofstream &write) {
    if (int i=0;i<(ancho-size),i++) {
        write.put(' ');
    }
}

char * leer_cadena_exacta(ifstream &read) {
    char *str,buffer[MAX_CARACTERES];
    read>>buffer;
    if (read.eof())return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

char * leer_cadena_csv(ifstream &read, char delim, int n) {
    char buffer[n],*str;
    read.getline(buffer,n,delim);
    if (read.eof())return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

int BuscarAlumnos(int cod, struct Alumno *alumno, int n) {
    for (int i = 0; i < n; i++) {
        if (alumno[i].codigo==cod) {
            return i;
        }
    }
    return -1;
}

void llenarAlumnos(const char *file, struct Alumno *alumno, int n_alumnos) {
    ifstream read;
    apertura_lectura(file,read);
    int codigoAlumno,pos;
    while (true) {
        read>>codigoAlumno;
        if (read.eof()) break;
        read.get();
        pos=BuscarAlumnos(codigoAlumno,alumno,n_alumnos);
        if (pos!=-1) {
            alumno[pos].nombre=leer_cadena_csv(read,',',MAX_CARACTERES);
            alumno[pos].facultad.codigo=leer_cadena_csv(read,'\n',MAX_CARACTERES);
        }
        else {
            leer_cadena_csv(read,'\n',300);
            continue;
        }
    }
}

int BuscarFacultad(char * codigo_facu, struct Alumno * alumno, int n_alumnos) {
    for (int i = 0; i < n_alumnos; i++) {
        if (strcmp(alumno[i].facultad.codigo,codigo_facu)==0) {
            return i;
        }
    }
    return -1;
}

void llenarAlumnosPorDos(const char *file, struct Alumno *alumno, int n_alumnos) {
    ifstream read;
    apertura_lectura(file,read);
    char *facultad,*codigoFacu;
    int pos;
    while (true) {
        facultad=leer_cadena_exacta(read);
        if (read.eof())break;
        facultad=modificarCadena(facultad);
        codigoFacu=leer_cadena_exacta(read);
        for (int i = 0; i < n_alumnos; i++) {
            if (strcmp(alumno[i].facultad.codigo,codigoFacu)==0) {
                alumno[i].facultad.nombre=asignarCadena(facultad);
            }
        }
    }
}

char * modificarCadena(char *cadena) {
    char *str;
    str = new char[strlen(cadena)+1];
    strcpy(str,cadena);
    for (int i=0;str[i];i++) {
        if (str[i]=='_')str[i]=' ';
    }
    return str;
}

char * asignarCadena(const char *nombre) {
    char *str;
    str = new char[strlen(nombre)+1];
    strcpy(str,nombre);
    return str;
}
