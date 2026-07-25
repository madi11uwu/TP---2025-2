//
// Created by Madi on 21/09/2025.
//

#include "Funciones.hpp"

void ProcesarDatos(const char *canales, const char *preferencias, const char *televidentes, const char *salida) {
    ifstream leer_canales;
    ifstream leer_preferencias;
    ifstream leer_televidentes;
    apertura_lectura(canales,leer_canales);
    apertura_lectura(preferencias,leer_preferencias);
    apertura_lectura(televidentes,leer_televidentes);
    ofstream write;
    apertura_escritura(salida,write);
    imprimir_encabezado(write);
    imprimir_reporte(leer_canales,write,leer_preferencias,leer_televidentes);
    leer_canales.close();
    leer_preferencias.close();
    leer_televidentes.close();
    write.close();
}

void apertura_lectura(const char *file, ifstream &leer) {
    leer.open(file, ios::in);
    if (!leer.is_open()) {
        cout<<"El archivo: "<<file<<" no pudo abrirse"<<endl;
        exit(1);
    }
}

void apertura_escritura(const char *file, ofstream &write) {
    write.open(file, ios::out);
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

void imprimir_encabezado(ofstream &write) {
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO1)/2)<<""<<"EMPRESA DE OPINION DE MERCADO TP S.A."<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO2)/2)<<""<<"AVENIDA UNIVERSITARIA 1234 San Miguel"<<endl;
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO3)/2)<<""<<"LIMA - PERU"<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<setw((ANCHO_REPORTE-ANCHO_TITULO4)/2)<<""<<"REGISTRO DE PREFERENCIAS DE LOS TELEVIDENTES POR CANAL DE PREFERENCIA"<<endl;

}

void imprimir_encabezadoEstatico(ifstream &leer_canales,ofstream &write,int canal) {
    imprimir_linea(ANCHO_REPORTE,'=',write);
    write<<"CANAL: ";
    leer_canal(leer_canales,write);
    write<<setw(15)<<""<<"NUMERO: "<<canal<<endl;
    write<<"LISTADO DE TELEVIDENTES QUE VEN EL CANAL: "<<endl;
}
//310   /Television Peruana/
void leer_canal(ifstream &leer,ofstream &write) {
    char c;
    leer>>c;
    while (true) {
        c=leer.get();
        if (c=='/')break;
        if (c>='a' and c<='z') c=c-'a'+'A';
        write.put(c);
    }
}

void imprimir_reporte(ifstream &leer_canales,ofstream &write,ifstream &leer_preferencias,ifstream &leer_televidentes) {
    int canal,televidentes,DuracionTotal,jovenes,menores,adultos;
    while (true) {
        leer_canales>>canal;
        if (leer_canales.eof())break;
        imprimir_encabezadoEstatico(leer_canales,write,canal);
        imprimir_datosDinamicos(leer_preferencias,write,canal,leer_televidentes,televidentes,DuracionTotal,jovenes,menores,adultos);
        imprimir_estadisticaCanal(write,DuracionTotal,televidentes,jovenes,adultos,menores);
    }
}

void imprimir_estadisticaCanal(ofstream &write,int DuracionTotal,int televidentes,int jovenes,int adultos,int menores) {
    write<<"PROMEDIO DE TIEMPO QUE VEN LOS TELEVIDENTES EL CANAL: ";
    int tiempoPromedio=DuracionTotal/televidentes;
    imprimir_duracion(tiempoPromedio,write);
    write<<endl;
    write<<"PORCENTAJES SEGUN SU EDAD: "<<endl;
    double porcJovenes=(jovenes/(double)televidentes)*100.0;
    double porcAdultos=(adultos/(double)televidentes)*100.0;
    double porcMenores=(menores/(double)televidentes)*100.0;
    write<<setw(6)<<""<<"MENORES:"<<setw(5)<<""<<fixed<<setprecision(2)<<porcMenores<<"%"<<endl;
    write<<setw(6)<<""<<"JOVENES:"<<setw(5)<<""<<fixed<<setprecision(2)<<porcJovenes<<"%"<<endl;
    write<<setw(6)<<""<<"ADULTOS:"<<setw(5)<<""<<fixed<<setprecision(2)<<porcAdultos<<"%"<<endl;
    write<<"TOTAL DE PERSONAS QUE VEN EL CANAL: "<<televidentes<<endl;
    imprimir_linea(ANCHO_REPORTE,'=',write);
}
void imprimir_encabezadoEstatico2(ofstream &write) {
    imprimir_linea(ANCHO_REPORTE,'-',write);
    write<<"DNI No.";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"NOMBRE";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"SEXO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"CATEGORIA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"COMPANIA";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"RANGO";
    write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<""<<"DURACION"<<endl;
    imprimir_linea(ANCHO_REPORTE,'-',write);
}


//69323674      ROSARIO_MENDOZA_EGUSQUIZA  31/03/2013      F  B
void imprimir_datosDinamicos(ifstream &leer_preferencias,ofstream &write,int canal,ifstream &leer_televidentes,int &televidentes,int &DuracionTotal,int &jovenes,int &menores,int &adultos) {
    int DNI=0,canalLeido,horaI,horaF;
    char c;
    televidentes=0;
    DuracionTotal=0,jovenes=0,menores=0,adultos=0;
    leer_preferencias.clear();
    leer_preferencias.seekg(0,ios::beg);
    imprimir_encabezadoEstatico2(write);
    while (true) {
        leer_preferencias>>DNI;
        if (leer_preferencias.eof())break;
        while (true) {
            leer_preferencias>>canalLeido;
            horaI=almacenarDuracion(leer_preferencias),horaF=almacenarDuracion(leer_preferencias);
            if (canalLeido==canal) {
                write<<DNI;
                name_sex_category_compania(leer_televidentes,DNI,write,jovenes,adultos,menores);
                write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
                imprimir_duracion(horaI,write);
                write<<"-";
                imprimir_duracion(horaF,write);
                write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
                imprimir_duracion(horaF-horaI,write);
                write<<endl;
                televidentes++,DuracionTotal+=horaF-horaI;
            }
            c=leer_preferencias.get();
            if (c=='\n')break;
        }
    }
    imprimir_linea(ANCHO_REPORTE,'-',write);
}

void imprimir_fecha (int fecha,ofstream &write) {
    write<<setw(2)<<setfill('0')<<fecha%100<<"/"<<setw(2)<<setfill('0')<<(fecha%10000)/100<<"/"<<fecha/10000;
    write<<setfill(' ');
}

void imprimir_duracion (int duracion,ofstream &write) {
    write<<setw(2)<<setfill('0')<<duracion/3600<<":"<<setw(2)<<setfill('0')<<(duracion%3600)/60<<":"<<setw(2)<<setfill('0')<<(duracion%3600)%60;
    write<<setfill(' ');
}

int almacenarDuracion(ifstream &leer) {
    int h,m,s;
    char c;
    leer>>h>>c>>m>>c>>s;
    return (h*3600+m*60+s);
}
//69323674      ROSARIO_MENDOZA_EGUSQUIZA  31/03/2013      F  B
void name_sex_category_compania(ifstream &leer_televidentes,int DNI,ofstream &write,int &jovenes,int &adultos,int &menores) {
    int DNILeido,fecha;
    char sexo,compania;
    leer_televidentes.clear();
    leer_televidentes.seekg(0,ios::beg);
    while (true) {
        leer_televidentes>>DNILeido;
        if (leer_televidentes.eof())break;
        if (DNI==DNILeido) {
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_nombreCamelizacion(leer_televidentes,write);
            fecha=convertir_Fecha(leer_televidentes);
            leer_televidentes>>ws>>sexo>>ws>>compania;
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_sexo(sexo,write);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_categoria(fecha,write,jovenes,adultos,menores);
            write<<setw(ANCHO_REPORTE/(NRO_COLUMNAS))<<"";
            imprimir_compania(compania,write);
            break;
        }
        else {
            leer_televidentes.ignore(500,'\n');
            continue;
        }
    }
}

void imprimir_sexo(char sexo,ofstream &write) {
    if (sexo=='F') write<<"Femenino";
    else write<<"Masculino";
}
void imprimir_compania(char compania,ofstream &write) {
    if (compania=='A') write<<"TVPUCP";
    else if (compania=='B') write<<"CableMas";
    else write<<"TPVision";
}
void imprimir_categoria(int fecha,ofstream &write,int &jovenes,int &adultos,int &menores) {
    int fecha1=2009,fecha2=1988;
    if (fecha/10000>2009) {
        write<<"Menor";
        menores++;
    }
    else if (fecha/10000>1988 and fecha/10000<=2009) {
        write<<"Joven";
        jovenes++;
    }
    else {
        write<<"Adulto";
        adultos++;
    }
}
//ROSARIO_MENDOZA_EGUSQUIZA
void imprimir_nombreCamelizacion(ifstream &leer,ofstream &write) {
    char c;
    int i=1,tamaño=0,j=0;
    leer>>ws;
    while (true) {
        c=leer.get();
        if (c==' ')break;
        if (i%2==0 and c!='_') c=(char)(c+'a'-'A');
        if (c!='_') {
            i++;
        }
        if (c=='_') c=' ';
        write.put(c);
        tamaño++;
    }
    int ancho=ANCHO_REPORTE/NRO_COLUMNAS;
    while (j<(ancho-tamaño)) {
        write.put(' ');
        j++;
    }
}

int convertir_Fecha(ifstream &leer) {
    int dd,mm,yyyy;
    char c;
    leer>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000)+mm*100+dd;
}