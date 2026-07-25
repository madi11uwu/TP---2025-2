//
// Created by Madi on 7/09/2025.
//

#include "Funciones.hpp"

void imprimir_reporte() {
    imprimir_encabezado();
    imprimir_info();
}

void imprimir_encabezado() {
    cout<<setw(30)<<""<<"MINISTERIO DE TRANSPORTE"<<endl;
    cout<<setw(20)<<""<<"MULTAS IMPUESTAS A LAS COMPANIAS"<<endl;
    cout<<setw(15)<<""<<"RANGO DE FECHAS A CONSIDERAR: DEL ";
    imprimir_fecha();
    cout<<"AL ";
    imprimir_fecha();
    cout<<endl;
}

void imprimir_fecha() {
    int dd, mm, yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    cout<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
    cout<<setfill(' ');
}

void imprimir_linea(int n,char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}

void transformarMayus(char &c) {
    if (c>='a' and c<='z') {
        c= (char)(c-'a'+'A');
    }
}

void parte_estatica() {
    imprimir_linea(120,'-');
    cout<<"VEHICULOS INFRACCIONADOS:";
    cout<<setw(50)<<""<<"INCREMENTOS"<<endl;
    cout<<setw(2)<<""<<"TIPO";
    cout<<setw(10)<<""<<"PLACA";
    cout<<setw(10)<<""<<"FECHA";
    cout<<setw(10)<<""<<"HORA";
    cout<<setw(10)<<""<<"GRAVEDAD";
    cout<<setw(10)<<""<<"MULTA";
    cout<<setw(10)<<""<<"POR TIPO";
    cout<<setw(10)<<""<<"POR FECHA";
    cout<<setw(10)<<""<<"POR HORA";
    cout<<setw(10)<<""<<"TOTAL A PAGAR";
    cout<<endl;
}

void imprimir_info(){
    int mañanaI=43000,mañanaF=112500,tardeF=204000,fechaF=20250225,fechaI=20240128,DNI,fecha,hora,DNIM=0,DNIm=0,i=1;
    double montoFecha,montoHora,montoTamaño,montoTotal,totalPago,PagoTotal=0,porcentaje,incrementoFecha,incrementoHora,monto,mayorpago=0,menorPago=1000000000;
    char c,car;
    while (true) {
        cin>>DNI;
        if (cin.eof()) break;
        imprimir_linea(120,'=');
        cout<<"COMPANIA No. "<<i<<endl;
        cout<<"REPRESENTANTE LEGAL: ";
        totalPago=0;
        imprimir_nombre();
        cout<<setw(20)<<""<<"DNI: "<<DNI<<endl;
        parte_estatica();
        while (true){
            leer_tipo(porcentaje);
            leer_fecha(fecha);
            monto_calcular(fecha,incrementoFecha,incrementoHora,fechaI,fechaF);
            leer_hora(hora);
            monto_calcularHora(hora,mañanaF,mañanaI,tardeF,incrementoHora);
            Gravedad(monto);
            cout<<setw(10)<<""<<monto;
            calcular_montos(montoFecha,montoHora,montoTamaño,montoTotal,monto,incrementoFecha,incrementoHora,porcentaje);
            imprimir(montoTamaño,montoFecha,montoHora,montoTotal);
            totalPago=totalPago+montoTotal;
            CalcularMayor(totalPago,menorPago,DNI,mayorpago,DNIm,DNIM);
            cin.get(car);
            if (car=='\n') break;
        }
        imprimir_linea(120,'-');
        cout<<"PAGO TOTAL :"<<totalPago<<endl;
        PagoTotal=PagoTotal+totalPago;
        i++;
    }
    imprimir_estadisticas(DNIm,DNIM,menorPago,mayorpago);
}

void leer_tipo(double &porcentaje) {
    int numero,num1;
    char c,t;
    cin>>ws;
    cin>>c>>numero>>t>>num1;
    if (c=='P') {
        cout<<"-PEQUENO";
        porcentaje=2.5;
    }
    else if (c=='M') {
        cout<<"-MEDIANO";
        porcentaje=11.7;
    }
    else if (c=='C') {
        cout<<"-GRANDE";
        porcentaje=15.3;
    }
    cout<<setw(10)<<""<<c<<numero<<num1;
}

void calcular_montos(double &montoFecha,double &montoHora,double &montoTamaño,double &montoTotal,double monto,double incrementoFecha,
    double incrementoHora,double porcentaje) {
    montoFecha=incrementoFecha*monto;
    montoHora=incrementoHora*monto;
    montoTamaño=porcentaje*monto;
    montoTotal=monto+montoFecha+montoHora+montoTamaño;
}

void CalcularMayor(double totalPago,double &menorPago,int DNI,double &mayorpago,int &DNIm,int &DNIM) {
    if (totalPago<menorPago) {
        menorPago=totalPago;
        DNIm=DNI;
    }
    if (totalPago>mayorpago) {
        mayorpago=totalPago;
        DNIM=DNI;
    }
}

void leer_fecha(int &fecha) {
    int dd, mm, yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    cout<<setw(10)<<""<<setw(2)<<setfill('0')<<dd<<"/"<<setw(2)<<setfill('0')<<mm<<"/"<<yyyy;
    cout<<setfill(' ');
    fecha=convertirFecha(dd,mm,yyyy);
}

void leer_hora(int &hora) {
    int h,m,s;
    char c;
    cin>>h>>c>>m>>c>>s;
    cout<<setw(10)<<""<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<':'<<setw(2)<<setfill('0')<<s;
    cout<<setfill(' ');
    hora=convertirHora(h,m,s);
}

int convertirFecha(int dd,int mm,int yyyy) {
    int fecha;
    fecha=yyyy*10000+mm*100+dd;
    return fecha;
}

int convertirHora(int h,int m,int s) {
    int hora;
    hora=h*10000+m*100+s;
    return hora;
}

void Gravedad(double &monto) {
    char c;
    cin>>ws;
    cin.get(c);
    if (c=='L') {
        monto=158.33;
        cout<<setw(10)<<""<<"LEVE";
    }
    else if (c=='G') {
        monto=516.75;
        cout<<setw(10)<<""<<"GRAVE";
    }
    else if (c=='M') {
        monto=3920.25;
        cout<<setw(10)<<""<<"MUY GRAVE";
    }
}

void imprimir_estadisticas(int DNIm,int DNIM,double menorPago,double mayorPago) {
    cout<<setfill('/')<<setw(10)<<endl;
    cout<<setw(2)<<setfill('/')<<"COMPANIA CON MAYOR PAGO POR INFRACCIONES: "<<endl;
    cout<<"DNI:"<<setw(10)<<""<<DNIM<<endl;
    cout<<setw(2)<<setfill('/')<<"TOTAL PAGADO:"<<mayorPago<<endl;
    cout<<setfill('/')<<setw(10)<<endl;
    cout<<setw(2)<<setfill('/')<<"COMPANIA CON MENOR PAGO POR INFRACCIONES: "<<endl;
    cout<<"DNI:"<<setw(10)<<""<<DNIm<<endl;
    cout<<setw(2)<<setfill('/')<<"TOTAL PAGADO:"<<menorPago<<endl;
}

void imprimir(double montoTamaño,double montoFecha,double montoHora,double montoTotal) {
    cout<<setw(10)<<""<<montoTamaño;
    cout<<setw(10)<<""<<montoFecha;
    cout<<setw(10)<<""<<montoHora;
    cout<<setw(10)<<""<<montoTotal;
    cout<<endl;
}

void monto_calcular(int fecha,double &incrementoFecha,double &incrementoHora,int fechaI,int fechaF) {
    if (fecha<fechaI) incrementoFecha=10.75/100.0;
    else if (fecha>fechaI and fecha<fechaF) incrementoFecha=7.25/100.0;
    else if (fecha>fechaF) incrementoFecha=0;
}

void monto_calcularHora(int hora,int mañanaF,int mañanaI,int tardeF,double &incrementoHora) {
    if (hora>mañanaI and hora<mañanaF) incrementoHora=8.5/100.0;
    else if (hora>mañanaF and hora<tardeF) incrementoHora=5.8/100.0;
    else if (hora>tardeF and hora<mañanaI) incrementoHora=3.7/100.0;
}

void imprimir_nombre() {
    char c;
    cin>>ws;
    while (true){
        cin.get(c);
        transformarMayus(c);
        if (c==' ') break;
        if (c=='/' or c=='-') c=' ';
        cout.put(c);
    }
}