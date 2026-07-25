//
// Created by Madi on 29/09/2025.
//

#include "Funciones.hpp"

void cargarInfracciones(const char *infracciones, char *c_infraccion, int *int_infraccion, double *multas, int &n_infracciones) {
    ifstream leer_infraccion;
    apertura_lectura(infracciones,leer_infraccion);
    char codigo_infraccion;
    while (true) {
        leer_infraccion>>codigo_infraccion;
        if (leer_infraccion.eof())break;
        leer_infraccion>>int_infraccion[n_infracciones]>>multas[n_infracciones];
        c_infraccion[n_infracciones]=codigo_infraccion;
        ignorar(leer_infraccion,'\n');
        n_infracciones++;
    }
}

void probarInfracciones(const char *salida_infracciones, char *c_infraccion, int *int_infraccion, double *multas, int n_infracciones) {
    ofstream write;
    apertura_escritura(salida_infracciones,write);
    int i=0;
    write<<"TABLA DE INFRACCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(5)<<""<<"CODIGO DE INFRACCION";
    write<<setw(ANCHO_REPORTE/6)<<""<<"MULTA"<<endl;
    while (i<n_infracciones) {
        write<<setw(5)<<""<<c_infraccion[i]<<int_infraccion[i];
        write<<setw(ANCHO_REPORTE/4)<<""<<multas[i]<<endl;
        i++;
    }
    write.close();
}

void ignorar(ifstream &leer,char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void cargarEmpresas(const char *empresas, int *DNIRepre, int &n_empresas) {
    ifstream leer_empresas;
    apertura_lectura(empresas,leer_empresas);
    int DNI;
    while (true) {
        leer_empresas>>DNI;
        if (leer_empresas.eof())break;
        ignorar(leer_empresas,'\n');
        DNIRepre[n_empresas]=DNI;
        n_empresas++;
    }
}

void probarEmpresas(const char *salida_empresas, int *DNIRepre, int n_empresas) {
    ofstream write;
    apertura_escritura(salida_empresas,write);
    int i=0;
    write<<"EMPRESAS REGISTRADAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(6)<<""<<"DNI DE REPRESENTANTE"<<endl;
    while (i<n_empresas) {
        write<<setw(10)<<""<<DNIRepre[i]<<endl;
        i++;
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

void imprimir_linea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void ContarFaltasYMultas(int *leves,int *graves,int *muyGraves,int *Totales,double *multasLeves,
                        double *multasGraves,double *multasMuyGraves,double *multasTotales,const char *placas,
                        const char *infraccionesCometidas,int *DNIRepre,) {
    ifstream leer_placas;
    ifstream leer_infracciones;
    apertura_lectura(placas,leer_placas);
    apertura_lectura(infraccionesCometidas,leer_infracciones);

}