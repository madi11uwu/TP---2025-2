//
// Created by Madi on 2/11/2025.
//

#include "Funciones.hpp"

void insertar_ordenado(int * codigos, char * escalas, int &n_alumnos, int codigo, char escala) {
    int i=n_alumnos-1;
    while (i>=0 and codigos[i]>codigo) {
        codigos[i+1]=codigos[i];
        escalas[i+1]=escalas[i];
        i--;
    }
    codigos[i+1]=codigo;
    escalas[i+1]=escala;
    n_alumnos++;
}

void insertar_ordenado2(int *codigo_curso, char **nombre_curso,
                        double *precio_credito, int &n_cursos,
                        int codigo, double credito,
                        char *nombre) {
    int i=n_cursos-1;
    while (i>=0 and codigo_curso[i]>codigo) {
        nombre_curso[i+1]=nombre_curso[i];
        precio_credito[i+1]=precio_credito[i];
        codigo_curso[i+1]=codigo_curso[i];
        i--;
    }
    nombre_curso[i+1]=nombre;
    precio_credito[i+1]=credito;
    codigo_curso[i+1]=codigo;
    n_cursos++;
}

void cargar_escalas(const char *escalas, int *year, int *semestre,
                    char *Escalas, double *precio_credito,
                    int &n_escalas) {
    ifstream leer_escalas;
    apertura_lectura(escalas,leer_escalas);
    int anio;
    char c;
    while (true) {
        leer_escalas>>anio;
        if (leer_escalas.eof())break;
        year[n_escalas]=anio;
        leer_escalas>>c>>semestre[n_escalas];
        leer_escalas>>ws>>Escalas[n_escalas];
        leer_escalas>>precio_credito[n_escalas];
        n_escalas++;
    }
}

int BuscarBinariaAlumno(int *codigo_alumnos, int n_alumnos,
                         int codigo_alumno) {
    int limite_inferior=0,limite_superior=n_alumnos-1,punto_medio;
    while (true) {
        if (limite_inferior>limite_superior) return -1;
        punto_medio=(limite_superior+limite_inferior)/2;
        if (codigo_alumnos[punto_medio]==codigo_alumno) return punto_medio;
        if (codigo_alumnos[punto_medio]<codigo_alumno) limite_inferior=punto_medio+1;
        else limite_superior=punto_medio-1;
    }
}

void cargarNombres(ifstream & leer, int * codAlumno, char ** nombre,int &n_nombres) {
    int codigo_alumno;
    while (true) {
        leer>>codigo_alumno;
        if (leer.eof())break;
        codAlumno[n_nombres]=codigo_alumno;
        nombre[n_nombres]=leerCadenaExacta(leer);
        n_nombres++;
    }
}

void cargarApellidos(ifstream & leer, char ** apellido,int &n_apellidos) {
    char *cad;
    while (true) {
        cad=leerCadenaExacta(leer);
        if (leer.eof())break;
        apellido[n_apellidos]=cad;
        n_apellidos++;
    }
}

void imprimir_reporte(const char *reporte, const char *nombres,
                      const char *apellidos, int *codigo_alumnos,
                      char *string, int n_alumnos,
                      double *cant_creditos,
                      int *cant_cursos, double *monto_pagado,
                      int anio, int ciclo) {
    ifstream leer_nombres;
    ifstream leer_apellidos;
    apertura_lectura(nombres, leer_nombres);
    apertura_lectura(apellidos, leer_apellidos);
    int codAlumno[MAX_ALUMNOS]{},n_nombres=0,n_apellidos=0;
    char *nombre[MAX_ALUMNOS]{},*apellido[MAX_ALUMNOS]{};
    cargarNombres(leer_nombres,codAlumno,nombre,n_nombres);
    cargarApellidos(leer_apellidos,apellido,n_apellidos);
    ofstream write;
    apertura_escritura(reporte, write);
    imprimir_encabezado(write, anio, ciclo);
    char *c=new char[MAX_ALUMNOS];
    for (int i=0;i<n_alumnos;i++) {
        c=modificaTexto(apellido[i],nombre[i]);
        write<<c<<endl;
    }
}

char * modificaTexto(char *cadena1, char *cadena2) {
    char *str,*apellidoPaterno=new char[strlen(cadena2)+1],*Nombre=new char[strlen(cadena2)+1];
    int i=0,pos=0;
    while (cadena2[i]!='_' and cadena2[i]!='\0') {
        if (cadena2[i]>='a' and cadena2[i]<='z')cadena2[i]=cadena2[i]-32;
        apellidoPaterno[i]=cadena2[i];
        i++;
    }
    apellidoPaterno[i]='\0';
    while (cadena2[i]!='\0') {
        if (cadena2[i]=='_')cadena2[i]=' ';
        if (cadena2[i]>='a' and cadena2[i]<='z')cadena2[i]=cadena2[i]-32;
        Nombre[pos]=cadena2[i];
        pos++;
        i++;
    }
    Nombre[pos]='\0';
    for (int i=0;cadena1[i];i++) {
        if (cadena1[i]>='a' and cadena1[i]<='z') cadena1[i]=cadena1[i]-32;
    }
    str=new char[strlen(cadena1)+strlen(apellidoPaterno)+strlen(Nombre)+3];
    strcpy(str,apellidoPaterno);
    strcat(str," ");
    strcat(str,cadena1);
    strcat(str,Nombre);
    return str;
}

int BuscarEscala(int *year, int *semestre, char *escalas,
                 int anio, int ciclo,int n_escalas,
                 char escala) {
    int i=0;
    while (i<n_escalas) {
        if (year[i]==anio and semestre[i]==ciclo and escalas[i]==escala)return i;
        i++;
    }
    return -1;
}

void llenarArreglos(const char *matricula, int anio, int ciclo, int *codigo_alumnos,
                    char *escalas, int n_alumnos, int *codigo_curso, double *NumCredito,
                    int n_cursos, int *year, int *semestre, char *Escalas,
                    double *PrecioCredito,double *cantCreditos,
                    int n_escalas,int *cantCursos,double *MontoPagado) {
    ifstream leer_matricula;
    apertura_lectura(matricula,leer_matricula);
    int anio1,ciclo1,codigoAlumno,codCurso,posAlumno,posCurso,posEscala;
    char c;
    while (true) {
        leer_matricula>>anio1;
        if (leer_matricula.eof())break;
        leer_matricula>>c>>ciclo1;
        if (anio1==anio and ciclo==ciclo1) {
            leer_matricula>>codigoAlumno;
            posAlumno = BuscarBinariaAlumno(codigo_alumnos, n_alumnos, codigoAlumno);
            while (true) {
                if (posAlumno!=-1) {
                    leer_matricula>>codCurso;
                    posCurso = BuscarBinariaAlumno(codigo_curso, n_cursos, codCurso);
                    if (posCurso!=-1) {
                        cantCursos[posAlumno]++;
                        posEscala = BuscarEscala(year, semestre, Escalas,anio, ciclo,n_escalas, escalas[posAlumno]);
                        cantCreditos[posAlumno]+=NumCredito[posCurso];
                        MontoPagado[posAlumno]+=NumCredito[posCurso]*PrecioCredito[posEscala];
                    }
                    c=leer_matricula.get();
                    if (c=='\n')break;
                }
                else {
                    leer_matricula.ignore(600,'\n');
                    break;
                }
            }
        }
        else {
            leer_matricula.ignore(500,'\n');
            continue;
        }
    }
}

void cargar_cursosOrdenado(const char *cursos, int *codigo_curso,
                           char **nombre_curso,
                           double *precio_credito, int &n_cursos) {
    ifstream leer_cursos;
    apertura_lectura(cursos, leer_cursos);
    int codigo;
    char *nombre;
    double credito;
    while (true) {
        leer_cursos>>codigo;
        if (leer_cursos.eof())break;
        nombre=leerCadenaExacta(leer_cursos);
        leer_cursos>>credito;
        insertar_ordenado2(codigo_curso, nombre_curso, precio_credito,
                           n_cursos, codigo, credito, nombre);
    }
}

char * leerCadenaExacta(ifstream &leer) {
    char *cadena,buffer[MAX_CARACTERES];
    leer>>buffer;
    if (leer.eof()) return nullptr;
    cadena=new char[strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}

void cargar_alumnosOrdenado(const char * alumnos, int * codigos, char *escalas, int &n_alumnos) {
    ifstream leer_alumnos;
    apertura_lectura(alumnos,leer_alumnos);
    int codigo;
    char escala;
    while (true) {
        leer_alumnos >> codigo;
        if (leer_alumnos.eof()) break;
        leer_alumnos >> escala;
        insertar_ordenado(codigos,escalas,n_alumnos,codigo,escala);
    }
}

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

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimir_encabezado(ofstream &write, int anio, int ciclo) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"INSTITUCION EDUCATIVA_TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"DETALLE DE PAGOS REALIZADO POR CICLO"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"CICLO: "<<anio<<"-"<<ciclo<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"ALUMNOS"<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
    write<<"No. DE Cursos"<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
    write<<"CREDITOS"<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
    write<<"ESCALA"<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
    write<<"MONTO PAGADO"<<endl;
    imprimir_linea(ANCHO_REPORTE,'_',write);
}
