//
// Created by Madi on 27/10/2025.
//

#include "Funciones.hpp"

void cargar_ordenado_infraccion(const char *tabla, int *arrCodigoInfraccion,
                                double *arrMultasInfraccion,
                                int &n_tabla_infraccion) {
    ifstream leer_tabla;
    apertura_lectura(tabla,leer_tabla);
    int codigo;
    double multa;
    while (true) {
        leer_tabla>>codigo;
        if (leer_tabla.eof())break;
        leer_tabla>>multa;
        ignorar(leer_tabla,'\n');
        insertar_ordenado(arrCodigoInfraccion, arrMultasInfraccion,
                          n_tabla_infraccion,
                          codigo, multa);
    }
}

void insertar_ordenado(int *arr_codigo_infraccion, double *arr_multas_infraccion,
                       int &n_tabla_infraccion, int codigo, double multa) {
    int i=n_tabla_infraccion-1;
    while (i>=0 and arr_codigo_infraccion[i]>codigo) {
        arr_codigo_infraccion[i+1]=arr_codigo_infraccion[i];
        arr_multas_infraccion[i+1]=arr_multas_infraccion[i];
        i--;
    }
    arr_codigo_infraccion[i+1]=codigo;
    arr_multas_infraccion[i+1]=multa;
    n_tabla_infraccion++;
}

void llenarArreglos(const char *infracciones, int *arrDNI, int *arrMasMultaAntigua,
                    double *arrMultasInfraccion,int *arrUltimaPendiente, double *arrTotalMultas,
                    double *arrTotalPagadas,int *arrCodigoInfraccion,
                    double *arrTotalPendientes,int n_tablaInfraccion) {
    ifstream leer_infraccion;
    apertura_lectura(infracciones,leer_infraccion);
    int fechaCometida,num1,num2,DNI,codigo_infraccion,pos,fechaPagada;
    char c,c_placa;
    while (true) {
        fechaCometida=AlmacenarFecha(leer_infraccion);
        if (leer_infraccion.eof()) break;
        leer_infraccion>>c_placa>>num1>>c>>num2>>DNI>>codigo_infraccion;
        pos=BusquedaBinaria(arrCodigoInfraccion,codigo_infraccion,n_tablaInfraccion);
        c=leer_infraccion.get();
        if (c=='\n') fechaPagada=0;
        else {
            leer_infraccion>>c;
            fechaPagada=AlmacenarFecha(leer_infraccion);
        }
        if (pos!=-1) {
            if (arrMasMultaAntigua[pos]==0 or arrMasMultaAntigua[pos]>fechaCometida)arrMasMultaAntigua[pos]=fechaCometida;
            if (fechaPagada!=0 and (arrUltimaPendiente[pos]==0 or arrUltimaPendiente[pos]<fechaPagada))arrUltimaPendiente[pos]=fechaPagada;
            if (fechaPagada!=0)arrTotalPagadas[pos]+=arrMultasInfraccion[pos];
            else arrTotalPendientes[pos]+=arrMultasInfraccion[pos];
            arrTotalMultas[pos]+=arrTotalPagadas[pos]+arrTotalPendientes[pos];
        }
    }
}

int BusquedaBinaria(int *arrDNI,int DNI,int n_tablaInfraccion) {
    int limite_inferior=0,limite_superior=n_tablaInfraccion-1;
    int centro;
    while (true) {
        if (limite_inferior>limite_superior) return -1;
        centro=(limite_superior+limite_inferior)/2;
        if (arrDNI[centro]==DNI) return centro;
        if (arrDNI[centro]>DNI) limite_superior=centro-1;
        else limite_inferior=centro+1;
    }
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void apertura_lectura(const char *file,ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file,ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTES"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"LISTADO DE INFRACCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw(50)<<""<<"MULTA MAS"<<setw(ANCHO_REPORTE/8)<<""<<"ULTIMA MULTA";
    write<<setw(ANCHO_REPORTE/8)<<""<<"TOTAL EN"<<setw(ANCHO_REPORTE/8)<<""<<"MULTAS";
    write<<setw(ANCHO_REPORTE/8)<<""<<"MULTAS"<<endl;
    write<<"No."<<setw(ANCHO_REPORTE/8)<<""<<"DNI";
    write<<setw(ANCHO_REPORTE/8)<<""<<"PLACAS"<<setw(ANCHO_REPORTE/8)<<""<<"ANTIGUA";
    write<<setw(ANCHO_REPORTE/8)<<""<<"PAGADA"<<setw(ANCHO_REPORTE/8)<<""<<"PENDIENTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void ignorar(ifstream &leer,char c) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
    }
}

void probar_ordenado_infraccion(const char *Infraccion, int *arrCodigoInfraccion,
                                double *arr_multas_infraccion, int n_tabla_infraccion) {
    ofstream write;
    apertura_escritura(Infraccion,write);
    write<<"TABLA DE INFRACCIONES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"CODIGO DE INFRACCION"<<setw(20)<<""<<"MULTAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    int i=0;
    while (i<n_tabla_infraccion) {
        write<<arrCodigoInfraccion[i]<<setw(20)<<""<<arr_multas_infraccion[i]<<endl;
        i++;
    }
}

