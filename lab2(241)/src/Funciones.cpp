//
// Created by Madi on 14/09/2025.
//

#include "Funciones.hpp"

void procesar_datos_imprimir(const char *entrada, const char *salida) {
    ifstream leer;
    apertura_entrada(leer,entrada);
    ofstream write;
    apertura_salida(write,salida);
    imprimir_todo(leer,write);
    write.close();
    leer.close();
}

void apertura_salida(ofstream &write,const char *salida) {
    write.open(salida,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<salida<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_entrada(ifstream &leer,const char *entrada) {
    leer.open(entrada,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<entrada<<" no pudo abrirse"<<endl;
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
void imprimir_encabezado(ofstream &write) {
    write<<setw((ANCHO_REGISTRO-ANCHO_TITULO)/2)<<""<<"EMPRESA DE SALUD S. A."<<endl;
    imprimir_linea(ANCHO_REGISTRO,'=',write);
    write<<setw((ANCHO_REGISTRO-ANCHO_TITULO)/8)<<""<<"REGISTRO DE CITAS DE LAS CONSULTAS MEDICAS EN PEDIATRIA"<<endl;
    write<<setw((ANCHO_REGISTRO-ANCHO_TITULO)/8)<<""<<"ENTRE 1 HORA CON 15 MINUTOS Y 30 SEGUNDOS Y 2 HORAS 30 MINUTOS Y 25 SEGUNDOS DE DURACION"<<endl;
    imprimir_linea(ANCHO_REGISTRO,'=',write);
}

void imprimir_encabezado2(ofstream &write) {
    write<<"Fecha";
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS))<<""<<"Paciente";
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+8))<<""<<"Inicio";
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+5))<<""<<"Fin";
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+8))<<""<<"Duracion(H:M:S";
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+8))<<""<<"Duracion(H)";
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+8))<<""<<"% por Seguro";
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+8))<<""<<"Pago (cita+medicinas)"<<endl;
    imprimir_linea(ANCHO_REGISTRO,'-',write);
}
//9/09/2023   94683380   2.60   11:17:52   12:48:30   124.34   C   S   317.86
void leer_imprimirDatosDinamicos(ifstream &leer,ofstream &write) {
    int fecha,DNI,duracionI,duracionF,duracionT,RegistroT=0,RegistroR=0;
    double desc,tarifa,monto,pagoTotal=0.0,pago;
    char c,especialidad,medicina;
    while (true) {
        monto=0.0;
        fecha=leer_calcularFecha(leer);
        leer>>DNI;
        RegistroT++;
        if (leer.eof()) break;
        leer>>desc;
        duracionI=leer_calcularDuracion(leer);
        duracionF=leer_calcularDuracion(leer);
        duracionT=duracionF-duracionI;
        if (!DuracionValida(duracionT)) {
            leer.ignore(3000,'\n');
            continue;
        }
        RegistroR++;
        leer>>tarifa;
        leer>>especialidad;
        leer>>medicina;
        if (medicina=='S') leer>>monto;
        imprimir_datos(DNI,duracionF,duracionI,duracionT,fecha,write,desc,pago,tarifa,monto);
        pagoTotal=pagoTotal+pago;
        c=leer.get();
        if (c=='\n') continue;
    }
    imprimir_gastoTotal(pagoTotal,write);
    estadisticas_totales(RegistroR,RegistroT,write);
}
void imprimir_todo(ifstream &leer,ofstream &write) {
    imprimir_encabezado(write);
    imprimir_encabezado2(write);
    leer_imprimirDatosDinamicos(leer,write);
}
void imprimir_gastoTotal(double pagoTotal,ofstream &write) {
    imprimir_linea(ANCHO_REGISTRO,'=',write);
    write<<"Total de ingresos: "<<pagoTotal<<endl;
    imprimir_linea(ANCHO_REGISTRO,'=',write);
}
void estadisticas_totales(int RegistroR,int RegistroT,ofstream &write) {
    double porcentaje;
    porcentaje=((double)RegistroR/RegistroT)*100;
    write<<"ESTADISTICAS OBTENIDAS: "<<endl;
    write<<"Cantidad de registros del archivo: "<<RegistroT<<endl;
    write<<"Cantidad de registros procesados: "<<RegistroR<<endl;
    write<<"Porcentaje de registros procesados: "<<setprecision(4)<<porcentaje<<endl;
    imprimir_linea(ANCHO_REGISTRO,'=',write);
}
void imprimir_datos(int DNI,int duracionF,int duracionI,int duracionT,int fecha,ofstream &write,double desc,
    double &pago,double tarifa,double monto) {
    imprimir_fecha(fecha,write);
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+6))<<""<<DNI;
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+6))<<"";
    imprimir_duracion(duracionI,write);
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+6))<<"";
    imprimir_duracion(duracionF,write);
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+10))<<"";
    imprimir_duracion(duracionT,write);
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+6))<<""<<duracionT/3600.0;
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+6))<<""<<desc<<"%";
    pago=((duracionT/3600.0)*tarifa*desc/100.0+monto*desc/200.0);
    write<<setw(ANCHO_REGISTRO/(NRO_COLUMNAS+6))<<""<<pago<<endl;
}

bool DuracionValida(int duracion) {
    int duracionI=1*3600+15*60+30,duracionF=2*3600+30*60+25;
    if (duracion>=duracionI and duracion<=duracionF) return true;
    else return false;
}

int leer_calcularFecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return yyyy*10000+mm*100+dd;
}

int leer_calcularDuracion(ifstream &leer) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    return hh*3600+mm*60+ss;
}

void imprimir_duracion(int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<(fecha/10000);
    write<<setfill(' ');
}