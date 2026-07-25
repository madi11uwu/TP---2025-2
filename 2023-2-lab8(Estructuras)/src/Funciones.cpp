//
// Created by Madi on 10/11/2025.
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

void imprimir_encabezado(ofstream &write, char *semestre) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"INSTITUCION EDUCATIVA_TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"DETALLE DE PAGOS REALIZADO POR CICLO"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"CICLO: "<<semestre<<endl;
    imprimir_linea('=', ANCHO_REPORTE, write);
    write<<"No. ";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+3)+2)<<""<<"CURSO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS-2))<<""<<"CREDITOS";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+6))<<""<<"ALUMNOS.MAT";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+8))<<""<<"MONTO PAGADO"<<endl;
    imprimir_linea('-', ANCHO_REPORTE, write);
}

void imprimir_linea(char c, int n, ofstream &write) {
    for (int i = 0; i < n; i++) {
        write.put(c);
    }
    write<<endl;
}

void cargarCursos(const char *file, struct Curso *&curso, int &n_alumno) {
    ifstream read;
    apertura_lectura(file, read);
    int codigo_curso;
    char *cadena;
    curso=new struct Curso[MAX_CURSOS]();
    while (true) {
        read>>codigo_curso;
        if (read.eof()) break;
        read.get();
        curso[n_alumno].codigoCurso=codigo_curso;
        cadena=leer_cadena(read,MAX_CARACTERES,',');
        curso[n_alumno].nombre=modificarCadena(cadena);
        curso[n_alumno].numCreditos=leer_double(read);
        n_alumno++;
    }
}

void cargarEscalas(const char *file, struct Escala *&escala, int &n_escala) {
    ifstream read;
    apertura_lectura(file, read);
    char *semestre;
    escala=new struct Escala[MAX_ESCALAS]();
    while (true) {
        semestre=leer_cadena(read,MAX_CARACTERES,',');
        if (read.eof())break;
        escala[n_escala].semestre=asignarCadena(semestre);
        escala[n_escala].escala=leer_char(read);
        escala[n_escala].costoPorCredito=leer_double(read);
        n_escala++;
    }
}

char * leer_cadena(ifstream &read, int n, char delim) {
    char *str,buffer[n];
    read.getline(buffer,n,delim);
    if (read.eof())return nullptr;
    str = new char[strlen(buffer)+1];
    strcpy(str,buffer);
    return str;
}

char leer_char(ifstream &read) {
    char c;
    read>>c;
    read.get();
    return c;
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

char * asignarCadena(const char *nombre) {
    char *str;
    str = new char[strlen(nombre)+1];
    strcpy(str,nombre);
    return str;
}

int BuscarCurso(int cod, struct Curso *curso, int n) {
    for (int i = 0; i < n; i++) {
        if (curso[i].codigoCurso==cod) return i;
    }
    return -1;
}

int BuscarAlumno(int cod, struct Alumno *alumno, int n) {
    for (int i = 0; i < n; i++) {
        if (alumno[i].codigo==cod) return i;
    }
    return -1;
}

int BuscarEscala(char *semestre, char c, struct Escala *escala, int n) {
    for (int i = 0; i < n; i++) {
        if (escala[i].escala==c and strcmp(semestre,escala[i].semestre)==0) return i;
    }
    return -1;
}

void ordenarCursos(struct Curso *curso, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int k=i+1; k<n; k++) {
            if (curso[i].cantAlumnos>curso[k].cantAlumnos or
                (curso[i].cantAlumnos==curso[k].cantAlumnos and
                strcmp(curso[i].nombre,curso[k].nombre)>0)) {
                swapStruct(curso[i],curso[k]);
            }
        }
    }
}

void swapStruct(struct Curso &a, struct Curso &b) {
    struct Curso aux;
    aux=a;
    a=b;
    b=aux;
}

char * modificarCadena(char *cadena) {
    char *str;
    str = new char[strlen(cadena)+1];
    strcpy(str,cadena);
    for (int i = 0; str[i]; i++) {
        if (str[i]>='a' and str[i]<='z') str[i]-=32;
    }
    return str;
}

void imprimirEspacios(int n, int ancho, ofstream &write) {
    for (int i = 0; i<ancho-n; i++) {
        write.put(' ');
    }
}

void imprimir_reporte(const char *file, struct Escala *escala, struct Curso *curso, struct Alumno *alumno,
                      int n_escala, int n_curso, int n_alumno,char *semestre) {
    ofstream write;
    apertura_escritura(file, write);
    imprimir_encabezado(write,semestre);
    int nroCurso=1;
    for (int i = 0; i < n_curso; i++) {
        write<<setw(2)<<setfill('0')<<nroCurso<<")";
        write<<setfill(' ');
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+20))<<""<<curso[i].codigoCurso;
        write<<" - "<<curso[i].nombre;
        imprimirEspacios(strlen(curso[i].nombre)+9,ANCHO_REPORTE/(NRO_COLUMNAS-3) +2,write);
        write<<fixed<<setprecision(2)<<curso[i].numCreditos;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+3))<<""<<curso[i].cantAlumnos;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+3))<<""<<curso[i].montoAlumnos<<endl;
        nroCurso++;
    }
}

void completarCursos(const char *file, struct Curso *curso, int n_curso, char *semestre,
                     struct Escala *escala, int n_escala, struct Alumno *alumno,
                     int n_alumno) {
    ifstream read;
    apertura_lectura(file, read);
    char *semestreLeido, c;
    int codigo_alumno, codigo_curso, posCurso,posAlumno,posEscala;
    while (true) {
        semestreLeido = leer_cadena(read,MAX_CARACTERES, ',');
        if (read.eof())break;
        codigo_alumno = leer_int(read);
        if (strcmp(semestre, semestreLeido) == 0) {
            while (true) {
                read >> codigo_curso;
                c = read.get();
                posCurso = BuscarCurso(codigo_curso, curso, n_curso);
                posAlumno = BuscarAlumno(codigo_alumno, alumno, n_alumno);
                if (posCurso != -1) {
                    if (posAlumno!=-1) {
                        posEscala = BuscarEscala(semestre,alumno[posAlumno].escala,escala,n_escala);
                        curso[posCurso].cantAlumnos++;
                        curso[posCurso].montoAlumnos+=curso[posCurso].numCreditos*escala[posEscala].costoPorCredito;
                    }
                }
                if (c == '\n')break;
            }
        } else {
            leer_cadena(read, 200, '\n');
            continue;
        }
    }
}

void cargarAlumnos(const char *file, struct Alumno *&alumno, int &n_alumno) {
    ifstream read;
    apertura_lectura(file, read);
    alumno=new struct Alumno[MAX_ALUMNOS]();
    int codigo;
    while (true) {
        read>>codigo;
        if (read.eof()) break;
        read.get();
        alumno[n_alumno].codigo=codigo;
        alumno[n_alumno].nombre=leer_cadena(read,MAX_CARACTERES,',');
        read>>alumno[n_alumno].escala;
        n_alumno++;
    }
}
