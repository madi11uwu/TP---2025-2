//
// Created by Madi on 15/09/2025.
//

#include "Funciones.hpp"
void ProcesarDatosTelevidentes(const char *entrada,const char *salida) {
    ifstream leer;
    apertura_entrada(leer,entrada);
    ofstream write;
    apertura_salida(write,salida);
    imprimir_reporte(write,leer);
    leer.close();
    write.close();
}

void apertura_entrada(ifstream &leer, const char *entrada) {
    leer.open(entrada,ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<entrada<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_salida(ofstream &write, const char *salida) {
    write.open(salida,ios::out);
    if (!write.is_open()) {
        cout<<"El archivo: "<<salida<<" no pudo abrirse"<<endl;
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
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/2)<<""<<"EMPRESA DE OPINION DE MERCADO S. A."<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/5)<<""<<"REGISTRO DE PREFERENCIAS DE LOS TELEVIDENTES"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void imprimir_encabezadoEstatico(ofstream &write) {
    write<<"DNI No. ";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"SEXO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"CATEGORIA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"COMPANIA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"CANAL";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"RANGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"DURACION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}
//69323674  M  ROSARIO_MENDOZA_EGUSQUIZA   B   31/03/2013
void leer_imprimirEstaticos(ofstream &write,ifstream &leer,int DNI,int &fecha,char &sexo,char &compañia) {
    leer>>ws>>sexo;
    write<<DNI;
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
    CamelizacionNombre(leer,write);
    leer>>ws>>compañia;
    fecha=calcular_fecha(leer);
    imprimirCategoria_compañiaYSexo(sexo,fecha,compañia,write);
}

void imprimir_reporte(ofstream &write,ifstream &leer) {
    int DNI,canal=0,fecha,cantMujeres=0,cantMujeresA=0,DuracionTotalMyA=0,cantMenoresYAdultos=0,DuracionCanal;
    char sexo,compañia;
    imprimir_encabezado(write);
    while (true) {
        leer>>DNI;
        if (leer.eof())break;
        imprimir_encabezadoEstatico(write);
        leer_imprimirEstaticos(write,leer,DNI,fecha,sexo,compañia);
        leer_imprimir_Dinamicos(leer,write,DuracionCanal);
        canal++;
        if (fecha/10000>2009 or fecha/10000<=1988) {
            DuracionTotalMyA+=DuracionCanal;
            cantMenoresYAdultos++;
        }
        if (sexo=='F') {
            cantMujeres++;
            if (compañia=='A') cantMujeresA++;
        }
    }
    imprimir_estadisticas(cantMujeres,cantMenoresYAdultos,DuracionTotalMyA,canal,write,cantMujeresA);
}
//556     13:54:27   16:12:37
void imprimir_estadisticas(int cantMujeres,int cantMenoresYAdultos,int DuracionTotalMyA,int canal,ofstream &write,int cantMujeresA) {
    int TiempoProm;
    double porcentaje;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/5)<<""<<"ESTADISTICAS OBTENIDAS: "<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/5)<<""<<"Cantidad de televidentes registrados "<<canal<<endl;
    TiempoProm=(double) DuracionTotalMyA/cantMenoresYAdultos;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/5)<<""<<"Tiempo promedio que ven los menores y adultos: ";
    imprimir_duracion(TiempoProm,write);
    write<<endl;
    porcentaje=((double)cantMujeresA/cantMujeres)*100;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO)/5)<<""<<"Porcentaje de mujeres que ve TVPUCP "<<porcentaje<<"%"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}

void leer_imprimir_Dinamicos(ifstream &leer,ofstream &write,int &DuracionCanal) {
    int canal,hora1,hora2,duracionT;
    char c;
    DuracionCanal=0;
    while (true) {
        leer>>canal;
        hora1=leer_calcularDuracion(leer);
        hora2=leer_calcularDuracion(leer);
        duracionT=hora2-hora1;
        DuracionCanal+=duracionT;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<canal;
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
        imprimir_duracion(hora1,write);
        write<<"-";
        imprimir_duracion(hora2,write);
        write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
        imprimir_duracion(duracionT,write);
        write<<endl;
        c=leer.get();
        if (c=='\n')break;
    }
    write<<setw(90)<<""<<"TIEMPO TOTAL: ";
    imprimir_duracion(DuracionCanal,write);
    write<<endl;
}

void imprimirCategoria_compañiaYSexo(char sexo,int fecha,char compañia,ofstream &write) {
    if (sexo=='F') write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"Femenino";
    else if (sexo=='M') write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"Masculino";
    if (fecha/10000>2009) write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"Menor";
    else if (fecha/10000>1988 and fecha/10000<=2009) write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"Joven";
    else write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"Adulto";
    if (compañia=='A') write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"TVPUCP";
    else if (compañia=='B') write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"CableMas";
    else write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"TPVision";
}

int calcular_fecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return yyyy*10000+mm*100+dd;
}

void CamelizacionNombre(ifstream &leer,ofstream &write) {
    bool esMayuscula=true;
    char c;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (esMayuscula) {
            esMayuscula=false;
        }
        else {
            if (c>='A' and c<='Z') {
                c=(char)(c+'a'-'A');
            }
            if (c==' ')break;
            if (c=='_') {
                c=' ';
                esMayuscula=true;
            }
        }
        write.put(c);
    }
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