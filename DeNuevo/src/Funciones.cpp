//
// Created by Madi on 22/09/2025.
//

#include "Funciones.hpp"

void ProcesarDatos(const char *registradas, const char *cometidas, const char *infracciones, const char *salida) {
    ifstream leer_registrada;
    ifstream leer_cometida;
    ifstream leer_infracciones;
    apertura_lectura(registradas,leer_registrada);
    apertura_lectura(cometidas,leer_cometida);
    apertura_lectura(infracciones,leer_infracciones);
    ofstream write;
    apertura_escritura(salida,write);
    imprimir_encabezado(write);
    imprimir_reporte(write,leer_registrada,leer_infracciones,leer_cometida);
    leer_cometida.close();
    leer_infracciones.close();
    leer_registrada.close();
    write.close();
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file, ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<"no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<file<<"no pudo abrirse"<<endl;
        exit(1);
    }
}

void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTE"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"MULTAS IMPUESTAS A LAS COMPANIAS"<<endl;
    imprimir_linea(ANCHO_REPORTE, '=', write);
}

void imprimir_linea(int n, char c, ofstream &write) {
    int i=0;
    while (i<n) {
        write.put(c);
        i++;
    }
    write<<endl;
}

void imprimir_reporte(ofstream &write,ifstream &leer_registrada,ifstream &leer_infracciones,ifstream &leer_cometida) {
    int DNI,compania=1,num1,num2,placa=1;
    char c_placa,c;
    while (true) {
        leer_registrada>>DNI;
        if (leer_registrada.eof())break;
        imprimir_encabezadoEstatico(DNI,write,leer_registrada,compania);
        while (true) {
            leer_registrada>>c_placa>>num1>>c>>num2;
            imprimir_encabezadoDinamico(write,c_placa,num1,num2,placa);
            imprimir_datosDinamicos(write,leer_cometida,leer_infracciones,c_placa,num1,num2);
            c=leer_registrada.get();
            if (c=='\n')break;
            placa++;
            break;
        }
        compania++;
        break;
    }
}

void imprimir_datosDinamicos(ofstream &write,ifstream &leer_cometida,ifstream &leer_infracciones,char c_placa,int num1,int num2) {
    int infraccion=1,int_infraccion,fecha;
    char c_infraccion;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<setw(2)<<setfill('0')<<infraccion<<")";
    write<<setfill(' ');
    RecuperarFechaEInfraccion(c_placa,num1,num2,leer_infracciones,leer_cometida,c_infraccion,int_infraccion,fecha);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<"";
    imprimir_fecha(fecha,write);
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<int_infraccion;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<"";
    imprimir_gravedad(c_infraccion,write);
    imprimir_multaYDescripcion(leer_cometida,write,c_infraccion,int_infraccion);
    imprimir_linea(ANCHO_REPORTE, '-', write);
}

void imprimir_multaYDescripcion(ifstream &leer_infracciones,ofstream &write,char c_infraccion,int int_infraccion) {
    leer_infracciones.clear();
    leer_infracciones.seekg(0,ios::beg);
    char c_infraccionLeida;
    int int_infraccionLeida;
    double multa;
    while (true) {
        leer_infracciones>>c_infraccionLeida>>int_infraccionLeida;
        if (leer_infracciones.eof()) break;
        if (c_infraccionLeida==c_infraccion and int_infraccionLeida==int_infraccion) {
            leer_infracciones>>multa;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<multa;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<"";
            imprimir_texto('\n',write,leer_infracciones);
            break;
        }
        else {
            leer_infracciones.ignore(200,'\n');
            continue;
        }
    }
}
void imprimir_gravedad(char c_infraccion,ofstream &write) {
    if (c_infraccion=='L') write<<"LEVE";
    else if (c_infraccion=='G') write<<"GRAVE";
    else write<<"MUY GRAVE";
}
void RecuperarFechaEInfraccion(char c_placa,int num1,int num2,ifstream &leer_infraccion,ifstream &leer_cometida,
    char &c_infraccion,int int_infraccion,int &fecha) {
    int num1Leida,num2Leida;
    char c_placaLeida,c;
    leer_cometida.clear();
    leer_cometida.seekg(0,ios::beg);
    while (true) {
        fecha=AlmacenarFecha(leer_cometida);
        if (leer_cometida.eof()) break;
        leer_cometida>>ws>>c_placaLeida>>num1Leida>>c>>num2Leida;
        if (c_placaLeida==c_placa and num1Leida==num1 and num2Leida==num2) {
            leer_cometida>>ws>>c_infraccion>>int_infraccion;
            break;
        }
        else {
            leer_cometida.ignore(500,'\n');
            continue;
        }
    }
}

int AlmacenarFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha (int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

void imprimir_encabezadoDinamico1(ofstream &write) {
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<"No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<"FECHA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<"INFRACCION";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<"GRAVEDAD";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<"MULTA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS+4))<<""<<"DESCRIPCION"<<endl;
}

void imprimir_encabezadoDinamico(ofstream &write,char c_placa,int num1,int num2,int placa) {
    write<<"VEHICULOS INFRACCIONADOS:"<<endl;
    write<<setw(2)<<""<<setw(2)<<setfill('0')<<placa<<")";
    write<<setfill(' ');
    write<<setw(2)<<""<<"PLACA: "<<c_placa<<num1<<"-"<<num2;
    write<<setw(2)<<""<<"TIPO: ";
    imprimir_tipo(write,c_placa);
    write<<endl;
    imprimir_encabezadoDinamico1(write);
}

void imprimir_tipo(ofstream &write,char c_placa) {
    if (c_placa=='P')write<<"PEQUEÑO";
    else if (c_placa=='M')write<<"MEDIANO";
    else write<<"GRANDE";
}

void imprimir_encabezadoEstatico(int DNI,ofstream &write,ifstream &leer_registrada,int compania) {
    write<<"COMPANIA No. "<<compania<<endl;
    write<<"REPRESENTANTE LEGAL: ";
    imprimir_nombre(write,leer_registrada);
    write<<setw(5)<<""<<"DNI: "<<DNI;
    write<<setw(5)<<""<<"DISTRITO: ";
    imprimir_texto(' ',write,leer_registrada);
    write<<endl;
    imprimir_linea(ANCHO_REPORTE, '-', write);
}

void imprimir_nombre (ofstream &write,ifstream &leer_registrada) {
    char c;
    bool InicioPalabra=true;
    leer_registrada>>ws;
    while (true) {
        c=leer_registrada.get();
        if (c==' ')break;
        if (InicioPalabra) {
            c=(char)(c-'a'+'A');
            InicioPalabra=false;
        }
        if (c=='/') {
            c=' ';
            InicioPalabra=true;
        }
        write.put(c);
    }
}

void imprimir_texto(char c,ofstream &write,ifstream &leer) {
    char car;
    leer>>ws;
    while (true) {
        car=leer.get();
        if (car==c)break;
        write.put(car);
    }
}