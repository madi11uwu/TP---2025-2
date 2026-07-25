//
// Created by Madi on 22/09/2025.
//

#include "Funciones.hpp"

void ProcesarDatos(const char *registradas, const char *cometidas, const char *infracciones, const char *salidad) {
    ifstream leer_registrada;
    ifstream leer_cometida;
    ifstream leer_infracciones;
    apertura_lectura(registradas,leer_registrada);
    apertura_lectura(cometidas,leer_cometida);
    apertura_lectura(infracciones,leer_infracciones);
    ofstream write;
    apertura_escritura(salidad,write);
    imprimir_encabezadoPrincipal(write);
    imprimir_reporte(leer_registrada,write,leer_infracciones,leer_cometida);
    leer_infracciones.close();
    leer_cometida.close();
    leer_registrada.close();
    write.close();
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse."<<endl;
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

void imprimir_reporte(ifstream &leer_registrada, ofstream &write,ifstream &leer_infracciones,ifstream &leer_cometida) {
    int compania=1,DNI;
    while (true) {
        leer_registrada>>DNI;
        if (leer_registrada.eof())break;
        imprimir_encabezadoEstatico(leer_registrada,write,compania,DNI);
        imprimir_datosDinamicos(write,leer_registrada,leer_cometida,leer_infracciones);
        compania++;
        break;
    }
}

void imprimir_datosDinamicos(ofstream &write,ifstream &leer_registrada,ifstream &leer_cometida,ifstream &leer_infracciones) {
    char c_placa,c;
    write<<"VEHICULOS INFRACCIONADOS: "<<endl;
    int i=1,num1,num2,infraccion=1;
    leer_registrada>>ws>>c_placa>>num1>>c>>num2;
    imprimir_encabezadoDinamico(write,i,c_placa,num1,num2);
    while (true) {
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<setw(2)<<setfill('0')<<infraccion<<")";
        write<<setfill(' ');
        encontrar_fecha_infr_grav_mult_desc(write,leer_cometida,c_placa,num1,num2,leer_infracciones);
        write<<endl;
        c=leer_registrada.get();
        i++;
    }
    imprimir_linea(ANCHO_REPORTE,'-',write);
    i++;
}
void encontrar_fecha_infr_grav_mult_desc(ofstream &write,ifstream &leer_cometida,char c_placa,int num1,int num2,ifstream &leer_infracciones) {
    int fecha,num1Leido,num2Leido,int_infraccion;
    char c,c_placaLeida,c_infraccion;
    while (true) {
        fecha=AlmacenarFecha(leer_cometida);
        if (leer_cometida.eof()) break;
        leer_cometida>>ws>>c_placaLeida>>num1Leido>>c>>num2Leido;
        if (c_placaLeida==c_placa and num1Leido==num1 and num2Leido==num2) {
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_fecha(fecha,write);
            leer_cometida>>ws>>c_infraccion>>int_infraccion;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<int_infraccion;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_gravedad(write,c_infraccion);
            imprimir_multaYDescripcion(c_infraccion,int_infraccion,write,leer_infracciones);
            break;
        }
        else {
            leer_cometida.ignore(500,'\n');
            continue;
        }
    }
}

void imprimir_multaYDescripcion(char c_infraccion,int int_infraccion,ofstream &write,ifstream &leer_infracciones) {
    leer_infracciones.clear();
    leer_infracciones.seekg(0,ios::beg);
    char c_infraccionLeida;
    int int_infraccionLeida;
    double multa;
    while (true) {
        leer_infracciones>>c_infraccionLeida>>int_infraccionLeida;
        if (leer_infracciones.eof())break;
        if (c_infraccionLeida==c_infraccion and int_infraccionLeida==int_infraccion) {
            leer_infracciones>>multa;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<multa;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_descripcion(write,leer_infracciones);
            break;
        }
        else {
            leer_infracciones.ignore(300,'\n');
            continue;
        }
    }
}

void imprimir_descripcion(ofstream &write,ifstream &leer) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c=='\n')break;
        write.put(c);
    }
}
void imprimir_gravedad(ofstream &write,char c_infraccion) {
    if (c_infraccion=='G') write<<"GRAVE";
    else if (c_infraccion=='L') write<<"LEVE";
    else write<<"MUY GRAVE";
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}
void imprimir_encabezadoDinamico(ofstream &write,int i,char c_placa,int num1,int num2) {
    write<<setw(2)<<""<<setw(2)<<setfill('0')<<i;
    write<<setfill(' ');
    write<<setw(2)<<""<<"PLACA: "<<c_placa<<num1<<"-"<<num2;
    write<<setw(2)<<""<<"TIPO: ";
    imprimir_tipo(write,c_placa);
    write<<endl;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"INFRACCION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"GRAVEDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"MULTA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"DESCRIPCION"<<endl;
}
void imprimir_tipo(ofstream &write,char c_placa) {
    if (c_placa=='P') write<<"PEQUEÑO";
    else if (c_placa=='M') write<<"MEDIANO";
    else write<<"GRANDE";
}
void imprimir_encabezadoEstatico(ifstream &leer,ofstream &write,int canal,int DNI) {
    write<<"COMPANIA No. "<<canal<<endl;
    write<<"REPRESENTANTE LEGAL: ";
    imprimir_nombre(write,leer);
    write<<setw(4)<<""<<"DNI: "<<DNI;
    write<<setw(4)<<""<<"DISTRITO: ";
    imprimir_distrito(leer,write);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void imprimir_nombre(ofstream &write,ifstream &leer) {
    bool inicioPalabra=true;
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (inicioPalabra) {
            c=(char)(c-'a'+'A');
            inicioPalabra=false;
        }
        if (c==' ')break;
        if (c=='/') {
            c=' ';
            inicioPalabra=true;
        }
        write.put(c);
    }
}

void imprimir_distrito(ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        write.put(c);
    }
}