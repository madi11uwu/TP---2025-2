//
// Created by Madi on 14/09/2025.
//

#include "Funciones.hpp"

void imprimir_procesar_datos(const char *entrada, const char *salida) {
    int fecha1,fecha2;
    ifstream leer;
    apertura_lectura(leer,entrada);
    ofstream write;
    apertura_escritura(write,salida);
    imprimirTodo(write,leer);
    write.close();
    leer.close();
}

void apertura_lectura(ifstream &leer, const char *entrada) {
    leer.open(entrada, ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<entrada<<"no pudo abrirse"<<endl;
        exit(1);
    }
}
void apertura_escritura(ofstream &write, const char *salida) {
    write.open(salida,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<salida<<"no pudo abrirse"<<endl;
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

void imprimir_encabeza(ofstream &write, ifstream &leer,int &fecha1,int &fecha2) {
    write<<setw((ANCHO-ANCHO_TITULO1)/2)<<""<<"MINISTERIO DE TRANSPORTE"<<endl;
    write<<setw((ANCHO-ANCHO_TITULO2)/2)<<""<<"MULTAS IMPUESTAS A LAS COMPANIAS"<<endl;
    write<<setw((ANCHO-ANCHO_TITULO3)/2)<<""<<"RANGO DE FECHAS A CONSIDERAR: DEL ";
    fecha1=leer_calcularFecha(leer);
    fecha2=leer_calcularFecha(leer);
    imprimir_fecha(fecha1,write);
    write<<" AL ";
    imprimir_fecha(fecha2,write);
    write<<endl;
}

void imprimir_encabezadoEstatico(ofstream &write,int compañia) {
    imprimir_linea(ANCHO,'=',write);
    write<<"COMPAÑIA No. "<<compañia<<endl;
}

void imprimir_leerDatosEstaticos(ofstream &write,ifstream &leer,int DNI,int compañia) {
    imprimir_encabezadoEstatico(write,compañia);
    write<<"REPRESENTANTE LEGAL: ";
    leer_nombre(leer,write);
    write<<setw(ANCHO/(NRO_COLUMNAS1+5))<<""<<"DNI: ";
    write<<DNI<<endl;
    imprimir_linea(ANCHO,'-',write);
}
//48528209      Zavaleta/Coronado/Felicita-Eloisa  C262-654    9/06/2024  00:05:29  M
void imprimir_encabezadoDinamico(ofstream &write) {
    write<<"VEHICULOS INFRACCIONADOS: "<<endl;
    write<<setw(ANCHO/(NRO_COLUMNAS1-1))<<""<<"INCREMENTOS"<<endl;
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"TIPO";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"PLACA";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"FECHA";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"HORA";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"GRAVEDAD";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"MULTA";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"POR TIPO";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"POR FECHA";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"POR HORA";
    write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<""<<"TOTAL A PAGAR"<<endl;
}
// P599-629    12/12/2023  10:42:26      L
void imprimir_datosDinamicos(ofstream &write,ifstream &leer,int fecha1,int fecha2,double &incrementoCanal) {
    int fecha,hora;
    double incG,incT,incH,incF,incrementoTotal;
    incrementoCanal=0;
    char tipo,gravedad,c;
    imprimir_encabezadoDinamico(write);
    while (true) {
        leer>>tipo;
        write<<setw(ANCHO/(NRO_COLUMNAS2+2))<<"";
        imprimir_tipo(tipo,write);
        write<<setw(ANCHO/(NRO_COLUMNAS2+5))<<"";
        imprimir_placa(leer,write,tipo);
        fecha=leer_calcularFecha(leer);
        write<<setw(ANCHO/(NRO_COLUMNAS2+5))<<"";
        imprimir_fecha(fecha,write);
        write<<setw(ANCHO/(NRO_COLUMNAS2+8))<<"";
        leer_imprimirHora(write,leer,hora);
        leer>>ws>>gravedad;
        write<<setw(ANCHO/(NRO_COLUMNAS2+5))<<"";
        incrementos_Gravedad(write,hora,gravedad,tipo,fecha1,fecha2,incG,incT,incH,incF,fecha,incrementoTotal);
        imprimir_incrementos(write,incG,incT,incH,incF,incrementoTotal);
        incrementoCanal+=incrementoTotal;
        c=leer.get();
        if (c=='\n')break;
    }
}

void imprimir_incrementos(ofstream &write,double incG,double incT,double incH,double incF,double &incrementoTotal) {
    write<<setw(ANCHO/(NRO_COLUMNAS2))<<""<<incG;
    write<<setw(ANCHO/(NRO_COLUMNAS2))<<""<<incT;
    write<<setw(ANCHO/(NRO_COLUMNAS2))<<""<<incF;
    write<<setw(ANCHO/(NRO_COLUMNAS2))<<""<<incH;
    write<<setw(ANCHO/(NRO_COLUMNAS2))<<""<<incrementoTotal<<endl;
}
void incrementos_Gravedad(ofstream &write,int hora,char gravedad,char tipo,int fecha1,int fecha2,double &incG,
    double &incT,double &incH,double &incF,int fecha,double &incrementoTotal) {
    int horaIM,horaFM,horaFT;
    horaIM=4*3600+30*60;
    horaFM=11*3600+25*60;
    horaFT=20*3600+40*60;
    if (gravedad=='L') {
        write<<"LEVE";
        incG=158.33;
    }
    else if (gravedad=='G') {
        write<<"GRAVE";
        incG=516.75;
    }
    else if (gravedad=='M') {
        write<<"MUY GRAVE";
        incG=3920.25;
    }
    if (tipo=='P') incT=incG*(2.7/100.0);
    else if (tipo=='M') incT=incG*(11.7/100.0);
    else if (tipo=='C') incT=incG*(15.3/100.0);
    if (hora>horaIM and hora<horaFM) incH=incG*(8.5/100.0);
    else if (hora>=horaFM and hora<horaFT) incH=incG*(5.8/100.0);
    else if (hora>horaFT or hora<=horaIM) incH=incG*(3.7/100.0);
    if (fecha<fecha1) incF=incG*(10.75/100.0);
    else if (fecha>=fecha1 and fecha<fecha2) incF=incG*(7.25/100.0);
    else if (fecha>=fecha2) incF=incG*(0.00/100.0);
    incrementoTotal=incG+incT+incF+incH;
}
void leer_imprimirHora(ofstream &write,ifstream &leer,int &hora) {
    int hh,mm,ss;
    char c;
    leer>>hh>>c>>mm>>c>>ss;
    write<<setw(2)<<setfill('0')<<hh<<":"<<setw(2)<<setfill('0')<<mm<<":"<<setw(2)<<setfill('0')<<ss;
    write<<setfill(' ');
    hora=hh*3600+mm*60+ss;
}

void imprimir_placa(ifstream &leer,ofstream &write,char tipo) {
    int num1,num2;
    char c;
    leer>>num1>>c>>num2;
    write<<tipo<<num1<<num2;
}
void imprimir_tipo(char tipo,ofstream &write) {
    if (tipo=='P') write<<"PEQUEÑO";
    else if (tipo=='M') write<<"MEDIANO";
    else if (tipo=='C') write<<"GRAVE";
}

void leer_nombre(ifstream &leer,ofstream &write) {
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (c=='/' or c=='-') {
            c=' ';
        }
        if (c<='z' and c>='a') c=(char)(c-'a'+'A');
        write.put(c);
    }
}
int leer_calcularFecha(ifstream &leer) {
    int dd,mm,yyyy,fecha;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    fecha=yyyy*10000+mm*100+dd;
    return fecha;
}

void imprimir_fecha(int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<(fecha%100)<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<setw(2)<<setfill('0')<<fecha/10000;
    write<<setfill(' ');
}

void imprimirTodo(ofstream &write,ifstream &leer) {
    int fecha1,fecha2,DNI,compañia=0,DNIM=0,DNIm=0;
    double incrementoTotal,mayorPago=0,menorPago=100000000000;
    imprimir_encabeza(write,leer,fecha1,fecha2);
    while (true) {
        leer>>DNI;
        if (leer.eof())break;
        imprimir_leerDatosEstaticos(write,leer,DNI,compañia);
        imprimir_datosDinamicos(write,leer,fecha1,fecha2,incrementoTotal);
        imprimir_linea(ANCHO,'-',write);
        write<<"PAGO: "<<incrementoTotal<<endl;
        compañia++;
        if (incrementoTotal>mayorPago) {
            mayorPago=incrementoTotal;
            DNIM=DNI;
        }
        if (incrementoTotal<menorPago) {
            menorPago=incrementoTotal;
            DNIm=DNI;
        }
    }
    imprimir_compañiaGastoMayor(write,mayorPago,menorPago,DNIM,DNIm);
}

void imprimir_compañiaGastoMayor(ofstream &write,double MayorPago,double MenorPago,int DNIM,int DNIm) {
    write<<setw(ANCHO/3)<<setfill('/')<<endl;
    write<<setw(2)<<setfill('/')<<"COMPANIA CON MAYOR PAGO POR INFRACCIONES: "<<setw(2)<<setfill('/')<<endl;
    write<<setw(2)<<setfill('/')<<"DNI: "<<DNIM<<endl;
    write<<setw(2)<<setfill('/')<<"TOTAL PAGADO: "<<MayorPago<<endl;
    write<<setw(ANCHO/3)<<setfill('/')<<endl;
    write<<setw(2)<<setfill('/')<<"COMPANIA CON MENOR PAGO POR INFRACCIONES: "<<setw(2)<<setfill('/')<<endl;
    write<<setw(2)<<setfill('/')<<"DNI: "<<DNIm<<endl;
    write<<setw(2)<<setfill('/')<<"TOTAL PAGADO: "<<MenorPago<<endl;
}