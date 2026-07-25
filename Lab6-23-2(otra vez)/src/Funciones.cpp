//
// Created by Madi on 3/11/2025.
//

#include "Funciones.hpp"

void ignorar(ifstream &leer, char c) {
    leer>>ws;
    char car;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(int fecha, ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/";
    write<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/";
    write<<setw(2)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
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

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTES"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE INFRACCIONES"<<endl;
}

void imprimir_linea(int n, char c, ofstream &write) {
    for (int i=0; i<n; i++) {
        write.put(c);
    }
    write<<endl;
}

void insertar_ordenado(int codigo, double multas,
                       int *codigo_infraccion,
                       double *multa, int &n_infraciones) {
    int i=n_infraciones-1;
    while (i>=0 && codigo_infraccion[i]>codigo) {
        codigo_infraccion[i+1]=codigo_infraccion[i];
        multa[i+1]=multa[i];
        i--;
    }
    codigo_infraccion[i+1]=codigo;
    multa[i+1]=multas;
    n_infraciones++;
}

void cargar_ordenado(const char *infracciones, int *codigo_infraccion,
                     double *multa, int &n_infraciones) {
    ifstream leer_infracciones;
    apertura_lectura(infracciones, leer_infracciones);
    int codigo;
    double multas;
    while (true) {
        leer_infracciones>>codigo;
        if (leer_infracciones.eof())break;
        leer_infracciones>>multas;
        ignorar(leer_infracciones,'\n');
        insertar_ordenado(codigo, multas, codigo_infraccion, multa,
                          n_infraciones);
    }
}

void prueba_infracciones(const char *reporte_infracciones, int *codigo_infraccion,
                         double *multa, int n_infraciones) {
    ofstream write;
    apertura_escritura(reporte_infracciones, write);
    write<<"TABLA DE INFRACCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(10)<<""<<"CODIGO DE INFRACCION";
    write<<setw(15)<<""<<"MULTA"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    for (int i=0; i<n_infraciones; i++) {
        write<<setw(20)<<""<<codigo_infraccion[i];
        write<<setw(20)<<""<<fixed<<setprecision(2)<<multa[i]<<endl;
    }
}
