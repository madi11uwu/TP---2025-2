//
// Created by Madi on 12/10/2025.
//

#include "Funciones.hpp"

void GenerarReporte(const char *alumnos, const char *cursos, const char *escalas,
                    const char *matricula, const char *reporte) {
    int año=2023,ciclo=1;
    ifstream leer_alumnos;
    ifstream leer_cursos;
    ifstream leer_escalas;
    ifstream leer_matricula;
    ofstream write;
    apertura_lectura(alumnos,leer_alumnos);
    apertura_lectura(cursos,leer_cursos);
    apertura_lectura(escalas,leer_escalas);
    apertura_lectura(matricula,leer_matricula);
    apertura_escritura(reporte,write);
    imprimir_reporte(leer_alumnos,leer_cursos,leer_escalas,
                    leer_matricula,write,año,ciclo);
    leer_alumnos.close();
    leer_cursos.close();
    leer_escalas.close();
    leer_matricula.close();
    write.close();
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

void imprimirEncabezado(int año, int ciclo, ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"INSTITUCION EDUCATIVA_TP"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"DETALLE DE PAGOS REALIZADO POR CICLO"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"CICLO: "<<año<<"-"<<ciclo<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void leer_nombres(ifstream &leer,ofstream &write,char c,char c1) {
    leer>>ws;
    char car;
    if (c=='A') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            if (car=='_')car=' ';
            if (car>='a' and car<='z')car=car-32;
            write.put(car);
        }
    }
    else if (c=='C') {
        while (true) {
            car=leer.get();
            if (car==c1)break;
            if (car=='_')car=' ';
            write.put(car);
        }
    }
}

void imprimir_reporte(ifstream &leer_alumnos,ifstream &leer_cursos,
                        ifstream &leer_escalas,
                        ifstream &leer_matricula,ofstream &write,
                        int año,int ciclo) {
    int codigo_alumno,nroAlumnos=0;
    char escala;
    double creditosAlumno,montoAlumno,montoTotal=0.0;
    imprimirEncabezado(año,ciclo,write);
    while (true) {
        leer_alumnos>>codigo_alumno;
        if (leer_alumnos.eof())break;
        imprimirParteEstatica(leer_alumnos,write,codigo_alumno,escala);
        imprimirParteDinamica(leer_cursos,leer_escalas,leer_matricula,
                             write,codigo_alumno,escala,creditosAlumno,montoAlumno,
                             año,ciclo);
        imprimir_linea(ANCHO_REPORTE,'-',write);
        imprimirEstadisticaAlumno(creditosAlumno,montoAlumno,write);
        montoTotal+=montoAlumno;
        nroAlumnos++;
    }
    write<<"RESUMEN: "<<endl;
    write<<"CANTIDAD TOTAL DE ALUMNOS: "<<nroAlumnos;
    write<<setw(15)<<""<<"MONTO TOTAL PAGADO: "<<fixed<<setprecision(2)<<montoTotal<<endl;
}
void imprimirEstadisticaAlumno(double creditoAlumno,double montoAlumno,ofstream &write) {
    write<<"TOTAL CREDITOS: "<<creditoAlumno;
    write<<setw(10)<<""<<"TOTAL MONTO PAGADO: "<<montoAlumno<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
void imprimirParteEstatica(ifstream &leer_alumnos,ofstream &write,
                            int codigo,char &escala) {
    write<<"ALUMNO: "<<codigo<<" - ";
    leer_nombres(leer_alumnos,write,'A',' ');
    leer_alumnos>>ws>>escala;
    write<<setw(50)<<""<<"ESCALA: "<<escala<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void imprimirParteDinamica(ifstream &leer_cursos,ifstream &leer_escalas,ifstream &leer_matricula
                            ,ofstream &write,int codigo,char escala,double &creditosAlumno,
                            double &montoAlumno,int año,int ciclo) {
    leer_matricula.clear();
    leer_matricula.seekg(0,ios::beg);
    int añoLeido,cicloLeido,codigoLeido,codigo_curso;
    double numCreditos,valorCredito,montoPagoCurso;
    creditosAlumno=0.0,montoAlumno=0.0;
    char c;
    int nroCurso=1;
    write<<setw(10)<<""<<"CURSO MATRICULADO"<<setw(10)<<""<<"CREDITOS"<<setw(8)<<""<<"MONTO PAGADO"<<endl;;
    while (true) {
        leer_matricula>>añoLeido;
        if (leer_matricula.eof())break;
        leer_matricula>>c>>cicloLeido>>codigoLeido;
        if (codigoLeido==codigo and añoLeido==año and cicloLeido==ciclo) {
            while (true) {
                leer_matricula>>codigo_curso;
                imprimirDatosDinamicos(leer_escalas,leer_cursos,
                                    write,nroCurso,codigo_curso,numCreditos,
                                    año,ciclo,escala,valorCredito,montoPagoCurso);
                creditosAlumno+=numCreditos;
                montoAlumno+=montoPagoCurso;
                nroCurso++;
                c=leer_matricula.get();
                if (c=='\n')break;
            }
        }
        else {
            leer_matricula.ignore(200,'\n');
            continue;
        }
    }
}

void imprimirDatosDinamicos(ifstream &leer_escalas,ifstream &leer_cursos,
                            ofstream &write,int nro_curso,int codigo,double &numCreditos,
                            int año,int ciclo,char escala,double &valorCredito,
                            double &montoPagoCurso) {
    write<<setw(2)<<setfill('0')<<nro_curso<<")";
    write<<setfill(' ');
    write<<setw(2)<<""<<codigo<<" - ";
    BuscarNombreyNumeroCreditos(leer_cursos,write,numCreditos,codigo);
    write<<setw(8)<<""<<fixed<<setprecision(2)<<numCreditos;
    BuscarValorCredito(leer_escalas,año,ciclo,escala,valorCredito);
    montoPagoCurso=valorCredito*numCreditos;
    write<<setw(10)<<""<<montoPagoCurso<<endl;
}

void BuscarValorCredito(ifstream &leer_escalas,int año,int ciclo,char escala,double &valorCredito) {
    leer_escalas.clear();
    leer_escalas.seekg(0,ios::beg);
    int añoLeido,cicloLeido;
    char escalaLeido,c;
    while (true) {
        leer_escalas>>añoLeido;
        if (leer_escalas.eof()) break;
        leer_escalas>>c>>cicloLeido>>ws>>escalaLeido;
        if (año==añoLeido and ciclo==cicloLeido and escala==escalaLeido) {
            leer_escalas>>valorCredito;
        }
        else {
            leer_escalas.ignore(200,'\n');
            continue;
        }
    }
}
void BuscarNombreyNumeroCreditos(ifstream &leer_cursos,ofstream &write,double &numCreditos,int codigo) {
    leer_cursos.clear();
    leer_cursos.seekg(0,ios::beg);
    int codigoLeido;
    while (true) {
        leer_cursos>>codigoLeido;
        if (leer_cursos.eof()) break;
        if (codigoLeido==codigo) {
            leer_nombres(leer_cursos,write,'C',' ');
            leer_cursos>>numCreditos;
        }
        else {
            leer_cursos.ignore(200,'\n');
            continue;
        }
    }
}