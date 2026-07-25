//
// Created by Madi on 11/09/2025.
//

#include "Funciones.hpp"

void imprimir_calcular_reporte() {
    imprimir_encabezado();
    imprimir_datos();
}

void imprimir_linea(int n,char c) {
    int i=0;
    while (i<n) {
        cout.put(c);
        i++;
    }
    cout<<endl;
}
//15/10/2022    F3765    Fextralife        508816      16/07/2025   00:25:55   1396
void imprimir_datos() {
    int i=1,codigo,fecha,TotalRepro,TotalHora,MayorFecha,TotalReproGlobal=0,streams=0,TotalHorasGlobales=0,TotalIngresos=0;
    int MayorCodigo;
    double ingresos,ingresoMayor=0;
    char letra,mayorLetra;
    while (true) {
        fecha=calcularFecha();
        if (cin.eof()) break;
        if (!validarFecha(fecha)) {
            cin.ignore(1000,'\n');
            continue;
        }
        imprimir_estatico(i);
        cout<<setw(8)<<"";
        cin>>ws>>letra>>codigo;
        imprimir_datos_estaticos(fecha,letra,codigo);
        i++;
        imprimir_datosDinamicos(TotalRepro,TotalHora,ingresos,MayorFecha,streams);
        if (ingresos>ingresoMayor) {
            ingresoMayor=ingresos,mayorLetra=letra,MayorCodigo=codigo;
        }
        imprimir_estadisticasPorCanal(TotalRepro,MayorFecha,ingresos,TotalHora);
        TotalReproGlobal=TotalReproGlobal+TotalRepro,TotalHorasGlobales=TotalHorasGlobales+TotalHora,TotalIngresos=TotalIngresos+ingresos;
    }
    imprimir_estadisticasGlobales(ingresoMayor,mayorLetra,MayorCodigo,TotalReproGlobal,TotalHorasGlobales,streams,TotalIngresos);
}

void imprimir_estadisticasGlobales(double ingresoMayor,char mayorLetra,int MayorCodigo,int TotalRepro,int TotalHoras,int streams,double TotalIngreso) {
    imprimir_linea(120,'=');
    cout<<"RESUMEN FINAL"<<endl;
    cout<<"CANTIDAD TOTAL DE STREAMS COLOCADOS POR LOS CANALES: "<<setw(8)<<streams<<endl;
    cout<<"DURACION TOTAL DE LOS STREAMS PUBLICADOS: "<<setw(10)<<"";
    imprimir_hora(TotalHoras);
    cout<<endl;
    cout<<"INGRESOS TOTALES POR PUBLICIDAD: "<<setw(15)<<""<<"S/. "<<TotalIngreso<<endl;
    cout<<"CANAL CON MAYORES INGRESOS POR PUBLICIDAD: "<<setw(10)<<""<<mayorLetra<<MayorCodigo<<" CON S/. "<<ingresoMayor<<endl;
}

void imprimir_estadisticasPorCanal(int ReproTotal,int fecha,double ingresos,int TotalHora) {
    imprimir_linea(120,'-');
    cout<<setw(8)<<""<<"RESUMEN DEL CANAL:"<<endl;
    cout<<setw(8)<<""<<"DURACION TOTAL DE LAS REPRODUCCIONES: ";
    cout<<setw(5)<<"";
    imprimir_hora(TotalHora);
    cout<<endl;
    cout<<setw(8)<<""<<"ULTIMA PUBLICACION: ";
    cout<<setw(5)<<"";
    imprimir_fecha(fecha);
    cout<<endl;
    cout<<setw(8)<<""<<"TOTAL DE REPRODUCCIONES: "<<ReproTotal<<endl;
    cout<<setw(8)<<""<<"INGRESOS POR PUBLICIDAD: "<<setw(8)<<""<<"S/. "<<fixed<<setprecision(2)<<ingresos<<endl;
}

void imprimir_hora(int hora) {
    cout<<setw(2)<<setfill('0')<<hora/3600<<':'<<setw(2)<<setfill('0')<<(hora%3600)/60<<':'<<setw(2)<<setfill('0')<<(hora%3600)%60;
    cout<<setfill(' ');
}
void imprimir_encabezado() {
    cout<<setw(40)<<""<<"PLATAFORMA TP_Twitch"<<endl;
    cout<<setw(35)<<""<<"REGISTRO DE LOS CANALES AFILIADOS"<<endl;
    cout<<setw(25)<<""<<"FECHAS DE CREACION ENTRE EL 09/09/2022 Y EL 01/01/2023"<<endl;
}

void imprimir_estatico(int i) {
    imprimir_linea(120,'=');
    cout<<"CANAL No. "<<i<<endl;
    cout<<setw(8)<<""<<"NOMBRE";
    cout<<setw(8)<<""<<"CODIGO";
    cout<<setw(8)<<""<<"CREADO EL";
    cout<<setw(8)<<""<<"NUMERO DE SEGUIDORES"<<endl;
}
//15/10/2022    F3765    Fextralife        508816      16/07/2025   00:25:55   1396
void imprimir_datos_estaticos(int fecha,char letra,int codigo) {
    int seguidores;
    char c;
    cout<<setw(8)<<"";
    imprimir_nombreMayus(c);
    cout<<setw(8)<<""<<letra<<codigo;
    cout<<setw(8)<<"";
    imprimir_fecha(fecha);
    cin>>seguidores;
    cout<<setw(8)<<""<<seguidores<<endl;
    imprimir_linea(120,'-');
}

bool validarFecha(int fecha) {
    if (fecha>=20220909 and fecha<=20230101) return true;
    else return false;
}

int calcularFecha() {
    int dd,mm,yyyy;
    char c;
    cin>>dd>>c>>mm>>c>>yyyy;
    return (yyyy*10000+mm*100+dd);
}

void imprimir_fecha(int fecha) {
    cout<<setw(2)<<setfill('0')<<fecha%100<<'/'<<setw(2)<<setfill('0')<<(fecha%10000)/100<<'/'<<(fecha/10000);
    cout<<setfill(' ');
}
//15/10/2022    F3765    Fextralife        508816      16/07/2025   00:25:55   1396
void imprimir_nombreMayus(char &c) {
    cin>>ws;
    while (true) {
        cin.get(c);
        if (c>='a' and c<='z') {
            c=(char)(c-'a'+'A');
        }
        if (c==' ') break;
        cout.put(c);
    }
}

void imprimir_segundoEncabezado() {
    cout<<setw(8)<<""<<"ULTIMAS REPRODUCCIONES"<<endl;
    cout<<setw(12)<<""<<"FECHA DE PUBLICACION";
    cout<<setw(12)<<""<<"TIEMPO DE DURACION";
    cout<<setw(12)<<""<<"NUMERO DE REPRODUCCIONES"<<endl;
}
//15/10/2022    F3765    Fextralife        508816      16/07/2025   00:25:55   1396
void imprimir_datosDinamicos(int &TotalRepro,int &TotalHora,double &ingresos,int &fechaMayor,int &streams) {
    int reproducciones,hora,fecha;
    fechaMayor=20220909,TotalRepro=0;TotalHora=0;
    imprimir_segundoEncabezado();
    while (true) {
        fecha=calcularFecha();
        cout<<setw(12)<<"";
        imprimir_fecha(fecha);
        cout<<setw(25)<<"";
        leer_hora_Imprimir(hora);
        if (fecha>fechaMayor) fechaMayor=fecha;
        cin>>reproducciones;
        cout<<setw(25)<<""<<reproducciones<<endl;
        TotalRepro+=reproducciones;
        TotalHora+=hora;
        streams++;
        if (cin.get()=='\n')break;
    }
    ingresos=(TotalRepro+999)*(3.25/1000.0);
}

void leer_hora_Imprimir(int &hora) {
    int h,m,s;
    char c;
    cin>>h>>c>>m>>c>>s;
    cout<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<':'<<setw(2)<<setfill('0')<<s;
    cout<<setfill(' ');
    hora=h*3600+m*60+s;
}

