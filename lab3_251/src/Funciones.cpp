//
// Created by Madi on 18/09/2025.
//

#include "Funciones.hpp"

void procesar_datos_infracciones(const char *registradas, const char *cometidas, const char *infracciones,
    const char *salida) {
    ifstream leer_infracciones;
    ifstream leer_registradas;
    ifstream leer_cometidas;
    apertura_archivo_lectura(leer_infracciones,infracciones);
    apertura_archivo_lectura(leer_registradas,registradas);
    apertura_archivo_lectura(leer_cometidas,cometidas);
    ofstream write;
    apertura_archivo_salida(write,salida);
    imprimir_encabezadoPrincipal(write);
    datosDinamicos(leer_infracciones,leer_registradas,leer_cometidas,write);
    leer_infracciones.close();
    leer_registradas.close();
    leer_cometidas.close();
    write.close();
}

void apertura_archivo_lectura(ifstream &leer,const char *file_name) {
    leer.open(file_name,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file_name<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_archivo_salida(ofstream &write,const char *file_name) {
    write.open(file_name,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file_name<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_encabezadoPrincipal(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTE"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"MULTAS IMPUESTAS A LAS COMPANIAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_linea(int n,char c,ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}
//79672079        contreras/chang/johana-cinthia     Chorrillos
void imprimir_Encabezado1(ofstream &write,ifstream &leer_registradas,int canal,int DNI) {
    write<<"COMPANIA No. "<<canal<<endl;
    write<<"REPRESENTANTE LEGAL: ";
    leer_nombreCamelizacion(leer_registradas,write);
    write<<"    DNI: "<<DNI;
    write<<setw(4)<<""<<"DISTRITO: ";
    leer_Distrito(leer_registradas,write);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void leer_Distrito(ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ') break;
        write.put(c);
    }
}
void leer_nombreCamelizacion(ifstream &leer,ofstream &write) {
    bool inicioPalabra=true;
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ') break;
        if (inicioPalabra) {
            c=(c-'a'+'A');
            inicioPalabra=false;
        }
        if (c=='/' or c=='-') {
            c=' ';
            inicioPalabra=true;
        }
        write.put(c);
    }
}
//P599-629
//1/12/2020   G760-721    G2022
void datosDinamicos(ifstream &leer_infracciones,ifstream &leer_registradas,ifstream &leer_cometidas,ofstream &write) {
    char c,letra,letra1,cinfraccion,cinfraccion1;
    bool encontrado=false;
    int num1,num2,fecha,numero1,numero2,infraccion,infraccion1,DNI;
    double multa;
    int i=1,j=1,canal=1;
    while (true) {
        leer_registradas>>DNI;
        if (leer_registradas.eof())break;
        imprimir_Encabezado1(write,leer_registradas,canal,DNI);
        leer_registradas>>ws>>letra>>num1>>c>>num2;
        write<<"VEHICULOS INFRACCIONADOS: "<<endl;
        write<<setw(2)<<""<<"0"<<i<<")"<<" PLACA: ";
        write<<letra<<num1<<"-"<<num2;
        write<<"    TIPO: ";
        imprimir_tipo(write,letra);
        write<<endl;
        imprimir_encabezado2(write);
        while (true) {
            while (true) {
                fecha=CalcularFecha(leer_cometidas);
                if (leer_cometidas.eof()) break;
                leer_cometidas>>ws>>letra1>>numero1>>c>>numero2;
                if (letra1==letra and numero1==num1 and numero2==num2) {
                    leer_cometidas>>ws>>cinfraccion>>infraccion;
                    break;
                }
                else {
                    leer_cometidas.ignore(50,'\n');
                    continue;
                }
            }
            while (true) {
                leer_infracciones>>ws>>cinfraccion1>>infraccion1;
                if (leer_infracciones.eof() or encontrado) break;
                if (infraccion1==infraccion and cinfraccion1==cinfraccion) {
                    leer_infracciones>>multa;
                    encontrado=true;
                }
                else {
                    leer_infracciones.ignore(500,'\n');
                    continue;
                }
            }
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<setw(2)<<j<<")";
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_fecha(fecha,write);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<infraccion1;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            if (encontrado) {
                imprimir_codigoInfraccion(cinfraccion,write);
                write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<multa;
                write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<setw(2)<<j<<")";
                imprimir_descripcion(write,leer_infracciones);
            }
            else write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"No se encontro esa infraccion"<<endl;
            j++;
            c=leer_registradas.get();
            if (c=='\n') break;
        }
        canal++;
        imprimir_linea(ANCHO_REPORTE,'-',write);
    }
}

void imprimir_codigoInfraccion(char infraccion,ofstream &write) {
    if (infraccion=='L') write<<"LEVE";
    else if (infraccion=='G') write<<"GRAVE";
    else write<<"MUY GRAVE";
}
void imprimir_encabezado2(ofstream &write) {
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"INFRACCION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"GRAVEDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"MULTA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"DESCRIPCION"<<endl;
}

int CalcularFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_tipo(ofstream &write,char letra) {
    if (letra=='P') write<<"PEQUEÑO";
    else if (letra=='M') write<<"MEDIANO";
    else write<<"GRANDE";
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

void imprimir_descripcion(ofstream &write,ifstream &leer) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c=='\n') break;
        write.put(c);
    }
    write<<endl;
}