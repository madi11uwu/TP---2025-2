//
// Created by Madi on 20/09/2025.
//

#include "Funciones.hpp"

void calcular_imprimirReporte(const char *registradas, const char *cometidas,
    const char *infracciones, const char *salida) {
    ifstream leer_registrada;
    ifstream leer_cometida;
    ifstream leer_infracciones;
    apertura_entrada(registradas,leer_registrada);
    apertura_entrada(cometidas,leer_cometida);
    apertura_entrada(infracciones,leer_infracciones);
    ofstream write;
    apertura_salida(salida,write);
    imprimir_encabezadoPrincipal(write);
    imprimir_Dinamico(leer_registrada,write,leer_infracciones,leer_cometida);
    leer_registrada.close();
    leer_cometida.close();
    leer_infracciones.close();
    write.close();
}

void apertura_entrada(const char *file,ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_salida(const char *file,ofstream &write) {
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

void imprimir_encabezadoPrincipal(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTE"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"MULTAS IMPUESTAS A LAS COMPANIAS"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_encabezadoEstatico(int compania,ifstream &leer_registrada,ofstream &write,int DNI) {
    write<<"COMPANIA No. "<<compania<<endl;
    write<<"REPRESENTANTE LEGAL: ";
    imprimir_nombre(leer_registrada,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+10))<<""<<"DNI: "<<DNI;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS1+10))<<""<<"DISTRITO: ";
    imprimir_distrito(leer_registrada,write);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}
//79672079        contreras/chang/johana-cinthia     Chorrillos
void imprimir_nombre (ifstream &leer_registrada,ofstream &write) {
    char c;
    bool inicio_linea=true;
    leer_registrada>>ws;
    while (true) {
        c=leer_registrada.get();
        if (c==' ')break;
        if (inicio_linea) {
            c=(char)(c-'a'+'A');
            inicio_linea=false;
        }
        if (c=='/' or c=='-') {
            c=' ';
            inicio_linea=true;
        }
        write.put(c);
    }
}

void imprimir_distrito(ifstream &leer_registrada,ofstream &write) {
    char c;
    leer_registrada>>ws;
    while (true) {
        c=leer_registrada.get();
        if (c==' ')break;
        if (c=='_') c=' ';
        write.put(c);
    }
}
//P599-629
void imprimir_Dinamico(ifstream &leer_registrada,ofstream &write,ifstream &leer_infracciones,ifstream &leer_cometida) {
    char c,c_placa;
    int DNI,num1,num2,vehiculo,compania=1;
    while (true) {
        leer_registrada>>DNI;
        if (leer_registrada.eof())break;
        imprimir_encabezadoEstatico(compania,leer_registrada,write,DNI);
        write<<"VEHICULOS INFRACCIONADOS:"<<endl;
        vehiculo=1;
        while (true) {
            leer_registrada>>ws>>c_placa>>num1>>c>>num2;
            encabezadoDinamico1(write,vehiculo,c_placa,num1,num2);
            imprimir_fecha_inf(c_placa,num1,num2,leer_cometida,write,vehiculo,leer_infracciones);
            c=leer_registrada.get();
            if (c=='\n') break;
            vehiculo++;
        }
        compania++;
    }
}
//1/12/2020   G760-721      G2022
void imprimir_fecha_inf(char c_placa,int num1,int num2,ifstream &leer_cometida,ofstream &write,int vehiculo,ifstream &leer_infracciones) {
    int i=1,fecha,num1Leido,num2Leido,int_infr,cantL=0,cantG=0,cantM=0;
    double multaTotal=0.0,multaL=0.0,multaM=0.0,multaG=0.0;
    char c,c_placaLeida,c_inf;
    leer_cometida.clear();
    leer_cometida.seekg(0,ios::beg);
    while (true) {
        fecha=convertirFecha(leer_cometida);
        if (leer_cometida.eof())break;
        leer_cometida>>ws>>c_placaLeida>>num1Leido>>c>>num2Leido;
        if (c_placaLeida==c_placa and num1==num1Leido and num2==num2Leido) {
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<setw(2)<<setfill('0')<<i<<")"<<setfill(' ');
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<"";
            imprimir_fecha(fecha,write);
            leer_cometida>>ws>>c_inf>>int_infr;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<int_infr;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<"";
            imprimir_gravedad(c_inf,write,cantL,cantG,cantM);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<encontrar_multa(c_inf,int_infr,leer_infracciones);
            multaTotal=multaTotal+encontrar_multa(c_inf,int_infr,leer_infracciones);
            if (c_inf=='L') multaL=multaL+encontrar_multa(c_inf,int_infr,leer_infracciones);
            else if (c_inf=='G') multaG=multaG+encontrar_multa(c_inf,int_infr,leer_infracciones);
            else multaM=multaM+encontrar_multa(c_inf,int_infr,leer_infracciones);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<"";
            imprimir_descripcion(leer_infracciones,write);
            i++;
            c=leer_infracciones.get();
            if (c=='\n')break;
        }
        else {
            leer_cometida.ignore(400,'\n');
            continue;
        }
    }
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void encabezadoDinamico1(ofstream &write,int vehiculo,char c_placa,int num1,int num2) {
    write<<setw(5)<<""<<setw(2)<<setfill('0')<<vehiculo<<")";
    write<<setfill(' ');
    write<<setw(5)<<""<<"PLACA: "<<c_placa<<num1<<"-"<<num2;
    write<<setw(5)<<""<<"TIPO: ";
    imprimir_tipo(c_placa,write);
    write<<endl;
    imprimir_encabezadoDinamico(write);
}

void imprimir_encabezadoDinamico(ofstream &write) {
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"INFRACCION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"GRAVEDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"MULTA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS2+5))<<""<<"DESCRIPCION"<<endl;
}
void imprimir_tipo(char c_placa,ofstream &write) {
    if (c_placa=='P')write<<"PEQUEÑO";
    else if (c_placa=='M')write<<"MEDIANO";
    else write<<"GRANDE";
}

void imprimir_gravedad(char c_inf,ofstream &write,int &cantL,int &cantG,int &cantM) {
    if (c_inf=='L') {
        cantL++;
        write<<"LEVE";
    }
    else if (c_inf=='G') {
        write<<"GRAVE";
        cantG++;
    }
    else {
        write<<"MUY GRAVE";
        cantM++;
    }
}

int convertirFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

double encontrar_multa(char c_infr,int int_inf,ifstream &leer) {
    char c_infrLeida;
    int int_infLeida;
    double multa;
    leer.clear();
    leer.seekg(0,ios::beg);
    while (true) {
        leer>>c_infrLeida>>int_infLeida;
        if (c_infrLeida==c_infr and int_infLeida==int_inf) {
            leer>>multa;
            break;
        }
        else {
            leer.ignore(1000,'\n');
            continue;
        }
    }
    return multa;
}

void imprimir_descripcion(ifstream &leer,ofstream &write) {
    char c;
    while (true) {
        c=leer.get();
        if (c=='\n')break;
        write.put(c);
    }
    write<<endl;
}